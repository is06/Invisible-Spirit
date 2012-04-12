/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_GAMEPAD_H__
#define __IS06_GAMEPAD_H__

#include "enums/control/GamepadDirection.h"
#include "enums/engine/EventType.h"

namespace is06
{
namespace engine
{

typedef std::map<irr::u16, bool> GamepadButtonMap;
typedef std::map<EGamepadDirection, bool> GamepadDirectionMap;

class CGamepad
{
  public:
    CGamepad();

    irr::u8 getLeftJoystickForce();
    irr::f32 getLeftJoystickAngle();
    irr::s8 getLeftJoystickXAxis();
    irr::s8 getLeftJoystickYAxis();

    irr::u8 getRightJoystickForce();
    irr::f32 getRightJoystickAngle();
    irr::s8 getRightJoystickXAxis();
    irr::s8 getRightJoystickYAxis();

    bool buttonPressed(irr::u16 buttons, engine::EEventType type = engine::EVENT_ALWAYS);
    bool dirPressed(EGamepadDirection direction, engine::EEventType type = engine::EVENT_ALWAYS);

  private:
    GamepadButtonMap ButtonOnce;
    GamepadDirectionMap DirectionOnce;
};

}
}

#endif
