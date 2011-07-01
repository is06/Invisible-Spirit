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

using namespace irr;

/**
 * Permet de savoir si une touche spécifique est pressée
 * @param EKEY_CODE code le code de la touche à tester
 * @param EventType type le type d'événement entre ONCE et ALWAYS
 */
bool Keyboard::pressed(EKEY_CODE code, EventType type) {
  if(type == EVENT_ONCE) {
    return Game::getEventManager()->isKeyDownOnce(code);
  } else {
    return Game::getEventManager()->isKeyDown(code);
  }
}

/**
 * Permet de savoir si n'importe quelle touche est pressée
 * @param EventType type le type d'événement entre ONCE et ALWAYS
 */
bool Keyboard::any(EventType type) {
  if(type == EVENT_ONCE) {
    return Game::getEventManager()->anyKeyDownOnce();
  } else {
    return Game::getEventManager()->anyKeyDown();
  }
}

s8 Keyboard::getDirectionXAxis() {
  if(Game::getEventManager()->isKeyDown(KEY_LEFT)) {
    if(Game::getEventManager()->isKeyDown(KEY_UP)) {
      directionAngle = 135.0f;
      return -87;
    } else if(Game::getEventManager()->isKeyDown(KEY_DOWN)) {
      directionAngle = 225.0f;
      return -87;
    } else {
      directionAngle = 180.0f;
      return -127;
    }
  } else if(Game::getEventManager()->isKeyDown(KEY_RIGHT)) {
    if(Game::getEventManager()->isKeyDown(KEY_UP)) {
      directionAngle = 45.0f;
      return 87;
    } else if(Game::getEventManager()->isKeyDown(KEY_DOWN)) {
      directionAngle = 315.0f;
      return 87;
    } else {
      directionAngle = 0.0f;
      return 127;
    }
  } else {
    return 0;
  }
}

s8 Keyboard::getDirectionYAxis() {
  if(Game::getEventManager()->isKeyDown(KEY_UP)) {
    if(Game::getEventManager()->isKeyDown(KEY_LEFT)) {
      directionAngle = 135.0f;
      return 87;
    } else if(Game::getEventManager()->isKeyDown(KEY_RIGHT)) {
      directionAngle = 45.0f;
      return 87;
    } else {
      directionAngle = 90.0f;
      return 127;
    }
  } else if(Game::getEventManager()->isKeyDown(KEY_DOWN)) {
    if(Game::getEventManager()->isKeyDown(KEY_LEFT)) {
      directionAngle = 225.0f;
      return -87;
    } else if(Game::getEventManager()->isKeyDown(KEY_RIGHT)) {
      directionAngle = 315.0f;
      return -87;
    } else {
      directionAngle = 270.0f;
      return -127;
    }
  } else {
    return 0;
  }
}

f32 Keyboard::getDirectionAngle() {
  return directionAngle;
}
