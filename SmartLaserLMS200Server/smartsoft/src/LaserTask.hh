//--------------------------------------------------------------------------
// Code generated by the SmartSoft MDSD Toolchain
// The SmartSoft Toolchain has been developed by:
//  
// Christian Schlegel (schlegel@hs-ulm.de)
// University of Applied Sciences Ulm
// Prittwitzstr. 10
// 89075 Ulm (Germany)
//
// Information about the SmartSoft MDSD Toolchain is available at:
// www.servicerobotik-ulm.de
//
// This file is generated once. Modify this file to your needs. 
// If you want the toolchain to re-generate this file, please 
// delete it before running the code generator.
//--------------------------------------------------------------------------

//--------------------------------------------------------------------------
//
//  Copyright (C) 2003 Boris Kluge
//                2009 Andreas Steck
//
//        schlegel@hs-ulm.de
//
//        ZAFH Servicerobotic Ulm
//        University of Applied Sciences
//        Prittwitzstr. 10
//        89075 Ulm
//        Germany
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 2.1
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  General Public License for more details.
//
//  You should have received a copy of the GNU General Public License along
//  with this library; if not, write to the Free Software Foundation, Inc.,
//  59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
//
//--------------------------------------------------------------------------
#ifndef _LASERTASK_HH
#define _LASERTASK_HH

#include "LaserTaskCore.hh"

#include <smartSickInterface.hh>
	
class LaserTask  : public LaserTaskCore
{
private:
	Smart::StatusCode status;
	Smart::SickInterface laser;
	CommBasicObjects::CommMobileLaserScan scan;
	CommBasicObjects::CommBaseState base_state;
	CommBasicObjects::CommBaseVelocity zero_velocity;
	unsigned long update_count;
	unsigned long long startTime, stopTime;
	timeval ts;

	mutable SmartACE::SmartMutex mutex;
	CommBasicObjects::CommMobileLaserScan laser_scan;
	void setLaserScan(const CommBasicObjects::CommMobileLaserScan &scan);

public:
	LaserTask(Smart::IComponent *comp);
	virtual ~LaserTask();
	
	bool init_laser(Smart::SickInterface &laser) const;

	virtual int on_entry();
	virtual int on_execute();
	virtual int on_exit();

	CommBasicObjects::CommMobileLaserScan getLaserScan() const;
};

#endif