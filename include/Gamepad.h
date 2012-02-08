/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef GAMEPAD_H
#define GAMEPAD_H

#include "enums/control/GamepadDirection.h"
#include "enums/engine/EventType.h"

using namespace irr;
using namespace std;

typedef map<u16, bool> GamepadButtonMap;
typedef map<GamepadDirection, bool> GamepadDirectionMap;

class Gamepad
{
  public:
    Gamepad();

    u8 getLeftJoystickForce();
    f32 getLeftJoystickAngle();
    s8 getLeftJoystickXAxis();
    s8 getLeftJoystickYAxis();

    u8 getRightJoystickForce();
    f32 getRightJoystickAngle();
    s8 getRightJoystickXAxis();
    s8 getRightJoystickYAxis();

    bool buttonPressed(u16 buttons, EventType type = EVENT_ALWAYS);
    bool dirPressed(GamepadDirection direction, EventType type = EVENT_ALWAYS);

  private:
    GamepadButtonMap buttonOnce;
    GamepadDirectionMap directionOnce;
};

#endif
