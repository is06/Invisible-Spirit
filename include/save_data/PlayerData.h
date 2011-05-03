/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_PLAYER_DATA_H__
#define __IS06_PLAYER_DATA_H__

using namespace irr;
using namespace std;

struct PlayerData {
  u8 currentLevel;
  u16 currentHP;
  u16 maxHP;
  u16 currentMP;
  u16 maxMP;
  u32 currentExp;
  u32 nextLevel;

  u8 strength;
  u8 defense;
  u8 magic;
  u8 resistance; // (Defmag)
  u8 precision;
  u8 speed;
};

#endif
