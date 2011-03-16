/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"

using namespace std;
using namespace irr;

PostRenderGlow::PostRenderGlow() : Hud2DElement(640,480,0,0) {
  texture = 0;

  // Qualité de la texture du render target
  u32 quality = Game::settings->getParamInt("shader", "texture_quality");
  switch(quality) {
    case 1: quality = 64; break;
    default:
    case 2: quality = 128; break;
    case 3: quality = 256; break;
    case 4: quality = 512; break;
  }

  vertices[0].TCoords.X = 0.0;
  vertices[0].TCoords.Y = 1.0;
  vertices[1].TCoords.X = 1.0;
  vertices[1].TCoords.Y = 1.0;
  vertices[2].TCoords.X = 0.0;
  vertices[2].TCoords.Y = 0.0;
  vertices[3].TCoords.X = 1.0;
  vertices[3].TCoords.Y = 0.0;

  material.MaterialType = (video::E_MATERIAL_TYPE)Game::shaders.glow;
  if(Game::getVideoDriver()->queryFeature(video::EVDF_RENDER_TO_TARGET)
  && Game::getVideoDriver()->queryFeature(video::EVDF_PIXEL_SHADER_1_1)) {
    texture = Game::getVideoDriver()->addRenderTargetTexture(core::dimension2du(quality,quality), "RTT1", video::ECF_R8G8B8);
    material.setTexture(0, texture);
  }
}

void PostRenderGlow::render() { Hud2DElement::render();
  if(texture) {
    Game::getVideoDriver()->setRenderTarget(texture, true, true, video::SColor(255,0,0,0));
    Game::getSceneManager()->drawAll();
    Game::getVideoDriver()->setRenderTarget(0, false, true, 0);
  }
}

PostRenderGlow::~PostRenderGlow() {

}
