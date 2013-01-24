/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_MUSIC_SEQUENCE_H__
#define __IS06_MUSIC_SEQUENCE_H__

#include "SMusicSequenceInfo.h"

namespace is06
{
namespace NSound
{

//! A music sequence element
class CMusicSequence
{
  public:
    CMusicSequence(const SMusicSequenceInfo& info);
    ~CMusicSequence();

    void play();
    void setVolume(f32 value);

  private:
    FMOD_CHANNEL* ChannelPtr;
    FMOD_SOUND* SoundPtr;
};

}
}

#endif
