/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_PLAYER_STATE_H__
#define __IS06_PLAYER_STATE_H__

#include "../Hud.h"

namespace is06
{
namespace hud
{

class CPlayerState : public CHud
{
  public:
    CPlayerState();
    ~CPlayerState();

    void render();
    void show();
    void hide();
    void setOpacity(irr::u8 value);

  private:
    CText* PlayerName;
    CText* LevelLabel;
    CText* LevelInfo;

    CMainStateInfo* HpInfo;
    CMainStateInfo* ExpInfo;
    CMainStateInfo* NextLevelInfo;

    CCapacityInfo* StrengthInfo;
    CCapacityInfo* DefenseInfo;
    CCapacityInfo* MagicInfo;
    CCapacityInfo* ConcInfo;
    CCapacityInfo* PrecInfo;
    CCapacityInfo* SpeedInfo;
};

}
}

#endif
