/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_GAME_TIME_COUNTER_H__
#define __IS06_GAME_TIME_COUNTER_H__

#include "Counter.h"

namespace is06
{
namespace hud
{

class CGameTimeCounter : public CCounter
{
  public:
    CGameTimeCounter();
    ~CGameTimeCounter();

    void render();
    void render(irr::s32 totalGameTime);
    void hide();
    void show();
    void setOpacity(irr::u8 value);

  private:
    std::string Seconds;
    std::string Minutes;
    std::string Hours;
    std::ostringstream Oss;

    CText* CounterText;

    void updateValues(irr::s32 time);
    void updateDigits();
};

}
}

#endif
