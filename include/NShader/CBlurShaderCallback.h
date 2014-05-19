/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_SHADER_BLUR_SHADER_CALLBACK_H__
#define __IS06_SHADER_BLUR_SHADER_CALLBACK_H__

#include "../N3D/NCamera/CCamera.h"
#include "../NScene/CScene.h"
#include "../NEngine/NCore/CGame.h"

using namespace irr;

namespace is06 { namespace NShader {

//! Shader interface for blur effect (post process effect)
class CBlurShaderCallback : public video::IShaderConstantSetCallBack
{
public:
  const video::SMaterial* usedMaterial;

  virtual void OnSetMaterial(const video::SMaterial& material)
  {
    usedMaterial = &material;
  }

  virtual void OnSetConstants(video::IMaterialRendererServices* services, s32 userData)
  {
    core::matrix4 worldViewProj;
    worldViewProj = NEngine::NCore::CGame::getVideoDriver()->getTransform(video::ETS_PROJECTION);
    worldViewProj *= NEngine::NCore::CGame::getVideoDriver()->getTransform(video::ETS_VIEW);
    worldViewProj *= NEngine::NCore::CGame::getVideoDriver()->getTransform(video::ETS_WORLD);
    services->setVertexShaderConstant("worldViewProj", worldViewProj.pointer(), 16);
  }
};

}}

#endif


