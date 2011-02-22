/**************************************************************************************
Le code source d'Invisible Spirit par Thomas Noury est mis à disposition selon les
termes de la licence Creative Commons Paternité - Pas d'Utilisation Commerciale -
Partage des Conditions Initiales à l'Identique 3.0 Unported.
Basé(e) sur une oeuvre à www.is06.com.  Les autorisations au-delà du champ de
cette licence peuvent être obtenues à http://www.is06.com.
***************************************************************************************/

#include "core.h"

using namespace irr;
using namespace std;

/**
 * Initialise un objet Camera ainsi que les interfaces d'événements comme le clavier ou la manette
 */
Scene::Scene() {
  cam = NULL;
  keyboard = new Keyboard();
  gamepad = new Gamepad();
}

/**
 * Fonction de test des événements de toutes les scènes du jeu
 * (Evénements globaux)
 */
void Scene::events() {
  if(keyboard->pressed(KEY_ESCAPE, EVENT_ONCE)) {
    Game::debugExit();
  }
}

/**
 *
 */
Scene::~Scene() {
  delete gamepad;
  delete keyboard;
}
