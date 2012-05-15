/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/core.h"
#include "../../include/engine/CGame.h"
#include "../../include/sound/CMusicSequence.h"
#include "../../include/sound/CSoundManager.h"

namespace is06
{
namespace nSound
{

CMusicSequence::CMusicSequence(const SMusicSequenceInfo& info)
{
  string filePath("resource/music/");
  filePath += info.FileName;

  if (info.Looped) {
    FMOD_System_CreateStream(nEngine::CGame::getSoundManager()->getSystem(), filePath.c_str(), FMOD_HARDWARE | FMOD_LOOP_NORMAL, 0, &SoundPtr);
    FMOD_Sound_SetLoopPoints(SoundPtr, info.LoopStart, FMOD_TIMEUNIT_MS, info.LoopEnd, FMOD_TIMEUNIT_MS);
  } else {
    FMOD_System_CreateStream(nEngine::CGame::getSoundManager()->getSystem(), filePath.c_str(), FMOD_HARDWARE | FMOD_LOOP_OFF, 0, &SoundPtr);
  }
}

void CMusicSequence::play()
{
  FMOD_System_PlaySound(nEngine::CGame::getSoundManager()->getSystem(), FMOD_CHANNEL_FREE, SoundPtr, 0, &ChannelPtr);
}

void CMusicSequence::setVolume(f32 value)
{
  if (value >= 0.0f && value <= 1.0f) {
    FMOD_Channel_SetVolume(ChannelPtr, value);
  }
}

CMusicSequence::~CMusicSequence()
{
  FMOD_Sound_Release(SoundPtr);
}

}
}