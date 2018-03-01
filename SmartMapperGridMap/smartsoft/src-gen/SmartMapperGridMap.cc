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
#include "SmartMapperGridMap.hh"
#include "smartTimedTaskTrigger.h"
//FIXME: implement logging
//#include "smartGlobalLogger.hh"


// constructor
SmartMapperGridMap::SmartMapperGridMap()
{
	std::cout << "constructor of SmartMapperGridMap\n";
	
	component = NULL;
	
	// set all pointer members to NULL
	curMapTask = NULL;
	curMapTaskTrigger = NULL;
	currMapOut = NULL;
	currQueryServer = NULL;
	currQueryServerInputTaskTrigger = NULL;
	currQueryServerHandler = NULL;
	laserServiceIn = NULL;
	laserServiceInInputTaskTrigger = NULL;
	laserServiceInUpcallManager = NULL;
	ltmMapTask = NULL;
	ltmMapTaskTrigger = NULL;
	ltmQueryServer = NULL;
	ltmQueryServerInputTaskTrigger = NULL;
	ltmQueryServerHandler = NULL;
	stateChangeHandler = NULL;
	stateSlave = NULL;
	wiringSlave = NULL;
	param = NULL;
	
	// set default ini parameter values
	connections.component.name = "SmartMapperGridMap";
	connections.component.initialMainState = "Neutral";
	connections.component.defaultScheduler = "DEFAULT";
	connections.component.useLogger = false;
	
	connections.currMapOut.serviceName = "CurrMapOut";
	connections.currQueryServer.serviceName = "CurrQueryServer";
	connections.ltmQueryServer.serviceName = "LtmQueryServer";
	connections.laserServiceIn.serverName = "unknown";
	connections.laserServiceIn.serviceName = "unknown";
	connections.laserServiceIn.interval = 1;
	connections.curMapTask.minActFreq = 10.0;
	connections.curMapTask.maxActFreq = 20.0;
	connections.curMapTask.prescale = 1;
	// scheduling default parameters
	connections.curMapTask.scheduler = "DEFAULT";
	connections.curMapTask.priority = -1;
	connections.curMapTask.cpuAffinity = -1;
	connections.ltmMapTask.minActFreq = 2.0;
	connections.ltmMapTask.maxActFreq = 10.0;
	connections.ltmMapTask.prescale = 1;
	connections.ltmMapTask.trigger = "PeriodicTimer";
	connections.ltmMapTask.periodicActFreq = 2.0;
	// scheduling default parameters
	connections.ltmMapTask.scheduler = "DEFAULT";
	connections.ltmMapTask.priority = -1;
	connections.ltmMapTask.cpuAffinity = -1;
}



/**
 * Notify the component that setup/initialization is finished.
 * You may call this function from anywhere in the component.
 *
 * Set component's internal lifecycle state automaton (if any) into 
 * Alive mode (from here on the component is ready to provide its services)
 */
void SmartMapperGridMap::setStartupFinished() {
	stateSlave->setWaitState("Alive");
	std::cout << "ComponentDefinition initialization/startup finished." << std::endl;
}


Smart::StatusCode SmartMapperGridMap::connectLaserServiceIn(const std::string &serverName, const std::string &serviceName) {
	Smart::StatusCode status;
	
	std::cout << "connecting to: " << serverName << "; " << serviceName << std::endl;
	status = laserServiceIn->connect(serverName, serviceName);
	while(status != Smart::SMART_OK)
	{
		ACE_OS::sleep(ACE_Time_Value(0,500000));
		status = COMP->laserServiceIn->connect(serverName, serviceName);
	}
	std::cout << "connected.\n";
	laserServiceIn->subscribe(connections.laserServiceIn.interval);
	return status;
}


/**
 * First connect ALL client ports contained in this component, then start all services:
 * activate state, push, etc...
 */
Smart::StatusCode SmartMapperGridMap::connectAndStartAllServices() {
	Smart::StatusCode status = Smart::SMART_OK;
	
	status = connectLaserServiceIn(connections.laserServiceIn.serverName, connections.laserServiceIn.serviceName);
	if(status != Smart::SMART_OK) return status;
	
	return status;
}

/**
 * Start all tasks contained in this component.
 */
