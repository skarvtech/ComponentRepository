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
#ifndef _SPEECHQUERYHANDLER_CORE_HH
#define _SPEECHQUERYHANDLER_CORE_HH
		
#include "aceSmartSoft.hh"

#include <CommBasicObjects/CommPropertySet.hh>
#include <DomainSpeech/CommSpeechOutputMessage.hh>

// include the input interfaces (if any)

// include all interaction-observer interfaces
#include <SpeechQueryHandlerObserverInterface.hh>

class SpeechQueryHandlerCore 
:	public Smart::IInputHandler<std::pair<Smart::QueryIdPtr,DomainSpeech::CommSpeechOutputMessage>>
,	public Smart::TaskTriggerSubject
{
private:
virtual void handle_input(const std::pair<Smart::QueryIdPtr,DomainSpeech::CommSpeechOutputMessage> &input) override {
	this->handleQuery(input.first, input.second);
}


	virtual void updateAllCommObjects();

/**
 * Implementation of the Subject part of an InteractionObserver
 */
private:
	std::mutex interaction_observers_mutex;
	std::list<SpeechQueryHandlerObserverInterface*> interaction_observers;
protected:
	void notify_all_interaction_observers();
public:
	void attach_interaction_observer(SpeechQueryHandlerObserverInterface *observer);
	void detach_interaction_observer(SpeechQueryHandlerObserverInterface *observer);

protected:
	
public:
	using IQueryServer = Smart::IQueryServerPattern<DomainSpeech::CommSpeechOutputMessage, CommBasicObjects::CommPropertySet>;
	using QueryId = Smart::QueryIdPtr;
	SpeechQueryHandlerCore(IQueryServer *server);
	virtual ~SpeechQueryHandlerCore() = default;
	
protected:
	IQueryServer *server;
	//this user-method has to be implemented in derived classes
	virtual void handleQuery(const QueryId &id, const DomainSpeech::CommSpeechOutputMessage& request) = 0;
};
#endif
