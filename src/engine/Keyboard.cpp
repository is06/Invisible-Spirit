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

/**
 * Permet de savoir si une touche spécifique est pressée
 * @param EKEY_CODE code le code de la touche à tester
 * @param EventType type le type d'événement entre ONCE et ALWAYS
 */
bool CKeyboard::pressed(EKEY_CODE code, nEngine::EEventType type)
{
  if (type == EVENT_ONCE) {
    return CGame::getEventManager()->isKeyDownOnce(code);
  } else {
    return CGame::getEventManager()->isKeyDown(code);
  }
}

/**
 * Permet de savoir si n'importe quelle touche est pressée
 * @param EventType type le type d'événement entre ONCE et ALWAYS
 */
bool CKeyboard::any(EEventType type)
{
  if (type == EVENT_ONCE) {
    return CGame::getEventManager()->anyKeyDownOnce();
  } else {
    return CGame::getEventManager()->anyKeyDown();
  }
}

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

f32 CKeyboard::getDirectionAngle()
{
  return DirectionAngle;
}

}
}
