/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../../include/ref/core.h"
#include "../../../../include/Game.h"
#include "../../../../include/Keyboard.h"
#include "../../../../include/Translation.h"
#include "../../../../include/gui/menus/gameplay/GameplayMenu.h"
#include "../../../../include/gui/menus/common/Menu.h"
#include "../../../../include/gui/menus/common/MenuOption.h"
#include "../../../../include/gui/Picture.h"
#include "../../../../include/gui/gameplay/PlayerState.h"
#include "../../../../include/gui/counter/GameTimeCounter.h"

using namespace irr;
using namespace std;

/**
 * All elements creation
 */
GameplayMenu::GameplayMenu(Translation* trans, Keyboard* kb)
{
  // Properties
  isVisible = false;

  // Sub Menus pointers
  wpMenu = NULL;
  spMenu = NULL;
  itMenu = NULL;
  mpMenu = NULL;
  stMenu = NULL;
  dmMenu = NULL;
  tlMenu = NULL;
  mnMenu = NULL;
  seMenu = NULL;

  // Translation pointer
  globalTranslations = trans;

  // Keyboard pointer
  keyboard = kb;

  // Black transparent background
  background = new Picture(0, 0, 1280, 720, "resource/hud/menus/gameplay/back.png");
  background->setOpacity(128);

  // Silver title top bar
  topBar = new Picture(0, Game::screenPos.top - 20, 1280, 40, "resource/hud/menus/gameplay/top_bar.png");

  // Menu (left)
  sectionMenu = new Menu(Game::screenPos.left + 80, Game::screenPos.top - 80, 150, 8, MENU_STYLE_TITLE);
  sectionMenu->addOption(MENU_ICON_NONE, trans->getTranslation("gameplay_menu_swords"));
  sectionMenu->addOption(MENU_ICON_NONE, trans->getTranslation("gameplay_menu_spirits"));
  sectionMenu->addOption(MENU_ICON_NONE, trans->getTranslation("gameplay_menu_items"));
  sectionMenu->addOption(MENU_ICON_NONE, trans->getTranslation("gameplay_menu_maps"));
  sectionMenu->addOption(MENU_ICON_NONE, trans->getTranslation("gameplay_menu_status"));
  sectionMenu->addOption(MENU_ICON_NONE, trans->getTranslation("gameplay_menu_dimensions"));
  sectionMenu->addOption(MENU_ICON_NONE, trans->getTranslation("gameplay_menu_tales"));
  sectionMenu->addOption(MENU_ICON_NONE, trans->getTranslation("gameplay_menu_monsters"));
  sectionMenu->addOption(MENU_ICON_NONE, trans->getTranslation("gameplay_menu_settings"));
  sectionMenu->addOption(MENU_ICON_NONE, trans->getTranslation("gameplay_menu_quit"));

  //sectionMenu->getOption(0)->setEnabled(false);

  // Player state info panel (right)
  stateInfo = new PlayerState();

  // Gameplay time
  gameplayTime = new GameTimeCounter();

  // Money TODO
  //moneyCounter = new DigitCounter();
}

/**
 * Gameplay menu render: all entities are rendered here
 */
void GameplayMenu::render()
{
  if (isVisible) {
    if (keyboard->pressed(KEY_DOWN, EVENT_ONCE)) {
      sectionMenu->nextOption();
    }
    if (keyboard->pressed(KEY_UP, EVENT_ONCE)) {
      sectionMenu->prevOption();
    }

    background->render();
    topBar->render();
    sectionMenu->render();
    stateInfo->render();
    gameplayTime->render();
    //moneyCounter->render();

    if (wpMenu) {
      wpMenu->render(keyboard);
    }
    if (spMenu) {
      spMenu->render(keyboard);
    }
    if (itMenu) {
      itMenu->render(keyboard);
    }
    if (mpMenu) {
      mpMenu->render(keyboard);
    }
    if (stMenu) {
      stMenu->render(keyboard);
    }
    if (dmMenu) {
      dmMenu->render(keyboard);
    }
    if (tlMenu) {
      tlMenu->render(keyboard);
    }
    if (mnMenu) {
      mnMenu->render(keyboard);
    }
    if (seMenu) {
      seMenu->render(keyboard);
    }
  }
}

void GameplayMenu::show()
{

}

void GameplayMenu::hide()
{

}

void GameplayMenu::setOpacity(u8 value)
{

}

/**
 * Toggles visibility of the menu
 */
void GameplayMenu::toggle()
{
  if (isVisible) {
    isVisible = false;
  } else {
    isVisible = true;
  }
}

/**
 *
 */
Menu* GameplayMenu::getSectionMenu()
{
  return sectionMenu;
}

/**
 *
 */
void GameplayMenu::goToWeaponMenu()
{
  wpMenu = new WeaponMenu();
}

/**
 *
 */
void GameplayMenu::goToSpiritMenu()
{

}

/**
 *
 */
void GameplayMenu::goToItemMenu()
{

}

/**
 *
 */
void GameplayMenu::goToMapMenu()
{

}

/**
 *
 */
void GameplayMenu::goToStatusMenu()
{

}

/**
 *
 */
void GameplayMenu::goToDimensionMenu()
{

}

/**
 *
 */
void GameplayMenu::goToTalesMenu()
{

}

/**
 *
 */
void GameplayMenu::goToMonstersMenu()
{

}

/**
 *
 */
void GameplayMenu::goToSettingsMenu()
{

}

/**
 *
 */
GameplayMenu::~GameplayMenu()
{
  delete background;
  delete topBar;
  delete sectionMenu;
  delete stateInfo;
  delete gameplayTime;
  //delete moneyCounter;
}
