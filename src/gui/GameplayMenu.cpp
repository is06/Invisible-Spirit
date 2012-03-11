/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/gui/GameplayMenu.h"
#include "../../include/Game.h"
#include "../../include/gui/Menu.h"
#include "../../include/gui/Picture.h"
#include "../../include/Translation.h"
#include "../../include/gui/PlayerState.h"

using namespace irr;
using namespace std;

GameplayMenu::GameplayMenu(Translation* trans)
{
  globalTranslations = trans;

  isVisible = false;

  sectionMenu = new Menu(Game::screenPos.left + 80, Game::screenPos.top - 80, 150, 8, MENU_STYLE_TITLE);
  sectionMenu->addOption(MENU_ICON_NONE, trans->getTranslation("gameplay_menu_swords"));
  sectionMenu->addOption(MENU_ICON_NONE, trans->getTranslation("gameplay_menu_spirits"));
  sectionMenu->addOption(MENU_ICON_NONE, trans->getTranslation("gameplay_menu_items"));
  sectionMenu->addOption(MENU_ICON_NONE, trans->getTranslation("gameplay_menu_status"));
  sectionMenu->addOption(MENU_ICON_NONE, trans->getTranslation("gameplay_menu_dimensions"));
  sectionMenu->addOption(MENU_ICON_NONE, trans->getTranslation("gameplay_menu_tales"));
  sectionMenu->addOption(MENU_ICON_NONE, trans->getTranslation("gameplay_menu_monsters"));
  sectionMenu->addOption(MENU_ICON_NONE, trans->getTranslation("gameplay_menu_settings"));
  sectionMenu->addOption(MENU_ICON_NONE, trans->getTranslation("gameplay_menu_quit"));

  stateInfo = new PlayerState();

  background = new Picture(0, 0, 1280, 720, "resource/hud/menus/gameplay/back.png");
  background->setOpacity(128);
  topBar = new Picture(0, Game::screenPos.top - 20, 1280, 40, "resource/hud/menus/gameplay/top_bar.png");
}

void GameplayMenu::render()
{
  if (isVisible) {
    background->render();
    topBar->render();

    //stateInfo->render();
    sectionMenu->render();
  }
}

void GameplayMenu::toggle()
{
  if (isVisible) {
    isVisible = false;
  } else {
    isVisible = true;
  }
}

Menu* GameplayMenu::getSectionMenu()
{
  return sectionMenu;
}

GameplayMenu::~GameplayMenu()
{
  delete sectionMenu;
  delete stateInfo;
  delete background;
  delete topBar;
}
