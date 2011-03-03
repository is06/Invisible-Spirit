/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../include/core.h"

using namespace std;
using namespace irr;

TextChar::TextChar(u8 code, f32& x, f32& y, u8 size, TextFont* font, bool visible) : Hud2DElement(size, size, x, y) {
  f32 rsize = (size / 100.0f);
  isVisible = visible;

  x += ((size * (font->getCharOffset(code) / 100.0f)) / 2);
  setPosition(x, y);
  x += ((size * (font->getCharOffset(code) / 100.0f)) / 2);

  fontStyle = font;
  material.setTexture(0, fontStyle->getMaterial().getTexture(0));

  f32 space = 1.0f / 16.0f;

  f32 endU = ((code / 16) + 1) * space;
  f32 endV = ((code - ((code / 16) * 16)) + 1) * space;
  f32 startU = endU - space;
  f32 startV = endV - space;

  vertices[0].TCoords.X = startV;
  vertices[0].TCoords.Y = startU;
  vertices[1].TCoords.X = endV;
  vertices[1].TCoords.Y = startU;
  vertices[2].TCoords.X = startV;
  vertices[2].TCoords.Y = endU;
  vertices[3].TCoords.X = endV;
  vertices[3].TCoords.Y = endU;
}

void TextChar::render() { Hud2DElement::render();

}

TextChar::~TextChar() {

}
