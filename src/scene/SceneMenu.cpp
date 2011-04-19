/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"

using namespace irr;
using namespace std;

SceneMenu::SceneMenu() : Scene() {
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

  cpt = new BarCounter(100, 0, 100, 0, 0, 200, 10, BAR_STYLE_LIFE);
/*
  lightRays = new StaticModel();
  lightRays->loadMesh("resource/mesh/menus/title/rays.obj");
  lightRays->createNode(core::vector3df(0,1000,0));
  lightRays->getNode()->setMaterialFlag(video::EMF_BACK_FACE_CULLING, false);
  lightRays->getNode()->setMaterialType(video::EMT_TRANSPARENT_ALPHA_CHANNEL);
  lightRays->getNode()->setScale(core::vector3df(300.0f, 300.0f, 300.0f));
*/
/*
  cloud1 = new StaticModel();
  cloud1->loadMesh("resource/mesh/menus/title/nuage.obj");
  cloud1->createNode(core::vector3df(0,-400,-2000));
  cloud1->getNode()->setMaterialType(video::EMT_TRANSPARENT_ALPHA_CHANNEL);
  cloud1->getNode()->setScale(core::vector3df(1000.0f, 1000.0f, 0.0f));
  cloud1->getNode()->setRotation(core::vector3df(0.0f, 180.0f, 0.0f));
*/
}

void SceneMenu::events() { Scene::events();
  //lightRays->render();
  //cloud1->render();

  // Rotation des rayons de lumière
  /*
  lightRays->getNode()->setRotation(core::vector3df(
    lightRays->getNode()->getRotation().X,
    lightRays->getNode()->getRotation().Y + (5 * Game::getSpeedFactor()),
    lightRays->getNode()->getRotation().Z
  ));
  */

  cam->getNode()->setPosition(core::vector3df(
    cam->getNode()->getPosition().X,
    cam->getNode()->getPosition().Y,
    cam->getNode()->getPosition().Z + (2 * Game::getSpeedFactor())
  ));

  if(keyboard->pressed(KEY_KEY_A, EVENT_ONCE)) {
    cpt->setValue(30);
  }
  if(keyboard->pressed(KEY_KEY_Z, EVENT_ONCE)) {
    cpt->setValue(75);
  }

  if(keyboard->pressed(KEY_DOWN, EVENT_ONCE)) {
    mainMenu->nextOption();
  }
  if(keyboard->pressed(KEY_UP, EVENT_ONCE)) {
    mainMenu->prevOption();
  }
  if(keyboard->pressed(KEY_SPACE, EVENT_ONCE)) {
    switch(mainMenu->getCurrentOption()) {
      case 0: Game::getCurrentSave()->createNewFile(); break;
      case 1: Game::quit(); break;
    }
  }
}

void SceneMenu::postRender() { Scene::postRender();
  dummy->render();
  //mainMenu->render();
  //title->render();

  cpt->render();
}

SceneMenu::~SceneMenu() {
  delete dummy;
  //delete lightRays;
  //delete cloud1;

  delete cpt;

  delete title;
  delete mainMenu;
  delete cam;
}
