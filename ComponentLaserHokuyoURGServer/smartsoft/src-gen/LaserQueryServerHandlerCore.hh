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
#ifndef _LASERQUERYSERVERHANDLER_CORE_HH
#define _LASERQUERYSERVERHANDLER_CORE_HH
		
#include "aceSmartSoft.hh"

#include <CommBasicObjects/CommMobileLaserScan.hh>
#include <CommBasicObjects/CommVoid.hh>

// include the input interfaces (if any)

// include all interaction-observer interfaces
#include <LaserQueryServerHandlerObserverInterface.hh>

class LaserQueryServerHandlerCore 
:	public Smart::IQueryServerHandler<CommBasicObjects::CommVoid, CommBasicObjects::CommMobileLaserScan, SmartACE::QueryId>
,	public Smart::TaskTriggerSubject
{
private:

	virtual void updateAllCommObjects();

/**
 * Implementation of the Subject part of an InteractionObserver
 */
private:
	std::mutex interaction_observers_mutex;
	std::list<LaserQueryServerHandlerObserverInterface*> interaction_observers;
protected:
	void notify_all_interaction_observers();
public:
	void attach_interaction_observer(LaserQueryServerHandlerObserverInterface *observer);
	void detach_interaction_observer(LaserQueryServerHandlerObserverInterface *observer);

protected:
	
public:
	LaserQueryServerHandlerCore(Smart::IQueryServerPattern<CommBasicObjects::CommVoid, CommBasicObjects::CommMobileLaserScan, SmartACE::QueryId>* server);
	virtual ~LaserQueryServerHandlerCore();
	//virtual void handleQuery(const SmartACE::QueryId &id, const CommBasicObjects::CommVoid& request);
};
#endif