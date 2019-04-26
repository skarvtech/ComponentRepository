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
#include "ParameterUpdateHandler.hh"

#include "ComponentLaserHokuyoURGServer.hh"

SmartACE::CommParameterResponse ParamUpdateHandler::handleParameter(const SmartACE::CommParameterRequest& request)
{
	SmartACE::CommParameterResponse answer;

	std::string tag = request.getTag();
	std::cout<<"PARAMETER: "<<tag<<std::endl;
	
	if (tag == "COMMIT")
	{
		answer.setResponse(globalState.handleCOMMIT(commitState));
		if(answer.getResponse() == SmartACE::ParamResponseType::OK) {
			globalStateLock.acquire();
			// change the content of the globalState, however change only the generated content
			// without affecting potential user member variables (which is more intuitive for the user)
			globalState.setContent(commitState);
			globalStateLock.release();
		} else {
			// the commit validation check returned != OK
			// the commit state is rejected and is not copied into the global state
		}
	}
	else
	{
		/////////////////////////////////////////////////////////////////////
		// default new
		std::cout<<"ERROR wrong Parameter!"<<std::endl;
		answer.setResponse(SmartACE::ParamResponseType::INVALID);
	}
	

	std::cout<<"[handleQuery] PARAMETER "<<tag<<" DONE\n\n";

	return answer;
}


ParameterStateStruct ParamUpdateHandler::getGlobalState() const{
	SmartACE::SmartGuard g(globalStateLock);
	return this->globalState;
}


void ParamUpdateHandler::loadParameter(SmartACE::SmartIniParameter &parameter)
{
	/*
	 Parameters can be specified via command line -filename=<filename>

	 With this parameter present:
	 - The component will look for the file in the current working directory,
	 a path relative to the current directory or any absolute path
	 - The component will use the default values if the file cannot be found

	 With this parameter absent:
	 - <Name of Component>.ini will be read from current working directory, if found there
	 - $SMART_ROOT/etc/<Name of Component>.ini will be read otherwise
	 - Default values will be used if neither found in working directory or /etc
	 */

	// load parameters
	try
	{
		// print all known parameters
		parameter.print();

		//
		// load internal parameters (if any)
		//
		// parameter Base_manipulator
		if(parameter.getDouble("Base_manipulator", "base_azimuth", commitState.Base_manipulator.base_azimuth))
		{
			globalState.Base_manipulator.base_azimuth = commitState.Base_manipulator.base_azimuth;
		}
		if(parameter.getDouble("Base_manipulator", "base_elevation", commitState.Base_manipulator.base_elevation))
		{
			globalState.Base_manipulator.base_elevation = commitState.Base_manipulator.base_elevation;
		}
		if(parameter.getDouble("Base_manipulator", "base_roll", commitState.Base_manipulator.base_roll))
		{
			globalState.Base_manipulator.base_roll = commitState.Base_manipulator.base_roll;
		}
		if(parameter.getBoolean("Base_manipulator", "on_base", commitState.Base_manipulator.on_base))
		{
			globalState.Base_manipulator.on_base = commitState.Base_manipulator.on_base;
		}
		if(parameter.getBoolean("Base_manipulator", "on_manipulator", commitState.Base_manipulator.on_manipulator))
		{
			globalState.Base_manipulator.on_manipulator = commitState.Base_manipulator.on_manipulator;
		}
		if(parameter.getDouble("Base_manipulator", "x", commitState.Base_manipulator.x))
		{
			globalState.Base_manipulator.x = commitState.Base_manipulator.x;
		}
		if(parameter.getDouble("Base_manipulator", "y", commitState.Base_manipulator.y))
		{
			globalState.Base_manipulator.y = commitState.Base_manipulator.y;
		}
		if(parameter.getDouble("Base_manipulator", "z", commitState.Base_manipulator.z))
		{
			globalState.Base_manipulator.z = commitState.Base_manipulator.z;
		}
		// parameter Scanner
		if(parameter.getDouble("Scanner", "azimuth", commitState.Scanner.azimuth))
		{
			globalState.Scanner.azimuth = commitState.Scanner.azimuth;
		}
		if(parameter.getString("Scanner", "device", commitState.Scanner.device))
		{
			globalState.Scanner.device = commitState.Scanner.device;
		}
		if(parameter.getDouble("Scanner", "elevation", commitState.Scanner.elevation))
		{
			globalState.Scanner.elevation = commitState.Scanner.elevation;
		}
		if(parameter.getInteger("Scanner", "max_range", commitState.Scanner.max_range))
		{
			globalState.Scanner.max_range = commitState.Scanner.max_range;
		}
		if(parameter.getInteger("Scanner", "min_range", commitState.Scanner.min_range))
		{
			globalState.Scanner.min_range = commitState.Scanner.min_range;
		}
		if(parameter.getInteger("Scanner", "opening_angle", commitState.Scanner.opening_angle))
		{
			globalState.Scanner.opening_angle = commitState.Scanner.opening_angle;
		}
		if(parameter.getDouble("Scanner", "roll", commitState.Scanner.roll))
		{
			globalState.Scanner.roll = commitState.Scanner.roll;
		}
		if(parameter.getBoolean("Scanner", "verbose", commitState.Scanner.verbose))
		{
			globalState.Scanner.verbose = commitState.Scanner.verbose;
		}
		if(parameter.getDouble("Scanner", "x", commitState.Scanner.x))
		{
			globalState.Scanner.x = commitState.Scanner.x;
		}
		if(parameter.getDouble("Scanner", "y", commitState.Scanner.y))
		{
			globalState.Scanner.y = commitState.Scanner.y;
		}
		if(parameter.getDouble("Scanner", "z", commitState.Scanner.z))
		{
			globalState.Scanner.z = commitState.Scanner.z;
		}
		// parameter Services
		if(parameter.getBoolean("Services", "activate_push_newest", commitState.Services.activate_push_newest))
		{
			globalState.Services.activate_push_newest = commitState.Services.activate_push_newest;
		}
		if(parameter.getBoolean("Services", "activate_push_timed", commitState.Services.activate_push_timed))
		{
			globalState.Services.activate_push_timed = commitState.Services.activate_push_timed;
		}
		
		//
		// load extended parameters (if any)
		//
		
		//
		// load instance parameters (if a parameter definition was instantiated in the model)
		//

	} catch (const SmartACE::IniParameterError & e)
	{
		std::cerr << "Exception from parameter handling: " << e << std::endl;
	} catch (const std::exception &ex)
	{
		std::cerr << "Uncaught std:: exception" << ex.what() << std::endl;
	} catch (...)
	{
		std::cerr << "Uncaught exception" << std::endl;
	}
}