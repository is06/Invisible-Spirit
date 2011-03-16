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

  mainMenu = new Menu();
  mainMenu->addOption(MENU_ICON_NONE, L"Alpha Zone");
  mainMenu->addOption(MENU_ICON_NONE, L"Map Canyon");
  mainMenu->addOption(MENU_ICON_NONE, globalTranslations->getTranslation("main_menu_quit"));
}

void SceneMenu::events() { Scene::events();
  if(keyboard->pressed(KEY_DOWN, EVENT_ONCE)) {
    mainMenu->nextOption();
  }
  if(keyboard->pressed(KEY_UP, EVENT_ONCE)) {
    mainMenu->prevOption();
  }
  if(keyboard->pressed(KEY_SPACE, EVENT_ONCE)) {
    switch(mainMenu->getCurrentOption()) {
      case 0: Game::changeScene(SCENE_MAP_ALPHA_ZONE); break;
      case 1: Game::changeScene(SCENE_MAP_CANYON); break;
      case 2: Game::debugExit(); break;
    }
  }
}

void SceneMenu::postRender() { Scene::postRender();
  mainMenu->render();
}

SceneMenu::~SceneMenu() {
  delete mainMenu;
  delete cam;
}
