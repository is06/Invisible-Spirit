/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_3D_LIGHT_LIGHT_H__
#define __IS06_3D_LIGHT_LIGHT_H__

#include "../../NEngine/NCore/CEntity.h"

namespace is06 { namespace N3D { namespace NLight {

//! Base class for lights
class CLight : public NEngine::NCore::CEntity
{
public:
  CLight();
  ~CLight();

  void update();

private:
  scene::ILightSceneNode* Node;
  scene::IBillboardSceneNode* Icon;
};

}}}

#endif
