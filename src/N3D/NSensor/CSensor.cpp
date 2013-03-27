/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/N3D/NSensor/CSensor.h"

using namespace irr;

namespace is06 { namespace N3D { namespace NSensor {

//! Construcotr
CSensor::CSensor(f32 width, f32 height, f32 depth, const core::vector3df& position) : NEngine::NCore::CEntity()
{
  setSize(width, height, depth, position);
}

//! Update method, called every cycle for event testing
void CSensor::update()
{
  //CEntity::update();
}

//! Changes the size of the sensor
void CSensor::setSize(f32 width, f32 height, f32 depth, const core::vector3df& position)
{
  core::vector3df min = core::vector3df((width / 2) * -1, (height / 2) * -1, (depth / 2) * - 1) + position;
  core::vector3df max = core::vector3df((width / 2), (height / 2), (depth / 2)) + position;

  Box = core::aabbox3df(min, max);
}

//! Returns the aligned axis bounding box of the sensor
const core::aabbox3df& CSensor::getBox()
{
  return Box;
}

}}}
