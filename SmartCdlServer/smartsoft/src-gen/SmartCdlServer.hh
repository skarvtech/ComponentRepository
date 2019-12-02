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
#ifndef _SMARTCDLSERVER_HH
#define _SMARTCDLSERVER_HH

#include <map>
#include <iostream>
#include "aceSmartSoft.hh"
#include "smartQueryServerTaskTrigger_T.h"
#include "SmartCdlServerCore.hh"

#include "SmartCdlServerPortFactoryInterface.hh"
#include "SmartCdlServerExtension.hh"

// forward declarations
class SmartCdlServerPortFactoryInterface;
class SmartCdlServerExtension;

// includes for OpcUaBackendComponentGeneratorExtension

// includes for SmartCdlServerROSExtension

// includes for PlainOpcUaSmartCdlServerExtension
// include plain OPC UA device clients
// include plain OPC UA status servers


// include communication objects
#include <CommNavigationObjects/CdlGoalEventState.hh>
#include <CommNavigationObjects/CdlGoalEventStateACE.hh>
#include <CommBasicObjects/CommBaseState.hh>
#include <CommBasicObjects/CommBaseStateACE.hh>
#include <CommNavigationObjects/CommCdlGoalEventParameter.hh>
#include <CommNavigationObjects/CommCdlGoalEventParameterACE.hh>
#include <CommNavigationObjects/CommCdlGoalEventResult.hh>
#include <CommNavigationObjects/CommCdlGoalEventResultACE.hh>
#include <CommNavigationObjects/CommCdlRobotBlockedEventParameter.hh>
#include <CommNavigationObjects/CommCdlRobotBlockedEventParameterACE.hh>
#include <CommNavigationObjects/CommCdlRobotBlockedEventResult.hh>
#include <CommNavigationObjects/CommCdlRobotBlockedEventResultACE.hh>
#include <CommNavigationObjects/CommCdlRobotBlockedState.hh>
#include <CommNavigationObjects/CommCdlRobotBlockedStateACE.hh>
#include <CommBasicObjects/CommMobileIRScan.hh>
#include <CommBasicObjects/CommMobileIRScanACE.hh>
#include <CommBasicObjects/CommMobileLaserScan.hh>
#include <CommBasicObjects/CommMobileLaserScanACE.hh>
#include <CommBasicObjects/CommNavigationVelocity.hh>
#include <CommBasicObjects/CommNavigationVelocityACE.hh>
#include <CommRobotinoObjects/CommPathNavigationGoal.hh>
#include <CommRobotinoObjects/CommPathNavigationGoalACE.hh>
#include <CommNavigationObjects/CommPlannerGoal.hh>
#include <CommNavigationObjects/CommPlannerGoalACE.hh>
#include <CommTrackingObjects/CommTrackingGoal.hh>
#include <CommTrackingObjects/CommTrackingGoalACE.hh>

// include tasks
#include "CdlTask.hh"
// include UpcallManagers
#include "BaseStateClientUpcallManager.hh"
#include "IRClientUpcallManager.hh"
#include "LaserClientUpcallManager.hh"
#include "LaserClient2UpcallManager.hh"
#include "NavVelSendServerUpcallManager.hh"
#include "PathNavigationGoalClientUpcallManager.hh"
#include "PlannerClientUpcallManager.hh"
#include "TrackingClientUpcallManager.hh"

// include input-handler(s)
// include request-handler(s)

// include handler
#include "CompHandler.hh"

#include "ParameterStateStruct.hh"
#include "ParameterUpdateHandler.hh"

#include "SmartStateChangeHandler.hh"

#define COMP SmartCdlServer::instance()

class SmartCdlServer : public SmartCdlServerCore {
private:
	static SmartCdlServer *_smartCdlServer;
	
	// constructor
	SmartCdlServer();
	
	// copy-constructor
	SmartCdlServer(const SmartCdlServer& cc);
	
	// destructor
	~SmartCdlServer() { };
	
	// load parameter from ini file
	void loadParameter(int argc, char* argv[]);
	
	// instantiate comp-handler
	CompHandler compHandler;
	
	// helper method that maps a string-name to an according TaskTriggerSubject
	Smart::TaskTriggerSubject* getInputTaskTriggerFromString(const std::string &client);
	
	// internal map storing the different port-creation factories (that internally map to specific middleware implementations)
	std::map<std::string, SmartCdlServerPortFactoryInterface*> portFactoryRegistry;
	
	// internal map storing various extensions of this component class
	std::map<std::string, SmartCdlServerExtension*> componentExtensionRegistry;
	
public:
	ParameterStateStruct getGlobalState() const
	{
		return paramHandler.getGlobalState();
	}
	
	ParameterStateStruct getParameters() const
	{
		return paramHandler.getGlobalState();
	}
	
	// define tasks
	Smart::TaskTriggerSubject* cdlTaskTrigger;
	CdlTask *cdlTask;
	
