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

#ifndef SMARTGAZEBOBASESERVER_OPC_UA_BACKEND_PORTFACTORY_HH_
#define SMARTGAZEBOBASESERVER_OPC_UA_BACKEND_PORTFACTORY_HH_

// include the main component-definition class
#include "SmartGazeboBaseServerPortFactoryInterface.hh"

#include <thread>
#include <chrono>

// include SeRoNetSDK library
#include <SeRoNetSDK/SeRoNet/Utils/Task.hpp>
#include <SeRoNetSDK/SeRoNet/Utils/Component.hpp>

class SmartGazeboBaseServerOpcUaBackendPortFactory: public SmartGazeboBaseServerPortFactoryInterface
{
private:
	// internal component instance
	SeRoNet::Utils::Component *componentImpl;
	
	// component thread
	std::thread component_thread;
	
	// internal component thread method
	int task_execution();
public:
	SmartGazeboBaseServerOpcUaBackendPortFactory();
	virtual ~SmartGazeboBaseServerOpcUaBackendPortFactory();

	virtual void initialize(SmartGazeboBaseServer *component, int argc, char* argv[]) override;
	virtual int onStartup() override;

	
	virtual Smart::IPushServerPattern<CommBasicObjects::CommBaseState> * createBaseStateServiceOut(const std::string &serviceName) override;
	virtual Smart::ISendServerPattern<CommBasicObjects::CommBasePositionUpdate> * createLocalizationUpdateServiceIn(const std::string &serviceName) override;
	virtual Smart::IQueryServerPattern<CommBasicObjects::CommVoid, CommBasicObjects::CommBaseState> * createBaseSatateQueryAnsw(const std::string &serviceName) override;
	virtual Smart::IPushServerPattern<CommBasicObjects::CommMobileLaserScan> * createLaserServiceOut(const std::string &serviceName) override;
	virtual Smart::ISendServerPattern<CommBasicObjects::CommNavigationVelocity> * createNavVelServiceIn(const std::string &serviceName) override;
	
	virtual int onShutdown(const std::chrono::steady_clock::duration &timeoutTime=std::chrono::seconds(2)) override;
	virtual void destroy() override;
};

#endif /* SMARTGAZEBOBASESERVER_SERONET_SDK_PORTFACTORY_HH_ */
