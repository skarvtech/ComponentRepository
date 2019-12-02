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
#include "ComponentLaserHokuyoURGServer.hh"
#include "smartTimedTaskTrigger.h"
//FIXME: implement logging
//#include "smartGlobalLogger.hh"

// the ace port-factory is used as a default port-mapping
#include "ComponentLaserHokuyoURGServerAcePortFactory.hh"


// initialize static singleton pointer to zero
ComponentLaserHokuyoURGServer* ComponentLaserHokuyoURGServer::_componentLaserHokuyoURGServer = 0;

// constructor
ComponentLaserHokuyoURGServer::ComponentLaserHokuyoURGServer()
{
	std::cout << "constructor of ComponentLaserHokuyoURGServer\n";
	
	// set all pointer members to NULL
	//componentLaserHokuyoURGServer = NULL;
	//coordinationPort = NULL;
	laserTask = NULL;
	laserTaskTrigger = NULL;
	watchDogTask = NULL;
	watchDogTaskTrigger = NULL;
	baseTimedClient = NULL;
	baseTimedClientInputTaskTrigger = NULL;
	baseTimedClientUpcallManager = NULL;
	laserPushNewestServer = NULL;
	laserQueryServer = NULL;
	laserQueryServerInputTaskTrigger = NULL;
	laserQueryServerHandler = NULL;
	manipulatorTimedClient = NULL;
	manipulatorTimedClientInputTaskTrigger = NULL;
	manipulatorTimedClientUpcallManager = NULL;
	stateChangeHandler = NULL;
	stateSlave = NULL;
	wiringSlave = NULL;
	param = NULL;
	
	// set default ini parameter values
	connections.component.name = "ComponentLaserHokuyoURGServer";
	connections.component.initialComponentMode = "Neutral";
	connections.component.defaultScheduler = "DEFAULT";
	connections.component.useLogger = false;
	
	connections.laserPushNewestServer.serviceName = "laserPushNewestServer";
	connections.laserPushNewestServer.roboticMiddleware = "ACE_SmartSoft";
	connections.laserQueryServer.serviceName = "laserQueryServer";
	connections.laserQueryServer.roboticMiddleware = "ACE_SmartSoft";
	connections.baseTimedClient.initialConnect = false;
	connections.baseTimedClient.wiringName = "baseTimedClient";
	connections.baseTimedClient.serverName = "unknown";
	connections.baseTimedClient.serviceName = "unknown";
	connections.baseTimedClient.interval = 1;
	connections.baseTimedClient.roboticMiddleware = "ACE_SmartSoft";
	connections.manipulatorTimedClient.initialConnect = false;
	connections.manipulatorTimedClient.wiringName = "manipulatorTimedClient";
	connections.manipulatorTimedClient.serverName = "unknown";
	connections.manipulatorTimedClient.serviceName = "unknown";
	connections.manipulatorTimedClient.interval = 1;
	connections.manipulatorTimedClient.roboticMiddleware = "ACE_SmartSoft";
	connections.laserTask.minActFreq = 0.0;
	connections.laserTask.maxActFreq = 0.0;
	// scheduling default parameters
	connections.laserTask.scheduler = "DEFAULT";
	connections.laserTask.priority = -1;
	connections.laserTask.cpuAffinity = -1;
	connections.watchDogTask.minActFreq = 0.0;
	connections.watchDogTask.maxActFreq = 0.0;
	connections.watchDogTask.trigger = "PeriodicTimer";
	connections.watchDogTask.periodicActFreq = 1.0;
	// scheduling default parameters
	connections.watchDogTask.scheduler = "DEFAULT";
	connections.watchDogTask.priority = -1;
	connections.watchDogTask.cpuAffinity = -1;
	
	// initialize members of OpcUaBackendComponentGeneratorExtension
	
	// initialize members of ComponentLaserHokuyoURGServerROSExtension
	
	// initialize members of PlainOpcUaComponentLaserHokuyoURGServerExtension
	
}

void ComponentLaserHokuyoURGServer::addPortFactory(const std::string &name, ComponentLaserHokuyoURGServerPortFactoryInterface *portFactory)
{
	portFactoryRegistry[name] = portFactory;
}

void ComponentLaserHokuyoURGServer::addExtension(ComponentLaserHokuyoURGServerExtension *extension)
{
	componentExtensionRegistry[extension->getName()] = extension;
}

