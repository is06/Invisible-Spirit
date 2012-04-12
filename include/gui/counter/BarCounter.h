/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_BAR_COUNTER_H__
#define __IS06_BAR_COUNTER_H__

#include "Counter.h"
#include "../../enums/styles/BarStyle.h"

namespace is06
{
namespace hud
{

class CBarCounter : public CCounter
{
  public:
    CBarCounter(irr::s32 init = 0, irr::s32 min = 0, irr::s32 max = 1000, irr::f32 x = 0, irr::f32 y = 0, irr::f32 w = 150, irr::f32 h = 10, EBarStyle style = BAR_STYLE_DEFAULT);
    virtual ~CBarCounter();

    virtual void render();

    virtual void hide();
    virtual void show();
    virtual void setOpacity(irr::u8 value);

    void setPosition(irr::f32 x, irr::f32 y);
    void setX(irr::f32 value);
    void setY(irr::f32 value);

  protected:
    CPicture* Bar;
    CPicture* Sub;

    irr::s32 OldValue;
    irr::f32 BehindValue;
    irr::f32 InitWidth;
    irr::f32 InitX;
    irr::f32 InitY;
    irr::f32 DecreaseFactor;
    irr::f32 DecreaseTimer;

    bool Animate;
    bool Decrease;
};

}
}

#endif
