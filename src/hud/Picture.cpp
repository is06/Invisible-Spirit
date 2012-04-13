/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/core.h"
#include "../../include/engine/Game.h"
#include "../../include/hud/Picture.h"

namespace is06
{
namespace hud
{

CPicture::CPicture(f32 x, f32 y, f32 w, f32 h, const string& filePath) : CHud2DElement(x, y, w, h)
{
  changeTexture(filePath);
}

/**
 * Rendu de l'élément d'interface
 */
void CPicture::render()
{
  CHud2DElement::render();
}

void CPicture::loadSecondTexture(const string& filePath)
{
  video::ITexture* second = engine::CGame::getVideoDriver()->getTexture(filePath.c_str());
  if (second) {
    Material.setTexture(1, second);
  }
}

void CPicture::changeTexture(const string& filePath)
{
  Texture = engine::CGame::getVideoDriver()->getTexture(filePath.c_str());
  if (Texture) {
    Material.setTexture(0, Texture);
  }
}

CPicture::~CPicture()
{

}

}
}
