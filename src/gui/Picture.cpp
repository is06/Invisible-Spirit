/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/gui/Picture.h"
#include "../../include/Game.h"

namespace is06
{
namespace hud
{

CPicture::CPicture(irr::f32 x, irr::f32 y, irr::f32 w, irr::f32 h, const std::string& filePath) : CHud2DElement(x, y, w, h)
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

void CPicture::loadSecondTexture(const std::string& filePath)
{
  irr::video::ITexture* second = engine::CGame::getVideoDriver()->getTexture(filePath.c_str());
  if (second) {
    Material.setTexture(1, second);
  }
}

void CPicture::changeTexture(const std::string& filePath)
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
