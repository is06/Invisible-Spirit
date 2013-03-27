/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_ENGINE_CONTROL_KEYBOARD_H__
#define __IS06_ENGINE_CONTROL_KEYBOARD_H__

#include "../NEvent/EEventType.h"

namespace is06 { namespace NEngine { namespace NControl {

//! Keyboard interface
class CKeyboard
{
public:
  bool pressed(EKEY_CODE code, NEvent::EEventType type = NEvent::EET_ALWAYS);
  bool any(NEvent::EEventType type = NEvent::EET_ALWAYS);
  s8 getDirectionXAxis();
  s8 getDirectionYAxis();
  f32 getDirectionAngle();

private:
  f32 DirectionAngle;
};

}}}

#endif
