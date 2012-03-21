/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/3d/Light.h"
#include "../../include/Game.h"

using namespace irr;
using namespace std;

Light::Light() : Entity()
{
  video::ITexture* iconTexture = Game::getVideoDriver()->getTexture("resource/debug/icons/light.bmp");
  node = Game::getSceneManager()->addLightSceneNode(0, core::vector3df(0,2,0), video::SColor(255,255,200,0), 10.0f);

  icon = Game::getSceneManager()->addBillboardSceneNode(0, core::dimension2df(1.0f, 1.0f), core::vector3df(0,2,0));
  icon->setMaterialTexture(0, iconTexture);
}

void Light::update()
{
  //Entity::update();
}

Light::~Light()
{
  node->remove();
  icon->remove();
}
