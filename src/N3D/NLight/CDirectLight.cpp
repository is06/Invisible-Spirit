/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/core.h"
#include "../../../include/NEngine/NCore/CGame.h"
#include "../../../include/N3D/NLight/CDirectLight.h"

namespace is06 { namespace N3D { namespace NLight {

using is06::NEngine::NCore::CGame;

//! Constructor
CDirectLight::CDirectLight()
{
  Camera = CGame::getSceneManager()->addCameraSceneNode();
}

//! Destructor
CDirectLight::~CDirectLight()
{
  Camera->remove();
}

}}}
