/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../include/core.h"

using namespace irr;
using namespace std;

SceneMenu::SceneMenu() : Scene() {
  cam = new TPCamera();
  cam->setControl(false);

  mainMenu = new Menu();
  mainMenu->addOption(MENU_ICON_NONE, L"Nouvelle partie");
  mainMenu->addOption(MENU_ICON_NONE, L"Charger");
  mainMenu->addOption(MENU_ICON_NONE, L"Base de données");
  mainMenu->addOption(MENU_ICON_NONE, L"Quitter");
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
      case 0: Game::changeScene(SCENE_MAP_CANYON); break; //Game::loadScene(SCENE_MAP_CANYON); break;
      case 1:  break;
      case 2:  break;
      case 3: Game::debugExit(); break;
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
