/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/core.h"
#include "../../include/engine/Keyboard.h"
#include "../../include/engine/Game.h"
#include "../../include/engine/EventManager.h"

namespace is06
{
namespace nEngine
{

//! Tests if a specific key is pressed
/**
 * \param EKEY_CODE code
 * \param EventType type
 */
bool CKeyboard::pressed(EKEY_CODE code, nEngine::EEventType type)
{
  if (type == EVENT_ONCE) {
    return CGame::getEventManager()->isKeyDownOnce(code);
  } else {
    return CGame::getEventManager()->isKeyDown(code);
  }
}

//! Tests if any key is pressed
/**
 * \param EventType type
 */
bool CKeyboard::any(EEventType type)
{
  if (type == EVENT_ONCE) {
    return CGame::getEventManager()->anyKeyDownOnce();
  } else {
    return CGame::getEventManager()->anyKeyDown();
  }
}

//! Returns the joystick equivalent of the X axis from the arrows
s8 CKeyboard::getDirectionXAxis()
{
  if (CGame::getEventManager()->isKeyDown(KEY_LEFT)) {
    if (CGame::getEventManager()->isKeyDown(KEY_UP)) {
      DirectionAngle = 135.0f;
      return -87;
    } else if (CGame::getEventManager()->isKeyDown(KEY_DOWN)) {
      DirectionAngle = 225.0f;
      return -87;
    } else {
      DirectionAngle = 180.0f;
      return -127;
    }
  } else if (CGame::getEventManager()->isKeyDown(KEY_RIGHT)) {
    if (CGame::getEventManager()->isKeyDown(KEY_UP)) {
      DirectionAngle = 45.0f;
      return 87;
    } else if (CGame::getEventManager()->isKeyDown(KEY_DOWN)) {
      DirectionAngle = 315.0f;
      return 87;
    } else {
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
  if (CGame::getEventManager()->isKeyDown(KEY_UP)) {
    if (CGame::getEventManager()->isKeyDown(KEY_LEFT)) {
      DirectionAngle = 135.0f;
      return 87;
    } else if (CGame::getEventManager()->isKeyDown(KEY_RIGHT)) {
      DirectionAngle = 45.0f;
      return 87;
    } else {
      DirectionAngle = 90.0f;
      return 127;
    }
  } else if (CGame::getEventManager()->isKeyDown(KEY_DOWN)) {
    if (CGame::getEventManager()->isKeyDown(KEY_LEFT)) {
      DirectionAngle = 225.0f;
      return -87;
    } else if (CGame::getEventManager()->isKeyDown(KEY_RIGHT)) {
      DirectionAngle = 315.0f;
      return -87;
    } else {
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

}
}