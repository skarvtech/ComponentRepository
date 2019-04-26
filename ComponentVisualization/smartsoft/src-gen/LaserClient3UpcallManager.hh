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
#ifndef _LASERCLIENT3_UPCALL_MANAGER_HH
#define _LASERCLIENT3_UPCALL_MANAGER_HH

#include <list>
#include "aceSmartSoft.hh"
#include "LaserClient3UpcallInterface.hh"

/** LaserClient3UpcallManager connects input-handling with Upcall propagation
 *
 * This class implements an InputHandler for the InputPort laserClient3 and propagates the handling 
 * of incoming data to all associated (i.e. attached) Upcalls.
 */
class LaserClient3UpcallManager
:	public Smart::IInputHandler<CommBasicObjects::CommMobileLaserScan>
{
private:
	// list of associated updalls
	std::list<LaserClient3UpcallInterface*> upcalls;

	// call the on_laserClient3 of all the attached LaserClient3UpcallInterfaces
	void notify_upcalls(const CommBasicObjects::CommMobileLaserScan &input);
	
protected:
	virtual void handle_input(const CommBasicObjects::CommMobileLaserScan &input) {
		// relay input-handling to all attached LaserClient3UpcallInterfaces
		this->notify_upcalls(input);
	}
public:
	LaserClient3UpcallManager(
		Smart::InputSubject<CommBasicObjects::CommMobileLaserScan> *subject,
		const int &prescaleFactor=1
	);
	virtual ~LaserClient3UpcallManager();
	
	void attach(LaserClient3UpcallInterface *upcall);
	void detach(LaserClient3UpcallInterface *upcall);
};

#endif