/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/core.h"
#include "../../include/engine/Game.h"
#include "../../include/model/Light.h"

namespace is06
{
namespace model
{

CLight::CLight() : engine::CEntity()
{
  video::ITexture* iconTexture = engine::CGame::getVideoDriver()->getTexture("resource/debug/icons/light.bmp");
  Node = engine::CGame::getSceneManager()->addLightSceneNode(0, core::vector3df(0,2,0), video::SColor(255,255,200,0), 10.0f);

  Icon = engine::CGame::getSceneManager()->addBillboardSceneNode(0, core::dimension2df(1.0f, 1.0f), core::vector3df(0,2,0));
  Icon->setMaterialTexture(0, iconTexture);
}

void CLight::update()
{
  //Entity::update();
}

CLight::~CLight()
{
  Node->remove();
  Icon->remove();
}

}
}
