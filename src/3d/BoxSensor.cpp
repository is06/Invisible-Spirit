/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/3d/BoxSensor.h"

/**
 *
 */
BoxSensor::BoxSensor(const core::aabbox3df& initBox) : Sensor()
{
  box = initBox;
}

/**
 *
 */
void BoxSensor::update()
{
  Sensor::update();
}

/**
 *
 */
const core::aabbox3df& BoxSensor::getBox() const
{
  return box;
}
