/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../include/ref/core.h"
#include "../include/Keyboard.h"
#include "../include/Game.h"
#include "../include/EventManager.h"

namespace is06
{
namespace engine
{

/**
 * Permet de savoir si une touche spécifique est pressée
 * @param EKEY_CODE code le code de la touche à tester
 * @param EventType type le type d'événement entre ONCE et ALWAYS
 */
bool CKeyboard::pressed(irr::EKEY_CODE code, engine::EEventType type)
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

irr::s8 CKeyboard::getDirectionXAxis()
{
  if (CGame::getEventManager()->isKeyDown(irr::KEY_LEFT)) {
    if (CGame::getEventManager()->isKeyDown(irr::KEY_UP)) {
      DirectionAngle = 135.0f;
      return -87;
    } else if (CGame::getEventManager()->isKeyDown(irr::KEY_DOWN)) {
      DirectionAngle = 225.0f;
      return -87;
    } else {
      DirectionAngle = 180.0f;
      return -127;
    }
  } else if (CGame::getEventManager()->isKeyDown(irr::KEY_RIGHT)) {
    if (CGame::getEventManager()->isKeyDown(irr::KEY_UP)) {
      DirectionAngle = 45.0f;
      return 87;
    } else if (CGame::getEventManager()->isKeyDown(irr::KEY_DOWN)) {
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

irr::s8 CKeyboard::getDirectionYAxis()
{
  if (CGame::getEventManager()->isKeyDown(irr::KEY_UP)) {
    if (CGame::getEventManager()->isKeyDown(irr::KEY_LEFT)) {
      DirectionAngle = 135.0f;
      return 87;
    } else if (CGame::getEventManager()->isKeyDown(irr::KEY_RIGHT)) {
      DirectionAngle = 45.0f;
      return 87;
    } else {
      DirectionAngle = 90.0f;
      return 127;
    }
  } else if (CGame::getEventManager()->isKeyDown(irr::KEY_DOWN)) {
    if (CGame::getEventManager()->isKeyDown(irr::KEY_LEFT)) {
      DirectionAngle = 225.0f;
      return -87;
    } else if (CGame::getEventManager()->isKeyDown(irr::KEY_RIGHT)) {
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

irr::f32 CKeyboard::getDirectionAngle()
{
  return DirectionAngle;
}

}
}
