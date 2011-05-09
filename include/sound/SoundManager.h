/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

/**
 * Développé à l'aide du tutoriel de khayyam sur developpez.com :
 * http://khayyam.developpez.com/articles/cpp/fmodex/
 */

#ifndef __IS06_SOUND_MANAGER_H__
#define __IS06_SOUND_MANAGER_H__

class SoundManager {
  public:
    SoundManager();
    ~SoundManager();

    void loadSFX(SoundEffectIdentifier soundId);
    void playSFX(SoundEffectIdentifier soundId);
    void playMusic(MusicIdentifier musicId);
    void changeMusicSequence(MusicIdentifier musicId, u8 sequenceId);

    // Music Layers
    void toggleMusicLayer(MusicIdentifier musicId, u8 layerId);
    void setMusicLayerState(MusicIdentifier musicId, u8 layerId, bool active);
    bool getMusicLayerState(MusicIdentifier musicId, u8 layerId);

  private:
    //FMOD_SYSTEM* sys;
};

#endif
