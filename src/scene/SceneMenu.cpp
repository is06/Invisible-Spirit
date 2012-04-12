/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/scene/SceneMenu.h"
#include "../../include/3d/TPCamera.h"
#include "../../include/3d/StaticModel.h"
#include "../../include/gui/Picture.h"
#include "../../include/gui/menus/common/Menu.h"
#include "../../include/gui/Text.h"
#include "../../include/Translation.h"
#include "../../include/Game.h"
#include "../../include/Keyboard.h"
#include "../../include/save/Save.h"

namespace is06
{
namespace scene
{

/**
 * Init common elements
 */
CSceneMenu::CSceneMenu() : CScene()
{
  NewGameIsFading = false;
  QuitIsFading = false;

  InTitleFadeIn = false;
  InMainMenu = true;
  InSaveListMenu = false;
  InOptionMenu = false;
  InNewGameFadeOut = false;

  initModeList();

  Camera = new model::CTPCamera();
  Camera->setControl(false);

  Camera->getNode()->setPosition(irr::core::vector3df(0,1,-2700));
  Camera->getNode()->setTarget(irr::core::vector3df(0,100,0));
  Camera->getNode()->setFarValue(10000.0f);

  MainMenu = new hud::CMenu(engine::CGame::ScreenPos.Left + 100, -100, 150, 8, hud::MENU_STYLE_TITLE);
  MainMenu->addOption(hud::MENU_ICON_NONE, GlobalTranslations->getTranslation("main_menu_launch_demo"));
  MainMenu->addOption(hud::MENU_ICON_NONE, GlobalTranslations->getTranslation("main_menu_quit"));

  Title = new hud::CPicture(engine::CGame::ScreenPos.Right - 413, 100, 826, 101, "resource/texture/menus/title/main.png");
  CreativeCommons = new hud::CPicture(engine::CGame::ScreenPos.Left + 300, engine::CGame::ScreenPos.Bottom + 50, 420, 44, "resource/texture/menus/title/cc.png");

  fadeIn(0.5f);
}

/**
 * Common events
 */
void CSceneMenu::events()
{
  CScene::events();

  // Camera movement
  if (Camera->getZ() < 3500) {
    Camera->moveZ(2);
  }

  if (InMainMenu) {
    manageMainMenu();
  } else if (InSaveListMenu) {
    manageSaveListMenu();
  } else if (InOptionMenu) {
    manageOptionMenu();
  }
}

/**
 *
 */
void CSceneMenu::postRender()
{
  CScene::postRender();
}

/**
 * Hud render
 */
void CSceneMenu::hudRender()
{
  CScene::hudRender();

  MainMenu->render();
  Title->render();
  CreativeCommons->render();
}

/**
 * Main Menu events
 */
void CSceneMenu::manageMainMenu()
{
  if (!QuitIsFading && !NewGameIsFading) {
    if (Keyboard->pressed(irr::KEY_DOWN, engine::EVENT_ONCE)) {
      MainMenu->nextOption();
    }
    if (Keyboard->pressed(irr::KEY_UP, engine::EVENT_ONCE)) {
      MainMenu->prevOption();
    }
    if (Keyboard->pressed(irr::KEY_SPACE, engine::EVENT_ONCE)) {
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
        engine::CGame::getCurrentSave()->createNewFile();
      }
      if (QuitIsFading) {
        // Quit to OS
        engine::CGame::quit();
      }
    }
  }
}

/**
 * Get in Save List menu
 */
void CSceneMenu::createSaveListMenu()
{
  InMainMenu = false;
  InSaveListMenu = true;

  retrieveSaveSlotList();
}

/**
 * Save List menu events
 */
void CSceneMenu::manageSaveListMenu()
{

}

/**
 * Quit Save List menu
 */
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
  for (irr::u8 i = 0; i <= 255; i++) {
    engine::CSave* save = new engine::CSave();
    save->loadPrimitiveInfo(i);
    SaveSlotList[i] = new engine::CSaveSlot(save);
  }
}

/**
 * @todo
 */
void CSceneMenu::clearSaveSlotList()
{
  for (irr::u8 i = 0; i <= 255; i++) {
    SaveSlotList[i] = NULL;
  }
}

/**
 * Init supported video mode list
 */
void CSceneMenu::initModeList()
{
  irr::video::IVideoModeList* vml = engine::CGame::getDevice()->getVideoModeList();
  irr::s32 videoModeCount = vml->getVideoModeCount();
  irr::s32 colorDepth;
  irr::core::dimension2du vres;

  for (irr::s32 i = 0; i < videoModeCount; i++) {
    vres = vml->getVideoModeResolution(i);
    colorDepth = vml->getVideoModeDepth(i);

    ModeList[i] = irr::core::vector3di(vres.Width, vres.Height, colorDepth);
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
