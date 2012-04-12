/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_KEYBOARD_H__
#define __IS06_KEYBOARD_H__

#include "enums/engine/EventType.h"

namespace is06
{
namespace engine
{

class CKeyboard
{
  public:
    bool pressed(irr::EKEY_CODE code, EEventType type = EVENT_ALWAYS);
    bool any(EEventType type = EVENT_ALWAYS);
    irr::s8 getDirectionXAxis();
    irr::s8 getDirectionYAxis();
    irr::f32 getDirectionAngle();

  private:
    irr::f32 DirectionAngle;
};

}
}

#endif
