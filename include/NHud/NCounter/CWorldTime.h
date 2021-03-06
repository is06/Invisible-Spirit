/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_HUD_COUNTER_WORLD_TIME_H__
#define __IS06_HUD_COUNTER_WORLD_TIME_H__

#include "CCounter.h"

namespace is06 { namespace NHud { namespace NCounter {

//! Clock counter for time in the story
class CWorldTime : public CCounter
{
public:
  CWorldTime();
  ~CWorldTime();

  void render();
  void render(s32 worldTime);
  void hide();
  void show();
  void setOpacity(f32 value);
  void addOpacity(f32 value);
  void subOpacity(f32 value);
  f32 getOpacity();

private:
  string Minutes;
  string Hours;

  NText::CText* CounterText;

  void updateValues(s32 time);
  void updateDigits();
};

}}}

#endif