	// define input-ports
	// InputPort BaseStateClient
	Smart::IPushClientPattern<CommBasicObjects::CommBaseState> *baseStateClient;
	Smart::InputTaskTrigger<CommBasicObjects::CommBaseState> *baseStateClientInputTaskTrigger;
	BaseStateClientUpcallManager *baseStateClientUpcallManager;
	// InputPort IRClient
	Smart::IPushClientPattern<CommBasicObjects::CommMobileIRScan> *iRClient;
	Smart::InputTaskTrigger<CommBasicObjects::CommMobileIRScan> *iRClientInputTaskTrigger;
	IRClientUpcallManager *iRClientUpcallManager;
	// InputPort LaserClient
	Smart::IPushClientPattern<CommBasicObjects::CommMobileLaserScan> *laserClient;
	Smart::InputTaskTrigger<CommBasicObjects::CommMobileLaserScan> *laserClientInputTaskTrigger;
	LaserClientUpcallManager *laserClientUpcallManager;
	// InputPort LaserClient2
	Smart::IPushClientPattern<CommBasicObjects::CommMobileLaserScan> *laserClient2;
	Smart::InputTaskTrigger<CommBasicObjects::CommMobileLaserScan> *laserClient2InputTaskTrigger;
	LaserClient2UpcallManager *laserClient2UpcallManager;
	// InputPort NavVelSendServer
	Smart::ISendServerPattern<CommBasicObjects::CommNavigationVelocity> *navVelSendServer;
	Smart::InputTaskTrigger<CommBasicObjects::CommNavigationVelocity> *navVelSendServerInputTaskTrigger;
	NavVelSendServerUpcallManager *navVelSendServerUpcallManager;
	// InputPort PathNavigationGoalClient
	Smart::IPushClientPattern<CommRobotinoObjects::CommPathNavigationGoal> *pathNavigationGoalClient;
	Smart::InputTaskTrigger<CommRobotinoObjects::CommPathNavigationGoal> *pathNavigationGoalClientInputTaskTrigger;
	PathNavigationGoalClientUpcallManager *pathNavigationGoalClientUpcallManager;
	// InputPort PlannerClient
	Smart::IPushClientPattern<CommNavigationObjects::CommPlannerGoal> *plannerClient;
	Smart::InputTaskTrigger<CommNavigationObjects::CommPlannerGoal> *plannerClientInputTaskTrigger;
	PlannerClientUpcallManager *plannerClientUpcallManager;
	// InputPort TrackingClient
	Smart::IPushClientPattern<CommTrackingObjects::CommTrackingGoal> *trackingClient;
	Smart::InputTaskTrigger<CommTrackingObjects::CommTrackingGoal> *trackingClientInputTaskTrigger;
	TrackingClientUpcallManager *trackingClientUpcallManager;
	
	// define request-ports
	
	// define input-handler
	
	// define output-ports
	Smart::IEventServerPattern<CommNavigationObjects::CommCdlGoalEventParameter, CommNavigationObjects::CommCdlGoalEventResult, CommNavigationObjects::CdlGoalEventState> *goalEventServer;
	std::shared_ptr<Smart::IEventTestHandler<CommNavigationObjects::CommCdlGoalEventParameter, CommNavigationObjects::CommCdlGoalEventResult, CommNavigationObjects::CdlGoalEventState>> goalEventServerEventTestHandler;
	Smart::ISendClientPattern<CommBasicObjects::CommNavigationVelocity> *navVelSendClient;
	Smart::IEventServerPattern<CommNavigationObjects::CommCdlRobotBlockedEventParameter, CommNavigationObjects::CommCdlRobotBlockedEventResult, CommNavigationObjects::CommCdlRobotBlockedState> *robotBlockedEventServer;
	std::shared_ptr<Smart::IEventTestHandler<CommNavigationObjects::CommCdlRobotBlockedEventParameter, CommNavigationObjects::CommCdlRobotBlockedEventResult, CommNavigationObjects::CommCdlRobotBlockedState>> robotBlockedEventServerEventTestHandler;
	
	// define answer-ports
	
	// define request-handlers
	
	// definitions of OpcUaBackendComponentGeneratorExtension
	
	// definitions of SmartCdlServerROSExtension
	
	// definitions of PlainOpcUaSmartCdlServerExtension
	
	
	// define default slave ports
	SmartACE::StateSlave *stateSlave;
	SmartStateChangeHandler *stateChangeHandler;
	SmartACE::WiringSlave *wiringSlave;
	ParamUpdateHandler paramHandler;
	SmartACE::ParameterSlave *param;
	
	
	/// this method is used to register different PortFactory classes (one for each supported middleware framework)
	void addPortFactory(const std::string &name, SmartCdlServerPortFactoryInterface *portFactory);
	
	SmartACE::SmartComponent* getComponentImpl();
	
	/// this method is used to register different component-extension classes
	void addExtension(SmartCdlServerExtension *extension);
	
