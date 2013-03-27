/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/core.h"
#include "../../include/NEngine/NControl/EGamepadButton.h"
#include "../../include/NEngine/NSave/CSave.h"
#include "../../include/NEngine/NCore/CGame.h"
#include "../../include/NEngine/NControl/CKeyboard.h"
#include "../../include/NEngine/NControl/CGamepad.h"
#include "../../include/NEngine/NTime/CTimer.h"
#include "../../include/N3D/NPart/CMapPart.h"
#include "../../include/N3D/NCamera/CThirdPerson.h"
#include "../../include/N3D/NCharacter/CPlayableCharacter.h"
#include "../../include/NHud/NPart/CHudPart.h"
#include "../../include/NHud/NPart/CEnergy.h"
#include "../../include/NHud/NPauseScreen/CPauseScreen.h"
#include "../../include/NHud/NMenu/CMenu.h"
#include "../../include/NScene/CSceneGameplay.h"

namespace is06 { namespace NScene {

//! Constructor
CSceneGameplay::CSceneGameplay() : CScene()
{
  Camera = new N3D::NCamera::CThirdPerson();
  MapSections = new NEngine::NGameplay::CMapSectionInterface();

  // Hero info
  Hero = new N3D::NCharacter::CPlayableCharacter(Camera);
  //Hero->setShadowMode(SHADOW_MODE_CAST);

  // Link Hero to Third-Person Camera
  Camera->linkEntity(Hero);

  // GUI Interfaces
  HudEnsemble = new NHud::NPart::CHudPart();
  MiniMap = new NHud::NPart::CMiniMap(Hero);
  PauseScreen = new NHud::NPauseScreen::CPauseScreen(GlobalTranslations, Control);

  EverySecondTimer = new NEngine::NTime::CTimer(1.0f, boost::bind(&CSceneGameplay::everySecond, this), -1);
}

//! Loading sequence for all gameplay scenes
void CSceneGameplay::loadingSequence()
{

}

//! Loading screen for gameplay scenes (overworld, dungeons...)
void CSceneGameplay::loadingScreen()
{

}

//! Gameplay scenes start sequence
void CSceneGameplay::start()
{
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
  if (Control->commandEntered(NEngine::NControl::ECI_OPEN_MENU, NEngine::NEvent::EET_ONCE)) {
    PauseScreen->toggle();
    Hero->toggleControl();
    Camera->toggleControl();
  }
  if (PauseScreen->isVisible()) {
    manageMenuControl();
  }

  // Cinemascope mode
  if (Control->commandEntered(NEngine::NControl::ECI_PLAYER_GUARD, NEngine::NEvent::EET_ONCE)) {
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

    if (Control->commandEntered(NEngine::NControl::ECI_PLAYER_JUMP, NEngine::NEvent::EET_ONCE)) {
      if (!Hero->isJumping() && !Hero->isFalling()) {
        Hero->setJumpDelta(Hero->getJumpStrength());
      }
    }
    if (Control->commandEntered(NEngine::NControl::ECI_PLAYER_JUMP)) {
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

    if (Hero->getWallCollision(N3D::NCollision::ERT_WALL_P, MapSections->getSection(0), normal) < 1.0f
    || Hero->getWallCollision(N3D::NCollision::ERT_WALL_Q, MapSections->getSection(0), normal) < 1.0f) {
      while (Hero->getWallCollision(N3D::NCollision::ERT_WALL_P, MapSections->getSection(0), normal) < 0.99
      || Hero->getWallCollision(N3D::NCollision::ERT_WALL_Q, MapSections->getSection(0), normal) < 0.99) {
        Hero->moveOpposite(normal);
      }
    }
  }
}

//! Manages interactions between Hero and NPCs
void CSceneGameplay::manageCharacterNPCInteraction()
{
  N3D::NCharacter::CNPC* npc = NPCInterface->getNearestNPC(Hero);
  if (npc) {
    if (npc->getDistanceFrom(Hero) < 1.0f) {
      if (Control->commandEntered(NEngine::NControl::ECI_DIALOG_ACTION, NEngine::NEvent::EET_ONCE)) {
        npc->talk("npc_dialog_identifier_lambda");
      }
    }
  }
}

//! Manages menu control
void CSceneGameplay::manageMenuControl()
{
  if (Control->commandEntered(NEngine::NControl::ECI_MENU_OK, NEngine::NEvent::EET_ONCE)) {
    if (PauseScreen->getSectionMenu()->getCurrentOption() == 9) {
      QuitIsFading = true;
      fadeOut(0.5f);
    }
  }
  if (QuitIsFading && OutFader->isReady()) {
    NEngine::NCore::CGame::changeScene(ESI_MENU);
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
  HudEnsemble->render();
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

}}
