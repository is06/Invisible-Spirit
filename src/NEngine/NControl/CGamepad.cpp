/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/core.h"
#include "../../../include/NEngine/NCore/CGame.h"
#include "../../../include/NEngine/NControl/CGamepad.h"
#include "../../../include/NEngine/NEvent/CEventManager.h"

using namespace irr;

namespace is06 { namespace NEngine { namespace NControl {

//! Constructor
CGamepad::CGamepad()
{

}

//! Returns the left joystick strength
/**
 * \return u8
 */
u8 CGamepad::getLeftJoystickForce()
{
  return NEngine::NCore::CGame::getEventManager()->getLeftJoystickForce();
}

//! Returns the left joystick angle
/**
 * \return f32 in degrees
 */
f32 CGamepad::getLeftJoystickAngle()
{
  return NEngine::NCore::CGame::getEventManager()->getLeftJoystickAngle();
}

//! Returns the X axis value of the left joystick
/**
 * \return s8 between -128 (left) and 127 (right)
 */
s8 CGamepad::getLeftJoystickXAxis()
{
  return NEngine::NCore::CGame::getEventManager()->getLeftJoystickXAxis();
}

//! Returns the Y axis value of the left joystick
/**
 * \return s8 between -128 (down) and 127 (up)
 */
s8 CGamepad::getLeftJoystickYAxis()
{
  return NEngine::NCore::CGame::getEventManager()->getLeftJoystickYAxis();
}

//! Returns the right joystick strength
/**
 * \return u8
 */
u8 CGamepad::getRightJoystickForce()
{
  return NEngine::NCore::CGame::getEventManager()->getRightJoystickForce();
}

//! Returns the right joystick angle
/**
 * \return f32 in degrees
 */
f32 CGamepad::getRightJoystickAngle()
{
  return NEngine::NCore::CGame::getEventManager()->getRightJoystickAngle();
}

//! Returns the X axis value of the right joystick
/**
 * \return s8 between -128 (left) and 127 (right)
 */
s8 CGamepad::getRightJoystickXAxis()
{
  return NEngine::NCore::CGame::getEventManager()->getRightJoystickXAxis();
}

//! Returns the X axis value of the right joystick
/**
 * \return s8 between -128 (down) and 127 (up)
 */
s8 CGamepad::getRightJoystickYAxis()
{
  return NEngine::NCore::CGame::getEventManager()->getRightJoystickYAxis();
}

//! Tests if a button-combination is currently pressed
/**
 * \param u16 buttons specified in EGamepadButton enumeration
 * \return bool
 */
bool CGamepad::buttonPressed(u16 buttons, NEvent::EEventType type)
{
  if (type == NEvent::EET_ONCE) {
    if (!ButtonOnce[buttons]) {
      if (NEngine::NCore::CGame::getEventManager()->getPressedButtons() == buttons) {
        ButtonOnce[buttons] = true;
        return true;
      }
    } else {
      if (NEngine::NCore::CGame::getEventManager()->getPressedButtons() != buttons) {
        ButtonOnce[buttons] = false;
      }
    }
    return false;
  } else {
    return (NEngine::NCore::CGame::getEventManager()->getPressedButtons() == buttons);
  }
}

//! Test if a direction in the D-pad is pressed
/**
 * \param EGamepadDirection direction
 * \return bool
 */
bool CGamepad::dirPressed(EGamepadDirection direction, NEvent::EEventType type)
{
  if (type == NEvent::EET_ONCE) {
    if (!DirectionOnce[direction]) {
      if ((s32)NEngine::NCore::CGame::getEventManager()->getPovValue() == direction) {
        DirectionOnce[direction] = true;
        return true;
      }
    } else {
      if ((s32)NEngine::NCore::CGame::getEventManager()->getPovValue() != direction) {
        DirectionOnce[direction] = false;
      }
    }
    return false;
  } else {
    return ((s32)NEngine::NCore::CGame::getEventManager()->getPovValue() == direction);
  }
}

}}}
