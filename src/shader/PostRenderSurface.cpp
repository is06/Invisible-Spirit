/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/shader/PostRenderSurface.h"
#include "../../include/Game.h"
#include "../../include/Settings.h"

using namespace std;
using namespace irr;

PostRenderSurface::PostRenderSurface() : Hud2DElement(1280, 720, 0, 0)
{
  texture = 0;

  // Render to target texture quality
  u32 quality = Game::settings->getParamInt("glow", "quality");
  switch (quality) {
    case 1: quality = 64; break;  // 4K
    default:
    case 2: quality = 128; break; // 16K
    case 3: quality = 256; break; // 65K
    case 4: quality = 512; break; // 256K
    case 5: quality = 1024; break; // 1M
  }

  vertices[0].TCoords.X = 0.0f;
  vertices[0].TCoords.Y = 1.0f;
  vertices[1].TCoords.X = 1.0f;
  vertices[1].TCoords.Y = 1.0f;
  vertices[2].TCoords.X = 0.0f;
  vertices[2].TCoords.Y = 0.0f;
  vertices[3].TCoords.X = 1.0f;
  vertices[3].TCoords.Y = 0.0f;

  material.MaterialType = (video::E_MATERIAL_TYPE)Game::shaders.glow;
  texture = Game::getVideoDriver()->addRenderTargetTexture(core::dimension2du(quality, quality), "RTT1", video::ECF_R8G8B8);
  material.setTexture(0, texture);
}

void PostRenderSurface::render()
{
  Hud2DElement::render();
  if (texture) {
    Game::getVideoDriver()->setRenderTarget(texture, true, true, video::SColor(255, 0, 0, 0));
    Game::getSceneManager()->drawAll();
    Game::getVideoDriver()->setRenderTarget(0, false, true, 0);
  }
}

PostRenderSurface::~PostRenderSurface()
{

}
