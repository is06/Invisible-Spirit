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
 * Initialise les objets présents dans toutes scènes de Gameplay
 * (Ayron, décor, caméra TP...)
 */
SceneGameplay::SceneGameplay() : Scene() {
  level = new LevelMesh();
  cam = new TPCamera();
  ayron = new Ayron(cam);
  ayron->setCollisionType(COLLISION_CYLINDER);
  cam->linkEntity(ayron);
}

/**
 * Fonction qui teste les événements de toute scène de Gameplay
 * Contrôle du personnage et de la caméra
 */
void SceneGameplay::events() { Scene::events();

  if(ayron->getRayCastCollision(level) > 1.0) {
    ayron->fall();
  }
  if(ayron->getRayCastCollision(level) < 1.0) {
    while(ayron->getRayCastCollision(level) < 0.95) {
      ayron->raise();
    }
  }

  // Contrôle de la caméra
  if(cam->hasControl()) {
    // Mouvements au pavé numérique
    if(keyboard->pressed(KEY_NUMPAD4)) {
      cam->goLeft(100);
    } else if(keyboard->pressed(KEY_NUMPAD6)) {
      cam->goRight(100);
    }
    if(keyboard->pressed(KEY_NUMPAD8)) {
      cam->goNear(100);
    } else if(keyboard->pressed(KEY_NUMPAD2)) {
      cam->goFar(100);
    }

    // Mouvements au stick analogique droit
    if(fabs(gamepad->getRightJoystickXAxis()) > 35
    || fabs(gamepad->getRightJoystickYAxis()) > 35) {
      if(gamepad->getRightJoystickXAxis() < -35) {
        cam->goLeft(gamepad->getRightJoystickXAxis() * -1);
      } else if(gamepad->getRightJoystickXAxis() > 35) {
        cam->goRight(gamepad->getRightJoystickXAxis());
      }
      if(gamepad->getRightJoystickYAxis() > 35) {
        cam->goNear(gamepad->getRightJoystickYAxis());
      } else if(gamepad->getRightJoystickYAxis() < -35) {
        cam->goFar(gamepad->getRightJoystickYAxis() * -1);
      }
    }
  }

  // Contrôle d'Ayron au clavier
  if(keyboard->pressed(KEY_LEFT)) {
    ayron->goLeft(100.0f);
  } else if(keyboard->pressed(KEY_RIGHT)) {
    ayron->goRight(100.0f);
  }
  if(keyboard->pressed(KEY_UP)) {
    ayron->goForward(100.0f);
  } else if(keyboard->pressed(KEY_DOWN)) {
    ayron->goBackward(100.0f);
  }

  // Contrôle d'Ayron au stick analogique gauche
  if(fabs(gamepad->getLeftJoystickXAxis()) > 35
  || fabs(gamepad->getLeftJoystickYAxis()) > 35) {
    if(gamepad->getLeftJoystickXAxis() < -35) {
      ayron->goLeft(gamepad->getLeftJoystickXAxis() * -1);
    } else if(gamepad->getLeftJoystickXAxis() > 35) {
      ayron->goRight(gamepad->getLeftJoystickXAxis());
    }
    if(gamepad->getLeftJoystickYAxis() < -35) {
      ayron->goBackward(gamepad->getLeftJoystickYAxis() * -1);
    } else if(gamepad->getLeftJoystickYAxis() > 35) {
      ayron->goForward(gamepad->getLeftJoystickYAxis());
    }
  }

  // Rendu des entités
  ayron->render();
  cam->render();
}

/**
 * Détruit tous les objets initialisés dans le constructeur
 */
SceneGameplay::~SceneGameplay() {
  delete level;
  delete ayron;
  delete cam;
}
