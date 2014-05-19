/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_HUD_PLAYER_STATE_PLAYER_STATE_H__
#define __IS06_HUD_PLAYER_STATE_PLAYER_STATE_H__

#include "../NCore/CHudEntity.h"

namespace is06 { namespace NHud { namespace NPlayerState {

//! All player information
class CPlayerState : public NCore::CHudEntity
{
public:
  CPlayerState();
  ~CPlayerState();

  void render();
  void show();
  void hide();
  void setOpacity(f32 value);
  void addOpacity(f32 value);
  void subOpacity(f32 value);
  f32 getOpacity();

private:
  NText::CText* PlayerName;
  NText::CText* LevelLabel;
  NText::CText* LevelInfo;

  NPlayerState::CMainInfo* HpInfo;
  NPlayerState::CMainInfo* ExpInfo;
  NPlayerState::CMainInfo* NextLevelInfo;

  NPlayerState::CCapacity* StrengthInfo;
  NPlayerState::CCapacity* DefenseInfo;
  NPlayerState::CCapacity* MagicInfo;
  NPlayerState::CCapacity* ConcInfo;
  NPlayerState::CCapacity* PrecInfo;
  NPlayerState::CCapacity* SpeedInfo;

  f32 Opacity;
};

}}}

#endif
