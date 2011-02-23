/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../include/core.h"

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