SmartACE::SmartComponent* ComponentLaserHokuyoURGServer::getComponentImpl()
{
	return dynamic_cast<ComponentLaserHokuyoURGServerAcePortFactory*>(portFactoryRegistry["ACE_SmartSoft"])->getComponentImpl();
}

/**
 * Notify the component that setup/initialization is finished.
 * You may call this function from anywhere in the component.
 *
 * Set component's internal lifecycle state automaton (if any) into 
 * Alive mode (from here on the component is ready to provide its services)
 */
void ComponentLaserHokuyoURGServer::setStartupFinished() {
	stateSlave->setWaitState("Alive");
	std::cout << "ComponentDefinition initialization/startup finished." << std::endl;
}


Smart::StatusCode ComponentLaserHokuyoURGServer::connectBaseTimedClient(const std::string &serverName, const std::string &serviceName) {
	Smart::StatusCode status;
	
	if(connections.baseTimedClient.initialConnect == false) {
		return Smart::SMART_OK;
	}
	std::cout << "connecting to: " << serverName << "; " << serviceName << std::endl;
	status = baseTimedClient->connect(serverName, serviceName);
	while(status != Smart::SMART_OK)
	{
		ACE_OS::sleep(ACE_Time_Value(0,500000));
		status = COMP->baseTimedClient->connect(serverName, serviceName);
	}
	std::cout << "connected.\n";
	baseTimedClient->subscribe(connections.baseTimedClient.interval);
	return status;
}
Smart::StatusCode ComponentLaserHokuyoURGServer::connectManipulatorTimedClient(const std::string &serverName, const std::string &serviceName) {
	Smart::StatusCode status;
	
	if(connections.manipulatorTimedClient.initialConnect == false) {
		return Smart::SMART_OK;
	}
	std::cout << "connecting to: " << serverName << "; " << serviceName << std::endl;
	status = manipulatorTimedClient->connect(serverName, serviceName);
	while(status != Smart::SMART_OK)
	{
		ACE_OS::sleep(ACE_Time_Value(0,500000));
		status = COMP->manipulatorTimedClient->connect(serverName, serviceName);
	}
	std::cout << "connected.\n";
	manipulatorTimedClient->subscribe(connections.manipulatorTimedClient.interval);
	return status;
}


/**
 * First connect ALL client ports contained in this component, then start all services:
 * activate state, push, etc...
 */
Smart::StatusCode ComponentLaserHokuyoURGServer::connectAndStartAllServices() {
	Smart::StatusCode status = Smart::SMART_OK;
	
	status = connectBaseTimedClient(connections.baseTimedClient.serverName, connections.baseTimedClient.serviceName);
	if(status != Smart::SMART_OK) return status;
	status = connectManipulatorTimedClient(connections.manipulatorTimedClient.serverName, connections.manipulatorTimedClient.serviceName);
	if(status != Smart::SMART_OK) return status;
	return status;
}

/**
 * Start all tasks contained in this component.
 */
void ComponentLaserHokuyoURGServer::startAllTasks() {
	// start task LaserTask
	if(connections.laserTask.scheduler != "DEFAULT") {
		ACE_Sched_Params laserTask_SchedParams(ACE_SCHED_OTHER, ACE_THR_PRI_OTHER_DEF);
		if(connections.laserTask.scheduler == "FIFO") {
			laserTask_SchedParams.policy(ACE_SCHED_FIFO);
			laserTask_SchedParams.priority(ACE_THR_PRI_FIFO_MIN);
		} else if(connections.laserTask.scheduler == "RR") {
			laserTask_SchedParams.policy(ACE_SCHED_RR);
			laserTask_SchedParams.priority(ACE_THR_PRI_RR_MIN);
		}
		laserTask->start(laserTask_SchedParams, connections.laserTask.cpuAffinity);
	} else {
		laserTask->start();
	}
	// start task WatchDogTask
	if(connections.watchDogTask.scheduler != "DEFAULT") {
		ACE_Sched_Params watchDogTask_SchedParams(ACE_SCHED_OTHER, ACE_THR_PRI_OTHER_DEF);
		if(connections.watchDogTask.scheduler == "FIFO") {
			watchDogTask_SchedParams.policy(ACE_SCHED_FIFO);
			watchDogTask_SchedParams.priority(ACE_THR_PRI_FIFO_MIN);
		} else if(connections.watchDogTask.scheduler == "RR") {
			watchDogTask_SchedParams.policy(ACE_SCHED_RR);
			watchDogTask_SchedParams.priority(ACE_THR_PRI_RR_MIN);
		}
		watchDogTask->start(watchDogTask_SchedParams, connections.watchDogTask.cpuAffinity);
	} else {
		watchDogTask->start();
	}
}