void SmartMapperGridMap::startAllTasks() {
	// start task CurMapTask
	if(connections.curMapTask.scheduler != "DEFAULT") {
		ACE_Sched_Params curMapTask_SchedParams(ACE_SCHED_OTHER, ACE_THR_PRI_OTHER_DEF);
		if(connections.curMapTask.scheduler == "FIFO") {
			curMapTask_SchedParams.policy(ACE_SCHED_FIFO);
			curMapTask_SchedParams.priority(ACE_THR_PRI_FIFO_MIN);
		} else if(connections.curMapTask.scheduler == "RR") {
			curMapTask_SchedParams.policy(ACE_SCHED_RR);
			curMapTask_SchedParams.priority(ACE_THR_PRI_RR_MIN);
		}
		curMapTask->start(curMapTask_SchedParams, connections.curMapTask.cpuAffinity);
	} else {
		curMapTask->start();
	}
	// start task LtmMapTask
	if(connections.ltmMapTask.scheduler != "DEFAULT") {
		ACE_Sched_Params ltmMapTask_SchedParams(ACE_SCHED_OTHER, ACE_THR_PRI_OTHER_DEF);
		if(connections.ltmMapTask.scheduler == "FIFO") {
			ltmMapTask_SchedParams.policy(ACE_SCHED_FIFO);
			ltmMapTask_SchedParams.priority(ACE_THR_PRI_FIFO_MIN);
		} else if(connections.ltmMapTask.scheduler == "RR") {
			ltmMapTask_SchedParams.policy(ACE_SCHED_RR);
			ltmMapTask_SchedParams.priority(ACE_THR_PRI_RR_MIN);
		}
		ltmMapTask->start(ltmMapTask_SchedParams, connections.ltmMapTask.cpuAffinity);
	} else {
		ltmMapTask->start();
	}
}

/**
 * Start all timers contained in this component
 */
void SmartMapperGridMap::startAllTimers() {
}


Smart::TaskTriggerSubject* SmartMapperGridMap::getInputTaskTriggerFromString(const std::string &client)
{
	if(client == "LaserServiceIn") return laserServiceInInputTaskTrigger;
	
	return NULL;
}


