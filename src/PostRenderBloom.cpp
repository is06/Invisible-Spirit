/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../include/core.h"

using namespace std;
using namespace irr;

PostRenderBloom::PostRenderBloom() : Hud2DElement(848,480,0,0) {
  texture = 0;
  material.MaterialType = video::EMT_TRANSPARENT_ADD_COLOR;
  if(Game::getVideoDriver()->queryFeature(video::EVDF_RENDER_TO_TARGET)
  && Game::getVideoDriver()->queryFeature(video::EVDF_PIXEL_SHADER_1_1)) {
    texture = Game::getVideoDriver()->addRenderTargetTexture(core::dimension2du(256,256), "RTT1", video::ECF_R8G8B8);
    material.setTexture(0, texture);
  }
}

void PostRenderBloom::render() { Hud2DElement::render();
  if(texture) {
    Game::getVideoDriver()->setRenderTarget(texture, true, true, video::SColor(255,0,0,0));
    Game::getSceneManager()->drawAll();
    Game::getVideoDriver()->setRenderTarget(0, false, true, 0);
  }
}

PostRenderBloom::~PostRenderBloom() {

}