/**
 * Start all timers contained in this component
 */
void ComponentLaserHokuyoURGServer::startAllTimers() {
}


Smart::TaskTriggerSubject* ComponentLaserHokuyoURGServer::getInputTaskTriggerFromString(const std::string &client)
{
	if(client == "baseTimedClient") return baseTimedClientInputTaskTrigger;
	if(client == "manipulatorTimedClient") return manipulatorTimedClientInputTaskTrigger;
	
	return NULL;
}


void ComponentLaserHokuyoURGServer::init(int argc, char *argv[])
{
	try {
		Smart::StatusCode status;
		
		// load initial parameters from ini-file (if found)
		loadParameter(argc, argv);
		
		// print out the actual parameters which are used to initialize the component
		std::cout << " \nComponentDefinition Initial-Parameters:\n" << COMP->getParameters() << std::endl;
		
		// initializations of OpcUaBackendComponentGeneratorExtension
		
		// initializations of ComponentLaserHokuyoURGServerROSExtension
		
		// initializations of PlainOpcUaComponentLaserHokuyoURGServerExtension
		
		
		// initialize all registered port-factories
		for(auto portFactory = portFactoryRegistry.begin(); portFactory != portFactoryRegistry.end(); portFactory++) 
		{
			portFactory->second->initialize(this, argc, argv);
		}
		
		// initialize all registered component-extensions
		for(auto extension = componentExtensionRegistry.begin(); extension != componentExtensionRegistry.end(); extension++) 
		{
			extension->second->initialize(this, argc, argv);
		}
		
		ComponentLaserHokuyoURGServerPortFactoryInterface *acePortFactory = portFactoryRegistry["ACE_SmartSoft"];
		if(acePortFactory == 0) {
			std::cerr << "ERROR: acePortFactory NOT instantiated -> exit(-1)" << std::endl;
			exit(-1);
		}
		
		// this pointer is used for backwards compatibility (deprecated: should be removed as soon as all patterns, including coordination, are moved to port-factory)
		SmartACE::SmartComponent *component = dynamic_cast<ComponentLaserHokuyoURGServerAcePortFactory*>(acePortFactory)->getComponentImpl();
		
		std::cout << "ComponentDefinition ComponentLaserHokuyoURGServer is named " << connections.component.name << std::endl;
		
		if(connections.component.useLogger == true) {
			//FIXME: use logging
			//Smart::LOGGER->openLogFileInFolder("data/"+connections.component.name);
			//Smart::LOGGER->startLogging();
		}

		// create event-test handlers (if needed)
		
		// create server ports
		// TODO: set minCycleTime from Ini-file
		laserPushNewestServer = portFactoryRegistry[connections.laserPushNewestServer.roboticMiddleware]->createLaserPushNewestServer(connections.laserPushNewestServer.serviceName);
		laserQueryServer = portFactoryRegistry[connections.laserQueryServer.roboticMiddleware]->createLaserQueryServer(connections.laserQueryServer.serviceName);
		laserQueryServerInputTaskTrigger = new Smart::QueryServerTaskTrigger<CommBasicObjects::CommVoid, CommBasicObjects::CommMobileLaserScan>(laserQueryServer);
		
		// create client ports
		baseTimedClient = portFactoryRegistry[connections.baseTimedClient.roboticMiddleware]->createBaseTimedClient();
		manipulatorTimedClient = portFactoryRegistry[connections.manipulatorTimedClient.roboticMiddleware]->createManipulatorTimedClient();
		
		// create InputTaskTriggers and UpcallManagers
		baseTimedClientInputTaskTrigger = new Smart::InputTaskTrigger<CommBasicObjects::CommBaseState>(baseTimedClient);
		baseTimedClientUpcallManager = new BaseTimedClientUpcallManager(baseTimedClient);
		manipulatorTimedClientInputTaskTrigger = new Smart::InputTaskTrigger<CommManipulatorObjects::CommMobileManipulatorState>(manipulatorTimedClient);
		manipulatorTimedClientUpcallManager = new ManipulatorTimedClientUpcallManager(manipulatorTimedClient);
		
		// create input-handler
		
		// create request-handlers
		laserQueryServerHandler = new LaserQueryServerHandler(laserQueryServer);
		
		// create state pattern
		stateChangeHandler = new SmartStateChangeHandler();
		stateSlave = new SmartACE::StateSlave(component, stateChangeHandler);
		status = stateSlave->setUpInitialState(connections.component.initialComponentMode);
		if (status != Smart::SMART_OK) std::cerr << status << "; failed setting initial ComponentMode: " << connections.component.initialComponentMode << std::endl;
		// activate state slave
		status = stateSlave->activate();
		if(status != Smart::SMART_OK) std::cerr << "ERROR: activate state" << std::endl;
		
		wiringSlave = new SmartACE::WiringSlave(component);
		// add client port to wiring slave
		if(connections.baseTimedClient.roboticMiddleware == "ACE_SmartSoft") {
			//FIXME: this must also work with other implementations
			dynamic_cast<SmartACE::PushClient<CommBasicObjects::CommBaseState>*>(baseTimedClient)->add(wiringSlave, connections.baseTimedClient.wiringName);
		}
		if(connections.manipulatorTimedClient.roboticMiddleware == "ACE_SmartSoft") {
			//FIXME: this must also work with other implementations
			dynamic_cast<SmartACE::PushClient<CommManipulatorObjects::CommMobileManipulatorState>*>(manipulatorTimedClient)->add(wiringSlave, connections.manipulatorTimedClient.wiringName);
		}
		
		// create parameter slave
		param = new SmartACE::ParameterSlave(component, &paramHandler);
		
		
		// create Task LaserTask
		laserTask = new LaserTask(component);
		// configure input-links
		// configure task-trigger (if task is configurable)
		if(connections.laserTask.trigger == "PeriodicTimer") {
			// create PeriodicTimerTrigger
			int microseconds = 1000*1000 / connections.laserTask.periodicActFreq;
			if(microseconds > 0) {
				Smart::TimedTaskTrigger *triggerPtr = new Smart::TimedTaskTrigger();
				triggerPtr->attach(laserTask);
				component->getTimerManager()->scheduleTimer(triggerPtr, (void *) 0, std::chrono::microseconds(microseconds), std::chrono::microseconds(microseconds));
				// store trigger in class member
				laserTaskTrigger = triggerPtr;
			} else {
				std::cerr << "ERROR: could not set-up Timer with cycle-time " << microseconds << " as activation source for Task LaserTask" << std::endl;
			}
		} else if(connections.laserTask.trigger == "DataTriggered") {
			laserTaskTrigger = getInputTaskTriggerFromString(connections.laserTask.inPortRef);
			if(laserTaskTrigger != NULL) {
				laserTaskTrigger->attach(laserTask, connections.laserTask.prescale);
			} else {
				std::cerr << "ERROR: could not set-up InPort " << connections.laserTask.inPortRef << " as activation source for Task LaserTask" << std::endl;
			}
		} 
		
		// create Task WatchDogTask
		watchDogTask = new WatchDogTask(component);
		// configure input-links
		// configure task-trigger (if task is configurable)
		if(connections.watchDogTask.trigger == "PeriodicTimer") {
			// create PeriodicTimerTrigger
			int microseconds = 1000*1000 / connections.watchDogTask.periodicActFreq;
			if(microseconds > 0) {
				Smart::TimedTaskTrigger *triggerPtr = new Smart::TimedTaskTrigger();
				triggerPtr->attach(watchDogTask);
				component->getTimerManager()->scheduleTimer(triggerPtr, (void *) 0, std::chrono::microseconds(microseconds), std::chrono::microseconds(microseconds));
				// store trigger in class member
				watchDogTaskTrigger = triggerPtr;
			} else {
				std::cerr << "ERROR: could not set-up Timer with cycle-time " << microseconds << " as activation source for Task WatchDogTask" << std::endl;
			}
		} else if(connections.watchDogTask.trigger == "DataTriggered") {
			watchDogTaskTrigger = getInputTaskTriggerFromString(connections.watchDogTask.inPortRef);
			if(watchDogTaskTrigger != NULL) {
				watchDogTaskTrigger->attach(watchDogTask, connections.watchDogTask.prescale);
			} else {
				std::cerr << "ERROR: could not set-up InPort " << connections.watchDogTask.inPortRef << " as activation source for Task WatchDogTask" << std::endl;
			}
		} else
		{
			// setup default task-trigger as PeriodicTimer
			Smart::TimedTaskTrigger *triggerPtr = new Smart::TimedTaskTrigger();
			int microseconds = 1000*1000 / 1.0;
			if(microseconds > 0) {
				component->getTimerManager()->scheduleTimer(triggerPtr, (void *) 0, std::chrono::microseconds(microseconds), std::chrono::microseconds(microseconds));
				triggerPtr->attach(watchDogTask);
				// store trigger in class member
				watchDogTaskTrigger = triggerPtr;
			} else {
				std::cerr << "ERROR: could not set-up Timer with cycle-time " << microseconds << " as activation source for Task WatchDogTask" << std::endl;
			}
		}
		
		
		// link observers with subjects
	} catch (const std::exception &ex) {
		std::cerr << "Uncaught std exception" << ex.what() << std::endl;
	} catch (...) {
		std::cerr << "Uncaught exception" << std::endl;
	}
}

