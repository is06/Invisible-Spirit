/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/enums/control/GamepadButton.h"
#include "../../include/3d/LevelMesh.h"
#include "../../include/3d/TPCamera.h"
#include "../../include/3d/PlayableCharacter.h"
#include "../../include/gui/gameplay/GameplayInterface.h"
#include "../../include/gui/gameplay/EnergyInterface.h"
#include "../../include/gui/menus/gameplay/GameplayMenu.h"
#include "../../include/gui/menus/common/Menu.h"
#include "../../include/gui/counter/GameTimeCounter.h"
#include "../../include/gui/counter/WorldTimeCounter.h"
#include "../../include/save/Save.h"
#include "../../include/scene/SceneGameplay.h"
#include "../../include/Game.h"
#include "../../include/Keyboard.h"
#include "../../include/Gamepad.h"
#include "../../include/Timer.h"

using namespace irr;
using namespace std;

/**
 * Initialize all objects and entity in this type of scene
 */
SceneGameplay::SceneGameplay() : Scene()
{
  level = new LevelMesh();
  cam = new TPCamera();

  // Ayron info
  ayron = new PlayableCharacter(cam);
  //ayron->setShadowMode(SHADOW_MODE_CAST);
  // Link Ayron to Third-Person Camera
  cam->linkEntity(ayron);

  // GUI Interfaces
  gpInterface = new GameplayInterface();
  enInterface = new EnergyInterface();
  gpMenu = new GameplayMenu(globalTranslations);
  gameTotalTime = new GameTimeCounter();
  worldTime = new WorldTimeCounter();
  worldTimeTimer = new Timer(1.0f, boost::bind(&SceneGameplay::updateWorldTime, this), -1);

  // Flag for fade out
  quitIsFading = false;

  // Fade at scene start
  fadeIn(0.5f);
}

/**
 * This function manages all events in this type of scene
 */
void SceneGameplay::events()
{
  gameTotalTime->render(gameSave->getInteger(11)); // 11 = total game time

  worldTime->render(gameSave->getInteger(12)); // 12 = world time
  worldTimeTimer->update();

  Scene::events();

  manageCameraControl();
  manageCharacterJumps();
  manageCharacterMovements();
  manageCharacterCollisions();

  // Menu
  if (keyboard->pressed(KEY_KEY_D, EVENT_ONCE)) {
    gpMenu->toggle();
    ayron->toggleControl();
    cam->toggleControl();
  }

  if (gpMenu->isVisible) {
    manageMenuControl();
  }

  // Entities rendering
  ayron->render();
  cam->render();
}

void SceneGameplay::updateWorldTime()
{
  gameSave->incInteger(12, 1);
  if (gameSave->getInteger(12) >= 1440) {
    gameSave->setInteger(12, 0);
  }
}

/**
 * Manages camera control. Called every cycke
 */
void SceneGameplay::manageCameraControl()
{
  if (cam->hasControl()) {
    // Keyboard control
    if (keyboard->pressed(KEY_KEY_J)) {
      cam->goLeft(speedFactor * 100);
    } else if (keyboard->pressed(KEY_KEY_L)) {
      cam->goRight(speedFactor * 100);
    }
    if (keyboard->pressed(KEY_KEY_I)) {
      cam->goNear(speedFactor * 100);
    } else if (keyboard->pressed(KEY_KEY_K)) {
      cam->goFar(speedFactor * 100);
    }

    // Joystick control
    /*
    if (fabs(gamepad->getRightJoystickXAxis()) > 35
    || fabs(gamepad->getRightJoystickYAxis()) > 35) {
      if (gamepad->getRightJoystickXAxis() < -35) {
        cam->goLeft(speedFactor * gamepad->getRightJoystickXAxis() * -1);
      } else if (gamepad->getRightJoystickXAxis() > 35) {
        cam->goRight(speedFactor * gamepad->getRightJoystickXAxis());
      }
      if (gamepad->getRightJoystickYAxis() > 35) {
        cam->goNear(speedFactor * gamepad->getRightJoystickYAxis());
      } else if (gamepad->getRightJoystickYAxis() < -35) {
        cam->goFar(speedFactor * gamepad->getRightJoystickYAxis() * -1);
      }
    }
    */
  }
}

/**
 * Manages Character's jumps. Called every cycle
 */
void SceneGameplay::manageCharacterJumps()
{
  if (ayron->hasControl()) {
    ayron->isJumping = false;

    // Keyboard
    if (keyboard->pressed(KEY_KEY_V, EVENT_ONCE)) {
      if (!ayron->isJumping && !ayron->isFalling) {
        ayron->setJumpDelta(ayron->getJumpStrength());
      }
    }
    if (keyboard->pressed(KEY_KEY_V)) {
      ayron->isJumping = true;
      ayron->jump();
    }

    // Gamepad
    /*
    if (gamepad->buttonPressed(GP_BUTTON_B, EVENT_ONCE)) {
      if (!ayron->isJumping && !ayron->isFalling) {
        ayron->setJumpDelta(ayron->getJumpStrength());
      }
    }
    if (gamepad->buttonPressed(GP_BUTTON_B)) {
      ayron->isJumping = true;
      ayron->jump();
    }
    */
  }
}

