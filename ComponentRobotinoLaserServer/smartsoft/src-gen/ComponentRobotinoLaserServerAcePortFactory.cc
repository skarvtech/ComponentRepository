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

#include "ComponentRobotinoLaserServerAcePortFactory.hh"

// create a static instance of the default AcePortFactory
static ComponentRobotinoLaserServerAcePortFactory acePortFactory;

ComponentRobotinoLaserServerAcePortFactory::ComponentRobotinoLaserServerAcePortFactory()
{  
	componentImpl = 0;
	ComponentRobotinoLaserServer::instance()->addPortFactory("ACE_SmartSoft", this);
}

ComponentRobotinoLaserServerAcePortFactory::~ComponentRobotinoLaserServerAcePortFactory()
{  }

void ComponentRobotinoLaserServerAcePortFactory::initialize(ComponentRobotinoLaserServer *component, int argc, char* argv[])
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
		componentImpl = new ComponentRobotinoLaserServerImpl(component->connections.component.name, argc, argv, sched_params);
	} else {
		// create new instance of the SmartSoft component
		componentImpl = new ComponentRobotinoLaserServerImpl(component->connections.component.name, argc, argv);
	}
}

int ComponentRobotinoLaserServerAcePortFactory::onStartup()
{
	return componentImpl->startComponentInfrastructure();
}

Smart::IPushClientPattern<CommBasicObjects::CommBaseState> * ComponentRobotinoLaserServerAcePortFactory::createBaseTimedClient()
{
	return new SmartACE::PushClient<CommBasicObjects::CommBaseState>(componentImpl);
}


Smart::IPushServerPattern<CommBasicObjects::CommMobileLaserScan> * ComponentRobotinoLaserServerAcePortFactory::createPushNewestServer(const std::string &serviceName)
{
	return new SmartACE::PushServer<CommBasicObjects::CommMobileLaserScan>(componentImpl, serviceName);
}

Smart::IQueryServerPattern<CommBasicObjects::CommVoid, CommBasicObjects::CommMobileLaserScan> * ComponentRobotinoLaserServerAcePortFactory::createQueryServer(const std::string &serviceName)
{
	return new SmartACE::QueryServer<CommBasicObjects::CommVoid, CommBasicObjects::CommMobileLaserScan>(componentImpl, serviceName);
}

Smart::IEventServerPattern<CommBasicObjects::CommLaserSafetyEventParam, CommBasicObjects::CommLaserSafetyField, CommBasicObjects::CommLaserSafetyEventState> * ComponentRobotinoLaserServerAcePortFactory::createSafetyfieldEventServer(const std::string &serviceName, std::shared_ptr<Smart::IEventTestHandler<CommBasicObjects::CommLaserSafetyEventParam, CommBasicObjects::CommLaserSafetyField, CommBasicObjects::CommLaserSafetyEventState>> safetyfieldEventServerEventTestHandler)
{
	return new SmartACE::EventServer<CommBasicObjects::CommLaserSafetyEventParam, CommBasicObjects::CommLaserSafetyField, CommBasicObjects::CommLaserSafetyEventState>(componentImpl, serviceName, safetyfieldEventServerEventTestHandler);
}


SmartACE::SmartComponent* ComponentRobotinoLaserServerAcePortFactory::getComponentImpl()
{
	return componentImpl;
}

int ComponentRobotinoLaserServerAcePortFactory::onShutdown(const std::chrono::steady_clock::duration &timeoutTime)
{
	componentImpl->stopComponentInfrastructure(timeoutTime);
	return 0;
}

void ComponentRobotinoLaserServerAcePortFactory::destroy()
{
	// clean-up component's internally used resources (internally used communication middleware) 
	componentImpl->cleanUpComponentResources();
	delete componentImpl;
}
