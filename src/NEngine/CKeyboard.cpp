/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/core.h"
#include "../../../include/NEngine/NControl/CKeyboard.h"
#include "../../../include/NEngine/NCore/CGame.h"
#include "../../../include/NEngine/NEvent/CEventManager.h"

namespace is06 { namespace NEngine { namespace NControl {

//! Tests if a specific key is pressed
/**
 * \param EKEY_CODE code
 * \param EventType type
 */
bool CKeyboard::pressed(EKEY_CODE code, NEvent::EEventType type)
{
  if (type == NEvent::EET_ONCE) {
    return NCore::CGame::getEventManager()->isKeyDownOnce(code);
  } else {
    return NCore::CGame::getEventManager()->isKeyDown(code);
  }
}

//! Tests if any key is pressed
/**
 * \param EventType type
 */
bool CKeyboard::any(EEventType type)
{
  if (type == EET_ONCE) {
    return NCore::CGame::getEventManager()->anyKeyDownOnce();
  } else {
    return NCore::CGame::getEventManager()->anyKeyDown();
  }
}

//! Returns the joystick equivalent of the X axis from the arrows
s8 CKeyboard::getDirectionXAxis()
{
  if (NCore::CGame::getEventManager()->isKeyDown(KEY_LEFT)) {
    if (NCore::CGame::getEventManager()->isKeyDown(KEY_UP)) {
      // UP LEFT
      DirectionAngle = 135.0f;
      return -87;
    } else if (NCore::CGame::getEventManager()->isKeyDown(KEY_DOWN)) {
      // DOWN LEFT
      DirectionAngle = 225.0f;
      return -87;
    } else {
      // LEFT
      DirectionAngle = 180.0f;
      return -127;
    }
  } else if (NCore::CGame::getEventManager()->isKeyDown(KEY_RIGHT)) {
    if (NCore::CGame::getEventManager()->isKeyDown(KEY_UP)) {
      // UP RIGHT
      DirectionAngle = 45.0f;
      return 87;
    } else if (NCore::CGame::getEventManager()->isKeyDown(KEY_DOWN)) {
      // DOWN RIGHT
      DirectionAngle = 315.0f;
      return 87;
    } else {
      // RIGHT
      DirectionAngle = 0.0f;
      return 127;
    }
  } else {
    return 0;
  }
}

//! Returns the joystick equivalent of the Y axis from the arrows
s8 CKeyboard::getDirectionYAxis()
{
  if (NCore::CGame::getEventManager()->isKeyDown(KEY_UP)) {
    if (NCore::CGame::getEventManager()->isKeyDown(KEY_LEFT)) {
      // UP LEFT
      DirectionAngle = 135.0f;
      return 87;
    } else if (NCore::CGame::getEventManager()->isKeyDown(KEY_RIGHT)) {
      // UP RIGHT
      DirectionAngle = 45.0f;
      return 87;
    } else {
      // UP
      DirectionAngle = 90.0f;
      return 127;
    }
  } else if (NCore::CGame::getEventManager()->isKeyDown(KEY_DOWN)) {
    if (NCore::CGame::getEventManager()->isKeyDown(KEY_LEFT)) {
      // DOWN LEFT
      DirectionAngle = 225.0f;
      return -87;
    } else if (NCore::CGame::getEventManager()->isKeyDown(KEY_RIGHT)) {
      // DOWN RIGHT
      DirectionAngle = 315.0f;
      return -87;
    } else {
      // DOWN
      DirectionAngle = 270.0f;
      return -127;
    }
  } else {
    return 0;
  }
}

//! Returns the joystick equivalent of the direction angle from the arrows
f32 CKeyboard::getDirectionAngle()
{
  return DirectionAngle;
}

}}}
