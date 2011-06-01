/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_SOUND_MANAGER_H__
#define __IS06_SOUND_MANAGER_H__

using namespace irr;
using namespace std;

class SoundManager {
  public:
    SoundManager();
    ~SoundManager();

    void setEarsData(Camera* activeCamera, f32 cycleTime);
    void update();

    FMOD_SYSTEM* getSystem();

  private:
    FMOD_SYSTEM* sys;

    FMOD_VECTOR cameraPosition;
    FMOD_VECTOR cameraVelocity;
    FMOD_VECTOR cameraForward;
    FMOD_VECTOR cameraUp;
};

#endif
