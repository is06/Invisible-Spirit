/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/core.h"
#include "../../include/engine/CGame.h"
#include "../../include/engine/CResourceManager.h"
#include "../../include/3d/CLight.h"

namespace is06
{
namespace n3D
{

CLight::CLight() : nEngine::CEntity()
{
  video::ITexture* iconTexture = nEngine::CResourceManager::loadTexture("resource/debug/icons/light.bmp");
  Node = nEngine::CGame::getSceneManager()->addLightSceneNode(0, core::vector3df(0,2,0), video::SColor(255,255,200,0), 10.0f);

  Icon = nEngine::CGame::getSceneManager()->addBillboardSceneNode(0, core::dimension2df(1.0f, 1.0f), core::vector3df(0,2,0));
  Icon->setMaterialTexture(0, iconTexture);
}

void CLight::update()
{

}

CLight::~CLight()
{
  Node->remove();
  Icon->remove();
}

}
}
