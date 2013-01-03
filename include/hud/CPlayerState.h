/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_PLAYER_STATE_H__
#define __IS06_PLAYER_STATE_H__

#include "CHud.h"

namespace is06
{
namespace nHud
{

class CPlayerState : public CHud
{
  public:
    CPlayerState();
    ~CPlayerState();

    void render();
    void show();
    void hide();
    void setOpacity(u8 value);

  private:
    CText* PlayerName;
    CText* LevelLabel;
    CText* LevelInfo;

    CPlayerStateMainInfo* HpInfo;
    CPlayerStateMainInfo* ExpInfo;
    CPlayerStateMainInfo* NextLevelInfo;

    CPlayerStateCapacity* StrengthInfo;
    CPlayerStateCapacity* DefenseInfo;
    CPlayerStateCapacity* MagicInfo;
    CPlayerStateCapacity* ConcInfo;
    CPlayerStateCapacity* PrecInfo;
    CPlayerStateCapacity* SpeedInfo;
};

}
}

#endif
