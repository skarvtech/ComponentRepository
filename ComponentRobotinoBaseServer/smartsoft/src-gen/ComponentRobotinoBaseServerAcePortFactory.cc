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

#include "ComponentRobotinoBaseServerAcePortFactory.hh"

// create a static instance of the default AcePortFactory
static ComponentRobotinoBaseServerAcePortFactory acePortFactory;

ComponentRobotinoBaseServerAcePortFactory::ComponentRobotinoBaseServerAcePortFactory()
{  
	componentImpl = 0;
	ComponentRobotinoBaseServer::instance()->addPortFactory("ACE_SmartSoft", this);
}

ComponentRobotinoBaseServerAcePortFactory::~ComponentRobotinoBaseServerAcePortFactory()
{  }

void ComponentRobotinoBaseServerAcePortFactory::initialize(ComponentRobotinoBaseServer *component, int argc, char* argv[])
{
	if(component->connections.component.defaultScheduler != "DEFAULT") {
		ACE_Sched_Params sched_params(ACE_SCHED_OTHER, ACE_THR_PRI_OTHER_DEF);
		if(component->connections.component.defaultScheduler == "FIFO") {
			sched_params.policy(ACE_SCHED_FIFO);
			sched_params.priority(ACE_THR_PRI_FIFO_MIN);
		} else if(component->connections.component.defaultScheduler == "RR") {
			sched_params.policy(ACE_SCHED_RR);
			sched_params.priority(ACE_THR_PRI_RR_MIN);
		}
		// create new instance of the SmartSoft component with customized scheuling parameters 
		componentImpl = new ComponentRobotinoBaseServerImpl(component->connections.component.name, argc, argv, sched_params);
	} else {
		// create new instance of the SmartSoft component
		componentImpl = new ComponentRobotinoBaseServerImpl(component->connections.component.name, argc, argv);
	}
}

int ComponentRobotinoBaseServerAcePortFactory::onStartup()
{
	return componentImpl->startComponentInfrastructure();
}

Smart::IEventClientPattern<CommLocalizationObjects::CommLocalizationEventParameter, CommLocalizationObjects::CommLocalizationEventResult> * ComponentRobotinoBaseServerAcePortFactory::createLocalizationEventServiceIn()
{
	return new SmartACE::EventClient<CommLocalizationObjects::CommLocalizationEventParameter, CommLocalizationObjects::CommLocalizationEventResult>(componentImpl);
}


Smart::IQueryServerPattern<CommBasicObjects::CommVoid, CommBasicObjects::CommBaseState> * ComponentRobotinoBaseServerAcePortFactory::createBaseStateQueryServiceAnsw(const std::string &serviceName)
{
	return new SmartACE::QueryServer<CommBasicObjects::CommVoid, CommBasicObjects::CommBaseState>(componentImpl, serviceName);
}

Smart::IPushServerPattern<CommBasicObjects::CommBaseState> * ComponentRobotinoBaseServerAcePortFactory::createBaseStateServiceOut(const std::string &serviceName)
{
	return new SmartACE::PushServer<CommBasicObjects::CommBaseState>(componentImpl, serviceName);
}

Smart::IEventServerPattern<CommBasicObjects::CommBatteryParameter, CommBasicObjects::CommBatteryEvent, CommBasicObjects::CommBatteryState> * ComponentRobotinoBaseServerAcePortFactory::createBatteryEventServiceOut(const std::string &serviceName, std::shared_ptr<Smart::IEventTestHandler<CommBasicObjects::CommBatteryParameter, CommBasicObjects::CommBatteryEvent, CommBasicObjects::CommBatteryState>> batteryEventServiceOutEventTestHandler)
{
	return new SmartACE::EventServer<CommBasicObjects::CommBatteryParameter, CommBasicObjects::CommBatteryEvent, CommBasicObjects::CommBatteryState>(componentImpl, serviceName, batteryEventServiceOutEventTestHandler);
}

