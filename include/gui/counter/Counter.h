/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_COUNTER_H__
#define __IS06_COUNTER_H__

#include "../Hud.h"

namespace is06
{
namespace hud
{

class CCounter : public CHud
{
  public:
    CCounter(irr::s32 init = 0, irr::s32 min = 0, irr::s32 max = 1000);
    virtual ~CCounter();

    virtual void render() = 0;

    virtual void hide() = 0;
    virtual void show() = 0;
    virtual void setOpacity(irr::u8 value) = 0;

    void addValue(irr::s32 val);
    void subValue(irr::s32 val);
    void setValue(irr::s32 val);

    void setMin(irr::s32 val);
    void setMax(irr::s32 val);

    irr::s32 getValue();
    irr::s32 getMin();
    irr::s32 getMax();

  protected:
    irr::s32 CurrentValue;
    irr::s32 MaxValue;
    irr::s32 MinValue;
};

}
}

#endif
