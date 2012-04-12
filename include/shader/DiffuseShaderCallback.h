/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __DIFFUSE_SHADER_CALLBACK_H__
#define __DIFFUSE_SHADER_CALLBACK_H__

#include "../Game.h"

namespace is06
{
namespace shader
{

class CDiffuseShaderCallback : public irr::video::IShaderConstantSetCallBack
{
  public:
    const irr::video::SMaterial* UsedMaterial;

    virtual void OnSetMaterial(const irr::video::SMaterial& material)
    {
      UsedMaterial = &material;
    }

    virtual void OnSetConstants(irr::video::IMaterialRendererServices* services, irr::s32 userData)
    {
      irr::core::matrix4 worldViewProj;
      worldViewProj = engine::CGame::getVideoDriver()->getTransform(irr::video::ETS_PROJECTION);
      worldViewProj *= engine::CGame::getVideoDriver()->getTransform(irr::video::ETS_VIEW);
      worldViewProj *= engine::CGame::getVideoDriver()->getTransform(irr::video::ETS_WORLD);
      services->setVertexShaderConstant("mWorldViewProj", worldViewProj.pointer(), 16);

      irr::f32 vColor[4] = {
        UsedMaterial->DiffuseColor.getRed() / 255.0f,
        UsedMaterial->DiffuseColor.getGreen() / 255.0f,
        UsedMaterial->DiffuseColor.getBlue() / 255.0f,
        UsedMaterial->DiffuseColor.getAlpha() / 255.0f
      };
      services->setVertexShaderConstant("vColor", vColor, 4);
    }
};

}
}

#endif
