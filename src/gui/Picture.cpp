/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/gui/Picture.h"
#include "../../include/Game.h"

using namespace irr;
using namespace std;

/**
 * Création à l'aide de coordonnées directes
 */
Picture::Picture(f32 x, f32 y, f32 w, f32 h, const core::stringc& filePath) : Hud2DElement(x, y, w, h) {
  changeTexture(filePath);
}

/**
 * Rendu de l'élément d'interface
 */
void Picture::render() { Hud2DElement::render();

}

void Picture::loadSecondTexture(const core::stringc& filePath) {
  //video::ITexture* second = Game::getVideoDriver()->getTexture(filePath.c_str());
}

void Picture::changeTexture(const core::stringc& filePath) {
  cout << "[TEXTURE] Try to load : " << filePath.c_str() << endl;
  texture = Game::getVideoDriver()->getTexture(filePath);
  if(texture) {
    material.setTexture(0, texture);
  }
}

Picture::~Picture() {

}
