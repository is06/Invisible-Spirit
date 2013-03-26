/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/core.h"
#include "../../../include/NEngine/NCore/CGame.h"
#include "../../../include/NEngine/NResource/CResourceManager.h"
#include "../../../include/N3D/NLight/CLight.h"

namespace is06 { namespace N3D { namespace NLight {

using is06::NEngine::NCore::CGame;
using is06::NEngine::NResource::CResourceManager;

//! Constructor
CLight::CLight() : NEngine::NCore::CEntity()
{
  video::ITexture* iconTexture = CResourceManager::loadTexture("resource/debug/icons/light.bmp");
  Node = CGame::getSceneManager()->addLightSceneNode(0, core::vector3df(0,2,0), video::SColor(255,255,200,0), 10.0f);

  Icon = CGame::getSceneManager()->addBillboardSceneNode(0, core::dimension2df(1.0f, 1.0f), core::vector3df(0,2,0));
  Icon->setMaterialTexture(0, iconTexture);
}

//! Update method, called every cycle for event testing
void CLight::update()
{

}

//! Destructor
CLight::~CLight()
{
  Node->remove();
  Icon->remove();
}

}}}
