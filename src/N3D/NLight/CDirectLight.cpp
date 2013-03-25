/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/Engine/core.h"
#include "../../../include/Engine/CGame.h"
#include "../../../include/3D/Light/CDirect.h"

namespace is06 { namespace N3D { namespace NLight {

//! Constructor
CDirect::CDirect()
{
  Camera = NEngine::CGame::getSceneManager()->addCameraSceneNode();
}

//! Creates a direct light and add it to the shadow processor
CDirect* CDirect::create()
{
  // TODO: Add to shadow processor (factory design pattern)
  CDirect* obj = new CDirect();
  return obj;
}

//! Destructor
CDirect::~CDirect()
{
  Camera->remove();
}

}}}
