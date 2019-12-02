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
#include "BaseStateQueryHandler.hh"
#include "SmartGazeboBaseServer.hh"

BaseStateQueryHandler::BaseStateQueryHandler(Smart::IQueryServerPattern<CommBasicObjects::CommVoid, CommBasicObjects::CommBaseState>* server)
:	BaseStateQueryHandlerCore(server)
{
	
}

BaseStateQueryHandler::~BaseStateQueryHandler()
{
	
}


void BaseStateQueryHandler::handleQuery(const Smart::QueryIdPtr &id, const CommBasicObjects::CommVoid& request) 
{
    std::cout << "Query for basestate \n";
	CommBasicObjects::CommBaseState commCurrentBaseState;
	// get pose and velocity update from gazebo interface
	if (COMP->pose != NULL && COMP->velocity != NULL) {
		commCurrentBaseState.set_base_position(COMP->pose->getBasePose());
		commCurrentBaseState.set_base_raw_position(COMP->pose->getBasePose());
		commCurrentBaseState.set_base_velocity(COMP->velocity->getBaseVelocity());
	}
	else {
		std::cout << "Gazebo Simulator not yet started !" << std::endl;
	}
	CommBasicObjects::CommTimeStamp time_stamp;
	time_stamp.set_now();
	commCurrentBaseState.set_time_stamp(time_stamp);

    this->server->answer(id, commCurrentBaseState);
}
