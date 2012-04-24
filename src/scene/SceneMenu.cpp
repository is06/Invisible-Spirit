/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/core.h"
#include "../../include/engine/Translation.h"
#include "../../include/engine/Game.h"
#include "../../include/engine/Keyboard.h"
#include "../../include/engine/Save.h"
#include "../../include/scene/SceneMenu.h"
#include "../../include/3d/TPCamera.h"
#include "../../include/3d/StaticModel.h"
#include "../../include/hud/Picture.h"
#include "../../include/hud/Menu.h"
#include "../../include/hud/Text.h"

namespace is06
{
namespace nScene
{

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

  Camera = new n3D::CTPCamera();
  Camera->setControl(false);

  Camera->getNode()->setPosition(core::vector3df(0.0f, 1.0f, -2700.0f));
  Camera->getNode()->setTarget(core::vector3df(0.0f, 100.0f, 0.0f));
  Camera->getNode()->setFarValue(10000.0f);

  MainMenu = new nHud::CMenu(nEngine::CGame::ScreenPos.Left + 100.0f, -100.0f, 150.0f, 8, nHud::MENU_STYLE_TITLE);
  MainMenu->addOption(nHud::MENU_ICON_NONE, GlobalTranslations->getTranslation("main_menu_launch_demo"));
  MainMenu->addOption(nHud::MENU_ICON_NONE, GlobalTranslations->getTranslation("main_menu_quit"));

  Title = new nHud::CPicture(nEngine::CGame::ScreenPos.Right - 413.0f, 100.0f, 826.0f, 101.0f, "resource/texture/menus/title/main.png");
  CreativeCommons = new nHud::CPicture(nEngine::CGame::ScreenPos.Left + 300.0f, nEngine::CGame::ScreenPos.Bottom + 50.0f, 420.0f, 44.0f, "resource/texture/menus/title/cc.png");

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

//!
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
    if (Control->commandEntered(nEngine::COMMAND_MENU_DOWN, nEngine::EVENT_ONCE)) {
      MainMenu->nextOption();
    }
    if (Control->commandEntered(nEngine::COMMAND_MENU_UP, nEngine::EVENT_ONCE)) {
      MainMenu->prevOption();
    }
    if (Control->commandEntered(nEngine::COMMAND_MENU_OK, nEngine::EVENT_ONCE)) {
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
        nEngine::CGame::getCurrentSave()->createNewFile(nEngine::DIFFICULTY_MEDIUM);
      }
      if (QuitIsFading) {
        // Quit to OS
        nEngine::CGame::quit();
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

/**
 * Get in Option menu
 */
void CSceneMenu::createOptionMenu()
{
  InMainMenu = false;
  InOptionMenu = true;
}

/**
 * Option menu events
 */
void CSceneMenu::manageOptionMenu()
{

}

/**
 * Quit Option menu
 */
void CSceneMenu::destroyOptionMenu()
{
  InMainMenu = true;
  InOptionMenu = false;
}

/**
 * @todo
 */
void CSceneMenu::retrieveSaveSlotList()
{
  clearSaveSlotList();
  for (u8 i = 0; i <= 255; i++) {
    nEngine::CSave* save = new nEngine::CSave();
    save->loadPrimitiveInfo(i);
    SaveSlotList[i] = new nEngine::CSaveSlot(save);
  }
}

/**
 * @todo
 */
void CSceneMenu::clearSaveSlotList()
{
  for (u8 i = 0; i <= 255; i++) {
    SaveSlotList[i] = NULL;
  }
}

/**
 * Init supported video mode list
 */
void CSceneMenu::initModeList()
{
  video::IVideoModeList* vml = nEngine::CGame::getDevice()->getVideoModeList();
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

}
}
