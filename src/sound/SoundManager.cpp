/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"

SoundManager::SoundManager() {
  /*
  FMOD_RESULT result = FMOD::System_Create(&sys);
  if(result != FMOD_OK) {
    cout << "[FMOD] System Creation failed" << endl;
  }
  result = system->init(100, FMOD_INIT_NORMAL, 0);
  if(result != FMOD_OK) {
    cout << "[FMOD] System Init failed" << endl;
  }
  */
}

/*
FMOD::System* SoundManager::getFMODSystem() {
  //return sys;
}
*/

SoundManager::~SoundManager() {
  /*
  FMOD_RESULT result = sys->release();
  if(result != FMOD_OK) {
    cout << "[FMOD] System release failed" << endl;
  }
  */
}
