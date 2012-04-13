/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __ICE_SHADER_CALLBACK_H__
#define __ICE_SHADER_CALLBACK_H__

#include "../model/Camera.h"
#include "../screen/Scene.h"
#include "../engine/Game.h"

namespace is06
{
namespace shader
{

//! This class passes parameters to vertex and fragment programs to set up the shader ice-looking material
class CIceShaderCallback : public video::IShaderConstantSetCallBack
{
  public:
    const video::SMaterial* usedMaterial;

    virtual void OnSetMaterial(const video::SMaterial& material)
    {
      usedMaterial = &material;
    }

    virtual void OnSetConstants(video::IMaterialRendererServices* services, s32 userData)
    {
      // Inversed world matrix
      core::matrix4 invWorld = engine::CGame::getVideoDriver()->getTransform(video::ETS_WORLD);
      services->setVertexShaderConstant("invWorldMatrix", invWorld.pointer(), 16);

      // Camera position
      core::vector3df pos = engine::CGame::getCurrentScene()->getActiveCamera()->getNode()->getAbsolutePosition();
      services->setVertexShaderConstant("cameraPosition", reinterpret_cast<f32*>(&pos), 3);

      // Light color
      video::SColorf col(0.0f, 1.0f, 1.0f, 0.0f);
      services->setVertexShaderConstant("lightColor", reinterpret_cast<f32*>(&col), 4);
    }
};

}
}

#endif

