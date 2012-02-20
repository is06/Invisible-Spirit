/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_MUSIC_REFERENCE_H__
#define __IS06_MUSIC_REFERENCE_H__

#include "MusicInfo.h"

using namespace irr;
using namespace std;

class MusicReference
{
  public:
    MusicReference();
    ~MusicReference();

    void play(const string& id);
    void stop();

    void muteSequence(const string& id, u8 number);
    void soloSequence(const string& id, u8 number);

    Music* getCurrentMusic();

  private:
    string currentId;
    Music* currentMusic;
    map<string, MusicInfo> musicList;
};

#endif