// run the component
void ComponentLaserHokuyoURGServer::run()
{
	stateSlave->acquire("init");
	// startup all registered port-factories
	for(auto portFactory = portFactoryRegistry.begin(); portFactory != portFactoryRegistry.end(); portFactory++) 
	{
		portFactory->second->onStartup();
	}
	
	// startup all registered component-extensions
	for(auto extension = componentExtensionRegistry.begin(); extension != componentExtensionRegistry.end(); extension++) 
	{
		extension->second->onStartup();
	}
	stateSlave->release("init");
	
	// do not call this handler within the init state (see above) as this handler internally calls setStartupFinished() (this should be fixed in future)
	compHandler.onStartup();
	
	// this call blocks until the component is commanded to shutdown
	stateSlave->acquire("shutdown");
	
	// shutdown all registered component-extensions
	for(auto extension = componentExtensionRegistry.begin(); extension != componentExtensionRegistry.end(); extension++) 
	{
		extension->second->onShutdown();
	}
	
	// shutdown all registered port-factories
	for(auto portFactory = portFactoryRegistry.begin(); portFactory != portFactoryRegistry.end(); portFactory++) 
	{
		portFactory->second->onShutdown();
	}
	
	if(connections.component.useLogger == true) {
		//FIXME: use logging
		//Smart::LOGGER->stopLogging();
	}
	
	compHandler.onShutdown();
	
	stateSlave->release("shutdown");
}

