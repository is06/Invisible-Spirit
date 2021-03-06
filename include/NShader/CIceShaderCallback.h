/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_SHADER_ICE_SHADER_CALLBACK_H__
#define __IS06_SHADER_ICE_SHADER_CALLBACK_H__

#include "../N3D/CCamera.h"
#include "../NScene/CScene.h"
#include "../NEngine/NCore/CGame.h"

namespace is06 { namespace NShader {

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
    core::matrix4 invWorld = NEngine::NCore::CGame::getVideoDriver()->getTransform(video::ETS_WORLD);
    services->setVertexShaderConstant("invWorldMatrix", invWorld.pointer(), 16);

    // Camera position
    core::vector3df pos = NEngine::NCore::CGame::getCurrentScene()->getActiveCamera()->getNode()->getAbsolutePosition();
    services->setVertexShaderConstant("cameraPosition", reinterpret_cast<f32*>(&pos), 3);

    // Light color
    video::SColorf col(0.0f, 1.0f, 1.0f, 0.0f);
    services->setVertexShaderConstant("lightColor", reinterpret_cast<f32*>(&col), 4);
  }
};

}}

#endif

