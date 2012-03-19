/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_PLAYER_STATE_H__
#define __IS06_PLAYER_STATE_H__

#include "../Hud.h"

using namespace irr;
using namespace std;

class PlayerState : public Hud
{
  public:
    PlayerState();
    ~PlayerState();

    void render();

  private:
    Text* playerName;
    Text* levelLabel;
    Text* levelInfo;

    MainStateInfo* hpInfo;
    MainStateInfo* mpInfo;
    MainStateInfo* expInfo;
    MainStateInfo* nextLevelInfo;

    CapacityInfo* strengthInfo;
    CapacityInfo* defenseInfo;
    CapacityInfo* magicInfo;
    CapacityInfo* concInfo;
    CapacityInfo* precInfo;
    CapacityInfo* speedInfo;
};

#endif
