/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/core.h"
#include "../../include/NEngine/NResource/CTranslation.h"
#include "../../include/NEngine/NCore/CGame.h"
#include "../../include/NEngine/NControl/CKeyboard.h"
#include "../../include/NEngine/NSave/CSave.h"
#include "../../include/NScene/CSceneMenu.h"
#include "../../include/N3D/NCamera/CThirdPerson.h"
#include "../../include/N3D/NPrimitive/CStaticModel.h"
#include "../../include/NHud/NPrimitive/CPicture.h"
#include "../../include/NHud/NMenu/CMenu.h"
#include "../../include/NHud/NText/CText.h"

namespace is06 { namespace NScene {

//! Init common elements
CSceneMenu::CSceneMenu() : CScene()
{
  BackBufferColor = video::SColor(255, 255, 255, 255);

  NewGameIsFading = false;
  QuitIsFading = false;

  InTitleFadeIn = false;
  InMainMenu = true;
  InSaveListMenu = false;
  InOptionMenu = false;
  InNewGameFadeOut = false;

  initModeList();

  Camera = new N3D::NCamera::CThirdPerson();
  Camera->setControl(false);

  Camera->getNode()->setPosition(core::vector3df(0.0f, 1.0f, -2700.0f));
  Camera->getNode()->setTarget(core::vector3df(0.0f, 100.0f, 0.0f));
  Camera->getNode()->setFarValue(10000.0f);

  MainMenu = new NHud::NMenu::CMenu(NEngine::NCore::CGame::ScreenPos.Hud.Left + 100.0f, -100.0f, 150.0f, 8, NHud::NMenu::EMS_TITLE);
  MainMenu->addOption(NHud::NMenu::EMI_NONE, GlobalTranslations->getTranslation("main_menu_launch_demo"));
  MainMenu->addOption(NHud::NMenu::EMI_NONE, GlobalTranslations->getTranslation("main_menu_quit"));

  Title = new NHud::NPrimitive::CPicture(NEngine::NCore::CGame::ScreenPos.Hud.Right - 413.0f, 100.0f, 826.0f, 101.0f, "resource/texture/menus/title/main.png");
  CreativeCommons = new NHud::NPrimitive::CPicture(NEngine::NCore::CGame::ScreenPos.Hud.Left + 300.0f, NEngine::NCore::CGame::ScreenPos.Hud.Bottom + 50.0f, 420.0f, 44.0f, "resource/texture/menus/title/cc.png");

  fadeIn(0.5f);
}

//! Common events
void CSceneMenu::events()
{
  CScene::events();

  // Camera movement
  if (Camera->getZ() < 3500.0f) {
    Camera->moveZ(2.0f);
  }

  if (InMainMenu) {
    manageMainMenu();
  } else if (InSaveListMenu) {
    manageSaveListMenu();
  } else if (InOptionMenu) {
    manageOptionMenu();
  }
}

void CSceneMenu::postRender()
{
  CScene::postRender();
}

//! Hud render
void CSceneMenu::hudRender()
{
  CScene::hudRender();

  MainMenu->render();
  Title->render();
  CreativeCommons->render();
}

//! Main Menu events
void CSceneMenu::manageMainMenu()
{
  if (!QuitIsFading && !NewGameIsFading) {
    if (Control->commandEntered(NEngine::NControl::ECI_MENU_DOWN, NEngine::NEvent::EET_ONCE)) {
      MainMenu->nextOption();
    }
    if (Control->commandEntered(NEngine::NControl::ECI_MENU_UP, NEngine::NEvent::EET_ONCE)) {
      MainMenu->prevOption();
    }
    if (Control->commandEntered(NEngine::NControl::ECI_MENU_OK, NEngine::NEvent::EET_ONCE)) {
      switch (MainMenu->getCurrentOption()) {
        case 0:
          // Fade Out and boolean to go to gameplay (demo)
          fadeOut(0.5f);
          NewGameIsFading = true;
          break;
          /*
        case 1:
          createSaveListMenu();
          break;
        case 2:
          createOptionMenu();
          break;
          */
        case 1:
          // Fade Out and boolean to quit the game
          fadeOut(0.5f);
          QuitIsFading = true;
          break;
        default: break;
      }
    }
  } else {
    if (OutFader->isReady()) {
      if (NewGameIsFading) {
        // New Game
        NEngine::NCore::CGame::getCurrentSave()->newGame(NEngine::NGameplay::EDL_MEDIUM);
      }
      if (QuitIsFading) {
        // Quit to OS
        NEngine::NCore::CGame::quit();
      }
    }
  }
}

//! Get in Save List menu
void CSceneMenu::createSaveListMenu()
{
  InMainMenu = false;
  InSaveListMenu = true;

  retrieveSaveSlotList();
}

//! Save List menu events
void CSceneMenu::manageSaveListMenu()
{

}

//! Quit Save List menu
void CSceneMenu::destroySaveListMenu()
{
  InMainMenu = true;
  InSaveListMenu = false;
}

//! Get in Option menu
void CSceneMenu::createOptionMenu()
{
  InMainMenu = false;
  InOptionMenu = true;
}

//! Option menu events
void CSceneMenu::manageOptionMenu()
{

}

//! Quit Option menu
void CSceneMenu::destroyOptionMenu()
{
  InMainMenu = true;
  InOptionMenu = false;
}

void CSceneMenu::retrieveSaveSlotList()
{
  clearSaveSlotList();
  for (u8 i = 0; i <= 255; i++) {
    NEngine::NSave::CSave* save = new NEngine::NSave::CSave();
    save->loadPrimitiveInfo(i);
    SaveSlotList[i] = new NEngine::NSave::CSaveSlot(save);
  }
}

void CSceneMenu::clearSaveSlotList()
{
  for (u8 i = 0; i <= 255; i++) {
    SaveSlotList[i] = NULL;
  }
}

//! Init supported video mode list
void CSceneMenu::initModeList()
{
  video::IVideoModeList* vml = NEngine::NCore::CGame::getDevice()->getVideoModeList();
  s32 videoModeCount = vml->getVideoModeCount();
  s32 colorDepth;
  core::dimension2du vres;

  for (s32 i = 0; i < videoModeCount; i++) {
    vres = vml->getVideoModeResolution(i);
    colorDepth = vml->getVideoModeDepth(i);

    ModeList[i] = core::vector3di(vres.Width, vres.Height, colorDepth);
  }
}

CSceneMenu::~CSceneMenu()
{
  delete Title;
  delete CreativeCommons;
  delete MainMenu;
  delete Camera;
}

}}
