/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_SHADER_DEPTH_SHADER_CALLBACK_H__
#define __IS06_SHADER_DEPTH_SHADER_CALLBACK_H__

#include "../NEngine/NCore/CGame.h"

namespace is06 { namespace NShader {

//! Shader interface for depth information to a texture (used in shadow mapping technique)
class CDepthShaderCallback : public video::IShaderConstantSetCallBack
{
public:
  virtual void OnSetConstants(video::IMaterialRendererServices* services, s32 userData)
  {

  }

  f32 farLink;
};

}}

#endif
