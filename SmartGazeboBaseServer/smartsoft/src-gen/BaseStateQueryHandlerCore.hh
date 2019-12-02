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
#ifndef _BASESTATEQUERYHANDLER_CORE_HH
#define _BASESTATEQUERYHANDLER_CORE_HH
		
#include "aceSmartSoft.hh"

#include <CommBasicObjects/CommBaseState.hh>
#include <CommBasicObjects/CommVoid.hh>

// include the input interfaces (if any)

// include all interaction-observer interfaces
#include <BaseStateQueryHandlerObserverInterface.hh>
#include <BaseStateTaskObserverInterface.hh>

class BaseStateQueryHandlerCore 
:	public Smart::IInputHandler<std::pair<Smart::QueryIdPtr,CommBasicObjects::CommVoid>>
,	public Smart::TaskTriggerSubject
,	public BaseStateTaskObserverInterface
{
private:
virtual void handle_input(const std::pair<Smart::QueryIdPtr,CommBasicObjects::CommVoid> &input) override {
	this->handleQuery(input.first, input.second);
}


	virtual void updateAllCommObjects();

/**
 * Implementation of the Subject part of an InteractionObserver
 */
private:
	std::mutex interaction_observers_mutex;
	std::list<BaseStateQueryHandlerObserverInterface*> interaction_observers;
protected:
	void notify_all_interaction_observers();
public:
	void attach_interaction_observer(BaseStateQueryHandlerObserverInterface *observer);
	void detach_interaction_observer(BaseStateQueryHandlerObserverInterface *observer);

protected:
	// overload this method in derived classes!
	virtual void on_update_from(const BaseStateTask* subject) {
		// no-op
	}
	
public:
	using IQueryServer = Smart::IQueryServerPattern<CommBasicObjects::CommVoid, CommBasicObjects::CommBaseState>;
	using QueryId = Smart::QueryIdPtr;
	BaseStateQueryHandlerCore(IQueryServer *server);
	virtual ~BaseStateQueryHandlerCore() = default;
	
protected:
	IQueryServer *server;
	//this user-method has to be implemented in derived classes
	virtual void handleQuery(const QueryId &id, const CommBasicObjects::CommVoid& request) = 0;
};
#endif
