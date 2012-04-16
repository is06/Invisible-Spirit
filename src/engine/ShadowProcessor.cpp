/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/core.h"
#include "../../include/engine/Game.h"
#include "../../include/engine/Settings.h"
#include "../../include/engine/ShadowProcessor.h"

namespace is06
{
namespace nEngine
{

/**
 *
 */
CShadowProcessor::CShadowProcessor()
{
  // Render to target texture quality from settings.ini
  u32 textureQuality = CGame::Settings->getParamInt("shadows", "texture_quality");
  switch (textureQuality) {
    case 1: textureQuality = 64; break;  // 4K
    default:
    case 2: textureQuality = 128; break; // 16K
    case 3: textureQuality = 256; break; // 65K
    case 4: textureQuality = 512; break; // 256K
    case 5: textureQuality = 1024; break; // 1M
  }

  // Depth texture quality from settings.ini
  u32 depthQuality = CGame::Settings->getParamInt("shadows", "depth_quality");
  video::ECOLOR_FORMAT depthTextureQuality = video::ECF_G16R16F;
  if (depthQuality == 32) {
    depthTextureQuality = video::ECF_G32R32F;
  }

  // Shadow map texture creation (render target)
  ShadowMap = CGame::getVideoDriver()->addRenderTargetTexture(
    core::dimension2du(textureQuality, textureQuality),
    "IS06_SHADOW_MAP",
    depthTextureQuality
  );
}

/**
 *
 */
void CShadowProcessor::render()
{
  // Changing render target to a texture
  CGame::getVideoDriver()->setRenderTarget(ShadowMap, true, true, video::SColor(255, 255, 255, 255));

  for (ShadowsIt = Shadows.begin(); ShadowsIt != Shadows.end(); ShadowsIt++) {
    // Considering entities that casts shadows
    if (ShadowsIt->second.getMode() == SHADOW_MODE_CAST || ShadowsIt->second.getMode() == SHADOW_MODE_ALL) {
      ShadowsIt->first->render();
    }

    // Considering entities that receives shadows
    if (ShadowsIt->second.getMode() == SHADOW_MODE_RECEIVE || ShadowsIt->second.getMode() == SHADOW_MODE_ALL) {
      // @todo
    }
  }

  // Restore render target to main display window
  CGame::getVideoDriver()->setRenderTarget(0, true, true, video::SColor(255, 0, 0, 0));
}

void CShadowProcessor::renderCastingNodes()
{

}

void CShadowProcessor::renderReceivingNodes()
{

}

/**
 *
 */
void CShadowProcessor::setEntity(scene::ISceneNode* node, EShadowMode mode)
{
  Shadows[node] = CShadow(mode);
}

/**
 *
 */
void CShadowProcessor::removeEntity(scene::ISceneNode* node)
{
  ShadowsIt = Shadows.find(node);
  Shadows.erase(ShadowsIt);
}

/**
 *
 */
CShadowProcessor::~CShadowProcessor()
{

}

}
}
