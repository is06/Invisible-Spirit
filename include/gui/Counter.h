/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_COUNTER_H__
#define __IS06_COUNTER_H__

#include "Hud.h"

using namespace std;
using namespace irr;

class Counter : public Hud
{
  public:
    Counter(s32 init = 0, s32 min = 0, s32 max = 1000);
    virtual ~Counter();

    virtual void render() = 0;

    virtual void hide() = 0;
    virtual void show() = 0;
    virtual void setOpacity(u8 value) = 0;

    void addValue(s32 val);
    void subValue(s32 val);
    void setValue(s32 val);

    void setMin(s32 val);
    void setMax(s32 val);

    s32 getValue();
    s32 getMin();
    s32 getMax();

  protected:
    s32 currentValue;
    s32 maxValue;
    s32 minValue;
};

#endif
