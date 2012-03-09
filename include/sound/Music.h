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

using namespace irr;
using namespace std;

class Music
{
  public:
    Music(const string& id);
    ~Music();

    void playSequences(const map<u16, MusicSequenceInfo>& list);
    void addSequences(const map<u16, MusicSequenceInfo>& list);
    map<u16, MusicSequence*>& getSequenceMap();
    MusicSequence* getSequence(u16 number);

  private:
    map<u16, MusicSequence*> sequences;
};

#endif
