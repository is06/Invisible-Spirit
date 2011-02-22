/**************************************************************************************
Le code source d'Invisible Spirit par Thomas Noury est mis à disposition selon les
termes de la licence Creative Commons Paternité - Pas d'Utilisation Commerciale -
Partage des Conditions Initiales à l'Identique 3.0 Unported.
Basé(e) sur une oeuvre à www.is06.com.  Les autorisations au-delà du champ de
cette licence peuvent être obtenues à http://www.is06.com.
***************************************************************************************/

#include "core.h"

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
