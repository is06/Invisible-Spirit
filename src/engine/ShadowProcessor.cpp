/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/Game.h"
#include "../../include/Settings.h"
#include "../../include/engine/ShadowProcessor.h"

using namespace irr;
using namespace std;

/**
 *
 */
ShadowProcessor::ShadowProcessor()
{
  // Render to target texture quality from settings.ini
  u32 textureQuality = Game::settings->getParamInt("shadows", "texture_quality");
  switch (textureQuality) {
    case 1: textureQuality = 64; break;  // 4K
    default:
    case 2: textureQuality = 128; break; // 16K
    case 3: textureQuality = 256; break; // 65K
    case 4: textureQuality = 512; break; // 256K
    case 5: textureQuality = 1024; break; // 1M
  }

  // Depth texture quality from settings.ini
  u32 depthQuality = Game::settings->getParamInt("shadows", "depth_quality");
  video::ECOLOR_FORMAT depthTextureQuality = video::ECF_G16R16F;
  if (depthQuality == 32) {
    depthTextureQuality = video::ECF_G32R32F;
  }

  // Shadow map texture creation (render target)
  shadowMap = Game::getVideoDriver()->addRenderTargetTexture(
    core::dimension2du(textureQuality, textureQuality),
    "IS06_SHADOW_MAP",
    depthTextureQuality
  );
}

/**
 *
 */
void ShadowProcessor::render()
{
  // Changing render target to a texture
  Game::getVideoDriver()->setRenderTarget(shadowMap, true, true, video::SColor(255, 255, 255, 255));

  for (shadowsIt = shadows.begin(); shadowsIt != shadows.end(); shadowsIt++) {
    // Considering entities that casts shadows
    if (shadowsIt->second.getMode() == SHADOW_MODE_CAST || shadowsIt->second.getMode() == SHADOW_MODE_ALL) {
      shadowsIt->first->render();
    }

    // Considering entities that receives shadows
    if (shadowsIt->second.getMode() == SHADOW_MODE_RECEIVE || shadowsIt->second.getMode() == SHADOW_MODE_ALL) {
      // @todo
    }
  }

  // Restore render target to main display window
  Game::getVideoDriver()->setRenderTarget(0, true, true, video::SColor(255, 0, 0, 0));
}

void ShadowProcessor::renderCastingNodes()
{

}

void ShadowProcessor::renderReceivingNodes()
{

}

/**
 *
 */
void ShadowProcessor::setEntity(scene::ISceneNode* node, ShadowMode mode)
{
  shadows[node] = Shadow(mode);
}

/**
 *
 */
void ShadowProcessor::removeEntity(scene::ISceneNode* node)
{
  shadowsIt = shadows.find(node);
  shadows.erase(shadowsIt);
}

/**
 *
 */
ShadowProcessor::~ShadowProcessor()
{

}
