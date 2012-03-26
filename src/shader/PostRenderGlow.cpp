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
  u32 texture_quality = Game::settings->getParamInt("glow", "texture_quality");
  switch (texture_quality) {
    case 1: texture_quality = 64; break;  // 16KB
    default:
    case 2: texture_quality = 128; break; // 64KB
    case 3: texture_quality = 256; break; // 256KB
    case 4: texture_quality = 512; break; // 1MB
    case 5: texture_quality = 1024; break; // 4MB
  }

  u32 depth_quality = Game::settings->getParamInt("glow", "depth_quality");
  video::ECOLOR_FORMAT textureColorFormat = video::ECF_R5G6B5;
  if (depth_quality == 32) {
    textureColorFormat = video::ECF_R8G8B8;
  }

  minTextureOffset.X = 0.0f;
  minTextureOffset.Y = 1.0f;
  maxTextureOffset.X = 1.0f;
  maxTextureOffset.Y = 0.0f;

  texture = Game::getVideoDriver()->addRenderTargetTexture(core::dimension2du(512, 512), "GlowRTT", textureColorFormat);
  material.setTexture(0, texture);
}

/**
 * Render post render quad (Hud2DElement) two times (one for each shader pass)
 * Calling render of parent class results in an execution of both vertex and fragment shader
 * First pass : horizontal blur
 * Second pass : vertical blur
 */
void PostRenderGlow::render()
{
  // Perform first pass (horizontal blur)
  material.MaterialType = (video::E_MATERIAL_TYPE)Game::shaders.horizontalBlur;
  Hud2DElement::render();

  if (texture) {
    Game::getVideoDriver()->setRenderTarget(texture, true, true, video::SColor(255, 255, 255, 255));
    // Darken non glowing entities
    Game::getCurrentScene()->darkenNonGlowingEntities();
    // Draw the whole scene
    Game::getSceneManager()->drawAll();
    // Perform second pass (vertical blur)
    //material.MaterialType = (video::E_MATERIAL_TYPE)Game::shaders.verticalBlur;
    //Hud2DElement::render();
    // Restore lighting material of all darkened entities
    Game::getCurrentScene()->revealNonGlowingEntities();
    // Reset render target to main display viewport
    Game::getVideoDriver()->setRenderTarget(0, false, true, 0);
  }
}

PostRenderGlow::~PostRenderGlow()
{

}
