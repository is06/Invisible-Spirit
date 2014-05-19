/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_3D_SENSOR_SENSOR_H__
#define __IS06_3D_SENSOR_SENSOR_H__

#include "../../NEngine/NCore/CEntity.h"

using namespace irr;

namespace is06 { namespace N3D { namespace NSensor {

//! Main abstract class for all sensors
class CSensor : public NEngine::NCore::CEntity
{
public:
    CSensor();
    virtual ~CSensor();
    virtual void update();
};

}}}

#endif
