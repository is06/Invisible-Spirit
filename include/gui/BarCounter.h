/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_BAR_COUNTER_H__
#define __IS06_BAR_COUNTER_H__

#include "Counter.h"

#include "../enums/styles/BarStyle.h"

class BarCounter : public Counter {
  public:
    BarCounter(s32 init = 0, s32 min = 0, s32 max = 1000, f32 x = 0, f32 y = 0, f32 w = 150, f32 h = 10, BarStyle style = BAR_STYLE_DEFAULT);
    virtual ~BarCounter();

    virtual void render();

    void setPosition(f32 x, f32 y);
    void setX(f32 value);
    void setY(f32 value);

  protected:
    Picture* bar;
    Picture* sub;

    s32 oldValue;
    f32 behindValue;
    f32 initWidth;
    f32 initX;
    f32 initY;
    f32 decreaseFactor;
    f32 decreaseTimer;

    bool animate;
    bool decrease;
};

#endif
