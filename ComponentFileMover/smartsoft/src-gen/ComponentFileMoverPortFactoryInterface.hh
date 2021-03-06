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
// Please do not modify this file. It will be re-generated
// running the code generator.
//--------------------------------------------------------------------------

#ifndef COMPONENTFILEMOVER_PORTFACTORYINTERFACE_HH_
#define COMPONENTFILEMOVER_PORTFACTORYINTERFACE_HH_

// include communication objects
#include <CommBasicObjects/CommFileMoverEventParameter.hh>
#include <CommBasicObjects/CommFileMoverEventParameterACE.hh>
#include <CommBasicObjects/CommFileMoverEventResult.hh>
#include <CommBasicObjects/CommFileMoverEventResultACE.hh>
#include <CommBasicObjects/CommFileMoverEventState.hh>
#include <CommBasicObjects/CommFileMoverEventStateACE.hh>
#include <CommBasicObjects/CommFileReadAnswer.hh>
#include <CommBasicObjects/CommFileReadAnswerACE.hh>
#include <CommBasicObjects/CommFileReadRequest.hh>
#include <CommBasicObjects/CommFileReadRequestACE.hh>
#include <CommBasicObjects/CommFileWriteAnswer.hh>
#include <CommBasicObjects/CommFileWriteAnswerACE.hh>
#include <CommBasicObjects/CommFileWriteRequest.hh>
#include <CommBasicObjects/CommFileWriteRequestACE.hh>

#include <chrono>

// include component's main class
#include "ComponentFileMover.hh"

// forward declaration
class ComponentFileMover;

class ComponentFileMoverPortFactoryInterface {
public:
	ComponentFileMoverPortFactoryInterface() { };
	virtual ~ComponentFileMoverPortFactoryInterface() { };

	virtual void initialize(ComponentFileMover *component, int argc, char* argv[]) = 0;
	virtual int onStartup() = 0;

	virtual Smart::IQueryClientPattern<CommBasicObjects::CommFileReadRequest, CommBasicObjects::CommFileReadAnswer> * createCommFileReadQueryReq() = 0;
	virtual Smart::IQueryClientPattern<CommBasicObjects::CommFileWriteRequest, CommBasicObjects::CommFileWriteAnswer> * createCommFileWriteQueryReq() = 0;
	
	virtual Smart::IEventServerPattern<CommBasicObjects::CommFileMoverEventParameter, CommBasicObjects::CommFileMoverEventResult, CommBasicObjects::CommFileMoverEventState> * createCommFileMoveEventOut(const std::string &serviceName, std::shared_ptr<Smart::IEventTestHandler<CommBasicObjects::CommFileMoverEventParameter, CommBasicObjects::CommFileMoverEventResult, CommBasicObjects::CommFileMoverEventState>> commFileMoveEventOutEventTestHandler) = 0;

	virtual int onShutdown(const std::chrono::steady_clock::duration &timeoutTime=std::chrono::seconds(2)) = 0;
	virtual void destroy() = 0;
};

#endif /* COMPONENTFILEMOVER_PORTFACTORYINTERFACE_HH_ */
