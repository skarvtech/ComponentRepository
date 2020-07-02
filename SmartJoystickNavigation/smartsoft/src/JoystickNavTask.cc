//--------------------------------------------------------------------------
// Code generated by the SmartSoft MDSD Toolchain
// The SmartSoft Toolchain has been developed by:
//  
// Christian Schlegel (schlegel@hs-ulm.de)
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
//  Copyright (C) 2003 Boris Kluge
//
//        schlegel@hs-ulm.de
//
//        Prof. Dr. Christian Schlegel
//        University of Applied Sciences
//        Prittwitzstr. 10
//        D-89075 Ulm
//        Germany
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2.1 of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
// --------------------------------------------------------------------------

#include "JoystickNavTask.hh"
#include "SmartJoystickNavigation.hh"

#include <iostream>

JoystickNavTask::JoystickNavTask(SmartACE::SmartComponent *comp)
:	JoystickNavTaskCore(comp, false)
{
	std::cout << "constructor JoystickNavTask\n";
}
JoystickNavTask::~JoystickNavTask() 
{
	std::cout << "destructor JoystickNavTask\n";
}

int JoystickNavTask::getPreviousCommObjId()
{
	return 0;
}


int JoystickNavTask::on_entry()
{
	// do initialization procedures here, which are called once, each time the task is started
	// it is possible to return != 0 (e.g. when initialization fails) then the task is not executed further
	return 0;
}
int JoystickNavTask::on_execute()
{
	// this method is called from an outside loop,
	// hence, NEVER use an infinite loop (like "while(1)") here inside!!!
	// also do not use blocking calls which do not result from smartsoft kernel

	// get joystick value update
	status = this->joystickServiceInGetUpdate(js);
	if ( status != Smart::SMART_OK ) {
		std::cerr << "ERROR: failed to get update (" << status << ")" << std::endl;
		usleep(10000);
		return 0;
	}


	std::cout << js << std::endl;

	// transform joystick-value into navigation-velocity
	vel.set_vX(js.get_y() * COMP->getGlobalState().getSettings().getMax_velocity(), 1.0);
	vel.set_omega(js.get_x() * COMP->getGlobalState().getSettings().getMax_steering());
    vel.set_vY(js.get_x2() * COMP->getGlobalState().getSettings().getMax_velocity(), 1.0);
    vel.set_vZ(js.get_y2() * COMP->getGlobalState().getSettings().getMax_velocity(), 1.0);

//    vel.setUpdateCount(this->getCurrentUpdateCount());

    // send transformed navigation-velocity
	status = this->navVelServiceOutPut(vel);
	if ( status != Smart::SMART_OK ) {
		std::cerr << "ERROR: failed to send velocity ("	<< status << ")" << std::endl;
	} else {
		std::cout << vel << " sent." << std::endl;
	}

	// it is possible to return != 0 (e.g. when the task detects errors), then the outer loop breaks and the task stops
	return 0;
}
int JoystickNavTask::on_exit()
{
	// use this method to clean-up resources which are initialized in on_entry() and needs to be freed before the on_execute() can be called again
	return 0;
}
