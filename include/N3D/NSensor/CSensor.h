/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_SENSOR_H__
#define __IS06_SENSOR_H__

#include "../Engine/CEntity.h"

using namespace irr;

namespace is06 { namespace N3D { namespace NSensor {

//! Main abstract class for all sensors
class CSensor : public NEngine::CEntity
{
public:
  CSensor(f32 width, f32 height, f32 depth, const core::vector3df& position);
  virtual void update();

  void setSize(f32 width, f32 height, f32 depth, const core::vector3df& position);
  const core::aabbox3df& getBox();

protected:
  core::aabbox3df Box;
};

}}}

#endif
