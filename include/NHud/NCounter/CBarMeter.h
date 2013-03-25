/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_HUD_COUNTER_BAR_METER_H__
#define __IS06_HUD_COUNTER_BAR_METER_H__

#include "../CCounter.h"
#include "EBarStyle.h"

namespace is06 { namespace NHud { namespace NCounter {

//! A graphical horizontal bar counter with animation behaviors
class CBar : public CCounter
{
public:
  CBar(s32 init = 0, s32 min = 0, s32 max = 1000, f32 x = 0, f32 y = 0, f32 w = 150, f32 h = 10, EBarStyle style = EBS_DEFAULT);
  virtual ~CBar();

  virtual void render();

  virtual void hide();
  virtual void show();
  virtual void setOpacity(f32 value);
  virtual void addOpacity(f32 value);
  virtual void subOpacity(f32 value);
  virtual f32 getOpacity();

  void setPosition(f32 x, f32 y);
  void setX(f32 value);
  void setY(f32 value);

protected:
  CPicture* Bar;
  CPicture* Sub;

  s32 OldValue;
  f32 BehindValue;
  f32 InitWidth;
  f32 InitX;
  f32 InitY;
  f32 DecreaseFactor;
  f32 DecreaseTimer;

  bool Animate;
  bool Decrease;
};

}}}

#endif
