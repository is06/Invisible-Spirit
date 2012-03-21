/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/3d/PlaneSensor.h"

using namespace irr;

/**
 *
 */
PlaneSensor::PlaneSensor(const core::plane3df& initPlane) : Sensor()
{
  plane = initPlane;
}

/**
 *
 */
void PlaneSensor::update()
{
  Sensor::update();
}

/**
 *
 */
const core::plane3df& PlaneSensor::getPlane() const
{
  return plane;
}

