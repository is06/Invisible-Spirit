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

  //message = new Text("Voici un message a afficher progressivement\nMeme sur plusieurs lignes si c'est possible", Game::screenPos.left + 10, Game::screenPos.top - 10, FONT_STD_REGULAR, 1.0f);

  mainMenu = new Menu();
  mainMenu->addOption(MENU_ICON_NONE, L"Alpha Zone");
  mainMenu->addOption(MENU_ICON_NONE, L"Map Canyon");
  //mainMenu->addOption(MENU_ICON_NONE, L"Charger");
  //mainMenu->addOption(MENU_ICON_NONE, L"Base de donnees");
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
      case 0: Game::changeScene(SCENE_MAP_ALPHA_ZONE); break;
      case 1: Game::changeScene(SCENE_MAP_CANYON); break;
      case 2: Game::debugExit(); break;
    }
  }
}

void SceneMenu::postRender() { Scene::postRender();
  mainMenu->render();
  //message->render();
}

SceneMenu::~SceneMenu() {
  delete mainMenu;
  //delete message;
  delete cam;
}
