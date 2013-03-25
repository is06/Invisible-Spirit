/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/Engine/core.h"
#include "../../include/Engine/CGame.h"
#include "../../include/Engine/Resource/CSettings.h"
#include "../../include/3D/CModelEntity.h"
#include "../../include/Shader/CPostRenderShader.h"

namespace is06 { namespace NShader {

CPostRenderShader::CPostRenderShader() : CFlatElement(0, 0, NEngine::CGame::ScreenPos.Hud.Width, NEngine::CGame::ScreenPos.Hud.Height)
{
  Texture = 0;
  if (NEngine::CGame::Settings->getParamString("display", "renderer") == "direct3d") {
    // Direct3D post render texture coordinates
    MinTextureOffset.X = 0.0f;
    MinTextureOffset.Y = 0.0f;
    MaxTextureOffset.X = 1.0f;
    MaxTextureOffset.Y = 1.0f;
  } else {
    // OpenGL post render texture coordinates
    MinTextureOffset.X = 0.0f;
    MinTextureOffset.Y = 1.0f;
    MaxTextureOffset.X = 1.0f;
    MaxTextureOffset.Y = 0.0f;
  }
}

void CPostRenderShader::render()
{

}

void CPostRenderShader::addEntityForEffect(N3D::CModelEntity* entity, NShader::EEffect effect)
{
  EntityList[entity] = effect;
}

void CPostRenderShader::applyEffectsToEntities()
{
  for (EntityListIt = EntityList.begin(); EntityListIt != EntityList.end(); EntityListIt++) {
    switch (EntityListIt->second) {
      case EFFECT_DARKEN:
        // @todo : turn off all lights
        NEngine::CGame::getSceneManager()->setAmbientLight(video::SColorf(0.0f, 0.0f, 0.0f));
        EntityListIt->first->darken();
        break;
      case EFFECT_LIGHTEN:
        EntityListIt->first->lighten();
        break;
      case EFFECT_SHOW:
        EntityListIt->first->show();
        break;
      case EFFECT_HIDE:
        EntityListIt->first->hide();
        break;
      case EFFECT_TEXTURE_SWITCH:
        EntityListIt->first->textureSwitch();
        break;
      default:
        break;
    }
  }
}

void CPostRenderShader::removeEffectsToEntities()
{
  for (EntityListIt = EntityList.begin(); EntityListIt != EntityList.end(); EntityListIt++) {
    switch (EntityListIt->second) {
      case EFFECT_DARKEN:
        // @todo : turn on all lights
        NEngine::CGame::getSceneManager()->setAmbientLight(video::SColorf(1.0f, 1.0f, 1.0f));
        EntityListIt->first->undarken();
        break;
      case EFFECT_LIGHTEN:
        EntityListIt->first->unlighten();
        break;
      case EFFECT_SHOW:
        EntityListIt->first->hide();
        break;
      case EFFECT_HIDE:
        EntityListIt->first->show();
        break;
      case EFFECT_TEXTURE_SWITCH:
        EntityListIt->first->textureSwitch();
        break;
      default:
        break;
    }
  }
}

CPostRenderShader::~CPostRenderShader()
{

}

}}
