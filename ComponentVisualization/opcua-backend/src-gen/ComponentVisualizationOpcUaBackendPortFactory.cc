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

#include "ComponentVisualizationOpcUaBackendPortFactory.hh"

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
#include "CommBasicObjectsOpcUa/CommMobileIRScanOpcUa.hh"
#include "DomainVisionOpcUa/CommVideoImageOpcUa.hh"
#include "CommTrackingObjectsOpcUa/CommPersonIdOpcUa.hh"
#include "CommTrackingObjectsOpcUa/CommDetectedPersonOpcUa.hh"
#include "CommTrackingObjectsOpcUa/PersonLostEventStateOpcUa.hh"
#include "DomainVisionOpcUa/CommDepthImageOpcUa.hh"
#include "CommBasicObjectsOpcUa/CommBaseStateOpcUa.hh"
#include "CommTrackingObjectsOpcUa/CommDetectedMarkerListOpcUa.hh"
#include "CommTrackingObjectsOpcUa/CommPersonDetectionEventResultOpcUa.hh"
#include "CommNavigationObjectsOpcUa/CommGridMapRequestOpcUa.hh"
#include "DomainVisionOpcUa/CommRGBDImageOpcUa.hh"
#include "CommNavigationObjectsOpcUa/CommGridMapOpcUa.hh"
#include "CommBasicObjectsOpcUa/CommMobileUltrasonicScanOpcUa.hh"
#include "CommBasicObjectsOpcUa/CommVoidOpcUa.hh"
#include "CommBasicObjectsOpcUa/CommMobileLaserScanOpcUa.hh"
#include "CommTrackingObjectsOpcUa/CommPersonLostEventParameterOpcUa.hh"

// create a static instance of the OpcUaBackendPortFactory
static ComponentVisualizationOpcUaBackendPortFactory OpcUaBackendPortFactory;

ComponentVisualizationOpcUaBackendPortFactory::ComponentVisualizationOpcUaBackendPortFactory()
{  
	componentImpl = 0;
	ComponentVisualization::instance()->addPortFactory("OpcUa_SeRoNet", this);
}

ComponentVisualizationOpcUaBackendPortFactory::~ComponentVisualizationOpcUaBackendPortFactory()
{  }

void ComponentVisualizationOpcUaBackendPortFactory::initialize(ComponentVisualization *component, int argc, char* argv[])
{
	componentImpl = new SeRoNet::Utils::Component(component->connections.component.name);
}

int ComponentVisualizationOpcUaBackendPortFactory::onStartup()
{
	if (!component_thread.joinable()) {
    	component_thread = std::thread(&ComponentVisualizationOpcUaBackendPortFactory::task_execution, this);
    	return 0;
    }
	return -1;
}

Smart::IPushClientPattern<CommBasicObjects::CommMobileUltrasonicScan> * ComponentVisualizationOpcUaBackendPortFactory::createUltrasonicPushNewestClient()
{
	return new SeRoNet::OPCUA::Client::PushClient<CommBasicObjects::CommMobileUltrasonicScan>(componentImpl);
}

Smart::IPushClientPattern<DomainVision::CommRGBDImage> * ComponentVisualizationOpcUaBackendPortFactory::createRgbdPushNewestClient()
{
	return new SeRoNet::OPCUA::Client::PushClient<DomainVision::CommRGBDImage>(componentImpl);
}

Smart::IPushClientPattern<CommBasicObjects::CommBaseState> * ComponentVisualizationOpcUaBackendPortFactory::createBaseClient()
{
	return new SeRoNet::OPCUA::Client::PushClient<CommBasicObjects::CommBaseState>(componentImpl);
}

Smart::IPushClientPattern<DomainVision::CommDepthImage> * ComponentVisualizationOpcUaBackendPortFactory::createDepthPushNewestClient()
{
	return new SeRoNet::OPCUA::Client::PushClient<DomainVision::CommDepthImage>(componentImpl);
}

Smart::IQueryClientPattern<CommBasicObjects::CommVoid, DomainVision::CommRGBDImage> * ComponentVisualizationOpcUaBackendPortFactory::createRGBDImageQueryServiceReq()
{
	return new SeRoNet::OPCUA::Client::QueryClient<CommBasicObjects::CommVoid, DomainVision::CommRGBDImage>(componentImpl);
}

