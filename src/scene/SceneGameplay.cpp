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
#include "../../include/save/Save.h"
#include "../../include/scene/SceneGameplay.h"
#include "../../include/Game.h"
#include "../../include/Keyboard.h"
#include "../../include/Gamepad.h"
#include "../../include/Timer.h"

namespace is06
{
namespace scene
{

/**
 * Initialize all objects and entity in this type of scene
 */
CSceneGameplay::CSceneGameplay() : CScene()
{
  Level = new model::CLevelMesh();
  Camera = new model::CTPCamera();

  // Ayron info
  Ayron = new model::CPlayableCharacter(Camera);
  //ayron->setShadowMode(SHADOW_MODE_CAST);
  // Link Ayron to Third-Person Camera
  Camera->linkEntity(Ayron);

  // GUI Interfaces
  GameplayInterface = new hud::CGameplayInterface();
  EnergyInterface = new hud::CEnergyInterface();
  GameplayMenu = new hud::CGameplayMenu(GlobalTranslations, Keyboard);
  EverySecondTimer = new engine::CTimer(1.0f, boost::bind(&CSceneGameplay::everySecond, this), 9999);

  // Flag for fade out
  QuitIsFading = false;

  // Fade at scene start
  fadeIn(0.5f);
}

/**
 * This function manages all events in this type of scene
 */
void CSceneGameplay::events()
{
  CScene::events();

  EverySecondTimer->update();

  manageCameraControl();
  manageCharacterJumps();
  manageCharacterMovements();
  manageCharacterCollisions();

  // Menu
  if (Keyboard->pressed(irr::KEY_KEY_D, engine::EVENT_ONCE)) {
    GameplayMenu->toggle();
    Ayron->toggleControl();
    Camera->toggleControl();
  }

  if (GameplayMenu->IsVisible) {
    manageMenuControl();
  }

  // Entities rendering
  Ayron->update();
  Camera->update();
}

void CSceneGameplay::everySecond()
{
  GameSave->incInteger(21, 1);
}

/**
 * Manages camera control. Called every cycke
 */
void CSceneGameplay::manageCameraControl()
{
  if (Camera->hasControl()) {
    // Keyboard control
    if (Keyboard->pressed(irr::KEY_KEY_J)) {
      Camera->goLeft(SpeedFactor * 100);
    } else if (Keyboard->pressed(irr::KEY_KEY_L)) {
      Camera->goRight(SpeedFactor * 100);
    }
    if (Keyboard->pressed(irr::KEY_KEY_I)) {
      Camera->goNear(SpeedFactor * 100);
    } else if (Keyboard->pressed(irr::KEY_KEY_K)) {
      Camera->goFar(SpeedFactor * 100);
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
void CSceneGameplay::manageCharacterJumps()
{
  if (Ayron->hasControl()) {
    Ayron->IsJumping = false;

    // Keyboard
    if (Keyboard->pressed(irr::KEY_KEY_V, engine::EVENT_ONCE)) {
      if (!Ayron->IsJumping && !Ayron->IsFalling) {
        Ayron->setJumpDelta(Ayron->getJumpStrength());
      }
    }
    if (Keyboard->pressed(irr::KEY_KEY_V)) {
      Ayron->IsJumping = true;
      Ayron->jump();
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
void CSceneGameplay::manageCharacterMovements()
{
  if (Ayron->hasControl()) {
    // Keyboard control
    if (Keyboard->pressed(KEY_UP) || Keyboard->pressed(KEY_DOWN) || Keyboard->pressed(KEY_LEFT) || Keyboard->pressed(KEY_RIGHT)) {
      // Character's direction from keyboard's arrows angle
      Ayron->getNode()->setRotation(core::vector3df(
        Ayron->getNode()->getRotation().X,
        Camera->getNode()->getRotation().Y - (Keyboard->getDirectionAngle() + core::radToDeg(core::PI / 2)),
        Ayron->getNode()->getRotation().Z
      ));

      if (Keyboard->pressed(KEY_LEFT)) {
        Ayron->goLeft(SpeedFactor * Keyboard->getDirectionXAxis() * -1);
      } else if (Keyboard->pressed(KEY_RIGHT)) {
        Ayron->goRight(SpeedFactor * Keyboard->getDirectionXAxis());
      }

      if (Keyboard->pressed(KEY_DOWN)) {
        Ayron->goBackward(SpeedFactor * Keyboard->getDirectionYAxis() * -1);
      } else if (Keyboard->pressed(KEY_UP)) {
        Ayron->goForward(SpeedFactor * Keyboard->getDirectionYAxis());
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
void CSceneGameplay::manageCharacterCollisions()
{
  // Check if level was created
  if (Level->getMesh() == NULL) engine::CGame::fatalError(debug::ERRCODE_45);
  if (Level->getNode() == NULL) engine::CGame::fatalError(debug::ERRCODE_46);
  if (Level->getMainBody() == NULL) engine::CGame::fatalError(debug::ERRCODE_47);

  // Floor collision
  if (Ayron->getFloorCollision(Level) > 1.0) {
    Ayron->fall(SpeedFactor);
  }
  if (Ayron->getFloorCollision(Level) < 1.0) {
    while (Ayron->getFloorCollision(Level) < 0.95) {
      Ayron->raise();
    }
  }

  // Wall collision, this normal vector will be modified by getWallCollision functions
  core::vector3df normal;

  if (Ayron->getWallCollision(engine::RAY_WALL_P, Level, normal) < 1.0f
  || Ayron->getWallCollision(engine::RAY_WALL_Q, Level, normal) < 1.0f) {
    while (Ayron->getWallCollision(engine::RAY_WALL_P, Level, normal) < 0.99
    || Ayron->getWallCollision(engine::RAY_WALL_Q, Level, normal) < 0.99) {
      Ayron->moveOpposite(normal);
    }
  }
}

/**
 *
 */
void CSceneGameplay::manageMenuControl()
{
  if (Keyboard->pressed(irr::KEY_SPACE, engine::EVENT_ONCE)) {
    if (GameplayMenu->getSectionMenu()->getCurrentOption() == 9) {
      QuitIsFading = true;
      fadeOut(0.5f);
    }
  }
  if (QuitIsFading && OutFader->isReady()) {
    engine::CGame::changeScene(SCENE_MENU);
  }
}

/**
 *
 */
void CSceneGameplay::postRender()
{
  CScene::postRender();
}

/**
 * This functions is called after all scene object render
 * It renders HUD elements in front of camera
 */
void CSceneGameplay::hudRender()
{
  CScene::hudRender();

  //gpInterface->render();
  //enInterface->render();
  GameplayMenu->render();
}

/**
 * Destroys all objects defined by constructor
 */
CSceneGameplay::~CSceneGameplay()
{
  if (Level) delete Level;
  if (Ayron) delete Ayron;
  if (Camera) delete Camera;
  if (GameplayInterface) delete GameplayInterface;
  if (EnergyInterface) delete EnergyInterface;
  if (GameplayMenu) delete GameplayMenu;
  if (EverySecondTimer) delete EverySecondTimer;
}

}
}
