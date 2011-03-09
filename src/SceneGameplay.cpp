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
 * Initialize all objects and entity in this type of scene
 */
SceneGameplay::SceneGameplay() : Scene() {
  level = new LevelMesh();
  cam = new TPCamera();
  ayron = new Ayron(cam);
  cam->linkEntity(ayron);
  gpInterface = new GameplayInterface();
  gpMenu = new GameplayMenu();

  //myTimer = new Timer(3.0f, hello);
}

void SceneGameplay::hello() {
  cout << "hello" << endl;
}

/**
 * This function manages all events in this type of scene
 */
void SceneGameplay::events() { Scene::events();
  manageCameraControl();
  manageAyronJumps();
  manageAyronMovements();
  manageAyronCollisions();

  // Menu
  if(keyboard->pressed(KEY_KEY_D, EVENT_ONCE)) {
    gpMenu->toggle();
    ayron->toggleControl();
    cam->toggleControl();
  }

  if(gpMenu->isVisible) {
    manageMenuControl();
  }

  myTimer->update();

  // Entities rendering
  ayron->render();
  cam->render();
}

/**
 * Manages camera control. Called every cycke
 */
void SceneGameplay::manageCameraControl() {
  if(cam->hasControl()) {
    // Keyboard control
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

    // Joystick control
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
 * Manages Ayron's jumps. Called every cycle
 */
void SceneGameplay::manageAyronJumps() {
  if(ayron->hasControl()) {
    ayron->isJumping = false;

    // Clavier
    if(keyboard->pressed(KEY_KEY_V, EVENT_ONCE)) {
      if(!ayron->isJumping && !ayron->isFalling) {
        ayron->setJumpDelta(ayron->getJumpStrength());
      }
    }
    if(keyboard->pressed(KEY_KEY_V)) {
      ayron->isJumping = true;
      ayron->jump();
    }

    // Manette
    if(gamepad->buttonPressed(GP_BUTTON_B, EVENT_ONCE)) {
      if(!ayron->isJumping && !ayron->isFalling) {
        ayron->setJumpDelta(ayron->getJumpStrength());
      }
    }
    if(gamepad->buttonPressed(GP_BUTTON_B)) {
      ayron->isJumping = true;
      ayron->jump();
    }
  }
}

/**
 * This function manages Ayron's movements, both keyboard and gamepad
 * are functionnal. Called every cycle
 */
void SceneGameplay::manageAyronMovements() {

  if(ayron->hasControl()) {
    // Keyboard control
    if(keyboard->pressed(KEY_UP) || keyboard->pressed(KEY_DOWN)
    || keyboard->pressed(KEY_LEFT) || keyboard->pressed(KEY_RIGHT)) {
      // Ayron's direction from keyboard's arrows angle
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

    // Joystick control
    if(fabs(gamepad->getLeftJoystickXAxis()) > 35
    || fabs(gamepad->getLeftJoystickYAxis()) > 35) {
      // Ayron's direction from joystick's angle
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
}

/**
 * This function manages Ayron collision with floor and wall.
 * Called every cycle
 */
void SceneGameplay::manageAyronCollisions() {
  // Floor collision
  if(ayron->getFloorCollision(level) > 1.0) {
    ayron->fall();
  }
  if(ayron->getFloorCollision(level) < 1.0) {
    while(ayron->getFloorCollision(level) < 0.95) {
      ayron->raise();
    }
  }

  // Wall collision, this normal vector will be modified by getWallCollision functions
  core::vector3df normal;

  if(ayron->getWallCollision(RAY_WALL_P, level, normal) < 1.0f || ayron->getWallCollision(RAY_WALL_Q, level, normal) < 1.0f) {
    while(ayron->getWallCollision(RAY_WALL_P, level, normal) < 0.99 || ayron->getWallCollision(RAY_WALL_Q, level, normal) < 0.99) {
      ayron->moveOpposite(normal);
    }
  }
}

/**
 *
 */
void SceneGameplay::manageMenuControl() {
  if(keyboard->pressed(KEY_DOWN, EVENT_ONCE)) {
    gpMenu->getSectionMenu()->nextOption();
  }
  if(keyboard->pressed(KEY_UP, EVENT_ONCE)) {
    gpMenu->getSectionMenu()->prevOption();
  }
}

/**
 * This functions is called after all scene object render
 * It renders HUD elements in front of camera
 */
void SceneGameplay::postRender() { Scene::postRender();
  //gpInterface->render();
  gpMenu->render();
}

/**
 * Destroys all objects defined by constructor
 */
SceneGameplay::~SceneGameplay() {
  delete level;
  delete ayron;
  delete cam;
  delete gpInterface;
  delete gpMenu;

  delete myTimer;
}