// clean-up component's resources
void ComponentLaserHokuyoURGServer::fini()
{
	// unlink all observers
	
	// destroy all task instances
	// unlink all UpcallManagers
	// unlink the TaskTrigger
	if(laserTaskTrigger != NULL){
		laserTaskTrigger->detach(laserTask);
		delete laserTask;
	}
	// unlink all UpcallManagers
	// unlink the TaskTrigger
	if(watchDogTaskTrigger != NULL){
		watchDogTaskTrigger->detach(watchDogTask);
		delete watchDogTask;
	}

	// destroy all input-handler

	// destroy InputTaskTriggers and UpcallManagers
	delete baseTimedClientInputTaskTrigger;
	delete baseTimedClientUpcallManager;
	delete manipulatorTimedClientInputTaskTrigger;
	delete manipulatorTimedClientUpcallManager;

	// destroy client ports
	delete baseTimedClient;
	delete manipulatorTimedClient;

	// destroy server ports
	delete laserPushNewestServer;
	delete laserQueryServer;
	delete laserQueryServerInputTaskTrigger;
	// destroy event-test handlers (if needed)
	
	// destroy request-handlers
	delete laserQueryServerHandler;
	
	delete stateSlave;
	// destroy state-change-handler
	delete stateChangeHandler;
	
	// destroy all master/slave ports
	delete wiringSlave;
	delete param;
	

	// destroy all registered component-extensions
	for(auto extension = componentExtensionRegistry.begin(); extension != componentExtensionRegistry.end(); extension++) 
	{
		extension->second->destroy();
	}

	// destroy all registered port-factories
	for(auto portFactory = portFactoryRegistry.begin(); portFactory != portFactoryRegistry.end(); portFactory++) 
	{
		portFactory->second->destroy();
	}
	
	// destruction of OpcUaBackendComponentGeneratorExtension
	
	// destruction of ComponentLaserHokuyoURGServerROSExtension
	
	// destruction of PlainOpcUaComponentLaserHokuyoURGServerExtension
	
}

