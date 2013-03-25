/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_SOUND_MANAGER_H__
#define __IS06_SOUND_MANAGER_H__

namespace is06 { namespace NSound {

//! The 3D sound manager for sound effects in space
class CSoundManager
{
public:
  CSoundManager();
  ~CSoundManager();

  void setEarsData(N3D::CCamera* activeCamera);
  void update();

  FMOD_SYSTEM* getSystem();

private:
  FMOD_SYSTEM* System;

  FMOD_VECTOR CameraPosition;
  FMOD_VECTOR CameraVelocity;
  FMOD_VECTOR CameraForward;
  FMOD_VECTOR CameraUp;
};

}}

#endif