Smart::IPushClientPattern<DomainVision::CommDepthImage> * ComponentVisualizationOpcUaBackendPortFactory::createRgbdQueryClient()
{
	return new SeRoNet::OPCUA::Client::PushClient<DomainVision::CommDepthImage>(componentImpl);
}

Smart::IPushClientPattern<CommBasicObjects::CommMobileLaserScan> * ComponentVisualizationOpcUaBackendPortFactory::createLaserClient3()
{
	return new SeRoNet::OPCUA::Client::PushClient<CommBasicObjects::CommMobileLaserScan>(componentImpl);
}

Smart::IPushClientPattern<CommBasicObjects::CommMobileIRScan> * ComponentVisualizationOpcUaBackendPortFactory::createIrPushNewestClient()
{
	return new SeRoNet::OPCUA::Client::PushClient<CommBasicObjects::CommMobileIRScan>(componentImpl);
}

Smart::IQueryClientPattern<CommTrackingObjects::CommPersonId, CommTrackingObjects::CommDetectedPerson> * ComponentVisualizationOpcUaBackendPortFactory::createPersonDetectionQueryClient()
{
	return new SeRoNet::OPCUA::Client::QueryClient<CommTrackingObjects::CommPersonId, CommTrackingObjects::CommDetectedPerson>(componentImpl);
}

Smart::IPushClientPattern<DomainVision::CommVideoImage> * ComponentVisualizationOpcUaBackendPortFactory::createImagePushNewestClient()
{
	return new SeRoNet::OPCUA::Client::PushClient<DomainVision::CommVideoImage>(componentImpl);
}

Smart::IPushClientPattern<CommBasicObjects::CommMobileLaserScan> * ComponentVisualizationOpcUaBackendPortFactory::createLaserClient1()
{
	return new SeRoNet::OPCUA::Client::PushClient<CommBasicObjects::CommMobileLaserScan>(componentImpl);
}

Smart::IQueryClientPattern<CommNavigationObjects::CommGridMapRequest, CommNavigationObjects::CommGridMap> * ComponentVisualizationOpcUaBackendPortFactory::createLtmQueryClient()
{
	return new SeRoNet::OPCUA::Client::QueryClient<CommNavigationObjects::CommGridMapRequest, CommNavigationObjects::CommGridMap>(componentImpl);
}

Smart::IPushClientPattern<CommBasicObjects::CommMobileLaserScan> * ComponentVisualizationOpcUaBackendPortFactory::createLaserClient2()
{
	return new SeRoNet::OPCUA::Client::PushClient<CommBasicObjects::CommMobileLaserScan>(componentImpl);
}

Smart::IEventClientPattern<CommTrackingObjects::CommPersonLostEventParameter, CommTrackingObjects::CommPersonDetectionEventResult> * ComponentVisualizationOpcUaBackendPortFactory::createPersonDetectionEventClient()
{
	return new SeRoNet::OPCUA::Client::EventClient<CommTrackingObjects::CommPersonLostEventParameter, CommTrackingObjects::CommPersonDetectionEventResult>(componentImpl);
}

Smart::IPushClientPattern<CommTrackingObjects::CommDetectedMarkerList> * ComponentVisualizationOpcUaBackendPortFactory::createMarkerListDetectionServiceIn()
{
	return new SeRoNet::OPCUA::Client::PushClient<CommTrackingObjects::CommDetectedMarkerList>(componentImpl);
}

Smart::IPushClientPattern<CommNavigationObjects::CommGridMap> * ComponentVisualizationOpcUaBackendPortFactory::createCurPushClient()
{
	return new SeRoNet::OPCUA::Client::PushClient<CommNavigationObjects::CommGridMap>(componentImpl);
}



int ComponentVisualizationOpcUaBackendPortFactory::task_execution()
{
	componentImpl->run();
	return 0;
}

int ComponentVisualizationOpcUaBackendPortFactory::onShutdown(const std::chrono::steady_clock::duration &timeoutTime)
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

void ComponentVisualizationOpcUaBackendPortFactory::destroy()
{
	// clean-up component's internally used resources
	delete componentImpl;
}
