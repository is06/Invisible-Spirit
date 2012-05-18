/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/core.h"
#include "../../include/engine/EGamepadButton.h"
#include "../../include/engine/CSave.h"
#include "../../include/engine/CGame.h"
#include "../../include/engine/CKeyboard.h"
#include "../../include/engine/CGamepad.h"
#include "../../include/engine/CTimer.h"
#include "../../include/3d/CLevelMesh.h"
#include "../../include/3d/CTPCamera.h"
#include "../../include/3d/CPlayableCharacter.h"
#include "../../include/hud/CGameplayInterface.h"
#include "../../include/hud/CEnergyInterface.h"
#include "../../include/hud/CGameplayMenu.h"
#include "../../include/hud/CMenu.h"
#include "../../include/scene/CSceneGameplay.h"

namespace is06
{
namespace nScene
{

//! Initialize all objects and entity in this type of scene
CSceneGameplay::CSceneGameplay() : CScene()
{
  Level[0] = NULL;
  Level[1] = NULL;

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
  MiniMap = new nHud::CMiniMap(Ayron);
  GameplayMenu = new nHud::nMenu::CGameplayMenu(GlobalTranslations, Control);
  EverySecondTimer = new nEngine::CTimer(1.0f, boost::bind(&CSceneGameplay::everySecond, this), 9999);

  // Flag for fade out
  QuitIsFading = false;

  // Fade at scene start
  fadeIn(0.5f);
}

//! This function manages all events in this type of scene
void CSceneGameplay::events()
{
  CScene::events();

  EverySecondTimer->update();

  manageCameraControl();
  manageCharacterJumps();
  manageCharacterMovements();
  manageCharacterCollisions();

  // Menu
  if (Control->commandEntered(nEngine::ECI_OPEN_MENU, nEngine::EET_ONCE)) {
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

//! Called every second by a timer
void CSceneGameplay::everySecond()
{
  GameSave->incInteger(21, 1); // 21 = Total game time (in seconds)
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

    if (Control->commandEntered(nEngine::ECI_PLAYER_JUMP, nEngine::EET_ONCE)) {
      if (!Ayron->isJumping() && !Ayron->isFalling()) {
        Ayron->setJumpDelta(Ayron->getJumpStrength());
      }
    }
    if (Control->commandEntered(nEngine::ECI_PLAYER_JUMP)) {
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

    // Character's direction from angle
    if (Control->getPlayerXAxis() > 35
    || Control->getPlayerYAxis() > 35
    || Control->getPlayerXAxis() < -35
    || Control->getPlayerYAxis() < -35) {
      Ayron->getNode()->setRotation(core::vector3df(
        Ayron->getNode()->getRotation().X,
        Camera->getNode()->getRotation().Y - (Control->getPlayerDirection() + core::radToDeg(nEngine::PI_D2)),
        Ayron->getNode()->getRotation().Z
      ));
    }
  }
}

//! This function manages Character collision with floor and wall. Called every cycle
void CSceneGameplay::manageCharacterCollisions()
{
  // Check if level was created
  if (Level[0]->getMesh() == NULL) nEngine::CGame::fatalError(nDebug::EEC_CODE_45);
  if (Level[0]->getNode() == NULL) nEngine::CGame::fatalError(nDebug::EEC_CODE_46);
  if (Level[0]->getMainBody() == NULL) nEngine::CGame::fatalError(nDebug::EEC_CODE_47);

  // Floor collision
  if (Ayron->getFloorCollision(Level[0]) > 1.0) {
    Ayron->fall(SpeedFactor);
  }
  if (Ayron->getFloorCollision(Level[0]) < 1.0) {
    while (Ayron->getFloorCollision(Level[0]) < 0.95) {
      Ayron->raise();
    }
  }

  // Wall collision, this normal vector will be modified by getWallCollision functions
  core::vector3df normal;

  if (Ayron->getWallCollision(nEngine::ERT_WALL_P, Level[0], normal) < 1.0f
  || Ayron->getWallCollision(nEngine::ERT_WALL_Q, Level[0], normal) < 1.0f) {
    while (Ayron->getWallCollision(nEngine::ERT_WALL_P, Level[0], normal) < 0.99
    || Ayron->getWallCollision(nEngine::ERT_WALL_Q, Level[0], normal) < 0.99) {
      Ayron->moveOpposite(normal);
    }
  }
}

//! Manages menu control
void CSceneGameplay::manageMenuControl()
{
  if (Control->commandEntered(nEngine::ECI_MENU_OK, nEngine::EET_ONCE)) {
    if (GameplayMenu->getSectionMenu()->getCurrentOption() == 9) {
      QuitIsFading = true;
      fadeOut(0.5f);
    }
  }
  if (QuitIsFading && OutFader->isReady()) {
    nEngine::CGame::changeScene(ESI_MENU);
  }
}

//! Post render (shaders...)
void CSceneGameplay::postRender()
{
  CScene::postRender();
}

//! This functions is called after all scene object render. It renders HUD elements in front of camera
void CSceneGameplay::hudRender()
{
  CScene::hudRender();

  //GameplayInterface->render();
  //EnergyInterface->render();
  MiniMap->render();
  GameplayMenu->render();
}

void CSceneGameplay::switchLevelMeshes()
{
  n3D::CLevelMesh* tmp;
  tmp = Level[1];
  Level[1] = Level[0];
  Level[0] = tmp;
}

void CSceneGameplay::loadMapSection(const string& mapName, const string& sectionName, core::vector3df position)
{
  if (Level[0] != NULL) {
    switchLevelMeshes();
  }

  Level[0] = new n3D::CLevelMesh();
  Level[0]->loadMesh("resource/mesh/level/" + mapName + "/" + sectionName + ".obj");
  Level[0]->createNode(position);
  Level[0]->loadMeshCollision();

  unloadUnusedMapSection();
}

void CSceneGameplay::unloadUnusedMapSection()
{
  if (Level[1]) {
    delete Level[1];
  }
}

//! Destroys all objects defined by constructor
CSceneGameplay::~CSceneGameplay()
{
  if (Level[0]) delete Level[0];
  if (Level[1]) delete Level[1];
  if (Ayron) delete Ayron;
  if (Camera) delete Camera;
  if (GameplayInterface) delete GameplayInterface;
  if (EnergyInterface) delete EnergyInterface;
  if (MiniMap) delete MiniMap;
  if (GameplayMenu) delete GameplayMenu;
  if (EverySecondTimer) delete EverySecondTimer;
}

}
}
