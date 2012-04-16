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
namespace nEngine
{

//! Boolean gamepad buttons map indexed by u16
typedef map<u16, bool> TGamepadButtonMap;
//! Boolean gamepad directions map indexed by EGamepadDirection
typedef map<EGamepadDirection, bool> TGamepadDirectionMap;

//! Interface for gamepad controls
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

    bool buttonPressed(u16 buttons, nEngine::EEventType type = nEngine::EVENT_ALWAYS);
    bool dirPressed(EGamepadDirection direction, nEngine::EEventType type = nEngine::EVENT_ALWAYS);

  private:
    TGamepadButtonMap ButtonOnce;
    TGamepadDirectionMap DirectionOnce;
};

}
}

#endif
