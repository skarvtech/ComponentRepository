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

#ifndef COMPONENTKINECTV2SERVER_PORTFACTORYINTERFACE_HH_
#define COMPONENTKINECTV2SERVER_PORTFACTORYINTERFACE_HH_

// include communication objects
#include <CommBasicObjects/CommBaseState.hh>
#include <CommBasicObjects/CommBaseStateACE.hh>
#include <CommBasicObjects/CommDevicePoseState.hh>
#include <CommBasicObjects/CommDevicePoseStateACE.hh>
#include <DomainVision/CommRGBDImage.hh>
#include <DomainVision/CommRGBDImageACE.hh>
#include <DomainVision/CommVideoImage.hh>
#include <DomainVision/CommVideoImageACE.hh>
#include <CommBasicObjects/CommVoid.hh>
#include <CommBasicObjects/CommVoidACE.hh>

#include <chrono>

// include component's main class
#include "ComponentKinectV2Server.hh"

// forward declaration
class ComponentKinectV2Server;

class ComponentKinectV2ServerPortFactoryInterface {
public:
	ComponentKinectV2ServerPortFactoryInterface() { };
	virtual ~ComponentKinectV2ServerPortFactoryInterface() { };

	virtual void initialize(ComponentKinectV2Server *component, int argc, char* argv[]) = 0;
	virtual int onStartup() = 0;

	virtual Smart::IPushClientPattern<CommBasicObjects::CommBaseState> * createBasePushTimedClient() = 0;
	virtual Smart::IPushClientPattern<CommBasicObjects::CommDevicePoseState> * createPtuPosePushNewestClient() = 0;
	
	virtual Smart::IPushServerPattern<DomainVision::CommVideoImage> * createColorImagePushNewestServer(const std::string &serviceName) = 0;
	virtual Smart::IQueryServerPattern<CommBasicObjects::CommVoid, DomainVision::CommVideoImage> * createColorImageQueryServer(const std::string &serviceName) = 0;
	virtual Smart::IPushServerPattern<DomainVision::CommRGBDImage> * createImagePushNewestServer(const std::string &serviceName) = 0;
	virtual Smart::IQueryServerPattern<CommBasicObjects::CommVoid, DomainVision::CommRGBDImage> * createImageQueryV2Server(const std::string &serviceName) = 0;

	virtual int onShutdown(const std::chrono::steady_clock::duration &timeoutTime=std::chrono::seconds(2)) = 0;
	virtual void destroy() = 0;
};

#endif /* COMPONENTKINECTV2SERVER_PORTFACTORYINTERFACE_HH_ */
