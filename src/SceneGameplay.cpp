/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../include/core.h"

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
  cam->linkEntity(ayron);
  //gpInterface = new GameplayInterface();
}

/**
 * Fonction qui teste les événements de toute scène de Gameplay
 * Contrôle du personnage et de la caméra
 */
void SceneGameplay::events() { Scene::events();

  manageCameraControl();
  manageAyronJumps();
  manageAyronMovements();
  manageAyronCollisions();

  // Rendu des entités
  ayron->render();
  cam->render();
}

/**
 *
 */
void SceneGameplay::manageCameraControl() {
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
}

/**
 *
 */
void SceneGameplay::manageAyronJumps() {
  if(ayron->hasControl()) {
    ayron->isJumping = false;
    if(keyboard->pressed(KEY_KEY_V, EVENT_ONCE)) {
      if(!ayron->isJumping && !ayron->isFalling) {
        ayron->setJumpStrength(Ayron::JUMP_STRENGTH);
      }
    }
    if(keyboard->pressed(KEY_KEY_V)) {
      ayron->isJumping = true;
      ayron->jump();
    }
  }
}

/**
 *
 */
void SceneGameplay::manageAyronMovements() {

  if(keyboard->pressed(KEY_UP) || keyboard->pressed(KEY_DOWN)
  || keyboard->pressed(KEY_LEFT) || keyboard->pressed(KEY_RIGHT)) {
    // Direction d'Ayron en fonction de l'angle des touches
    ayron->getNode()->setRotation(core::vector3df(
      ayron->getNode()->getRotation().X,
      cam->getNode()->getRotation().Y - (keyboard->getDirectionAngle() + core::radToDeg(core::PI / 2)),
      ayron->getNode()->getRotation().Z
    ));

    if(keyboard->pressed(KEY_LEFT)) {
      ayron->goLeft(keyboard->getDirectionXAxis() * -1);
    } else if(keyboard->pressed(KEY_RIGHT)) {
      ayron->goRight(keyboard->getDirectionXAxis());
    }

    if(keyboard->pressed(KEY_DOWN)) {
      ayron->goBackward(keyboard->getDirectionYAxis() * -1);
    } else if(keyboard->pressed(KEY_UP)) {
      ayron->goForward(keyboard->getDirectionYAxis());
    }
  }

  // Contrôle d'Ayron au stick analogique gauche
  if(fabs(gamepad->getLeftJoystickXAxis()) > 35
  || fabs(gamepad->getLeftJoystickYAxis()) > 35) {
    // Direction d'Ayron en fonction de l'angle du joystick
    ayron->getNode()->setRotation(core::vector3df(
      ayron->getNode()->getRotation().X,
      cam->getNode()->getRotation().Y - (gamepad->getLeftJoystickAngle() + core::radToDeg(core::PI / 2)),
      ayron->getNode()->getRotation().Z
    ));

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
}

/**
 *
 */
void SceneGameplay::manageAyronCollisions() {
  // Collisions avec le sol
  if(ayron->getFloorCollision(level) > 1.0) {
    ayron->fall();
  }
  if(ayron->getFloorCollision(level) < 1.0) {
    while(ayron->getFloorCollision(level) < 0.95) {
      ayron->raise();
    }
  }

  // Collisions avec les murs
  core::vector3df originP;
  core::vector3df endP;
  core::vector3df originQ;
  core::vector3df endQ;

  originP = core::vector3df(-0.5,0,0);
  endP = core::vector3df(-0.5,0,-1);
  originQ = core::vector3df(0.5,0,0);
  endQ = core::vector3df(0.5,0,-1);

  f32 wallCollisionP = ayron->getWallCollisionP(level, originP, endP);
  f32 wallCollisionQ = ayron->getWallCollisionQ(level, originQ, endQ);
  f32 angle = 0.0f;
  if(wallCollisionP < 1.0f || wallCollisionQ < 1.0f) {

    if(wallCollisionP > 1.0f) wallCollisionP = 1.0f;
    if(wallCollisionQ > 1.0f) wallCollisionQ = 1.0f;

    //angle = atan(wallCollisionP - wallCollisionQ);
    //cout << "p = " << wallCollisionP << " ; q = " << wallCollisionQ << " ; a = " << angle << endl;

    while(ayron->getWallCollisionP(level, originP, endP) < 0.99 || ayron->getWallCollisionQ(level, originQ, endQ) < 0.99) {
      ayron->moveOpposite();
    }
  }

  core::matrix4 mat;
  Game::getVideoDriver()->setTransform(video::ETS_WORLD, mat);

  Game::getVideoDriver()->draw3DLine(originP, endP, video::SColor(255,255,0,0));
  Game::getVideoDriver()->draw3DLine(originQ, endQ, video::SColor(255,0,255,255));
}

/**
 *
 */
void SceneGameplay::postRender() { Scene::postRender();
  //gpInterface->render();
}

/**
 * Destroys all objects defined by constructor
 */
SceneGameplay::~SceneGameplay() {
  delete level;
  delete ayron;
  delete cam;
  //delete gpInterface;
}
