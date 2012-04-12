/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __ICE_SHADER_CALLBACK_H__
#define __ICE_SHADER_CALLBACK_H__

#include "../3d/Camera.h"
#include "../scene/Scene.h"
#include "../Game.h"

namespace is06
{
namespace shader
{

class CIceShaderCallback : public irr::video::IShaderConstantSetCallBack
{
  public:
    const irr::video::SMaterial* usedMaterial;

    virtual void OnSetMaterial(const irr::video::SMaterial& material)
    {
      usedMaterial = &material;
    }

    virtual void OnSetConstants(irr::video::IMaterialRendererServices* services, irr::s32 userData)
    {
      // Inversed world matrix
      irr::core::matrix4 invWorld = engine::CGame::getVideoDriver()->getTransform(irr::video::ETS_WORLD);
      services->setVertexShaderConstant("invWorldMatrix", invWorld.pointer(), 16);

      // Camera position
      irr::core::vector3df pos = engine::CGame::getCurrentScene()->getActiveCamera()->getNode()->getAbsolutePosition();
      services->setVertexShaderConstant("cameraPosition", reinterpret_cast<irr::f32*>(&pos), 3);

      // Light color
      irr::video::SColorf col(0.0f, 1.0f, 1.0f, 0.0f);
      services->setVertexShaderConstant("lightColor", reinterpret_cast<irr::f32*>(&col), 4);
    }
};

}
}

#endif

