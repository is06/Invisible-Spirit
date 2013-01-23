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
#include "../../include/model/CLevelMesh.h"
#include "../../include/model/CTPCamera.h"
#include "../../include/model/CPlayableCharacter.h"
#include "../../include/hud/CHudEnsemble.h"
#include "../../include/hud/CHudEnsembleEnergy.h"
#include "../../include/hud/CPauseScreen.h"
#include "../../include/hud/CMenu.h"
#include "../../include/scene/CSceneGameplay.h"

namespace is06
{
namespace nScene
{

//! Constructor
CSceneGameplay::CSceneGameplay() : CScene()
{
  cout << "Gameplay scene constructor" << endl;
}

//! Loading sequence for all gameplay scenes
void CSceneGameplay::loadingSequence()
{
  Camera = new n3D::CTPCamera();

  MapSections = new nEngine::CMapSectionInterface();

  // Hero info
  Hero = new n3D::CPlayableCharacter(Camera);
  //Hero->setShadowMode(SHADOW_MODE_CAST);

  // Link Hero to Third-Person Camera
  Camera->linkEntity(Hero);

  // GUI Interfaces
  HudEnsemble = new nHud::CHudEnsemble();
  MiniMap = new nHud::CMiniMap(Hero);
  PauseScreen = new nHud::nPauseScreen::CPauseScreen(GlobalTranslations, Control);
}

//! Loading screen for gameplay scenes (overworld, dungeons...)
void CSceneGameplay::loadingScreen()
{
  cout << "Loading screen" << endl;
}

//! Gameplay scenes start sequence
void CSceneGameplay::start()
{
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
  manageCharacterNPCInteraction();

  // Menu
  if (Control->commandEntered(nEngine::ECI_OPEN_MENU, nEngine::EET_ONCE)) {
    PauseScreen->toggle();
    Hero->toggleControl();
    Camera->toggleControl();
  }
  if (PauseScreen->isVisible()) {
    manageMenuControl();
  }

  // Cinemascope mode
  if (Control->commandEntered(nEngine::ECI_PLAYER_GUARD, nEngine::EET_ONCE)) {
    Cinemascope->fadeIn(500.0f);
  }

  // Entities rendering
  Hero->update();
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
  if (Hero->hasControl()) {
    Hero->setJumping(false);

    if (Control->commandEntered(nEngine::ECI_PLAYER_JUMP, nEngine::EET_ONCE)) {
      if (!Hero->isJumping() && !Hero->isFalling()) {
        Hero->setJumpDelta(Hero->getJumpStrength());
      }
    }
    if (Control->commandEntered(nEngine::ECI_PLAYER_JUMP)) {
      Hero->setJumping(true);
      Hero->jump();
    }
  }
}

//! This function manages Character's movements. Called every cycle
void CSceneGameplay::manageCharacterMovements()
{
  if (Hero->hasControl()) {
    // Character's Movements
    if (Control->getPlayerXAxis() > 35) {
      Hero->goRight(SpeedFactor * Control->getPlayerXAxis());
    } else if (Control->getPlayerXAxis() < -35) {
      Hero->goLeft(SpeedFactor * Control->getPlayerXAxis() * -1);
    }
    if (Control->getPlayerYAxis() > 35) {
      Hero->goForward(SpeedFactor * Control->getPlayerYAxis());
    } else if (Control->getPlayerYAxis() < -35) {
      Hero->goBackward(SpeedFactor * Control->getPlayerYAxis() * -1);
    }

    // Character's direction from angle
    if (Control->getPlayerXAxis() > 35
    || Control->getPlayerYAxis() > 35
    || Control->getPlayerXAxis() < -35
    || Control->getPlayerYAxis() < -35) {
      Hero->updateDirectionFromAngle(Control->getPlayerDirection());
    }
  }
}

//! This function manages Character collision with floor and wall. Called every cycle
void CSceneGameplay::manageCharacterCollisions()
{
  // Floor collision (only if a map section is loaded)
  if (MapSections->hasSections()) {
    if (Hero->getFloorCollision(MapSections->getSection(0)) > 1.0) {
      Hero->fall(SpeedFactor);
    }
    if (Hero->getFloorCollision(MapSections->getSection(0)) < 1.0) {
      while (Hero->getFloorCollision(MapSections->getSection(0)) < 0.95) {
        Hero->raise();
      }
    }

    // Wall collision, this normal vector will be modified by getWallCollision functions
    core::vector3df normal;

    if (Hero->getWallCollision(nEngine::ERT_WALL_P, MapSections->getSection(0), normal) < 1.0f
    || Hero->getWallCollision(nEngine::ERT_WALL_Q, MapSections->getSection(0), normal) < 1.0f) {
      while (Hero->getWallCollision(nEngine::ERT_WALL_P, MapSections->getSection(0), normal) < 0.99
      || Hero->getWallCollision(nEngine::ERT_WALL_Q, MapSections->getSection(0), normal) < 0.99) {
        Hero->moveOpposite(normal);
      }
    }
  }
}

//! Manages interactions between Hero and NPCs
void CSceneGameplay::manageCharacterNPCInteraction()
{
  n3D::CNPC* npc = NPCInterface->getNearestNPC(Hero);
  if (npc) {
    if (npc->getDistanceFrom(Hero) < 1.0f) {
      if (Control->commandEntered(nEngine::ECI_DIALOG_ACTION, nEngine::EET_ONCE)) {
        npc->talk("npc_dialog_identifier_lambda");
      }
    }
  }
}

//! Manages menu control
void CSceneGameplay::manageMenuControl()
{
  if (Control->commandEntered(nEngine::ECI_MENU_OK, nEngine::EET_ONCE)) {
    if (PauseScreen->getSectionMenu()->getCurrentOption() == 9) {
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
  PauseScreen->render();
}

//! Destroys all objects defined by constructor
CSceneGameplay::~CSceneGameplay()
{
  if (MapSections) delete MapSections;
  if (Hero) delete Hero;
  if (Camera) delete Camera;
  if (HudEnsemble) delete HudEnsemble;
  if (MiniMap) delete MiniMap;
  if (PauseScreen) delete PauseScreen;
  if (EverySecondTimer) delete EverySecondTimer;
}

}
}