void SmartMapperGridMap::init(int argc, char *argv[])
{
	try {
		Smart::StatusCode status;
		
		// load initial parameters from ini-file (if found)
		loadParameter(argc, argv);
		
		// print out the actual parameters which are used to initialize the component
		std::cout << " \nComponentDefinition Initial-Parameters:\n" << COMP->getGlobalState() << std::endl;
		if(connections.component.defaultScheduler != "DEFAULT") {
			ACE_Sched_Params sched_params(ACE_SCHED_OTHER, ACE_THR_PRI_OTHER_DEF);
			if(connections.component.defaultScheduler == "FIFO") {
				sched_params.policy(ACE_SCHED_FIFO);
				sched_params.priority(ACE_THR_PRI_FIFO_MIN);
			} else if(connections.component.defaultScheduler == "RR") {
				sched_params.policy(ACE_SCHED_RR);
				sched_params.priority(ACE_THR_PRI_RR_MIN);
			}
			// create new instance of the SmartSoft component with customized scheuling parameters 
			component = new SmartMapperGridMapImpl(connections.component.name, argc, argv, sched_params);
		} else {
			// create new instance of the SmartSoft component
			component = new SmartMapperGridMapImpl(connections.component.name, argc, argv);
		}
		
		
		std::cout << "ComponentDefinition SmartMapperGridMap is named " << connections.component.name << std::endl;
		
		if(connections.component.useLogger == true) {
			//FIXME: use logging
			//Smart::LOGGER->openLogFileInFolder("data/"+connections.component.name);
			//Smart::LOGGER->startLogging();
		}

		// create event-test handlers (if needed)
		
		// create server ports
		// TODO: set minCycleTime from Ini-file
		currMapOut = new SmartACE::PushServer<CommNavigationObjects::CommGridMap>(component, connections.currMapOut.serviceName);
		currQueryServer = new SmartACE::QueryServer<CommNavigationObjects::CommGridMapRequest, CommNavigationObjects::CommGridMap>(component, connections.currQueryServer.serviceName);
		currQueryServerInputTaskTrigger = new Smart::QueryServerTaskTrigger<CommNavigationObjects::CommGridMapRequest, CommNavigationObjects::CommGridMap,SmartACE::QueryId>(currQueryServer);
		ltmQueryServer = new SmartACE::QueryServer<CommNavigationObjects::CommGridMapRequest, CommNavigationObjects::CommGridMap>(component, connections.ltmQueryServer.serviceName);
		ltmQueryServerInputTaskTrigger = new Smart::QueryServerTaskTrigger<CommNavigationObjects::CommGridMapRequest, CommNavigationObjects::CommGridMap,SmartACE::QueryId>(ltmQueryServer);
		
		// create client ports
		laserServiceIn = new SmartACE::PushClient<CommBasicObjects::CommMobileLaserScan>(component);
		
		// create InputTaskTriggers and UpcallManagers
		laserServiceInInputTaskTrigger = new Smart::InputTaskTrigger<CommBasicObjects::CommMobileLaserScan>(laserServiceIn);
		laserServiceInUpcallManager = new LaserServiceInUpcallManager(laserServiceIn);
		
		// create input-handler
		
		// create request-handlers
		currQueryServerHandler = new CurrQueryServerHandler(currQueryServer);
		ltmQueryServerHandler = new LtmQueryServerHandler(ltmQueryServer);
		
		// create state pattern
		stateChangeHandler = new SmartStateChangeHandler();
		stateSlave = new SmartACE::StateSlave(component, stateChangeHandler);
		if (stateSlave->defineStates("BuildCurrMap" ,"currMap") != Smart::SMART_OK) std::cerr << "ERROR: defining state combinaion BuildCurrMap.currMap" << std::endl;
		if (stateSlave->defineStates("BuildLtmMap" ,"ltmMap") != Smart::SMART_OK) std::cerr << "ERROR: defining state combinaion BuildLtmMap.ltmMap" << std::endl;
		if (stateSlave->defineStates("BuildBothMaps" ,"currMap") != Smart::SMART_OK) std::cerr << "ERROR: defining state combinaion BuildBothMaps.currMap" << std::endl;
		if (stateSlave->defineStates("BuildBothMaps" ,"ltmMap") != Smart::SMART_OK) std::cerr << "ERROR: defining state combinaion BuildBothMaps.ltmMap" << std::endl;
		if (stateSlave->setUpInitialState(connections.component.initialMainState) != Smart::SMART_OK) std::cerr << "ERROR: setUpInitialState" << std::endl;
		// activate state slave
		status = stateSlave->activate();
		if(status != Smart::SMART_OK) std::cerr << "ERROR: activate state" << std::endl;
		
		wiringSlave = new SmartACE::WiringSlave(component);
		// add client port to wiring slave
		dynamic_cast<SmartACE::PushClient<CommBasicObjects::CommMobileLaserScan>*>(laserServiceIn)->add(wiringSlave, connections.laserServiceIn.wiringName);
		
		// create parameter slave
		param = new SmartACE::ParameterSlave(component, &paramHandler);
		
		
		// create Task CurMapTask
		curMapTask = new CurMapTask(component);
		// configure input-links
		laserServiceInUpcallManager->attach(curMapTask);
		// configure task-trigger (if task is configurable)
		if(connections.curMapTask.trigger == "PeriodicTimer") {
			// create PeriodicTimerTrigger
			int microseconds = 1000*1000 / connections.curMapTask.periodicActFreq;
			if(microseconds > 0) {
				Smart::TimedTaskTrigger *triggerPtr = new Smart::TimedTaskTrigger();
				triggerPtr->attach(curMapTask);
				component->getTimerManager()->scheduleTimer(triggerPtr, std::chrono::microseconds(microseconds), std::chrono::microseconds(microseconds));
				// store trigger in class member
				curMapTaskTrigger = triggerPtr;
			} else {
				std::cerr << "ERROR: could not set-up Timer with cycle-time " << microseconds << " as activation source for Task CurMapTask" << std::endl;
			}
		} else if(connections.curMapTask.trigger == "DataTriggered") {
			curMapTaskTrigger = getInputTaskTriggerFromString(connections.curMapTask.inPortRef);
			if(curMapTaskTrigger != NULL) {
				curMapTaskTrigger->attach(curMapTask, connections.curMapTask.prescale);
			} else {
				std::cerr << "ERROR: could not set-up InPort " << connections.curMapTask.inPortRef << " as activation source for Task CurMapTask" << std::endl;
			}
		} 
		
		// create Task LtmMapTask
		ltmMapTask = new LtmMapTask(component);
		// configure input-links
		laserServiceInUpcallManager->attach(ltmMapTask);
		// configure task-trigger (if task is configurable)
		if(connections.ltmMapTask.trigger == "PeriodicTimer") {
			// create PeriodicTimerTrigger
			int microseconds = 1000*1000 / connections.ltmMapTask.periodicActFreq;
			if(microseconds > 0) {
				Smart::TimedTaskTrigger *triggerPtr = new Smart::TimedTaskTrigger();
				triggerPtr->attach(ltmMapTask);
				component->getTimerManager()->scheduleTimer(triggerPtr, std::chrono::microseconds(microseconds), std::chrono::microseconds(microseconds));
				// store trigger in class member
				ltmMapTaskTrigger = triggerPtr;
			} else {
				std::cerr << "ERROR: could not set-up Timer with cycle-time " << microseconds << " as activation source for Task LtmMapTask" << std::endl;
			}
		} else if(connections.ltmMapTask.trigger == "DataTriggered") {
			ltmMapTaskTrigger = getInputTaskTriggerFromString(connections.ltmMapTask.inPortRef);
			if(ltmMapTaskTrigger != NULL) {
				ltmMapTaskTrigger->attach(ltmMapTask, connections.ltmMapTask.prescale);
			} else {
				std::cerr << "ERROR: could not set-up InPort " << connections.ltmMapTask.inPortRef << " as activation source for Task LtmMapTask" << std::endl;
			}
		} else
		{
			// setup default task-trigger as PeriodicTimer
			Smart::TimedTaskTrigger *triggerPtr = new Smart::TimedTaskTrigger();
			int microseconds = 1000*1000 / 2.0;
			if(microseconds > 0) {
				component->getTimerManager()->scheduleTimer(triggerPtr, std::chrono::microseconds(microseconds), std::chrono::microseconds(microseconds));
				triggerPtr->attach(ltmMapTask);
				// store trigger in class member
				ltmMapTaskTrigger = triggerPtr;
			} else {
				std::cerr << "ERROR: could not set-up Timer with cycle-time " << microseconds << " as activation source for Task LtmMapTask" << std::endl;
			}
		}
		
		
		// link observers with subjects
		curMapTask->attach(currQueryServerHandler);
		ltmMapTask->attach(ltmQueryServerHandler);
	} catch (const std::exception &ex) {
		std::cerr << "Uncaught std exception" << ex.what() << std::endl;
	} catch (...) {
		std::cerr << "Uncaught exception" << std::endl;
	}
}

