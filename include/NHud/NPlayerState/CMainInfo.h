/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_HUD_PLAYER_STATE_MAIN_INFO_H__
#define __IS06_HUD_PLAYER_STATE_MAIN_INFO_H__

#include "../NCore/CHudEntity.h"

namespace is06 { namespace NHud { namespace NPlayerState {

//! A player main information (name, level, HP...)
class CMainInfo : public NCore::CHudEntity
{
public:
  CMainInfo();
  ~CMainInfo();

  void render();
  void show();
  void hide();
  void setOpacity(f32 value);
  void addOpacity(f32 value);
  void subOpacity(f32 value);
  f32 getOpacity();

private:
  NText::CText* Label;
  NText::CText* Info;
  NCounter::CBarMeter* Gauge;
  f32 Opacity;
};

}}}

#endif
