/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/gui/TextChar.h"
#include "../../include/gui/TextFont.h"

namespace is06
{
namespace hud
{

CTextChar::CTextChar(irr::u8 code, irr::f32& x, irr::f32& y, irr::u8 size, CTextFont* font, bool visible, irr::u8 extTexture) : CHud2DElement(x, y, size, size)
{
  irr::u32 offsetCode = code;

  IsVisible = visible;

  if (extTexture) {
    offsetCode = ((irr::u16)extTexture * 1000) + ((irr::u16)code);
  }

  x += (size * (font->getCharOffset(offsetCode) / 100.0f) / 2);
  setPosition(x, y);
  x += (size * (font->getCharOffset(offsetCode) / 100.0f) / 2);

  FontStyle = font;

  if (!extTexture) {
    FontStyle->resetToStandard();
  } else {
    FontStyle->changeExtTexture(extTexture);
  }

  Material.setTexture(0, FontStyle->getMaterial().getTexture(0));

  irr::f32 space = 1.0f / 16.0f;

  irr::f32 endU = ((code / 16) + 1) * space;
  irr::f32 endV = ((code - ((code / 16) * 16)) + 1) * space;
  irr::f32 startU = endU - space;
  irr::f32 startV = endV - space;

  MinTextureOffset.X = startV;
  MinTextureOffset.Y = startU;
  MaxTextureOffset.X = endV;
  MaxTextureOffset.Y = endU;

  Vertices[0].TCoords.X = startV;
  Vertices[0].TCoords.Y = startU;
  Vertices[1].TCoords.X = endV;
  Vertices[1].TCoords.Y = startU;
  Vertices[2].TCoords.X = startV;
  Vertices[2].TCoords.Y = endU;
  Vertices[3].TCoords.X = endV;
  Vertices[3].TCoords.Y = endU;
}

void CTextChar::render()
{
  CHud2DElement::render();
}

CTextChar::~CTextChar()
{

}

}
}
