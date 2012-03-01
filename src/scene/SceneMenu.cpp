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
#include "../../include/gui/Menu.h"
#include "../../include/Translation.h"
#include "../../include/Game.h"
#include "../../include/Keyboard.h"
#include "../../include/save/Save.h"

using namespace irr;
using namespace std;

/**
 * Init common elements
 */
SceneMenu::SceneMenu() : Scene()
{
  newGameIsFading = false;
  quitIsFading = false;

  inTitleFadeIn = false;
  inMainMenu = true;
  inSaveListMenu = false;
  inOptionMenu = false;
  inNewGameFadeOut = false;

  initModeList();

  cam = new TPCamera();
  cam->setControl(false);

  cam->getNode()->setPosition(core::vector3df(0,1,-2700));
  cam->getNode()->setTarget(core::vector3df(0,100,0));
  cam->getNode()->setFarValue(10000.0f);

  // Temporary picture to avoid a strange bug in hud rendering (first picture to render badly positionned)
  dummy = new Picture(-5000, -5000, 0, 0);

  mainMenu = new Menu(-50, -100, 150, 8, MENU_STYLE_TITLE);
  mainMenu->addOption(MENU_ICON_NONE, globalTranslations->getTranslation("main_menu_new_game"));
  mainMenu->addOption(MENU_ICON_NONE, globalTranslations->getTranslation("main_menu_load_game"));
  mainMenu->addOption(MENU_ICON_NONE, globalTranslations->getTranslation("main_menu_option"));
  mainMenu->addOption(MENU_ICON_NONE, globalTranslations->getTranslation("main_menu_quit"));

  title = new Picture(100, 0, 256, 102, "resource/texture/menus/title/main.png");

  lightRays = new StaticModel();
  lightRays->loadMesh("resource/mesh/menus/title/rays.obj");
  lightRays->createNode(core::vector3df(0,1000,0));
  if (lightRays->getNode()) {
    lightRays->getNode()->setMaterialFlag(video::EMF_BACK_FACE_CULLING, false);
    lightRays->getNode()->setMaterialType(video::EMT_TRANSPARENT_ALPHA_CHANNEL);
    lightRays->getNode()->setScale(core::vector3df(300.0f, 300.0f, 300.0f));
  }

  fadeIn();
}

/**
 * Common events
 */
void SceneMenu::events()
{
  Scene::events();

  // Light rays rotation
  lightRays->render();
  if (lightRays->getNode()) {
    lightRays->turnY(5);
  }

  // Camera movement
  if (cam->getZ() < 3500) {
    cam->moveZ(2);
  }

  if (inMainMenu) {
    manageMainMenu();
  } else if (inSaveListMenu) {
    manageSaveListMenu();
  } else if (inOptionMenu) {
    manageOptionMenu();
  }
}

/**
 * Hud render
 */
void SceneMenu::postRender()
{
  Scene::postRender();
  dummy->render();
  mainMenu->render();
  title->render();
}

/**
 * Main Menu events
 */
void SceneMenu::manageMainMenu()
{
  cout << (u32)fader->isReady() << endl;
  if (!quitIsFading && !newGameIsFading) {
    if (keyboard->pressed(KEY_DOWN, EVENT_ONCE)) {
      mainMenu->nextOption();
    }
    if (keyboard->pressed(KEY_UP, EVENT_ONCE)) {
      mainMenu->prevOption();
    }
    if (keyboard->pressed(KEY_SPACE, EVENT_ONCE)) {
      switch (mainMenu->getCurrentOption()) {
        case 0:
          // Fade Out and boolean to go to gameplay (demo)
          fader->fadeOut(1.0f);
          newGameIsFading = true;
          break;
        case 1:
          createSaveListMenu();
          break;
        case 2:
          createOptionMenu();
          break;
        case 3:
          // Fade Out and boolean to quit the game
          fader->fadeOut(1.0f);
          quitIsFading = true;
          break;
        default: break;
      }
    }
  } else {
    if (fader->isReady()) {
      if (newGameIsFading) {
        // New Game
        Game::getCurrentSave()->createNewFile();
      }
      if (quitIsFading) {
        // Quit to OS
        //Game::quit();
      }
    }
  }

  if (fader->isReady()) {
    fader->remove();
    fader = Game::getDebugGUI()->addInOutFader();
  }
}

/**
 * Get in Save List menu
 */
void SceneMenu::createSaveListMenu()
{
  inMainMenu = false;
  inSaveListMenu = true;

  retrieveSaveSlotList();
}

/**
 * Save List menu events
 */
void SceneMenu::manageSaveListMenu()
{

}

/**
 * Quit Save List menu
 */
void SceneMenu::destroySaveListMenu()
{
  inMainMenu = true;
  inSaveListMenu = false;
}

/**
 * Get in Option menu
 */
void SceneMenu::createOptionMenu()
{
  inMainMenu = false;
  inOptionMenu = true;
}

/**
 * Option menu events
 */
void SceneMenu::manageOptionMenu()
{

}

/**
 * Quit Option menu
 */
void SceneMenu::destroyOptionMenu()
{
  inMainMenu = true;
  inOptionMenu = false;
}

/**
 * @todo
 */
void SceneMenu::retrieveSaveSlotList()
{
  clearSaveSlotList();
  for (u8 i = 0; i <= 255; i++) {
    Save* save = new Save();
    save->loadPrimitiveInfo(i);
    saveSlotList[i] = new SaveSlot(save);
  }
}

/**
 * @todo
 */
void SceneMenu::clearSaveSlotList()
{
  for (u8 i = 0; i <= 255; i++) {
    saveSlotList[i] = NULL;
  }
}

/**
 * Init supported video mode list
 */
void SceneMenu::initModeList()
{
  video::IVideoModeList* vml = Game::getDevice()->getVideoModeList();

  s32 videoModeCount = vml->getVideoModeCount();
  s32 colorDepth;
  core::dimension2du vres;

  for (s32 i = 0; i < videoModeCount; i++) {
    vres = vml->getVideoModeResolution(i);
    colorDepth = vml->getVideoModeDepth(i);

    modeList[i] = core::vector3di(vres.Width, vres.Height, colorDepth);
  }
}

SceneMenu::~SceneMenu()
{
  delete dummy;
  delete lightRays;
  delete title;
  delete mainMenu;
  delete cam;
}
