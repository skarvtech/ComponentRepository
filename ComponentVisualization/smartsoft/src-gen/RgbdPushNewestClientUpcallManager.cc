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
#include "RgbdPushNewestClientUpcallManager.hh"

RgbdPushNewestClientUpcallManager::RgbdPushNewestClientUpcallManager(
	Smart::InputSubject<DomainVision::CommRGBDImage> *subject,
	const int &prescaleFactor)
	:	Smart::IInputHandler<DomainVision::CommRGBDImage>(subject, prescaleFactor)
{  }
RgbdPushNewestClientUpcallManager::~RgbdPushNewestClientUpcallManager()
{  }

void RgbdPushNewestClientUpcallManager::notify_upcalls(const DomainVision::CommRGBDImage &input)
{
	for(auto it=upcalls.begin(); it!=upcalls.end(); it++) {
		(*it)->on_rgbdPushNewestClient(input);
	}
}

void RgbdPushNewestClientUpcallManager::attach(RgbdPushNewestClientUpcallInterface *upcall)
{
	upcalls.push_back(upcall);
}
void RgbdPushNewestClientUpcallManager::detach(RgbdPushNewestClientUpcallInterface *upcall)
{
	upcalls.remove(upcall);
}