void ComponentLaserHokuyoURGServer::loadParameter(int argc, char *argv[])
{
	/*
	 Parameters can be specified via command line --filename=<filename> or -f <filename>

	 With this parameter present:
	   - The component will look for the file in the current working directory,
	     a path relative to the current directory or any absolute path
	   - The component will use the default values if the file cannot be found

	 With this parameter absent:
	   - <Name of Component>.ini will be read from current working directory, if found there
	   - $SMART_ROOT/etc/<Name of Component>.ini will be read otherwise
	   - Default values will be used if neither found in working directory or /etc
	 */
	SmartACE::SmartIniParameter parameter;
	std::ifstream parameterfile;
	bool parameterFileFound = false;

	// load parameters
	try
	{
		// if paramfile is given as argument
		if(parameter.tryAddFileFromArgs(argc,argv,"filename", 'f'))
		{
			parameterFileFound = true;
			std::cout << "parameter file is loaded from an argv argument \n";
		} else if(parameter.searchFile("ComponentLaserHokuyoURGServer.ini", parameterfile)) {
			parameterFileFound = true;
			std::cout << "load ComponentLaserHokuyoURGServer.ini parameter file\n";
			parameter.addFile(parameterfile);
		} else {
			std::cout << "WARNING: ComponentLaserHokuyoURGServer.ini parameter file not found! (using default values or command line arguments)\n";
		}
		
		// add command line arguments to allow overwriting of parameters
		// from file
		parameter.addCommandLineArgs(argc,argv,"component");
		
		// initialize the naming service using the command line parameters parsed in the
		// SmartIniParameter class. The naming service parameters are expected to be in
		// the "component" parameter group.
		SmartACE::NAMING::instance()->checkForHelpArg(argc,argv);
		if(parameterFileFound) 
		{
			if(SmartACE::NAMING::instance()->init(parameter.getAllParametersFromGroup("component")) != 0) {
				// initialization of naming service failed
				throw std::logic_error( "<NamingService> Service initialization failed!\nPossible causes could be:\n-> Erroneous configuration.\n-> Naming service not reachable.\n" );
			}
		} else {
			if(SmartACE::NAMING::instance()->init(argc, argv) != 0) {
				// initialization of naming service failed
				throw std::logic_error( "<NamingService> Service initialization failed!\nPossible causes could be:\n-> Erroneous configuration.\n-> Naming service not reachable.\n" );
			}
		}
			
		// print all known parameters
		// parameter.print();
		
		//--- server port // client port // other parameter ---
		// load parameter
		parameter.getString("component", "name", connections.component.name);
		parameter.getString("component", "initialComponentMode", connections.component.initialComponentMode);
		if(parameter.checkIfParameterExists("component", "defaultScheduler")) {
			parameter.getString("component", "defaultScheduler", connections.component.defaultScheduler);
		}
		if(parameter.checkIfParameterExists("component", "useLogger")) {
			parameter.getBoolean("component", "useLogger", connections.component.useLogger);
		}
		
		// load parameters for client baseTimedClient
		parameter.getBoolean("baseTimedClient", "initialConnect", connections.baseTimedClient.initialConnect);
		parameter.getString("baseTimedClient", "serviceName", connections.baseTimedClient.serviceName);
		parameter.getString("baseTimedClient", "serverName", connections.baseTimedClient.serverName);
		parameter.getString("baseTimedClient", "wiringName", connections.baseTimedClient.wiringName);
		parameter.getInteger("baseTimedClient", "interval", connections.baseTimedClient.interval);
		if(parameter.checkIfParameterExists("baseTimedClient", "roboticMiddleware")) {
			parameter.getString("baseTimedClient", "roboticMiddleware", connections.baseTimedClient.roboticMiddleware);
		}
		// load parameters for client manipulatorTimedClient
		parameter.getBoolean("manipulatorTimedClient", "initialConnect", connections.manipulatorTimedClient.initialConnect);
		parameter.getString("manipulatorTimedClient", "serviceName", connections.manipulatorTimedClient.serviceName);
		parameter.getString("manipulatorTimedClient", "serverName", connections.manipulatorTimedClient.serverName);
		parameter.getString("manipulatorTimedClient", "wiringName", connections.manipulatorTimedClient.wiringName);
		parameter.getInteger("manipulatorTimedClient", "interval", connections.manipulatorTimedClient.interval);
		if(parameter.checkIfParameterExists("manipulatorTimedClient", "roboticMiddleware")) {
			parameter.getString("manipulatorTimedClient", "roboticMiddleware", connections.manipulatorTimedClient.roboticMiddleware);
		}
		
		// load parameters for server laserPushNewestServer
		parameter.getString("laserPushNewestServer", "serviceName", connections.laserPushNewestServer.serviceName);
		if(parameter.checkIfParameterExists("laserPushNewestServer", "roboticMiddleware")) {
			parameter.getString("laserPushNewestServer", "roboticMiddleware", connections.laserPushNewestServer.roboticMiddleware);
		}
		// load parameters for server laserQueryServer
		parameter.getString("laserQueryServer", "serviceName", connections.laserQueryServer.serviceName);
		if(parameter.checkIfParameterExists("laserQueryServer", "roboticMiddleware")) {
			parameter.getString("laserQueryServer", "roboticMiddleware", connections.laserQueryServer.roboticMiddleware);
		}
		
		// load parameters for task LaserTask
		parameter.getDouble("LaserTask", "minActFreqHz", connections.laserTask.minActFreq);
		parameter.getDouble("LaserTask", "maxActFreqHz", connections.laserTask.maxActFreq);
		parameter.getString("LaserTask", "triggerType", connections.laserTask.trigger);
		if(connections.laserTask.trigger == "PeriodicTimer") {
			parameter.getDouble("LaserTask", "periodicActFreqHz", connections.laserTask.periodicActFreq);
		} else if(connections.laserTask.trigger == "DataTriggered") {
			parameter.getString("LaserTask", "inPortRef", connections.laserTask.inPortRef);
			parameter.getInteger("LaserTask", "prescale", connections.laserTask.prescale);
		}
		if(parameter.checkIfParameterExists("LaserTask", "scheduler")) {
			parameter.getString("LaserTask", "scheduler", connections.laserTask.scheduler);
		}
		if(parameter.checkIfParameterExists("LaserTask", "priority")) {
			parameter.getInteger("LaserTask", "priority", connections.laserTask.priority);
		}
		if(parameter.checkIfParameterExists("LaserTask", "cpuAffinity")) {
			parameter.getInteger("LaserTask", "cpuAffinity", connections.laserTask.cpuAffinity);
		}
		// load parameters for task WatchDogTask
		parameter.getDouble("WatchDogTask", "minActFreqHz", connections.watchDogTask.minActFreq);
		parameter.getDouble("WatchDogTask", "maxActFreqHz", connections.watchDogTask.maxActFreq);
		parameter.getString("WatchDogTask", "triggerType", connections.watchDogTask.trigger);
		if(connections.watchDogTask.trigger == "PeriodicTimer") {
			parameter.getDouble("WatchDogTask", "periodicActFreqHz", connections.watchDogTask.periodicActFreq);
		} else if(connections.watchDogTask.trigger == "DataTriggered") {
			parameter.getString("WatchDogTask", "inPortRef", connections.watchDogTask.inPortRef);
			parameter.getInteger("WatchDogTask", "prescale", connections.watchDogTask.prescale);
		}
		if(parameter.checkIfParameterExists("WatchDogTask", "scheduler")) {
			parameter.getString("WatchDogTask", "scheduler", connections.watchDogTask.scheduler);
		}
		if(parameter.checkIfParameterExists("WatchDogTask", "priority")) {
			parameter.getInteger("WatchDogTask", "priority", connections.watchDogTask.priority);
		}
		if(parameter.checkIfParameterExists("WatchDogTask", "cpuAffinity")) {
			parameter.getInteger("WatchDogTask", "cpuAffinity", connections.watchDogTask.cpuAffinity);
		}
		
		// load parameters for OpcUaBackendComponentGeneratorExtension
		
		// load parameters for ComponentLaserHokuyoURGServerROSExtension
		
		// load parameters for PlainOpcUaComponentLaserHokuyoURGServerExtension
		
		
		// load parameters for all registered component-extensions
		for(auto extension = componentExtensionRegistry.begin(); extension != componentExtensionRegistry.end(); extension++) 
		{
			extension->second->loadParameters(parameter);
		}
		
		paramHandler.loadParameter(parameter);
	
	} catch (const SmartACE::IniParameterError & e) {
		std::cerr << e.what() << std::endl;
	} catch (const std::exception &ex) {
		std::cerr << "Uncaught std::exception: " << ex.what() << std::endl;
	} catch (...) {
		std::cerr << "Uncaught exception" << std::endl;
	}
}
