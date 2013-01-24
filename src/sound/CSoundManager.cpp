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

CSoundManager::CSoundManager()
{
  FMOD_System_Create(&sys);
  FMOD_System_Init(sys, 4, FMOD_INIT_NORMAL, NULL);
  FMOD_System_Set3DSettings(sys, 1.0f, 1.0f, 1.0f);
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

  cameraPosition.x = position.X;
  cameraPosition.y = position.Y;
  cameraPosition.z = position.Z;

  cameraForward.x = forward.X;
  cameraForward.y = forward.Y;
  cameraForward.z = forward.Z;

  cameraUp.x = up.X;
  cameraUp.y = up.Y;
  cameraUp.z = up.Z;

/*
  //@todo : for doppler effect, check and fix this calculation
  cameraVelocity.x = (position.X - lastPosition.X) / cycleTime;
  cameraVelocity.y = (position.Y - lastPosition.Y) / cycleTime;
  cameraVelocity.z = (position.Z - lastPosition.Z) / cycleTime;
*/
}

void CSoundManager::update()
{
  FMOD_RESULT result = FMOD_System_Set3DListenerAttributes(sys, 0, &cameraPosition, NULL, &cameraForward, &cameraUp);
  if (result != FMOD_OK) {
    cout << "[FMOD] Erreur update 3D" << endl;
  }
  FMOD_System_Update(sys);
}

FMOD_SYSTEM* CSoundManager::getSystem()
{
  return sys;
}

CSoundManager::~CSoundManager()
{
  FMOD_System_Close(sys);
  FMOD_System_Release(sys);
}

}
}
