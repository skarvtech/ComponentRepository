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

#include "SmartCdlServer.hh"

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
	else if (tag == "COMMNAVIGATIONOBJECTS.CDLPARAMETER.APPROACHDIST")
	{
		answer.setResponse(SmartACE::ParamResponseType::OK); // TODO: this should be decided according to validation checks defined in the model (not yet implemented)
		
		double temp_approachDistance = 0.0;
		if(request.getDouble("1", temp_approachDistance) == 0) {
			commitState.CommNavigationObjects.CdlParameter.APPROACHDIST.approachDistance = temp_approachDistance;
		} else {
			answer.setResponse(SmartACE::ParamResponseType::INVALID);
		}
		
	}
	else if (tag == "COMMNAVIGATIONOBJECTS.CDLPARAMETER.FREEBEHAVIOR")
	{
		answer.setResponse(SmartACE::ParamResponseType::OK); // TODO: this should be decided according to validation checks defined in the model (not yet implemented)
		
		std::string temp_free = "";
		if(request.getString("1", temp_free) == 0) {
			commitState.CommNavigationObjects.CdlParameter.FREEBEHAVIOR.free = temp_free;
		} else {
			answer.setResponse(SmartACE::ParamResponseType::INVALID);
		}
		
	}
	else if (tag == "COMMNAVIGATIONOBJECTS.CDLPARAMETER.GOALMODE")
	{
		answer.setResponse(SmartACE::ParamResponseType::OK); // TODO: this should be decided according to validation checks defined in the model (not yet implemented)
		
		std::string temp_gm = "";
		if(request.getString("1", temp_gm) == 0) {
			commitState.CommNavigationObjects.CdlParameter.GOALMODE.gm = temp_gm;
		} else {
			answer.setResponse(SmartACE::ParamResponseType::INVALID);
		}
		
	}
	else if (tag == "COMMNAVIGATIONOBJECTS.CDLPARAMETER.GOALREGION")
	{
		answer.setResponse(SmartACE::ParamResponseType::OK); // TODO: this should be decided according to validation checks defined in the model (not yet implemented)
		
		double temp_goalX = 0.0;
		if(request.getDouble("1", temp_goalX) == 0) {
			commitState.CommNavigationObjects.CdlParameter.GOALREGION.goalX = temp_goalX;
		} else {
			answer.setResponse(SmartACE::ParamResponseType::INVALID);
		}
		double temp_goalY = 0.0;
		if(request.getDouble("2", temp_goalY) == 0) {
			commitState.CommNavigationObjects.CdlParameter.GOALREGION.goalY = temp_goalY;
		} else {
			answer.setResponse(SmartACE::ParamResponseType::INVALID);
		}
		double temp_goalA = 0.0;
		if(request.getDouble("3", temp_goalA) == 0) {
			commitState.CommNavigationObjects.CdlParameter.GOALREGION.goalA = temp_goalA;
		} else {
			answer.setResponse(SmartACE::ParamResponseType::INVALID);
		}
		
	}
	else if (tag == "COMMNAVIGATIONOBJECTS.CDLPARAMETER.ID")
	{
		answer.setResponse(SmartACE::ParamResponseType::OK); // TODO: this should be decided according to validation checks defined in the model (not yet implemented)
		
		int temp_id = 0;
		if(request.getInteger("1", temp_id) == 0) {
			commitState.CommNavigationObjects.CdlParameter.ID.id = temp_id;
		} else {
			answer.setResponse(SmartACE::ParamResponseType::INVALID);
		}
		
	}
	else if (tag == "COMMNAVIGATIONOBJECTS.CDLPARAMETER.LOOKUPTABLE")
	{
		answer.setResponse(SmartACE::ParamResponseType::OK); // TODO: this should be decided according to validation checks defined in the model (not yet implemented)
		
		std::string temp_lt = "";
		if(request.getString("1", temp_lt) == 0) {
			commitState.CommNavigationObjects.CdlParameter.LOOKUPTABLE.lt = temp_lt;
		} else {
			answer.setResponse(SmartACE::ParamResponseType::INVALID);
		}
		
	}
	else if (tag == "COMMNAVIGATIONOBJECTS.CDLPARAMETER.PATHNAVFREEBEHAVIOR")
	{
		answer.setResponse(SmartACE::ParamResponseType::OK); // TODO: this should be decided according to validation checks defined in the model (not yet implemented)
		
		std::string temp_free = "";
		if(request.getString("1", temp_free) == 0) {
			commitState.CommNavigationObjects.CdlParameter.PATHNAVFREEBEHAVIOR.free = temp_free;
		} else {
			answer.setResponse(SmartACE::ParamResponseType::INVALID);
		}
		
	}
	else if (tag == "COMMNAVIGATIONOBJECTS.CDLPARAMETER.ROTVEL")
	{
		answer.setResponse(SmartACE::ParamResponseType::OK); // TODO: this should be decided according to validation checks defined in the model (not yet implemented)
		
		double temp_wmin = 0.0;
		if(request.getDouble("1", temp_wmin) == 0) {
			commitState.CommNavigationObjects.CdlParameter.ROTVEL.wmin = temp_wmin;
		} else {
			answer.setResponse(SmartACE::ParamResponseType::INVALID);
		}
		double temp_wmax = 0.0;
		if(request.getDouble("2", temp_wmax) == 0) {
			commitState.CommNavigationObjects.CdlParameter.ROTVEL.wmax = temp_wmax;
		} else {
			answer.setResponse(SmartACE::ParamResponseType::INVALID);
		}
		
	}
	else if (tag == "COMMNAVIGATIONOBJECTS.CDLPARAMETER.SAFETYCL")
	{
		answer.setResponse(SmartACE::ParamResponseType::OK); // TODO: this should be decided according to validation checks defined in the model (not yet implemented)
		
		int temp_safetyClearance = 0;
		if(request.getInteger("1", temp_safetyClearance) == 0) {
			commitState.CommNavigationObjects.CdlParameter.SAFETYCL.safetyClearance = temp_safetyClearance;
		} else {
			answer.setResponse(SmartACE::ParamResponseType::INVALID);
		}
		
	}
	else if (tag == "COMMNAVIGATIONOBJECTS.CDLPARAMETER.SAVECURPOS")
	{
		answer.setResponse(SmartACE::ParamResponseType::OK);
		
		int temp_goalId = 0;
		if(request.getInteger("1", temp_goalId) != 0) {
			answer.setResponse(SmartACE::ParamResponseType::INVALID);
		}
		
		if(answer.getResponse() == SmartACE::ParamResponseType::OK) {
			triggerHandler.handleCommNavigationObjects_CdlParameter_SAVECURPOSCore(
			temp_goalId
			);
		}
	}
	else if (tag == "COMMNAVIGATIONOBJECTS.CDLPARAMETER.SETGOALREGION")
	{
		answer.setResponse(SmartACE::ParamResponseType::OK);
		
		int temp_goalId = 0;
		if(request.getInteger("1", temp_goalId) != 0) {
			answer.setResponse(SmartACE::ParamResponseType::INVALID);
		}
		
		if(answer.getResponse() == SmartACE::ParamResponseType::OK) {
			triggerHandler.handleCommNavigationObjects_CdlParameter_SETGOALREGIONCore(
			temp_goalId
			);
		}
	}
	else if (tag == "COMMNAVIGATIONOBJECTS.CDLPARAMETER.SETSTRATEGY")
	{
		answer.setResponse(SmartACE::ParamResponseType::OK);
		
		std::string temp_strat = "";
		if(request.getString("1", temp_strat) != 0) {
			answer.setResponse(SmartACE::ParamResponseType::INVALID);
		}
		
		if(answer.getResponse() == SmartACE::ParamResponseType::OK) {
			triggerHandler.handleCommNavigationObjects_CdlParameter_SETSTRATEGYCore(
			temp_strat
			);
		}
	}
	else if (tag == "COMMNAVIGATIONOBJECTS.CDLPARAMETER.TRANSVEL")
	{
		answer.setResponse(SmartACE::ParamResponseType::OK); // TODO: this should be decided according to validation checks defined in the model (not yet implemented)
		
		double temp_vmin = 0.0;
		if(request.getDouble("1", temp_vmin) == 0) {
			commitState.CommNavigationObjects.CdlParameter.TRANSVEL.vmin = temp_vmin;
		} else {
			answer.setResponse(SmartACE::ParamResponseType::INVALID);
		}
		double temp_vmax = 0.0;
		if(request.getDouble("2", temp_vmax) == 0) {
			commitState.CommNavigationObjects.CdlParameter.TRANSVEL.vmax = temp_vmax;
		} else {
			answer.setResponse(SmartACE::ParamResponseType::INVALID);
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
		// parameter Cdl
		if(parameter.getString("Cdl", "accel_default_file", commitState.Cdl.accel_default_file))
		{
			globalState.Cdl.accel_default_file = commitState.Cdl.accel_default_file;
		}
		if(parameter.getString("Cdl", "accel_second_file", commitState.Cdl.accel_second_file))
		{
			globalState.Cdl.accel_second_file = commitState.Cdl.accel_second_file;
		}
		if(parameter.getString("Cdl", "contour_default_file", commitState.Cdl.contour_default_file))
		{
			globalState.Cdl.contour_default_file = commitState.Cdl.contour_default_file;
		}
		if(parameter.getString("Cdl", "contour_second_file", commitState.Cdl.contour_second_file))
		{
			globalState.Cdl.contour_second_file = commitState.Cdl.contour_second_file;
		}
		if(parameter.getString("Cdl", "curvature_default_file", commitState.Cdl.curvature_default_file))
		{
			globalState.Cdl.curvature_default_file = commitState.Cdl.curvature_default_file;
		}
		if(parameter.getString("Cdl", "curvature_second_file", commitState.Cdl.curvature_second_file))
		{
			globalState.Cdl.curvature_second_file = commitState.Cdl.curvature_second_file;
		}
		if(parameter.getString("Cdl", "dataDir", commitState.Cdl.dataDir))
		{
			globalState.Cdl.dataDir = commitState.Cdl.dataDir;
		}
		if(parameter.getDouble("Cdl", "delta_t_calc", commitState.Cdl.delta_t_calc))
		{
			globalState.Cdl.delta_t_calc = commitState.Cdl.delta_t_calc;
		}
		if(parameter.getDouble("Cdl", "delta_t_trigger", commitState.Cdl.delta_t_trigger))
		{
			globalState.Cdl.delta_t_trigger = commitState.Cdl.delta_t_trigger;
		}
		if(parameter.getBoolean("Cdl", "followHysteresis", commitState.Cdl.followHysteresis))
		{
			globalState.Cdl.followHysteresis = commitState.Cdl.followHysteresis;
		}
		if(parameter.getDouble("Cdl", "freeBehaviorDist", commitState.Cdl.freeBehaviorDist))
		{
			globalState.Cdl.freeBehaviorDist = commitState.Cdl.freeBehaviorDist;
		}
		if(parameter.getDouble("Cdl", "freeBehaviorDist_second", commitState.Cdl.freeBehaviorDist_second))
		{
			globalState.Cdl.freeBehaviorDist_second = commitState.Cdl.freeBehaviorDist_second;
		}
		if(parameter.getString("Cdl", "lookup_default_file", commitState.Cdl.lookup_default_file))
		{
			globalState.Cdl.lookup_default_file = commitState.Cdl.lookup_default_file;
		}
		if(parameter.getBoolean("Cdl", "lookup_default_file_compressed", commitState.Cdl.lookup_default_file_compressed))
		{
			globalState.Cdl.lookup_default_file_compressed = commitState.Cdl.lookup_default_file_compressed;
		}
		if(parameter.getString("Cdl", "lookup_second_file", commitState.Cdl.lookup_second_file))
		{
			globalState.Cdl.lookup_second_file = commitState.Cdl.lookup_second_file;
		}
		if(parameter.getBoolean("Cdl", "lookup_second_file_compressed", commitState.Cdl.lookup_second_file_compressed))
		{
			globalState.Cdl.lookup_second_file_compressed = commitState.Cdl.lookup_second_file_compressed;
		}
		if(parameter.getDouble("Cdl", "rotation_acc", commitState.Cdl.rotation_acc))
		{
			globalState.Cdl.rotation_acc = commitState.Cdl.rotation_acc;
		}
		if(parameter.getDouble("Cdl", "translation_acc", commitState.Cdl.translation_acc))
		{
			globalState.Cdl.translation_acc = commitState.Cdl.translation_acc;
		}
		if(parameter.getBoolean("Cdl", "use_obstacle_history", commitState.Cdl.use_obstacle_history))
		{
			globalState.Cdl.use_obstacle_history = commitState.Cdl.use_obstacle_history;
		}
		// parameter CdlRotate
		if(parameter.getDouble("CdlRotate", "error", commitState.CdlRotate.error))
		{
			globalState.CdlRotate.error = commitState.CdlRotate.error;
		}
		if(parameter.getDouble("CdlRotate", "rotDev1", commitState.CdlRotate.rotDev1))
		{
			globalState.CdlRotate.rotDev1 = commitState.CdlRotate.rotDev1;
		}
		if(parameter.getDouble("CdlRotate", "rotDev2", commitState.CdlRotate.rotDev2))
		{
			globalState.CdlRotate.rotDev2 = commitState.CdlRotate.rotDev2;
		}
		if(parameter.getDouble("CdlRotate", "rotDev3", commitState.CdlRotate.rotDev3))
		{
			globalState.CdlRotate.rotDev3 = commitState.CdlRotate.rotDev3;
		}
		if(parameter.getDouble("CdlRotate", "rotDev4", commitState.CdlRotate.rotDev4))
		{
			globalState.CdlRotate.rotDev4 = commitState.CdlRotate.rotDev4;
		}
		if(parameter.getDouble("CdlRotate", "rotSpeed1", commitState.CdlRotate.rotSpeed1))
		{
			globalState.CdlRotate.rotSpeed1 = commitState.CdlRotate.rotSpeed1;
		}
		if(parameter.getDouble("CdlRotate", "rotSpeed2", commitState.CdlRotate.rotSpeed2))
		{
			globalState.CdlRotate.rotSpeed2 = commitState.CdlRotate.rotSpeed2;
		}
		if(parameter.getDouble("CdlRotate", "rotSpeed3", commitState.CdlRotate.rotSpeed3))
		{
			globalState.CdlRotate.rotSpeed3 = commitState.CdlRotate.rotSpeed3;
		}
		if(parameter.getDouble("CdlRotate", "rotSpeed4", commitState.CdlRotate.rotSpeed4))
		{
			globalState.CdlRotate.rotSpeed4 = commitState.CdlRotate.rotSpeed4;
		}
		// parameter PathNav
		if(parameter.getDouble("PathNav", "pathNavPredictedGoalPose_controll1_dist", commitState.PathNav.pathNavPredictedGoalPose_controll1_dist))
		{
			globalState.PathNav.pathNavPredictedGoalPose_controll1_dist = commitState.PathNav.pathNavPredictedGoalPose_controll1_dist;
		}
		if(parameter.getDouble("PathNav", "pathNavPredictedGoalPose_controll1_speed", commitState.PathNav.pathNavPredictedGoalPose_controll1_speed))
		{
			globalState.PathNav.pathNavPredictedGoalPose_controll1_speed = commitState.PathNav.pathNavPredictedGoalPose_controll1_speed;
		}
		if(parameter.getDouble("PathNav", "pathNavPredictedGoalPose_controll2_dist", commitState.PathNav.pathNavPredictedGoalPose_controll2_dist))
		{
			globalState.PathNav.pathNavPredictedGoalPose_controll2_dist = commitState.PathNav.pathNavPredictedGoalPose_controll2_dist;
		}
		if(parameter.getDouble("PathNav", "pathNavPredictedGoalPose_controll2_speed", commitState.PathNav.pathNavPredictedGoalPose_controll2_speed))
		{
			globalState.PathNav.pathNavPredictedGoalPose_controll2_speed = commitState.PathNav.pathNavPredictedGoalPose_controll2_speed;
		}
		if(parameter.getDouble("PathNav", "pathNavPredictedGoalPose_controll3_dist", commitState.PathNav.pathNavPredictedGoalPose_controll3_dist))
		{
			globalState.PathNav.pathNavPredictedGoalPose_controll3_dist = commitState.PathNav.pathNavPredictedGoalPose_controll3_dist;
		}
		if(parameter.getDouble("PathNav", "pathNavPredictedGoalPose_controll3_speed", commitState.PathNav.pathNavPredictedGoalPose_controll3_speed))
		{
			globalState.PathNav.pathNavPredictedGoalPose_controll3_speed = commitState.PathNav.pathNavPredictedGoalPose_controll3_speed;
		}
		if(parameter.getDouble("PathNav", "pathNavPredictedGoalPose_minDist", commitState.PathNav.pathNavPredictedGoalPose_minDist))
		{
			globalState.PathNav.pathNavPredictedGoalPose_minDist = commitState.PathNav.pathNavPredictedGoalPose_minDist;
		}
		if(parameter.getDouble("PathNav", "pathNavRecover_max_dist", commitState.PathNav.pathNavRecover_max_dist))
		{
			globalState.PathNav.pathNavRecover_max_dist = commitState.PathNav.pathNavRecover_max_dist;
		}
		if(parameter.getInteger("PathNav", "robotBlocked_event_timeout", commitState.PathNav.robotBlocked_event_timeout))
		{
			globalState.PathNav.robotBlocked_event_timeout = commitState.PathNav.robotBlocked_event_timeout;
		}
		// parameter Server
		if(parameter.getBoolean("Server", "baseClientInit", commitState.Server.baseClientInit))
		{
			globalState.Server.baseClientInit = commitState.Server.baseClientInit;
		}
		if(parameter.getBoolean("Server", "irClientInit", commitState.Server.irClientInit))
		{
			globalState.Server.irClientInit = commitState.Server.irClientInit;
		}
		if(parameter.getBoolean("Server", "laserClient2Init", commitState.Server.laserClient2Init))
		{
			globalState.Server.laserClient2Init = commitState.Server.laserClient2Init;
		}
		if(parameter.getBoolean("Server", "pathNavInit", commitState.Server.pathNavInit))
		{
			globalState.Server.pathNavInit = commitState.Server.pathNavInit;
		}
		if(parameter.getBoolean("Server", "plannerInit", commitState.Server.plannerInit))
		{
			globalState.Server.plannerInit = commitState.Server.plannerInit;
		}
		if(parameter.getBoolean("Server", "trackerInit", commitState.Server.trackerInit))
		{
			globalState.Server.trackerInit = commitState.Server.trackerInit;
		}
		
		//
		// load extended parameters (if any)
		//
		
		//
		// load instance parameters (if a parameter definition was instantiated in the model)
		//
		// parameter CommNavigationObjects.CdlParameter.APPROACHDIST
		if(parameter.getDouble("CommNavigationObjects.CdlParameter.APPROACHDIST", "approachDistance", commitState.CommNavigationObjects.CdlParameter.APPROACHDIST.approachDistance))
		{
			globalState.CommNavigationObjects.CdlParameter.APPROACHDIST.approachDistance = commitState.CommNavigationObjects.CdlParameter.APPROACHDIST.approachDistance;
		}
		// parameter CommNavigationObjects.CdlParameter.FREEBEHAVIOR
		std::string temp_CommNavigationObjects_CdlParameter_FREEBEHAVIOR_free = "";
		if(parameter.getString("CommNavigationObjects.CdlParameter.FREEBEHAVIOR", "free", temp_CommNavigationObjects_CdlParameter_FREEBEHAVIOR_free))
		{
			commitState.CommNavigationObjects.CdlParameter.FREEBEHAVIOR.free = temp_CommNavigationObjects_CdlParameter_FREEBEHAVIOR_free;
			globalState.CommNavigationObjects.CdlParameter.FREEBEHAVIOR.free = commitState.CommNavigationObjects.CdlParameter.FREEBEHAVIOR.free;
		}
		// parameter CommNavigationObjects.CdlParameter.GOALMODE
		std::string temp_CommNavigationObjects_CdlParameter_GOALMODE_gm = "";
		if(parameter.getString("CommNavigationObjects.CdlParameter.GOALMODE", "gm", temp_CommNavigationObjects_CdlParameter_GOALMODE_gm))
		{
			commitState.CommNavigationObjects.CdlParameter.GOALMODE.gm = temp_CommNavigationObjects_CdlParameter_GOALMODE_gm;
			globalState.CommNavigationObjects.CdlParameter.GOALMODE.gm = commitState.CommNavigationObjects.CdlParameter.GOALMODE.gm;
		}
		// parameter CommNavigationObjects.CdlParameter.GOALREGION
		if(parameter.getDouble("CommNavigationObjects.CdlParameter.GOALREGION", "goalA", commitState.CommNavigationObjects.CdlParameter.GOALREGION.goalA))
		{
			globalState.CommNavigationObjects.CdlParameter.GOALREGION.goalA = commitState.CommNavigationObjects.CdlParameter.GOALREGION.goalA;
		}
		if(parameter.getDouble("CommNavigationObjects.CdlParameter.GOALREGION", "goalX", commitState.CommNavigationObjects.CdlParameter.GOALREGION.goalX))
		{
			globalState.CommNavigationObjects.CdlParameter.GOALREGION.goalX = commitState.CommNavigationObjects.CdlParameter.GOALREGION.goalX;
		}
		if(parameter.getDouble("CommNavigationObjects.CdlParameter.GOALREGION", "goalY", commitState.CommNavigationObjects.CdlParameter.GOALREGION.goalY))
		{
			globalState.CommNavigationObjects.CdlParameter.GOALREGION.goalY = commitState.CommNavigationObjects.CdlParameter.GOALREGION.goalY;
		}
		// parameter CommNavigationObjects.CdlParameter.ID
		if(parameter.getInteger("CommNavigationObjects.CdlParameter.ID", "id", commitState.CommNavigationObjects.CdlParameter.ID.id))
		{
			globalState.CommNavigationObjects.CdlParameter.ID.id = commitState.CommNavigationObjects.CdlParameter.ID.id;
		}
		// parameter CommNavigationObjects.CdlParameter.LOOKUPTABLE
		std::string temp_CommNavigationObjects_CdlParameter_LOOKUPTABLE_lt = "";
		if(parameter.getString("CommNavigationObjects.CdlParameter.LOOKUPTABLE", "lt", temp_CommNavigationObjects_CdlParameter_LOOKUPTABLE_lt))
		{
			commitState.CommNavigationObjects.CdlParameter.LOOKUPTABLE.lt = temp_CommNavigationObjects_CdlParameter_LOOKUPTABLE_lt;
			globalState.CommNavigationObjects.CdlParameter.LOOKUPTABLE.lt = commitState.CommNavigationObjects.CdlParameter.LOOKUPTABLE.lt;
		}
		// parameter CommNavigationObjects.CdlParameter.PATHNAVFREEBEHAVIOR
		std::string temp_CommNavigationObjects_CdlParameter_PATHNAVFREEBEHAVIOR_free = "";
		if(parameter.getString("CommNavigationObjects.CdlParameter.PATHNAVFREEBEHAVIOR", "free", temp_CommNavigationObjects_CdlParameter_PATHNAVFREEBEHAVIOR_free))
		{
			commitState.CommNavigationObjects.CdlParameter.PATHNAVFREEBEHAVIOR.free = temp_CommNavigationObjects_CdlParameter_PATHNAVFREEBEHAVIOR_free;
			globalState.CommNavigationObjects.CdlParameter.PATHNAVFREEBEHAVIOR.free = commitState.CommNavigationObjects.CdlParameter.PATHNAVFREEBEHAVIOR.free;
		}
		// parameter CommNavigationObjects.CdlParameter.ROTVEL
		if(parameter.getDouble("CommNavigationObjects.CdlParameter.ROTVEL", "wmax", commitState.CommNavigationObjects.CdlParameter.ROTVEL.wmax))
		{
			globalState.CommNavigationObjects.CdlParameter.ROTVEL.wmax = commitState.CommNavigationObjects.CdlParameter.ROTVEL.wmax;
		}
		if(parameter.getDouble("CommNavigationObjects.CdlParameter.ROTVEL", "wmin", commitState.CommNavigationObjects.CdlParameter.ROTVEL.wmin))
		{
			globalState.CommNavigationObjects.CdlParameter.ROTVEL.wmin = commitState.CommNavigationObjects.CdlParameter.ROTVEL.wmin;
		}
		// parameter CommNavigationObjects.CdlParameter.SAFETYCL
		if(parameter.getInteger("CommNavigationObjects.CdlParameter.SAFETYCL", "safetyClearance", commitState.CommNavigationObjects.CdlParameter.SAFETYCL.safetyClearance))
		{
			globalState.CommNavigationObjects.CdlParameter.SAFETYCL.safetyClearance = commitState.CommNavigationObjects.CdlParameter.SAFETYCL.safetyClearance;
		}
		// parameter CommNavigationObjects.CdlParameter.TRANSVEL
		if(parameter.getDouble("CommNavigationObjects.CdlParameter.TRANSVEL", "vmax", commitState.CommNavigationObjects.CdlParameter.TRANSVEL.vmax))
		{
			globalState.CommNavigationObjects.CdlParameter.TRANSVEL.vmax = commitState.CommNavigationObjects.CdlParameter.TRANSVEL.vmax;
		}
		if(parameter.getDouble("CommNavigationObjects.CdlParameter.TRANSVEL", "vmin", commitState.CommNavigationObjects.CdlParameter.TRANSVEL.vmin))
		{
			globalState.CommNavigationObjects.CdlParameter.TRANSVEL.vmin = commitState.CommNavigationObjects.CdlParameter.TRANSVEL.vmin;
		}

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
