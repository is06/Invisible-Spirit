/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"

using namespace irr;

// 0 = No Menu
// 1 = Main Menu
// 2 = Sub menu...

MapEditor::MapEditor() {
  currentMenuID = 0;

  mainMenu = new DebugMenu(10);

  mainMenu->addOption(L"Map");
  mainMenu->addOption(L"Entity");
  mainMenu->addOption(L"Effect");
  mainMenu->addOption(L"Music");

  for(u32 i = 0; i <= 4; i++) {
    subMenu[i] = new DebugMenu(((i+1) * 80) + 10);
  }
}

void MapEditor::events() {
  mainMenu->events();
  for(u32 i = 0; i <= 4; i++) {
    subMenu[i]->events();
  }

  if(currentMenuID == 1 && Game::getEventManager()->isKeyDownOnce(KEY_SPACE)) {
    switch(mainMenu->getCurrentOption()) {
      case 0: // Map
        currentMenuID = 10;
        subMenu[0]->removeAllOptions();
        subMenu[0]->addOption(L"Ambient light");
        subMenu[0]->addOption(L"Fog");
        subMenu[0]->addOption(L"Sky");
        subMenu[0]->addOption(L"Newton world");
        subMenu[0]->addOption(L"Debug data");
        subMenu[0]->addOption(L"Save increment");
        subMenu[0]->addOption(L"Save override");
        subMenu[0]->addOption(L"Reload");
      break;
      case 1: // Entity
        currentMenuID = 11;
        subMenu[0]->removeAllOptions();
        subMenu[0]->addOption(L"Animated");
        subMenu[0]->addOption(L"Static");
        subMenu[0]->addOption(L"Camera");
        subMenu[0]->addOption(L"Light");
        subMenu[0]->addOption(L"Speaker");
        subMenu[0]->addOption(L"Zone");
      break;
      case 2: // Effect
        currentMenuID = 12;
        subMenu[0]->removeAllOptions();
        subMenu[0]->addOption(L"Glow");
      break;
      case 3: // Music
        currentMenuID = 13;
        subMenu[0]->removeAllOptions();
        subMenu[0]->addOption(L"Add");
        subMenu[0]->addOption(L"Remove all");
      break;
    }
  } else if(currentMenuID == 10 && Game::getEventManager()->isKeyDownOnce(KEY_SPACE)) {
    currentMenuID = 3;
    switch(subMenu[0]->getCurrentOption()) {
      case 0: // Ambient Light
        subMenu[1]->removeAllOptions();
        subMenu[1]->addOption(L"Active", DEBUG_MENU_OPTION_CHECKBOX);
        subMenu[1]->addOption(L"Color");
      break;
    }
  }
}

void MapEditor::toggle() {
  if(active) {
    active = false;
    currentMenuID = 0;
  } else {
    active = true;
    currentMenuID = 1;
  }
}

bool MapEditor::isRunning() {
  return active;
}

MapEditor::~MapEditor() {
  delete mainMenu;
}
