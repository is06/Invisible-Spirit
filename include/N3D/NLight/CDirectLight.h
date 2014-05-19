/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_3D_LIGHT_DIRECT_LIGHT_H__
#define __IS06_3D_LIGHT_DIRECT_LIGHT_H__

#include "CLight.h"

namespace is06 { namespace N3D { namespace NLight {

//! Light for casting shadows using a camera scene node (not working yet)
class CDirectLight : public CLight
{
public:
  CDirectLight();
  ~CDirectLight();

  void setPosition(const core::vector3df& position);
  void setLookAt(const core::vector3df& position);

  scene::ICameraSceneNode* getCameraNode();

private:
  scene::ICameraSceneNode* Camera;
};

}}}

#endif