// run the component
void SmartMapperGridMap::run()
{
	compHandler.onStartup();
	
	// coponent will now start running and will continue (block in the run method) until it is commanded to shutdown (i.e. by a SIGINT signal)
	component->run();
	// component was signalled to shutdown
	// 1) signall all tasks to shutdown as well (and give them 2 seconds time to cooperate)
	// if time exceeds, component is killed without further clean-up
	component->closeAllAssociatedTasks(2);
	
	if(connections.component.useLogger == true) {
		//FIXME: use logging
		//Smart::LOGGER->stopLogging();
	}
	
	compHandler.onShutdown();
	
	// unlink all observers
	
	// destroy all task instances
	// unlink all UpcallManagers
	laserServiceInUpcallManager->detach(curMapTask);
	// unlink the TaskTrigger
	curMapTaskTrigger->detach(curMapTask);
	delete curMapTask;
	// unlink all UpcallManagers
	laserServiceInUpcallManager->detach(ltmMapTask);
	// unlink the TaskTrigger
	ltmMapTaskTrigger->detach(ltmMapTask);
	delete ltmMapTask;

	// destroy all input-handler

	// destroy InputTaskTriggers and UpcallManagers
	delete laserServiceInInputTaskTrigger;
	delete laserServiceInUpcallManager;

	// destroy client ports
	delete laserServiceIn;

	// destroy server ports
	delete currMapOut;
	delete currQueryServer;
	delete currQueryServerInputTaskTrigger;
	delete ltmQueryServer;
	delete ltmQueryServerInputTaskTrigger;
	// destroy event-test handlers (if needed)
	
	// create request-handlers
	delete currQueryServerHandler;
	delete ltmQueryServerHandler;

	delete stateSlave;
	// delete state-change-handler
	delete stateChangeHandler;
	
	// delete all master/slave ports
	delete wiringSlave;
	delete param;
	

	// clean-up component's internally used resources (internally used communication middleware) 
	component->cleanUpComponentResources();
	
	// finally delete the component itself
	delete component;
}

