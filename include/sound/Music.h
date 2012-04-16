/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_MUSIC_H__
#define __IS06_MUSIC_H__

#include "MusicSequence.h"
#include "MusicSequenceInfo.h"

namespace is06
{
namespace nSound
{

//! A multi-layer music element that can contains one or more sequences
class CMusic
{
  public:
    CMusic(const string& id);
    ~CMusic();

    void playSequences(const map<u16, SMusicSequenceInfo>& list);
    void addSequences(const map<u16, SMusicSequenceInfo>& list);
    map<u16, CMusicSequence*>& getSequenceMap();
    CMusicSequence* getSequence(u16 number);

  private:
    map<u16, CMusicSequence*> Sequences;
};

}
}

#endif
