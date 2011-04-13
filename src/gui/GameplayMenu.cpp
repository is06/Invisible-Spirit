/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"

using namespace irr;
using namespace std;

GameplayMenu::GameplayMenu(Translation* trans) {
  globalTranslations = trans;

  isVisible = false;

  sectionMenu = new Menu(Game::screenPos.left + 24, Game::screenPos.top - 48);
  sectionMenu->addOption(MENU_ICON_NONE, trans->getTranslation("gameplay_menu_status"));
  sectionMenu->addOption(MENU_ICON_NONE, trans->getTranslation("gameplay_menu_powers"));
  sectionMenu->addOption(MENU_ICON_NONE, trans->getTranslation("gameplay_menu_items"));
  sectionMenu->addOption(MENU_ICON_NONE, trans->getTranslation("gameplay_menu_config"));
  sectionMenu->addOption(MENU_ICON_NONE, trans->getTranslation("gameplay_menu_quit"));

  stateInfo = new PlayerState();
}

void GameplayMenu::render() {
  if(isVisible) {
    sectionMenu->render();
    stateInfo->render();
  }
}

void GameplayMenu::toggle() {
  if(isVisible) {
    isVisible = false;
  } else {
    isVisible = true;
  }
}

Menu* GameplayMenu::getSectionMenu() {
  return sectionMenu;
}

GameplayMenu::~GameplayMenu() {
  delete sectionMenu;
  delete stateInfo;
}
