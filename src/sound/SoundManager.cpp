/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"

SoundManager::SoundManager() {
  //FMOD_System_Create(&sys);
  //FMOD_System_Init(sys, 4, FMOD_INIT_NORMAL, NULL);
}

void SoundManager::loadSFX(SoundEffectIdentifier soundId) {

}

void SoundManager::playSFX(SoundEffectIdentifier soundId) {

}

void SoundManager::playMusic(MusicIdentifier musicId) {

}

void SoundManager::changeMusicSequence(MusicIdentifier musicId, u8 sequenceId) {

}

void SoundManager::toggleMusicLayer(MusicIdentifier musicId, u8 layerId) {

}

void SoundManager::setMusicLayerState(MusicIdentifier musicId, u8 layerId, bool active) {

}

bool SoundManager::getMusicLayerState(MusicIdentifier musicId, u8 layerId) {

}

SoundManager::~SoundManager() {
  //FMOD_System_Release(sys);
}
