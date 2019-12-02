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

#include "ComponentKeyboardNavigationOpcUaBackendPortFactory.hh"

// include all potentially required pattern implementations
#include <SeRoNetSDK/SeRoNet/OPCUA/Client/PushClient.hpp>
#include <SeRoNetSDK/SeRoNet/OPCUA/Client/EventClient.hpp>
#include <SeRoNetSDK/SeRoNet/OPCUA/Client/QClientOPCUA.hpp>
#include <SeRoNetSDK/SeRoNet/OPCUA/Client/SendClient.hpp>
#include <SeRoNetSDK/SeRoNet/OPCUA/Client/QueryClient.hpp>

#include <SeRoNetSDK/SeRoNet/OPCUA/Server/PushServer.hpp>
#include <SeRoNetSDK/SeRoNet/OPCUA/Server/EventServer.hpp>
#include <SeRoNetSDK/SeRoNet/OPCUA/Server/SendServer.hpp>
#include <SeRoNetSDK/SeRoNet/OPCUA/Server/QueryServer.hpp>

// include referenced CommunicationObject SeRoNetSDK self description implementations
#include "CommBasicObjectsOpcUa/CommNavigationVelocityOpcUa.hh"

// create a static instance of the OpcUaBackendPortFactory
static ComponentKeyboardNavigationOpcUaBackendPortFactory OpcUaBackendPortFactory;

ComponentKeyboardNavigationOpcUaBackendPortFactory::ComponentKeyboardNavigationOpcUaBackendPortFactory()
{  
	componentImpl = 0;
	ComponentKeyboardNavigation::instance()->addPortFactory("OpcUa_SeRoNet", this);
}

ComponentKeyboardNavigationOpcUaBackendPortFactory::~ComponentKeyboardNavigationOpcUaBackendPortFactory()
{  }

void ComponentKeyboardNavigationOpcUaBackendPortFactory::initialize(ComponentKeyboardNavigation *component, int argc, char* argv[])
{
	componentImpl = new SeRoNet::Utils::Component(component->connections.component.name);
}

int ComponentKeyboardNavigationOpcUaBackendPortFactory::onStartup()
{
	if (!component_thread.joinable()) {
    	component_thread = std::thread(&ComponentKeyboardNavigationOpcUaBackendPortFactory::task_execution, this);
    	return 0;
    }
	return -1;
}

Smart::ISendClientPattern<CommBasicObjects::CommNavigationVelocity> * ComponentKeyboardNavigationOpcUaBackendPortFactory::createNavVelSendClient()
{
	return new SeRoNet::OPCUA::Client::SendClient<CommBasicObjects::CommNavigationVelocity>(componentImpl);
}



int ComponentKeyboardNavigationOpcUaBackendPortFactory::task_execution()
{
	componentImpl->run();
	return 0;
}

int ComponentKeyboardNavigationOpcUaBackendPortFactory::onShutdown(const std::chrono::steady_clock::duration &timeoutTime)
{
	// stop component-internal infrastructure
	componentImpl->stopRunning();
	// wait on component thread to exit
	if (component_thread.joinable()) {
		// FIXME: don't wait infinetly (use timeoutTime here)
    	component_thread.join();
    }
	return 0;
}

void ComponentKeyboardNavigationOpcUaBackendPortFactory::destroy()
{
	// clean-up component's internally used resources
	delete componentImpl;
}
