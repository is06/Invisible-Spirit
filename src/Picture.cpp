/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../include/core.h"

using namespace irr;

/**
 * Création à l'aide de coordonnées directes
 */
Picture::Picture(f32 w, f32 h, f32 x, f32 y, const core::stringc& filePath) : Hud2DElement(w, h, x, y) {
  texture = Game::getVideoDriver()->getTexture(filePath.c_str());
  material.setTexture(0, texture);
}

/**
 * Rendu de l'élément d'interface
 */
void Picture::render() { Hud2DElement::render();

}

Picture::~Picture() {

}
