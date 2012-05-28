/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/3d/CPlaneSensor.h"

namespace is06
{
namespace n3D
{

CPlaneSensor::CPlaneSensor(const core::plane3df& initPlane) : CSensor()
{
  Plane = initPlane;
}

void CPlaneSensor::update()
{
  CSensor::update();
}

const core::plane3df& CPlaneSensor::getPlane() const
{
  return Plane;
}

}
}
