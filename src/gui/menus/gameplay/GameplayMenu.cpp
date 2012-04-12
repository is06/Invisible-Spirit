/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../../include/ref/core.h"
#include "../../../../include/Game.h"
#include "../../../../include/save/Save.h"
#include "../../../../include/Keyboard.h"
#include "../../../../include/Translation.h"
#include "../../../../include/gui/menus/gameplay/GameplayMenu.h"
#include "../../../../include/gui/menus/common/Menu.h"
#include "../../../../include/gui/menus/common/MenuOption.h"
#include "../../../../include/gui/Picture.h"
#include "../../../../include/gui/gameplay/PlayerState.h"
#include "../../../../include/gui/counter/GameTimeCounter.h"

namespace is06
{
namespace hud
{

/**
 * All elements creation
 */
CGameplayMenu::CGameplayMenu(engine::CTranslation* translation, engine::CKeyboard* keyboard)
{
  // Properties
  IsVisible = false;

  // Sub Menus pointers
  WpMenu = NULL;
  SpMenu = NULL;
  ItMenu = NULL;
  MpMenu = NULL;
  StMenu = NULL;
  DmMenu = NULL;
  TlMenu = NULL;
  MnMenu = NULL;
  SeMenu = NULL;

  // Keyboard pointer
  Keyboard = keyboard;

  // Translation pointer
  GlobalTranslations = translation;

  // Black transparent background
  Background = new CPicture(0, 0, 1280, 720, "resource/hud/menus/gameplay/back.png");
  Background->setOpacity(128);

  // Silver title top bar
  TopBar = new CPicture(0, engine::CGame::ScreenPos.Top - 20, 1280, 40, "resource/hud/menus/gameplay/top_bar.png");

  // Menu (left)
  SectionMenu = new CMenu(engine::CGame::ScreenPos.Left + 80, engine::CGame::ScreenPos.Top - 80, 150, 8, MENU_STYLE_TITLE);
  SectionMenu->addOption(MENU_ICON_NONE, GlobalTranslations->getTranslation("gameplay_menu_swords"));
  SectionMenu->addOption(MENU_ICON_NONE, GlobalTranslations->getTranslation("gameplay_menu_spirits"));
  SectionMenu->addOption(MENU_ICON_NONE, GlobalTranslations->getTranslation("gameplay_menu_items"));
  SectionMenu->addOption(MENU_ICON_NONE, GlobalTranslations->getTranslation("gameplay_menu_maps"));
  SectionMenu->addOption(MENU_ICON_NONE, GlobalTranslations->getTranslation("gameplay_menu_status"));
  SectionMenu->addOption(MENU_ICON_NONE, GlobalTranslations->getTranslation("gameplay_menu_dimensions"));
  SectionMenu->addOption(MENU_ICON_NONE, GlobalTranslations->getTranslation("gameplay_menu_tales"));
  SectionMenu->addOption(MENU_ICON_NONE, GlobalTranslations->getTranslation("gameplay_menu_monsters"));
  SectionMenu->addOption(MENU_ICON_NONE, GlobalTranslations->getTranslation("gameplay_menu_settings"));
  SectionMenu->addOption(MENU_ICON_NONE, GlobalTranslations->getTranslation("gameplay_menu_quit"));

  //sectionMenu->getOption(0)->setEnabled(false);

  // Player state info panel (right)
  StateInfo = new CPlayerState();

  // Gameplay time
  GameplayTime = new CGameTimeCounter();

  // Money TODO
  //moneyCounter = new DigitCounter();
}

/**
 * Gameplay menu render: all entities are rendered here
 */
void CGameplayMenu::render()
{
  if (IsVisible) {
    if (Keyboard->pressed(irr::KEY_DOWN, engine::EVENT_ONCE)) {
      SectionMenu->nextOption();
    }
    if (Keyboard->pressed(irr::KEY_UP, engine::EVENT_ONCE)) {
      SectionMenu->prevOption();
    }

    Background->render();
    TopBar->render();
    SectionMenu->render();
    StateInfo->render();
    GameplayTime->render();
    //moneyCounter->render();

    if (WpMenu) {
      WpMenu->render();
    }
    if (SpMenu) {
      SpMenu->render();
    }
    if (ItMenu) {
      ItMenu->render();
    }
    if (MpMenu) {
      MpMenu->render();
    }
    if (StMenu) {
      StMenu->render();
    }
    if (DmMenu) {
      DmMenu->render();
    }
    if (TlMenu) {
      TlMenu->render();
    }
    if (MnMenu) {
      MnMenu->render();
    }
    if (SeMenu) {
      SeMenu->render();
    }
  }
}

void CGameplayMenu::show()
{

}

void CGameplayMenu::hide()
{

}

void CGameplayMenu::setOpacity(irr::u8 value)
{

}

/**
 * Toggles visibility of the menu
 */
void CGameplayMenu::toggle()
{
  if (IsVisible) {
    IsVisible = false;
  } else {
    IsVisible = true;
  }
}

/**
 *
 */
CMenu* CGameplayMenu::getSectionMenu()
{
  return SectionMenu;
}

/**
 *
 */
void CGameplayMenu::goToWeaponMenu()
{
  WpMenu = new CWeaponMenu();
}

/**
 *
 */
void CGameplayMenu::goToSpiritMenu()
{

}

/**
 *
 */
void CGameplayMenu::goToItemMenu()
{

}

/**
 *
 */
void CGameplayMenu::goToMapMenu()
{

}

/**
 *
 */
void CGameplayMenu::goToStatusMenu()
{

}

/**
 *
 */
void CGameplayMenu::goToDimensionMenu()
{

}

/**
 *
 */
void CGameplayMenu::goToTalesMenu()
{

}

/**
 *
 */
void CGameplayMenu::goToMonstersMenu()
{

}

/**
 *
 */
void CGameplayMenu::goToSettingsMenu()
{

}

/**
 *
 */
CGameplayMenu::~CGameplayMenu()
{
  delete Background;
  delete TopBar;
  delete SectionMenu;
  delete StateInfo;
  delete GameplayTime;
  //delete moneyCounter;
}

}
}
