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
#include "../../include/Save.h"

using namespace irr;
using namespace std;

SceneMenu::SceneMenu() : Scene()
{
  cam = new TPCamera();
  cam->setControl(false);

  cam->getNode()->setPosition(core::vector3df(0,1,-2700));
  cam->getNode()->setTarget(core::vector3df(0,100,0));
  cam->getNode()->setFarValue(10000.0f);

  // Temporary picture to avoid a strange bug in hud rendering (first picture to render badly positionned)
  dummy = new Picture(-5000, -5000, 0, 0);

  mainMenu = new Menu(-50, -100, 150, 8, MENU_STYLE_TITLE);
  mainMenu->addOption(MENU_ICON_NONE, globalTranslations->getTranslation("main_menu_new_game"));
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
}

void SceneMenu::events()
{
  Scene::events();

  lightRays->render();

  // Rotation des rayons de lumière
  if (lightRays->getNode()) {
    lightRays->getNode()->setRotation(core::vector3df(
      lightRays->getNode()->getRotation().X,
      lightRays->getNode()->getRotation().Y + (5 * Game::getSpeedFactor()),
      lightRays->getNode()->getRotation().Z
    ));
  }

  cam->getNode()->setPosition(core::vector3df(
    cam->getNode()->getPosition().X,
    cam->getNode()->getPosition().Y,
    cam->getNode()->getPosition().Z + (2 * Game::getSpeedFactor())
  ));
  if (keyboard->pressed(KEY_DOWN, EVENT_ONCE)) {
    mainMenu->nextOption();
  }
  if (keyboard->pressed(KEY_UP, EVENT_ONCE)) {
    mainMenu->prevOption();
  }
  if (keyboard->pressed(KEY_SPACE, EVENT_ONCE)) {
    switch (mainMenu->getCurrentOption()) {
      case 0: Game::getCurrentSave()->createNewFile(); break;
      case 1: Game::quit(); break;
    }
  }
}

void SceneMenu::postRender()
{
  Scene::postRender();
  dummy->render();
  mainMenu->render();
  title->render();
}

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
