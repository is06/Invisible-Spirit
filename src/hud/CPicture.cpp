/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/core.h"
#include "../../include/engine/CGame.h"
#include "../../include/engine/CResourceManager.h"
#include "../../include/hud/CPicture.h"

namespace is06
{
namespace nHud
{

CPicture::CPicture(f32 x, f32 y, f32 w, f32 h, const string& filePath, bool useAlphaBlending) : CHud2DElement(x, y, w, h, useAlphaBlending)
{
  changeTexture(filePath);
}

void CPicture::render()
{
  CHud2DElement::render();
}

void CPicture::loadSecondTexture(const string& filePath)
{
  video::ITexture* second = nEngine::CResourceManager::loadTexture(filePath);
  if (second) {
    Material.setTexture(1, second);
  }
}

void CPicture::changeTexture(const string& filePath)
{
  Texture = nEngine::CResourceManager::loadTexture(filePath);
  if (Texture) {
    Material.setTexture(0, Texture);
  }
}

void CPicture::setRenderTarget(video::ITexture* renderTargetTexture)
{
  Texture = renderTargetTexture;
  if (Texture) {
    Material.setTexture(0, Texture);
  }
}

CPicture::~CPicture()
{

}

}
}
