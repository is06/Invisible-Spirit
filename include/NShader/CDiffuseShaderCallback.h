/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_SHADER_DIFFUSE_SHADER_CALLBACK_H__
#define __IS06_SHADER_DIFFUSE_SHADER_CALLBACK_H__

#include "../Engine/CGame.h"

namespace is06 { namespace NShader {

//! This class passes parameters to vertex and fragment programs to set up the shader diffuse material
class CDiffuseShaderCallback : public video::IShaderConstantSetCallBack
{
public:
  const video::SMaterial* UsedMaterial;

  virtual void OnSetMaterial(const video::SMaterial& material)
  {
    UsedMaterial = &material;
  }

  virtual void OnSetConstants(video::IMaterialRendererServices* services, s32 userData)
  {
    core::matrix4 worldViewProj;
    worldViewProj = NEngine::CGame::getVideoDriver()->getTransform(video::ETS_PROJECTION);
    worldViewProj *= NEngine::CGame::getVideoDriver()->getTransform(video::ETS_VIEW);
    worldViewProj *= NEngine::CGame::getVideoDriver()->getTransform(video::ETS_WORLD);
    services->setVertexShaderConstant("mWorldViewProj", worldViewProj.pointer(), 16);

    f32 vColor[4] = {
      UsedMaterial->DiffuseColor.getRed() / 255.0f,
      UsedMaterial->DiffuseColor.getGreen() / 255.0f,
      UsedMaterial->DiffuseColor.getBlue() / 255.0f,
      UsedMaterial->DiffuseColor.getAlpha() / 255.0f
    };
    services->setVertexShaderConstant("vColor", vColor, 4);
  }
};

}}

#endif
