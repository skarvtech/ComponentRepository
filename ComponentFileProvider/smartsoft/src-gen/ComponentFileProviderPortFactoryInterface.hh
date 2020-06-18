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

#ifndef COMPONENTFILEPROVIDER_PORTFACTORYINTERFACE_HH_
#define COMPONENTFILEPROVIDER_PORTFACTORYINTERFACE_HH_

// include communication objects
#include <CommBasicObjects/CommFileReadAnswer.hh>
#include <CommBasicObjects/CommFileReadAnswerACE.hh>
#include <CommBasicObjects/CommFileReadRequest.hh>
#include <CommBasicObjects/CommFileReadRequestACE.hh>
#include <CommBasicObjects/CommFileWriteAnswer.hh>
#include <CommBasicObjects/CommFileWriteAnswerACE.hh>
#include <CommBasicObjects/CommFileWriteRequest.hh>
#include <CommBasicObjects/CommFileWriteRequestACE.hh>

#include <chrono>

// include component's main class
#include "ComponentFileProvider.hh"

// forward declaration
class ComponentFileProvider;

class ComponentFileProviderPortFactoryInterface {
public:
	ComponentFileProviderPortFactoryInterface() { };
	virtual ~ComponentFileProviderPortFactoryInterface() { };

	virtual void initialize(ComponentFileProvider *component, int argc, char* argv[]) = 0;
	virtual int onStartup() = 0;

	
	virtual Smart::IQueryServerPattern<CommBasicObjects::CommFileReadRequest, CommBasicObjects::CommFileReadAnswer> * createFileReadQueryAnsw(const std::string &serviceName) = 0;
	virtual Smart::IQueryServerPattern<CommBasicObjects::CommFileWriteRequest, CommBasicObjects::CommFileWriteAnswer> * createFileWriteQueryAnsw(const std::string &serviceName) = 0;

	virtual int onShutdown(const std::chrono::steady_clock::duration &timeoutTime=std::chrono::seconds(2)) = 0;
	virtual void destroy() = 0;
};

#endif /* COMPONENTFILEPROVIDER_PORTFACTORYINTERFACE_HH_ */
