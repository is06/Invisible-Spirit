/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/Engine/core.h"
#include "../../include/Engine/CGame.h"
#include "../../include/Engine/Resource/CResourceManager.h"
#include "../../include/Hud/CPicture.h"

namespace is06
{
namespace NHud
{

CPicture::CPicture(f32 x, f32 y, f32 w, f32 h, const string& filePath, bool useAlphaBlending) : CFlatElement(x, y, w, h, useAlphaBlending)
{
  changeTexture(filePath);
}

void CPicture::render()
{
  CFlatElement::render();
}

void CPicture::loadSecondTexture(const string& filePath)
{
  video::ITexture* second = NEngine::NResource::CResourceManager::loadTexture(filePath);
  if (second) {
    Material.setTexture(1, second);
  }
}

void CPicture::changeTexture(const string& filePath)
{
  Texture = NEngine::NResource::CResourceManager::loadTexture(filePath);
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