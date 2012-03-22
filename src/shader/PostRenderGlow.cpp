/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/shader/PostRenderGlow.h"
#include "../../include/scene/Scene.h"
#include "../../include/Game.h"
#include "../../include/Settings.h"

using namespace std;
using namespace irr;

PostRenderGlow::PostRenderGlow() : Hud2DElement(0, 0, 1280, 720)
{
  texture = 0;

  // Render to target texture quality
  u32 quality = Game::settings->getParamInt("glow", "quality");
  switch (quality) {
    case 1: quality = 64; break;  // 16KB
    default:
    case 2: quality = 128; break; // 64KB
    case 3: quality = 256; break; // 256KB
    case 4: quality = 512; break; // 1MB
    case 5: quality = 1024; break; // 4MB
  }

  minTextureOffset.X = 0.0f;
  minTextureOffset.Y = 1.0f;
  maxTextureOffset.X = 1.0f;
  maxTextureOffset.Y = 0.0f;

  material.MaterialType = (video::E_MATERIAL_TYPE)Game::shaders.glow;
  texture = Game::getVideoDriver()->addRenderTargetTexture(core::dimension2du(quality, quality), "GlowRTT", video::ECF_R8G8B8);
  material.setTexture(0, texture);
}

void PostRenderGlow::render()
{
  Hud2DElement::render();

  if (texture) {
    Game::getVideoDriver()->setRenderTarget(texture, true, true, video::SColor(255, 0, 0, 0));
    Game::getCurrentScene()->darkenNonGlowingEntities();
    Game::getSceneManager()->drawAll();
    Game::getCurrentScene()->revealNonGlowingEntities();
    Game::getVideoDriver()->setRenderTarget(0, false, true, 0);
  }
}

PostRenderGlow::~PostRenderGlow()
{

}
