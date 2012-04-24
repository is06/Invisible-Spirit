/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/core.h"
#include "../../include/engine/GamepadButton.h"
#include "../../include/engine/Save.h"
#include "../../include/engine/Game.h"
#include "../../include/engine/Keyboard.h"
#include "../../include/engine/Gamepad.h"
#include "../../include/engine/Timer.h"
#include "../../include/3d/LevelMesh.h"
#include "../../include/3d/TPCamera.h"
#include "../../include/3d/PlayableCharacter.h"
#include "../../include/hud/GameplayInterface.h"
#include "../../include/hud/EnergyInterface.h"
#include "../../include/hud/GameplayMenu.h"
#include "../../include/hud/Menu.h"
#include "../../include/scene/SceneGameplay.h"

namespace is06
{
namespace nScene
{

/**
 * Initialize all objects and entity in this type of scene
 */
CSceneGameplay::CSceneGameplay() : CScene()
{
  Level = new n3D::CLevelMesh();
  Camera = new n3D::CTPCamera();

  // Ayron info
  Ayron = new n3D::CPlayableCharacter(Camera);
  //Lumi = new n3D::CPlayableCharacter(Camera, MODEL_LUMI);
  //Ayron->setShadowMode(SHADOW_MODE_CAST);
  // Link Ayron to Third-Person Camera
  Camera->linkEntity(Ayron);
  //Camera->linkEntity(Lumi);

  // GUI Interfaces
  GameplayInterface = new nHud::CGameplayInterface();
  EnergyInterface = new nHud::CEnergyInterface();
  GameplayMenu = new nHud::nMenu::CGameplayMenu(GlobalTranslations, Control);
  EverySecondTimer = new nEngine::CTimer(1.0f, boost::bind(&CSceneGameplay::everySecond, this), 9999);

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
  if (Control->commandEntered(nEngine::COMMAND_OPEN_MENU, nEngine::EVENT_ONCE)) {
    GameplayMenu->toggle();
    Ayron->toggleControl();
    Camera->toggleControl();
  }

  if (GameplayMenu->isVisible()) {
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

//! Manages camera control. Called every cycle
void CSceneGameplay::manageCameraControl()
{
  if (Camera->hasControl()) {
    if (Control->getCameraXAxis() < -35) {
      Camera->goLeft(SpeedFactor * Control->getCameraXAxis() * -1);
    } else if (Control->getCameraXAxis() > 35) {
      Camera->goRight(SpeedFactor * Control->getCameraXAxis());
    }
    if (Control->getCameraYAxis() > 35) {
      Camera->goNear(SpeedFactor * Control->getCameraYAxis());
    } else if (Control->getCameraYAxis() < -35) {
      Camera->goFar(SpeedFactor * Control->getCameraYAxis() * -1);
    }
  }
}

//! Manages Character's jumps. Called every cycle
void CSceneGameplay::manageCharacterJumps()
{
  if (Ayron->hasControl()) {
    Ayron->setJumping(false);

    if (Control->commandEntered(nEngine::COMMAND_PLAYER_JUMP, nEngine::EVENT_ONCE)) {
      if (!Ayron->isJumping() && !Ayron->isFalling()) {
        Ayron->setJumpDelta(Ayron->getJumpStrength());
      }
    }
    if (Control->commandEntered(nEngine::COMMAND_PLAYER_JUMP)) {
      Ayron->setJumping(true);
      Ayron->jump();
    }
  }
}

//! This function manages Character's movements. Called every cycle
void CSceneGameplay::manageCharacterMovements()
{
  if (Ayron->hasControl()) {
    // Character's Movements
    if (Control->getPlayerXAxis() > 35) {
      Ayron->goRight(SpeedFactor * Control->getPlayerXAxis());
    } else if (Control->getPlayerXAxis() < -35) {
      Ayron->goLeft(SpeedFactor * Control->getPlayerXAxis() * -1);
    }
    if (Control->getPlayerYAxis() > 35) {
      Ayron->goForward(SpeedFactor * Control->getPlayerYAxis());
    } else if (Control->getPlayerYAxis() < -35) {
      Ayron->goBackward(SpeedFactor * Control->getPlayerYAxis() * -1);
    }

    if (Control->getPlayerDirection() != 0.0f) {
      // Character's direction from angle
      Ayron->getNode()->setRotation(core::vector3df(
        Ayron->getNode()->getRotation().X,
        Camera->getNode()->getRotation().Y - (Control->getPlayerDirection() + core::radToDeg(core::PI / 2)),
        Ayron->getNode()->getRotation().Z
      ));
    }
  }
}

//! This function manages Character collision with floor and wall. Called every cycle
void CSceneGameplay::manageCharacterCollisions()
{
  // Check if level was created
  if (Level->getMesh() == NULL) nEngine::CGame::fatalError(nDebug::ERRCODE_45);
  if (Level->getNode() == NULL) nEngine::CGame::fatalError(nDebug::ERRCODE_46);
  if (Level->getMainBody() == NULL) nEngine::CGame::fatalError(nDebug::ERRCODE_47);

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

  if (Ayron->getWallCollision(nEngine::RAY_WALL_P, Level, normal) < 1.0f
  || Ayron->getWallCollision(nEngine::RAY_WALL_Q, Level, normal) < 1.0f) {
    while (Ayron->getWallCollision(nEngine::RAY_WALL_P, Level, normal) < 0.99
    || Ayron->getWallCollision(nEngine::RAY_WALL_Q, Level, normal) < 0.99) {
      Ayron->moveOpposite(normal);
    }
  }
}

/**
 *
 */
void CSceneGameplay::manageMenuControl()
{
  if (Control->commandEntered(nEngine::COMMAND_MENU_OK, nEngine::EVENT_ONCE)) {
    if (GameplayMenu->getSectionMenu()->getCurrentOption() == 9) {
      QuitIsFading = true;
      fadeOut(0.5f);
    }
  }
  if (QuitIsFading && OutFader->isReady()) {
    nEngine::CGame::changeScene(SCENE_MENU);
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
