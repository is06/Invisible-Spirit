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
  active = false;
  mainMenu = new DebugMenu(10);

  mainMenu->addOption(L"Map");
    mainMenu->getSubMenu(0)->addOption(L"Ambient Light");
      mainMenu->getSubMenu(0)->getSubMenu(0)->addOption(L"Active", DEBUG_MENU_OPTION_CHECKBOX);
      mainMenu->getSubMenu(0)->getSubMenu(0)->addOption(L"Color", DEBUG_MENU_OPTION_COLOR);
    mainMenu->getSubMenu(0)->addOption(L"Fog");
      mainMenu->getSubMenu(0)->getSubMenu(1)->addOption(L"Active", DEBUG_MENU_OPTION_CHECKBOX);
      mainMenu->getSubMenu(0)->getSubMenu(1)->addOption(L"Color", DEBUG_MENU_OPTION_COLOR);
      mainMenu->getSubMenu(0)->getSubMenu(1)->addOption(L"Type");
        mainMenu->getSubMenu(0)->getSubMenu(1)->getSubMenu(2)->addOption(L"Linear", DEBUG_MENU_OPTION_RADIO);
        mainMenu->getSubMenu(0)->getSubMenu(1)->getSubMenu(2)->addOption(L"Exp", DEBUG_MENU_OPTION_RADIO);
        mainMenu->getSubMenu(0)->getSubMenu(1)->getSubMenu(2)->addOption(L"Exp2", DEBUG_MENU_OPTION_RADIO);
      mainMenu->getSubMenu(0)->getSubMenu(1)->addOption(L"Near", DEBUG_MENU_OPTION_FLOAT);
      mainMenu->getSubMenu(0)->getSubMenu(1)->addOption(L"Far", DEBUG_MENU_OPTION_FLOAT);
    //mainMenu->getSubMenu(0)->addOption(L"Sky");
    //mainMenu->getSubMenu(0)->addOption(L"Newton world");
    //mainMenu->getSubMenu(0)->addOption(L"Debug data");
    //mainMenu->getSubMenu(0)->addOption(L"Save increment");
    //mainMenu->getSubMenu(0)->addOption(L"Save override");
    //mainMenu->getSubMenu(0)->addOption(L"Reload");
  //mainMenu->addOption(L"Entity");
    //mainMenu->getSubMenu(1)->addOption(L"Animated");
    //mainMenu->getSubMenu(1)->addOption(L"Static");
    //mainMenu->getSubMenu(1)->addOption(L"Camera");
    //mainMenu->getSubMenu(1)->addOption(L"Light");
    //mainMenu->getSubMenu(1)->addOption(L"Speaker");
    //mainMenu->getSubMenu(1)->addOption(L"Zone");
  //mainMenu->addOption(L"Effect");
    //mainMenu->getSubMenu(2)->addOption(L"Glow");
  //mainMenu->addOption(L"Music");
    //mainMenu->getSubMenu(3)->addOption(L"Add");
    //mainMenu->getSubMenu(3)->addOption(L"Remove all");

  mainMenu->setVisible(true);
  mainMenu->setBrowseable(true);
}

void MapEditor::events() {
  if(active) {
    mainMenu->events();
  }
}

void MapEditor::toggle() {
  if(active) {
    active = false;
  } else {
    active = true;
  }
}

bool MapEditor::isRunning() {
  return active;
}

MapEditor::~MapEditor() {
  delete mainMenu;
}