void SmartMapperGridMap::loadParameter(int argc, char *argv[])
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
		} else if(parameter.searchFile("SmartMapperGridMap.ini", parameterfile)) {
			parameterFileFound = true;
			std::cout << "load SmartMapperGridMap.ini parameter file\n";
			parameter.addFile(parameterfile);
		} else {
			std::cout << "WARNING: SmartMapperGridMap.ini parameter file not found! (using default values or command line arguments)\n";
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
		parameter.getString("component", "initialMainState", connections.component.initialMainState);
		if(parameter.checkIfParameterExists("component", "defaultScheduler")) {
			parameter.getString("component", "defaultScheduler", connections.component.defaultScheduler);
		}
		if(parameter.checkIfParameterExists("component", "useLogger")) {
			parameter.getBoolean("component", "useLogger", connections.component.useLogger);
		}
		
		// load parameters for client LaserServiceIn
		parameter.getString("laserServiceIn", "serviceName", connections.laserServiceIn.serviceName);
		parameter.getString("laserServiceIn", "serverName", connections.laserServiceIn.serverName);
		parameter.getString("laserServiceIn", "wiringName", connections.laserServiceIn.wiringName);
		parameter.getInteger("laserServiceIn", "interval", connections.laserServiceIn.interval);
		
		// load parameters for server CurrMapOut
		parameter.getString("currMapOut", "serviceName", connections.currMapOut.serviceName);
		// load parameters for server CurrQueryServer
		parameter.getString("currQueryServer", "serviceName", connections.currQueryServer.serviceName);
		// load parameters for server LtmQueryServer
		parameter.getString("ltmQueryServer", "serviceName", connections.ltmQueryServer.serviceName);
		
		// load parameters for task CurMapTask
		parameter.getDouble("CurMapTask", "minActFreqHz", connections.curMapTask.minActFreq);
		parameter.getDouble("CurMapTask", "maxActFreqHz", connections.curMapTask.maxActFreq);
		parameter.getString("CurMapTask", "triggerType", connections.curMapTask.trigger);
		if(connections.curMapTask.trigger == "PeriodicTimer") {
			parameter.getDouble("CurMapTask", "periodicActFreqHz", connections.curMapTask.periodicActFreq);
		} else if(connections.curMapTask.trigger == "DataTriggered") {
			parameter.getString("CurMapTask", "inPortRef", connections.curMapTask.inPortRef);
			parameter.getInteger("CurMapTask", "prescale", connections.curMapTask.prescale);
		}
		if(parameter.checkIfParameterExists("CurMapTask", "scheduler")) {
			parameter.getString("CurMapTask", "scheduler", connections.curMapTask.scheduler);
		}
		if(parameter.checkIfParameterExists("CurMapTask", "priority")) {
			parameter.getInteger("CurMapTask", "priority", connections.curMapTask.priority);
		}
		if(parameter.checkIfParameterExists("CurMapTask", "cpuAffinity")) {
			parameter.getInteger("CurMapTask", "cpuAffinity", connections.curMapTask.cpuAffinity);
		}
		// load parameters for task LtmMapTask
		parameter.getDouble("LtmMapTask", "minActFreqHz", connections.ltmMapTask.minActFreq);
		parameter.getDouble("LtmMapTask", "maxActFreqHz", connections.ltmMapTask.maxActFreq);
		parameter.getString("LtmMapTask", "triggerType", connections.ltmMapTask.trigger);
		if(connections.ltmMapTask.trigger == "PeriodicTimer") {
			parameter.getDouble("LtmMapTask", "periodicActFreqHz", connections.ltmMapTask.periodicActFreq);
		} else if(connections.ltmMapTask.trigger == "DataTriggered") {
			parameter.getString("LtmMapTask", "inPortRef", connections.ltmMapTask.inPortRef);
			parameter.getInteger("LtmMapTask", "prescale", connections.ltmMapTask.prescale);
		}
		if(parameter.checkIfParameterExists("LtmMapTask", "scheduler")) {
			parameter.getString("LtmMapTask", "scheduler", connections.ltmMapTask.scheduler);
		}
		if(parameter.checkIfParameterExists("LtmMapTask", "priority")) {
			parameter.getInteger("LtmMapTask", "priority", connections.ltmMapTask.priority);
		}
		if(parameter.checkIfParameterExists("LtmMapTask", "cpuAffinity")) {
			parameter.getInteger("LtmMapTask", "cpuAffinity", connections.ltmMapTask.cpuAffinity);
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
