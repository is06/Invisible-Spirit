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

namespace is06
{
namespace shader
{

CPostRenderGlow::CPostRenderGlow() : CHud2DElement(0, 0, engine::CGame::ScreenPos.Width, engine::CGame::ScreenPos.Height)
{
  Texture = 0;

  // Render to target texture quality
  irr::u32 texture_quality = engine::CGame::Settings->getParamInt("glow", "texture_quality");
  switch (texture_quality) {
    case 1: texture_quality = 64; break;  // 16KB
    default:
    case 2: texture_quality = 128; break; // 64KB
    case 3: texture_quality = 256; break; // 256KB
    case 4: texture_quality = 512; break; // 1MB
    case 5: texture_quality = 1024; break; // 4MB
  }

  irr::u32 depth_quality = engine::CGame::Settings->getParamInt("glow", "depth_quality");
  irr::video::ECOLOR_FORMAT textureColorFormat = irr::video::ECF_R5G6B5;
  if (depth_quality == 32) {
    textureColorFormat = irr::video::ECF_R8G8B8;
  }

  MinTextureOffset.X = 0.0f;
  MinTextureOffset.Y = 1.0f;
  MaxTextureOffset.X = 1.0f;
  MaxTextureOffset.Y = 0.0f;

  Material.AntiAliasing = false;
  Texture = engine::CGame::getVideoDriver()->addRenderTargetTexture(irr::core::dimension2du(512, 512), "GlowRTT", textureColorFormat);
  Material.setTexture(0, Texture);
}

/**
 * Render post render quad (Hud2DElement) two times (one for each shader pass)
 * Calling render of parent class results in an execution of both vertex and fragment shader
 * First pass : horizontal blur
 * Second pass : vertical blur
 */
void CPostRenderGlow::render()
{
  // Perform first pass (horizontal blur)
  Material.MaterialType = (irr::video::E_MATERIAL_TYPE)engine::CGame::Shaders.HorizontalBlur;
  CHud2DElement::render();

  if (Texture) {
    engine::CGame::getVideoDriver()->setRenderTarget(Texture, true, true, irr::video::SColor(255, 255, 255, 255));
    // Darken non glowing entities
    engine::CGame::getCurrentScene()->darkenNonGlowingEntities();
    // Draw the whole scene
    engine::CGame::getSceneManager()->drawAll();
    // Perform second pass (vertical blur)
    Material.MaterialType = (irr::video::E_MATERIAL_TYPE)engine::CGame::Shaders.VerticalBlur;
    CHud2DElement::render();
    // Restore lighting material of all darkened entities
    engine::CGame::getCurrentScene()->revealNonGlowingEntities();
    // Reset render target to main display viewport
    engine::CGame::getVideoDriver()->setRenderTarget(irr::video::ERT_FRAME_BUFFER, false, true, 0);
  }
}

CPostRenderGlow::~CPostRenderGlow()
{

}

}
}
