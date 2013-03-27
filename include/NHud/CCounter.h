/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_HUD_COUNTER_COUNTER_H__
#define __IS06_HUD_COUNTER_COUNTER_H__

#include "CHud.h"

namespace is06 { namespace NHud { namespace NCounter {

//! Abstract base class for hud counters
class CCounter : public CHud
{
public:
  CCounter(s32 init = 0, s32 min = 0, s32 max = 1000);
  virtual ~CCounter();

  virtual void render() = 0;

  virtual void hide() = 0;
  virtual void show() = 0;
  virtual void setOpacity(f32 value) = 0;
  virtual void addOpacity(f32 value) = 0;
  virtual void subOpacity(f32 value) = 0;
  virtual f32 getOpacity() = 0;

  void addValue(s32 val);
  void subValue(s32 val);
  void setValue(s32 val);

  void setMin(s32 val);
  void setMax(s32 val);

  s32 getValue();
  s32 getMin();
  s32 getMax();

protected:
  s32 CurrentValue;
  s32 MaxValue;
  s32 MinValue;
};

}}}

#endif
