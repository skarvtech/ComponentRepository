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

#include "ComponentFileMoverAcePortFactory.hh"

// create a static instance of the default AcePortFactory
static ComponentFileMoverAcePortFactory acePortFactory;

ComponentFileMoverAcePortFactory::ComponentFileMoverAcePortFactory()
{  
	componentImpl = 0;
	ComponentFileMover::instance()->addPortFactory("ACE_SmartSoft", this);
}

ComponentFileMoverAcePortFactory::~ComponentFileMoverAcePortFactory()
{  }

void ComponentFileMoverAcePortFactory::initialize(ComponentFileMover *component, int argc, char* argv[])
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
		componentImpl = new ComponentFileMoverImpl(component->connections.component.name, argc, argv, sched_params);
	} else {
		// create new instance of the SmartSoft component
		componentImpl = new ComponentFileMoverImpl(component->connections.component.name, argc, argv);
	}
}

int ComponentFileMoverAcePortFactory::onStartup()
{
	return componentImpl->startComponentInfrastructure();
}

Smart::IQueryClientPattern<CommBasicObjects::CommFileReadRequest, CommBasicObjects::CommFileReadAnswer> * ComponentFileMoverAcePortFactory::createCommFileReadQueryReq()
{
	return new SmartACE::QueryClient<CommBasicObjects::CommFileReadRequest, CommBasicObjects::CommFileReadAnswer>(componentImpl);
}

Smart::IQueryClientPattern<CommBasicObjects::CommFileWriteRequest, CommBasicObjects::CommFileWriteAnswer> * ComponentFileMoverAcePortFactory::createCommFileWriteQueryReq()
{
	return new SmartACE::QueryClient<CommBasicObjects::CommFileWriteRequest, CommBasicObjects::CommFileWriteAnswer>(componentImpl);
}


Smart::IEventServerPattern<CommBasicObjects::CommFileMoverEventParameter, CommBasicObjects::CommFileMoverEventResult, CommBasicObjects::CommFileMoverEventState> * ComponentFileMoverAcePortFactory::createCommFileMoveEventOut(const std::string &serviceName, std::shared_ptr<Smart::IEventTestHandler<CommBasicObjects::CommFileMoverEventParameter, CommBasicObjects::CommFileMoverEventResult, CommBasicObjects::CommFileMoverEventState>> commFileMoveEventOutEventTestHandler)
{
	return new SmartACE::EventServer<CommBasicObjects::CommFileMoverEventParameter, CommBasicObjects::CommFileMoverEventResult, CommBasicObjects::CommFileMoverEventState>(componentImpl, serviceName, commFileMoveEventOutEventTestHandler);
}


SmartACE::SmartComponent* ComponentFileMoverAcePortFactory::getComponentImpl()
{
	return componentImpl;
}

int ComponentFileMoverAcePortFactory::onShutdown(const std::chrono::steady_clock::duration &timeoutTime)
{
	componentImpl->stopComponentInfrastructure(timeoutTime);
	return 0;
}

void ComponentFileMoverAcePortFactory::destroy()
{
	// clean-up component's internally used resources (internally used communication middleware) 
	componentImpl->cleanUpComponentResources();
	delete componentImpl;
}
