/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_MUSIC_REFERENCE_H__
#define __IS06_MUSIC_REFERENCE_H__

#include "MusicInfo.h"

namespace is06
{
namespace sound
{

//! Interface for playing music in scenes or maps
class CMusicReference
{
  public:
    CMusicReference();
    ~CMusicReference();

    void play(const string& id);
    void stop();

    void muteSequence(const string& id, u16 number);
    void unmuteSequence(const string& id, u16 number);

    CMusic* getCurrentMusic();

  private:
    string CurrentId;
    CMusic* CurrentMusic;
    map<string, SMusicInfo> MusicList;
};

}
}

#endif
