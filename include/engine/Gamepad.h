/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_GAMEPAD_H__
#define __IS06_GAMEPAD_H__

#include "GamepadDirection.h"
#include "EventType.h"

namespace is06
{
namespace engine
{

typedef map<u16, bool> TGamepadButtonMap;
typedef map<EGamepadDirection, bool> TGamepadDirectionMap;

class CGamepad
{
  public:
    CGamepad();

    u8 getLeftJoystickForce();
    f32 getLeftJoystickAngle();
    s8 getLeftJoystickXAxis();
    s8 getLeftJoystickYAxis();

    u8 getRightJoystickForce();
    f32 getRightJoystickAngle();
    s8 getRightJoystickXAxis();
    s8 getRightJoystickYAxis();

    bool buttonPressed(u16 buttons, engine::EEventType type = engine::EVENT_ALWAYS);
    bool dirPressed(EGamepadDirection direction, engine::EEventType type = engine::EVENT_ALWAYS);

  private:
    TGamepadButtonMap ButtonOnce;
    TGamepadDirectionMap DirectionOnce;
};

}
}

#endif
