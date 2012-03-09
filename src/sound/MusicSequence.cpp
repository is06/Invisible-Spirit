/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/sound/MusicSequence.h"
#include "../../include/sound/SoundManager.h"
#include "../../include/Game.h"

using namespace std;
using namespace irr;

MusicSequence::MusicSequence(const MusicSequenceInfo& info)
{
  string filePath("resource/music/");
  filePath += info.fileName;

  if (info.looped) {
    FMOD_System_CreateStream(Game::getSoundManager()->getSystem(), filePath.c_str(), FMOD_HARDWARE | FMOD_LOOP_NORMAL, 0, &soundPtr);
    FMOD_Sound_SetLoopPoints(soundPtr, info.loopStart, FMOD_TIMEUNIT_MS, info.loopEnd, FMOD_TIMEUNIT_MS);
  } else {
    FMOD_System_CreateStream(Game::getSoundManager()->getSystem(), filePath.c_str(), FMOD_HARDWARE | FMOD_LOOP_OFF, 0, &soundPtr);
  }
}

void MusicSequence::play()
{
  FMOD_System_PlaySound(Game::getSoundManager()->getSystem(), FMOD_CHANNEL_FREE, soundPtr, 0, &channelPtr);
}

void MusicSequence::setVolume(f32 value)
{
  if (value >= 0.0f && value <= 1.0f) {
    FMOD_Channel_SetVolume(channelPtr, value);
  }
}

MusicSequence::~MusicSequence()
{
  FMOD_Sound_Release(soundPtr);
}
