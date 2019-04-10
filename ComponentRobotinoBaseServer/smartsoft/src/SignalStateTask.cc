
//--------------------------------------------------------------------------
// Code generated by the SmartSoft MDSD Toolchain
// The SmartSoft Toolchain has been developed by:
//  
// Service Robotics Research Center
// University of Applied Sciences Ulm
// Prittwitzstr. 10
// 89075 Ulm (Germany)
//
// Information about the SmartSoft MDSD Toolchain is available at:
// www.servicerobotik-ulm.de
//
// This file is generated once. Modify this file to your needs. 
// If you want the toolchain to re-generate this file, please 
// delete it before running the code generator.
//--------------------------------------------------------------------------

// --------------------------------------------------------------------------
//
//  Copyright (C) 2014 Matthias Lutz
//
//        lutz@hs-ulm.de
//
//        Servicerobotics Ulm
//        University of Applied Sciences
//        Prittwitzstr. 10
//        D-89075 Ulm
//        Germany
//
//  This file is part of the "SmartSoft Communication Classes".
//  It provides basic standardized data types for communication between
//  different components in the mobile robotics context. These classes
//  are designed to be used in conjunction with the SmartSoft Communication
//  Library.
//
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2.1 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
// --------------------------------------------------------------------------

#include "SignalStateTask.hh"
#include "aceSmartSoft.hh"
#include <iostream>
#include "ComponentRobotinoBaseServer.hh"

SignalStateTask::SignalStateTask(SmartACE::SmartComponent *comp) 
:	SignalStateTaskCore(comp)
{
	std::cout << "constructor SignalStateTast\n";
	std::cout << "constructor SignalStateTask\n";
		localizationState = false;

		blink = false;
		blinkLoc = false;
		newSignalState = CommBasicObjects::BaseTagType::SIGNAL_STATE_BUSY;
}
SignalStateTask::~SignalStateTask() 
{
	std::cout << "destructor SignalStateTask\n";
}

int SignalStateTask::on_entry()
{
	// do initialization procedures here, which are called once, each time the task is started
	// it is possible to return != 0 (e.g. when initialization fails) then the task is not executed further
	Smart::StatusCode status;
	// connect to all services
	std::cout << "in int SignalStateTask::on_entry() .. connecting to: "
			<< COMP->connections.localizationEventServiceIn.serverName << "; "
			<< COMP->connections.localizationEventServiceIn.serviceName << std::endl;
	status = COMP->localizationEventServiceIn->connect(
			COMP->connections.localizationEventServiceIn.serverName,
			COMP->connections.localizationEventServiceIn.serviceName);
	while (status != Smart::SMART_OK)
	{
		usleep(500000);
		status = COMP->localizationEventServiceIn->connect(
				COMP->connections.localizationEventServiceIn.serverName,
				COMP->connections.localizationEventServiceIn.serviceName);
	}
	std::cout << "connected.\n";

	int id = 0;
	CommLocalizationObjects::CommLocalizationEventParameter p;
	p.set(CommLocalizationObjects::LocalizationEventType::LOCALIZATION_UNKNOWN);
	status = COMP->localizationEventServiceIn->activate(Smart::continuous, p, id);
	if (status != Smart::SMART_OK) {
		std::cerr << "[SignalStateTask] WARNING: error on event (" << Smart::StatusCodeConversion(status)
				<< ")" << std::endl;
	}

	return 0;
}

int SignalStateTask::on_execute()
{
	// this method is called from an outside loop,
	// hence, NEVER use an infinite loop (like "while(1)") here inside!!!
	// also do not use blocking calls which do not result from smartsoft kernel
	Smart::StatusCode status;
	if(COMP->getGlobalState().getGeneral().getVerbose() == true)
		{
			std::cout<<"State is: "<<newSignalState<<" loc: "<<localizationState<<std::endl;
		}
		switch (newSignalState)
		{
		case CommBasicObjects::BaseTagType::SIGNAL_STATE_BUSY:
		{
			//BLINK
			if(newSignalState == signalState){
				COMP->robot->setDigitalOutput(4, blink);
				blink = !blink;
			}
			break;
		}
		case CommBasicObjects::BaseTagType::SIGNAL_STATE_ERROR:
		{
				COMP->robot->setDigitalOutput(2, 1);
				COMP->robot->setDigitalOutput(4, 0);
			break;
		}
		case CommBasicObjects::BaseTagType::SIGNAL_STATE_IDLE:
		{
			COMP->robot->setDigitalOutput(4, 1);
			break;
		}
	//	case CommBasicObjects::BaseTagType::SIGNAL_STATE_LOCALIZATION_ERROR:
	//	case CommBasicObjects::BaseTagType::SIGNAL_STATE_SAFETY_FIELD:

		}
		signalState = newSignalState;



		if(this->localizationState == false){
			//localization lost
			if (signalState != CommBasicObjects::BaseTagType::SIGNAL_STATE_ERROR){
				//not in error state
				COMP->robot->setDigitalOutput(2, blinkLoc);
				blinkLoc = !blinkLoc;
			}
		} else {
			//localization ok
			if (signalState != CommBasicObjects::BaseTagType::SIGNAL_STATE_ERROR){
				//not in error state
				COMP->robot->setDigitalOutput(2, 0);
			}
		}


		///////////////////////////////////////////////////////////////////////////////
		//Safety field
		std::vector<bool> in = COMP->robot->getDigitalInputArray();
		if(in[0] == false){
			COMP->robot->setDigitalOutput(3, 1);
		} else {
			COMP->robot->setDigitalOutput(3, 0);
		}


		// it is possible to return != 0 (e.g. when the task detects errors), then the outer loop breaks and the task stops
		return 0;
}

int SignalStateTask::on_exit()
{
	// use this method to clean-up resources which are initialized in on_entry() and needs to be freed before the on_execute() can be called again
	return 0;
}

void SignalStateTask::setSignalState(CommBasicObjects::BaseTagType state){
	SmartACE::SmartGuard posGuard(lockSignalState);
	newSignalState = state;

}

CommBasicObjects::BaseTagType SignalStateTask::getSignalState() const{
	SmartACE::SmartGuard posGuard(lockSignalState);
	return newSignalState;

}

void SignalStateTask::setLocalizationState(bool state){
	SmartACE::SmartGuard posGuard(lockSignalState);
	localizationState = state;
}

bool SignalStateTask::getLocalizationState()const{
	SmartACE::SmartGuard posGuard(lockSignalState);
	return localizationState;
}