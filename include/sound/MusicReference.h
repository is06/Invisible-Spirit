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

class CMusicReference
{
  public:
    CMusicReference();
    ~CMusicReference();

    void play(const std::string& id);
    void stop();

    void muteSequence(const std::string& id, irr::u16 number);
    void unmuteSequence(const std::string& id, irr::u16 number);

    CMusic* getCurrentMusic();

  private:
    std::string CurrentId;
    CMusic* CurrentMusic;
    std::map<std::string, SMusicInfo> MusicList;
};

}
}

#endif