	/// this method allows to access the registered component-extensions (automatically converting to the actuall implementation type)
	template <typename T>
	T* getExtension(const std::string &name) {
		auto it = componentExtensionRegistry.find(name);
		if(it != componentExtensionRegistry.end()) {
			return dynamic_cast<T*>(it->second);
		}
		return 0;
	}
	
	/// initialize component's internal members
	void init(int argc, char *argv[]);
	
	/// execute the component's infrastructure
	void run();
	
	/// clean-up component's resources
	void fini();
	
	/// call this method to set the overall component into the Alive state (i.e. component is then ready to operate)
	void setStartupFinished();
	
	/// connect all component's client ports
	Smart::StatusCode connectAndStartAllServices();
	
	/// start all assocuated Activities
	void startAllTasks();
	
	/// start all associated timers
	void startAllTimers();
	
	Smart::StatusCode connectBaseStateClient(const std::string &serverName, const std::string &serviceName);
	Smart::StatusCode connectIRClient(const std::string &serverName, const std::string &serviceName);
	Smart::StatusCode connectLaserClient(const std::string &serverName, const std::string &serviceName);
	Smart::StatusCode connectLaserClient2(const std::string &serverName, const std::string &serviceName);
	Smart::StatusCode connectNavVelSendClient(const std::string &serverName, const std::string &serviceName);
	Smart::StatusCode connectPathNavigationGoalClient(const std::string &serverName, const std::string &serviceName);
	Smart::StatusCode connectPlannerClient(const std::string &serverName, const std::string &serviceName);
	Smart::StatusCode connectTrackingClient(const std::string &serverName, const std::string &serviceName);

	// return singleton instance
	static SmartCdlServer* instance()
	{
		if(_smartCdlServer == 0) {
			_smartCdlServer = new SmartCdlServer();
		}
		return _smartCdlServer;
	}
	
	static void deleteInstance() {
		if(_smartCdlServer != 0) {
			delete _smartCdlServer;
		}
	}
	
	// connections parameter
	struct connections_struct
	{
		// component struct
		struct component_struct
		{
			// the name of the component
			std::string name;
			std::string initialComponentMode;
			std::string defaultScheduler;
			bool useLogger;
		} component;
		
		//--- task parameter ---
		struct CdlTask_struct {
			double minActFreq;
			double maxActFreq;
			std::string trigger;
			// only one of the following two params is 
			// actually used at run-time according 
			// to the system config model
			double periodicActFreq;
			// or
			std::string inPortRef;
			int prescale;
			// scheduling parameters
			std::string scheduler;
			int priority;
			int cpuAffinity;
		} cdlTask;
		
		//--- upcall parameter ---
		
		//--- server port parameter ---
		struct GoalEventServer_struct {
				std::string serviceName;
				std::string roboticMiddleware;
		} goalEventServer;
		struct NavVelSendServer_struct {
				std::string serviceName;
				std::string roboticMiddleware;
		} navVelSendServer;
		struct RobotBlockedEventServer_struct {
				std::string serviceName;
				std::string roboticMiddleware;
		} robotBlockedEventServer;
	
		//--- client port parameter ---
		struct BaseStateClient_struct {
			bool initialConnect;
			std::string serverName;
			std::string serviceName;
			std::string wiringName;
			long interval;
			std::string roboticMiddleware;
		} baseStateClient;
		struct IRClient_struct {
			bool initialConnect;
			std::string serverName;
			std::string serviceName;
			std::string wiringName;
			long interval;
			std::string roboticMiddleware;
		} iRClient;
		struct LaserClient_struct {
			std::string serverName;
			std::string serviceName;
			std::string wiringName;
			long interval;
			std::string roboticMiddleware;
		} laserClient;
		struct LaserClient2_struct {
			bool initialConnect;
			std::string serverName;
			std::string serviceName;
			std::string wiringName;
			long interval;
			std::string roboticMiddleware;
		} laserClient2;
		struct NavVelSendClient_struct {
			bool initialConnect;
			std::string serverName;
			std::string serviceName;
			std::string wiringName;
			long interval;
			std::string roboticMiddleware;
		} navVelSendClient;
		struct PathNavigationGoalClient_struct {
			bool initialConnect;
			std::string serverName;
			std::string serviceName;
			std::string wiringName;
			long interval;
			std::string roboticMiddleware;
		} pathNavigationGoalClient;
		struct PlannerClient_struct {
			bool initialConnect;
			std::string serverName;
			std::string serviceName;
			std::string wiringName;
			long interval;
			std::string roboticMiddleware;
		} plannerClient;
		struct TrackingClient_struct {
			bool initialConnect;
			std::string serverName;
			std::string serviceName;
			std::string wiringName;
			long interval;
			std::string roboticMiddleware;
		} trackingClient;
		
		// -- parameters for OpcUaBackendComponentGeneratorExtension
		
		// -- parameters for SmartCdlServerROSExtension
		
		// -- parameters for PlainOpcUaSmartCdlServerExtension
		
	} connections;
};
#endif
