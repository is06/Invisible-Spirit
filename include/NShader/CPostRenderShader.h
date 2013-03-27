/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_SHADER_POST_RENDER_SHADER_H__
#define __IS06_SHADER_POST_RENDER_SHADER_H__

#include "EEffect.h"
#include "../NHud/NPrimitive/CFlatElement.h"

namespace is06 { namespace NShader {

//! Aligned screen quad for post render in order to produce post process effects like glow or bloom
class CPostRenderShader : public NHud::NPrimitive::CFlatElement
{
public:
  CPostRenderShader();
  ~CPostRenderShader();

  virtual void render();
  void addEntityForEffect(N3D::NPrimitive::CModelEntity* entity, NShader::EEffect effect);
  void applyEffectsToEntities();
  void removeEffectsToEntities();

protected:
  // A map for post processing effects
  map<N3D::NPrimitive::CModelEntity*, NShader::EEffect> EntityList;
  map<N3D::NPrimitive::CModelEntity*, NShader::EEffect>::iterator EntityListIt;
};

}}

#endif

