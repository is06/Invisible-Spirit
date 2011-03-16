/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"

using namespace irr;
using namespace std;

GameplayMenu::GameplayMenu() {
  isVisible = false;

  sectionMenu = new Menu(Game::screenPos.left + 24, Game::screenPos.top - 48);
  sectionMenu->addOption(MENU_ICON_NONE, L"Etat");
  sectionMenu->addOption(MENU_ICON_NONE, L"Competences");
  sectionMenu->addOption(MENU_ICON_NONE, L"Objets");
  sectionMenu->addOption(MENU_ICON_NONE, L"Configuration");
  sectionMenu->addOption(MENU_ICON_NONE, L"Quitter le jeu");

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