Smart::IEventServerPattern<CommBasicObjects::CommBumperEventParameter, CommBasicObjects::CommBumperEventResult, CommBasicObjects::CommBumperEventState> * ComponentRobotinoBaseServerAcePortFactory::createBumperEventServiceOut(const std::string &serviceName, std::shared_ptr<Smart::IEventTestHandler<CommBasicObjects::CommBumperEventParameter, CommBasicObjects::CommBumperEventResult, CommBasicObjects::CommBumperEventState>> bumperEventServiceOutEventTestHandler)
{
	return new SmartACE::EventServer<CommBasicObjects::CommBumperEventParameter, CommBasicObjects::CommBumperEventResult, CommBasicObjects::CommBumperEventState>(componentImpl, serviceName, bumperEventServiceOutEventTestHandler);
}

Smart::IEventServerPattern<CommRobotinoObjects::CommDigitalInputEventParameter, CommRobotinoObjects::CommDigitalInputEventResult, CommRobotinoObjects::CommDigitalInputEventState> * ComponentRobotinoBaseServerAcePortFactory::createDigitalInputEventOut(const std::string &serviceName, std::shared_ptr<Smart::IEventTestHandler<CommRobotinoObjects::CommDigitalInputEventParameter, CommRobotinoObjects::CommDigitalInputEventResult, CommRobotinoObjects::CommDigitalInputEventState>> digitalInputEventOutEventTestHandler)
{
	return new SmartACE::EventServer<CommRobotinoObjects::CommDigitalInputEventParameter, CommRobotinoObjects::CommDigitalInputEventResult, CommRobotinoObjects::CommDigitalInputEventState>(componentImpl, serviceName, digitalInputEventOutEventTestHandler);
}

Smart::IEventServerPattern<CommBasicObjects::CommLaserSafetyEventParam, CommBasicObjects::CommLaserSafetyField, CommBasicObjects::CommLaserSafetyEventState> * ComponentRobotinoBaseServerAcePortFactory::createLaserSafetyEventServiceOut(const std::string &serviceName, std::shared_ptr<Smart::IEventTestHandler<CommBasicObjects::CommLaserSafetyEventParam, CommBasicObjects::CommLaserSafetyField, CommBasicObjects::CommLaserSafetyEventState>> laserSafetyEventServiceOutEventTestHandler)
{
	return new SmartACE::EventServer<CommBasicObjects::CommLaserSafetyEventParam, CommBasicObjects::CommLaserSafetyField, CommBasicObjects::CommLaserSafetyEventState>(componentImpl, serviceName, laserSafetyEventServiceOutEventTestHandler);
}

Smart::ISendServerPattern<CommBasicObjects::CommBasePositionUpdate> * ComponentRobotinoBaseServerAcePortFactory::createLocalizationUpdateServiceIn(const std::string &serviceName)
{
	return new SmartACE::SendServer<CommBasicObjects::CommBasePositionUpdate>(componentImpl, serviceName);
}

Smart::ISendServerPattern<CommBasicObjects::CommNavigationVelocity> * ComponentRobotinoBaseServerAcePortFactory::createNavigationVelocityServiceIn(const std::string &serviceName)
{
	return new SmartACE::SendServer<CommBasicObjects::CommNavigationVelocity>(componentImpl, serviceName);
}

Smart::ISendServerPattern<CommRobotinoObjects::CommRobotinoPowerOutputValue> * ComponentRobotinoBaseServerAcePortFactory::createPowerOutputSendIn(const std::string &serviceName)
{
	return new SmartACE::SendServer<CommRobotinoObjects::CommRobotinoPowerOutputValue>(componentImpl, serviceName);
}

Smart::IQueryServerPattern<CommRobotinoObjects::CommRobotinoIOValues, CommRobotinoObjects::CommRobotinoIOValues> * ComponentRobotinoBaseServerAcePortFactory::createRobotinoIOValuesQueryServiceAnsw(const std::string &serviceName)
{
	return new SmartACE::QueryServer<CommRobotinoObjects::CommRobotinoIOValues, CommRobotinoObjects::CommRobotinoIOValues>(componentImpl, serviceName);
}


SmartACE::SmartComponent* ComponentRobotinoBaseServerAcePortFactory::getComponentImpl()
{
	return componentImpl;
}

int ComponentRobotinoBaseServerAcePortFactory::onShutdown(const std::chrono::steady_clock::duration &timeoutTime)
{
	componentImpl->stopComponentInfrastructure(timeoutTime);
	return 0;
}

void ComponentRobotinoBaseServerAcePortFactory::destroy()
{
	// clean-up component's internally used resources (internally used communication middleware) 
	componentImpl->cleanUpComponentResources();
	delete componentImpl;
}
