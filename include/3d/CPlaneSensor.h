/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_PLANE_SENSOR_H__
#define __IS06_PLANE_SENSOR_H__

#include "CSensor.h"

namespace is06
{
namespace n3D
{

//! A concrete but invisible plane sensor with collision detection functions
class CPlaneSensor : public CSensor
{
  public:
    CPlaneSensor(const core::plane3df& initPlane);
    void update();

    const core::plane3df& getPlane() const;

  private:
    core::plane3df Plane;
};

}
}

#endif
