/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/Engine/core.h"
#include "../../include/3D/CCamera.h"
#include "../../include/Sound/CSoundManager.h"

namespace is06
{
namespace NSound
{

//! Constructor, initializes FMOD system with 3D settings
CSoundManager::CSoundManager()
{
  FMOD_System_Create(&System);
  FMOD_System_Init(System, 4, FMOD_INIT_NORMAL, NULL);
  FMOD_System_Set3DSettings(System, 1.0f, 1.0f, 1.0f);
}

//! Called by the Game main loop, this converts camera's position and rotation to FMOD vector format and store them into sound manager
void CSoundManager::setEarsData(N3D::CCamera* activeCamera)
{
  core::vector3df position = activeCamera->getNode()->getAbsolutePosition();
  //core::vector3df rotation = activeCamera->getNode()->getRotation();
  //core::vector3df lastPosition = activeCamera->getLastPosition();
  core::vector3df forward = activeCamera->getNode()->getTarget() - position;
  forward.normalize();
  core::vector3df up = activeCamera->getNode()->getUpVector();

  CameraPosition.x = position.X;
  CameraPosition.y = position.Y;
  CameraPosition.z = position.Z;

  CameraForward.x = forward.X;
  CameraForward.y = forward.Y;
  CameraForward.z = forward.Z;

  CameraUp.x = up.X;
  CameraUp.y = up.Y;
  CameraUp.z = up.Z;

/*
  //@todo : for doppler effect, check and fix this calculation
  CameraVelocity.x = (position.X - lastPosition.X) / cycleTime;
  CameraVelocity.y = (position.Y - lastPosition.Y) / cycleTime;
  CameraVelocity.z = (position.Z - lastPosition.Z) / cycleTime;
*/
}

//! Updates the FMOD system for 3D sound positions
void CSoundManager::update()
{
  FMOD_RESULT result = FMOD_System_Set3DListenerAttributes(System, 0, &CameraPosition, NULL, &CameraForward, &CameraUp);
  if (result != FMOD_OK) {
    cout << "[FMOD] 3D update error" << endl;
  }
  FMOD_System_Update(System);
}

//! Returns the FMOD system pointer
FMOD_SYSTEM* CSoundManager::getSystem()
{
  return System;
}

//! Destructor, releases FMOD System pointer
CSoundManager::~CSoundManager()
{
  FMOD_System_Close(System);
  FMOD_System_Release(System);
}

}
}
