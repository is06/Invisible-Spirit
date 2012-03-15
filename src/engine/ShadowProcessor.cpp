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
  u32 quality = Game::settings->getParamInt("shadows", "quality");
  switch (quality) {
    case 1: quality = 64; break;  // 4K
    default:
    case 2: quality = 128; break; // 16K
    case 3: quality = 256; break; // 65K
    case 4: quality = 512; break; // 256K
    case 5: quality = 1024; break; // 1M
  }

  // Shadow map texture creation (render target)
  shadowMap = Game::getVideoDriver()->addRenderTargetTexture(
    core::dimension2du(quality, quality),
    "IS06_SHADOW_MAP",
    video::ECF_G16R16F
  );
}

/**
 *
 */
void ShadowProcessor::render()
{
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
