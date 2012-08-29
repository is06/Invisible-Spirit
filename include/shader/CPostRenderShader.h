/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_POST_RENDER_SHADER_H__
#define __IS06_POST_RENDER_SHADER_H__

#include "EShaderEffect.h"
#include "../hud/CHud2DElement.h"

namespace is06
{
namespace nShader
{

//! Aligned screen quad for post render in order to simulated a light glowing effect
class CPostRenderShader : public nHud::CHud2DElement
{
  public:
    CPostRenderShader();
    ~CPostRenderShader();

    virtual void render();
    void addEntityForEffect(n3D::CModelEntity* entity, EShaderEffect effect);
    void applyEffectsToEntities();
    void removeEffectsToEntities();

  protected:
    // A map for post processing effects
    map<n3D::CModelEntity*, EShaderEffect> EntityList;
    map<n3D::CModelEntity*, EShaderEffect>::iterator EntityListIt;
};

}
}

#endif

