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
#ifndef _COMPONENTFILEMOVER_HH
#define _COMPONENTFILEMOVER_HH

#include <map>
#include <iostream>
#include "aceSmartSoft.hh"
#include "smartQueryServerTaskTrigger_T.h"
#include "ComponentFileMoverCore.hh"

#include "ComponentFileMoverPortFactoryInterface.hh"
#include "ComponentFileMoverExtension.hh"

// forward declarations
class ComponentFileMoverPortFactoryInterface;
class ComponentFileMoverExtension;

// includes for ComponentFileMoverROSExtension

// includes for OpcUaBackendComponentGeneratorExtension

// includes for PlainOpcUaComponentFileMoverExtension
// include plain OPC UA device clients
// include plain OPC UA status servers


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

// include tasks
#include "FileMoveEventHandler.hh"
// include UpcallManagers

// include input-handler(s)
// include request-handler(s)

// include handler
#include "CompHandler.hh"

#include "ParameterStateStruct.hh"
#include "ParameterUpdateHandler.hh"

#include "SmartStateChangeHandler.hh"

#define COMP ComponentFileMover::instance()

class ComponentFileMover : public ComponentFileMoverCore {
private:
	static ComponentFileMover *_componentFileMover;
	
	// constructor
	ComponentFileMover();
	
	// copy-constructor
	ComponentFileMover(const ComponentFileMover& cc);
	
	// destructor
	~ComponentFileMover() { };
	
	// load parameter from ini file
	void loadParameter(int argc, char* argv[]);
	
	// instantiate comp-handler
	CompHandler compHandler;
	
	// helper method that maps a string-name to an according TaskTriggerSubject
	Smart::TaskTriggerSubject* getInputTaskTriggerFromString(const std::string &client);
	
	// internal map storing the different port-creation factories (that internally map to specific middleware implementations)
	std::map<std::string, ComponentFileMoverPortFactoryInterface*> portFactoryRegistry;
	
	// internal map storing various extensions of this component class
	std::map<std::string, ComponentFileMoverExtension*> componentExtensionRegistry;
	
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
	Smart::TaskTriggerSubject* fileMoveEventHandlerTrigger;
	FileMoveEventHandler *fileMoveEventHandler;
	
	// define input-ports
	
	// define request-ports
	Smart::IQueryClientPattern<CommBasicObjects::CommFileReadRequest, CommBasicObjects::CommFileReadAnswer> *commFileReadQueryReq;
	Smart::IQueryClientPattern<CommBasicObjects::CommFileWriteRequest, CommBasicObjects::CommFileWriteAnswer> *commFileWriteQueryReq;
	
	// define input-handler
	
	// define output-ports
	Smart::IEventServerPattern<CommBasicObjects::CommFileMoverEventParameter, CommBasicObjects::CommFileMoverEventResult, CommBasicObjects::CommFileMoverEventState> *commFileMoveEventOut;
	std::shared_ptr<Smart::IEventTestHandler<CommBasicObjects::CommFileMoverEventParameter, CommBasicObjects::CommFileMoverEventResult, CommBasicObjects::CommFileMoverEventState>> commFileMoveEventOutEventTestHandler;
	
	// define answer-ports
	
	// define request-handlers
	
	// definitions of ComponentFileMoverROSExtension
	
	// definitions of OpcUaBackendComponentGeneratorExtension
	
	// definitions of PlainOpcUaComponentFileMoverExtension
	
	
	// define default slave ports
	SmartACE::StateSlave *stateSlave;
	SmartStateChangeHandler *stateChangeHandler;
	SmartACE::WiringSlave *wiringSlave;
	ParamUpdateHandler paramHandler;
	SmartACE::ParameterSlave *param;
	
	
	/// this method is used to register different PortFactory classes (one for each supported middleware framework)
	void addPortFactory(const std::string &name, ComponentFileMoverPortFactoryInterface *portFactory);
	
	SmartACE::SmartComponent* getComponentImpl();
	
	/// this method is used to register different component-extension classes
	void addExtension(ComponentFileMoverExtension *extension);
	
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
	
	Smart::StatusCode connectCommFileReadQueryReq(const std::string &serverName, const std::string &serviceName);
	Smart::StatusCode connectCommFileWriteQueryReq(const std::string &serverName, const std::string &serviceName);

	// return singleton instance
	static ComponentFileMover* instance()
	{
		if(_componentFileMover == 0) {
			_componentFileMover = new ComponentFileMover();
		}
		return _componentFileMover;
	}
	
	static void deleteInstance() {
		if(_componentFileMover != 0) {
			delete _componentFileMover;
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
		struct FileMoveEventHandler_struct {
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
		} fileMoveEventHandler;
		
		//--- upcall parameter ---
		
		//--- server port parameter ---
		struct CommFileMoveEventOut_struct {
				std::string serviceName;
				std::string roboticMiddleware;
		} commFileMoveEventOut;
	
		//--- client port parameter ---
		struct CommFileReadQueryReq_struct {
			bool initialConnect;
			std::string serverName;
			std::string serviceName;
			std::string wiringName;
			long interval;
			std::string roboticMiddleware;
		} commFileReadQueryReq;
		struct CommFileWriteQueryReq_struct {
			bool initialConnect;
			std::string serverName;
			std::string serviceName;
			std::string wiringName;
			long interval;
			std::string roboticMiddleware;
		} commFileWriteQueryReq;
		
		// -- parameters for ComponentFileMoverROSExtension
		
		// -- parameters for OpcUaBackendComponentGeneratorExtension
		
		// -- parameters for PlainOpcUaComponentFileMoverExtension
		
	} connections;
};
#endif
