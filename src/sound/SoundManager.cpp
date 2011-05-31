/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"

using namespace irr;
using namespace std;

SoundManager::SoundManager() {
  FMOD_System_Create(&sys);
  FMOD_System_Init(sys, 4, FMOD_INIT_NORMAL, NULL);

  FMOD_System_Set3DSettings(sys, 1.0f, 1.0f, 1.0f);

  FMOD_SOUND* sound;
  FMOD_CHANNEL* channel;
  FMOD_System_CreateStream(sys, "sp_a2_laser_chaining_b1.mp3", FMOD_HARDWARE | FMOD_LOOP_NORMAL | FMOD_2D, 0, &sound);
  FMOD_System_PlaySound(sys, FMOD_CHANNEL_FREE, sound, 0, &channel);
}

/**
 * Called by the Game main loop, this converts camera's position and rotation to
 * FMOD vector format and store them into sound manager
 */
void SoundManager::setEarsData(Camera* activeCamera, u32 cycleTime) {
  core::vector3df position = activeCamera->getNode()->getAbsolutePosition();
  core::vector3df rotation = activeCamera->getNode()->getRotation();
  core::vector3df lastPosition = activeCamera->getLastPosition();

  cameraPosition.x = position.X;
  cameraPosition.y = position.Y;
  cameraPosition.z = position.Z;

  cameraVelocity.x = (position.X - lastPosition.X) / cycleTime;
  cameraVelocity.y = (position.Y - lastPosition.Y) / cycleTime;
  cameraVelocity.z = (position.Z - lastPosition.Z) / cycleTime;
}

/**
 *
 */
void SoundManager::update() {
  FMOD_RESULT result = FMOD_System_Set3DListenerAttributes(sys, 0, &cameraPosition, &cameraVelocity, &cameraForward, &cameraUp);
  if(result != FMOD_OK) {
    cout << "[FMOD] Erreur update 3D" << endl;
  }
  FMOD_System_Update(sys);
}

SoundManager::~SoundManager() {
  FMOD_System_Close(sys);
  FMOD_System_Release(sys);
}
