/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/3d/BoxSensor.h"

namespace is06
{
namespace model
{

/**
 *
 */
CBoxSensor::CBoxSensor(const irr::core::aabbox3df& initBox) : CSensor()
{
  Box = initBox;
}

/**
 *
 */
void CBoxSensor::update()
{
  CSensor::update();
}

/**
 *
 */
const irr::core::aabbox3df& CBoxSensor::getBox() const
{
  return Box;
}

}
}
