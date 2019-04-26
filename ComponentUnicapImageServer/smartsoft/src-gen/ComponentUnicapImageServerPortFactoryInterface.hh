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

#ifndef COMPONENTUNICAPIMAGESERVER_PORTFACTORYINTERFACE_HH_
#define COMPONENTUNICAPIMAGESERVER_PORTFACTORYINTERFACE_HH_

// include communication objects
#include <CommBasicObjects/CommBaseState.hh>
#include <CommBasicObjects/CommBaseStateACE.hh>
#include <CommBasicObjects/CommDevicePoseState.hh>
#include <CommBasicObjects/CommDevicePoseStateACE.hh>
#include <DomainVision/CommVideoImage.hh>
#include <DomainVision/CommVideoImageACE.hh>
#include <CommBasicObjects/CommVoid.hh>
#include <CommBasicObjects/CommVoidACE.hh>

#include <chrono>

// include component's main class
#include "ComponentUnicapImageServer.hh"

// forward declaration
class ComponentUnicapImageServer;

class ComponentUnicapImageServerPortFactoryInterface {
public:
	ComponentUnicapImageServerPortFactoryInterface() { };
	virtual ~ComponentUnicapImageServerPortFactoryInterface() { };

	virtual void initialize(ComponentUnicapImageServer *component, int argc, char* argv[]) = 0;
	virtual int onStartup() = 0;

	virtual Smart::IPushClientPattern<CommBasicObjects::CommBaseState> * createBasePushTimedClient() = 0;
	virtual Smart::IPushClientPattern<CommBasicObjects::CommDevicePoseState> * createPtuPushTimedClient() = 0;
	
	virtual Smart::IPushServerPattern<DomainVision::CommVideoImage> * createImagePushNewestServer(const std::string &serviceName) = 0;
	virtual Smart::IQueryServerPattern<CommBasicObjects::CommVoid, DomainVision::CommVideoImage,SmartACE::QueryId> * createImageQueryServer(const std::string &serviceName) = 0;

	virtual int onShutdown(const std::chrono::steady_clock::duration &timeoutTime=std::chrono::seconds(2)) = 0;
	virtual void destroy() = 0;
};

#endif /* COMPONENTUNICAPIMAGESERVER_PORTFACTORYINTERFACE_HH_ */