/**
 * This function manages Character's movements, both keyboard and gamepad
 * are functionnal. Called every cycle
 */
void SceneGameplay::manageCharacterMovements()
{
  if (ayron->hasControl()) {
    // Keyboard control
    if (keyboard->pressed(KEY_UP) || keyboard->pressed(KEY_DOWN) || keyboard->pressed(KEY_LEFT) || keyboard->pressed(KEY_RIGHT)) {
      // Character's direction from keyboard's arrows angle
      ayron->getNode()->setRotation(core::vector3df(
        ayron->getNode()->getRotation().X,
        cam->getNode()->getRotation().Y - (keyboard->getDirectionAngle() + core::radToDeg(core::PI / 2)),
        ayron->getNode()->getRotation().Z
      ));

      if (keyboard->pressed(KEY_LEFT)) {
        ayron->goLeft(speedFactor * keyboard->getDirectionXAxis() * -1);
      } else if (keyboard->pressed(KEY_RIGHT)) {
        ayron->goRight(speedFactor * keyboard->getDirectionXAxis());
      }

      if (keyboard->pressed(KEY_DOWN)) {
        ayron->goBackward(speedFactor * keyboard->getDirectionYAxis() * -1);
      } else if (keyboard->pressed(KEY_UP)) {
        ayron->goForward(speedFactor * keyboard->getDirectionYAxis());
      }
    }

    // Joystick control
    /*
    if (fabs(gamepad->getLeftJoystickXAxis()) > 35 || fabs(gamepad->getLeftJoystickYAxis()) > 35) {
      // Character's direction from joystick's angle
      ayron->getNode()->setRotation(core::vector3df(
        ayron->getNode()->getRotation().X,
        cam->getNode()->getRotation().Y - (gamepad->getLeftJoystickAngle() + core::radToDeg(core::PI / 2)),
        ayron->getNode()->getRotation().Z
      ));

      if (gamepad->getLeftJoystickXAxis() < -35) {
        ayron->goLeft(speedFactor * gamepad->getLeftJoystickXAxis() * -1);
      } else if (gamepad->getLeftJoystickXAxis() > 35) {
        ayron->goRight(speedFactor * gamepad->getLeftJoystickXAxis());
      }

      if (gamepad->getLeftJoystickYAxis() < -35) {
        ayron->goBackward(speedFactor * gamepad->getLeftJoystickYAxis() * -1);
      } else if (gamepad->getLeftJoystickYAxis() > 35) {
        ayron->goForward(speedFactor * gamepad->getLeftJoystickYAxis());
      }
    }
    */
  }
}

/**
 * This function manages Character collision with floor and wall.
 * Called every cycle
 */
void SceneGameplay::manageCharacterCollisions()
{
  // Check if level was created
  if (level->getMesh() == NULL) Game::fatalError(ERRCODE_45);
  if (level->getNode() == NULL) Game::fatalError(ERRCODE_46);
  if (level->getMainBody() == NULL) Game::fatalError(ERRCODE_47);

  // Floor collision
  if (ayron->getFloorCollision(level) > 1.0) {
    ayron->fall(speedFactor);
  }
  if (ayron->getFloorCollision(level) < 1.0) {
    while (ayron->getFloorCollision(level) < 0.95) {
      ayron->raise();
    }
  }

  // Wall collision, this normal vector will be modified by getWallCollision functions
  core::vector3df normal;

  if (ayron->getWallCollision(RAY_WALL_P, level, normal) < 1.0f
  || ayron->getWallCollision(RAY_WALL_Q, level, normal) < 1.0f) {
    while (ayron->getWallCollision(RAY_WALL_P, level, normal) < 0.99
    || ayron->getWallCollision(RAY_WALL_Q, level, normal) < 0.99) {
      ayron->moveOpposite(normal);
    }
  }
}

/**
 *
 */
void SceneGameplay::manageMenuControl()
{
  if (keyboard->pressed(KEY_SPACE, EVENT_ONCE)) {
    if (gpMenu->getSectionMenu()->getCurrentOption() == 8) {
      quitIsFading = true;
      fadeOut(0.5f);
    }
  }
  if (quitIsFading && outFader->isReady()) {
    Game::changeScene(SCENE_MENU);
  }
}

/**
 * This functions is called after all scene object render
 * It renders HUD elements in front of camera
 */
void SceneGameplay::postRender()
{
  Scene::postRender();
  gpInterface->render();
  enInterface->render();
  gpMenu->render(keyboard);
}

/**
 * Destroys all objects defined by constructor
 */
SceneGameplay::~SceneGameplay()
{
  if (level) delete level;
  if (ayron) delete ayron;
  if (cam) delete cam;
  if (gpInterface) delete gpInterface;
  if (enInterface) delete enInterface;
  if (gpMenu) delete gpMenu;
  if (gameTotalTime) delete gameTotalTime;
  if (worldTime) delete worldTime;
  if (worldTimeTimer) delete worldTimeTimer;
}
