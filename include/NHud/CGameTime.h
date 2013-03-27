/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_HUD_COUNTER_GAME_TIME_H__
#define __IS06_HUD_COUNTER_GAME_TIME_H__

#include "../CCounter.h"

namespace is06 { namespace NHud { namespace NCounter {

//! A total game time counter in the main gameplay menu
class CGameTime : public CCounter
{
public:
  CGameTime();
  ~CGameTime();

  void render();
  void render(s32 totalGameTime);
  void hide();
  void show();
  void setOpacity(f32 value);
  void addOpacity(f32 value);
  void subOpacity(f32 value);
  f32 getOpacity();

private:
  string Seconds;
  string Minutes;
  string Hours;
  ostringstream Oss;

  CText* CounterText;

  void updateValues(s32 time);
  void updateDigits();
};

}}}

#endif
