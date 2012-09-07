/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/core.h"
#include "../../include/engine/CGame.h"
#include "../../include/engine/CSave.h"
#include "../../include/engine/CPlayerControl.h"
#include "../../include/engine/CTranslation.h"
#include "../../include/hud/CGameplayMenu.h"
#include "../../include/hud/CMenu.h"
#include "../../include/hud/CMenuOption.h"
#include "../../include/hud/CPicture.h"
#include "../../include/hud/CPlayerState.h"
#include "../../include/hud/CGameTimeCounter.h"

namespace is06
{
namespace nHud
{
namespace nMenu
{

//! All elements creation
CGameplayMenu::CGameplayMenu(nEngine::CTranslation* translation, nEngine::CPlayerControl* control)
{
  // Properties
  Visible = false;

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

  // Player control pointer
  Control = control;

  // Translation pointer
  GlobalTranslations = translation;

  // Black transparent background
  Background = new CPicture(0, 0, 1280, 720, "resource/hud/menus/gameplay/back.png");
  Background->setOpacity(128);

  // Silver title top bar
  TopBar = new CPicture(0, nEngine::CGame::ScreenPos.Hud.Top - 20, 1280, 40, "resource/hud/menus/gameplay/top_bar.png");

  // Menu (left)
  SectionMenu = new CMenu(nEngine::CGame::ScreenPos.Hud.Left + 80, nEngine::CGame::ScreenPos.Hud.Top - 80, 150, 8, EMS_TITLE);
  SectionMenu->addOption(EMI_NONE, GlobalTranslations->getTranslation("gameplay_menu_swords"));
  SectionMenu->addOption(EMI_NONE, GlobalTranslations->getTranslation("gameplay_menu_spirits"));
  SectionMenu->addOption(EMI_NONE, GlobalTranslations->getTranslation("gameplay_menu_items"));
  SectionMenu->addOption(EMI_NONE, GlobalTranslations->getTranslation("gameplay_menu_maps"));
  SectionMenu->addOption(EMI_NONE, GlobalTranslations->getTranslation("gameplay_menu_status"));
  SectionMenu->addOption(EMI_NONE, GlobalTranslations->getTranslation("gameplay_menu_dimensions"));
  SectionMenu->addOption(EMI_NONE, GlobalTranslations->getTranslation("gameplay_menu_tales"));
  SectionMenu->addOption(EMI_NONE, GlobalTranslations->getTranslation("gameplay_menu_monsters"));
  SectionMenu->addOption(EMI_NONE, GlobalTranslations->getTranslation("gameplay_menu_settings"));
  SectionMenu->addOption(EMI_NONE, GlobalTranslations->getTranslation("gameplay_menu_quit"));

  //sectionMenu->getOption(0)->setEnabled(false);

  // Player state info panel (right)
  StateInfo = new CPlayerState();

  // Gameplay time
  GameplayTime = new CGameTimeCounter();

  // Money TODO
  //moneyCounter = new DigitCounter();
}

//! Gameplay menu render: all entities are rendered here
void CGameplayMenu::render()
{
  if (Visible) {
    if (Control->commandEntered(nEngine::ECI_MENU_DOWN, nEngine::EET_ONCE)) {
      SectionMenu->nextOption();
    }
    if (Control->commandEntered(nEngine::ECI_MENU_UP, nEngine::EET_ONCE)) {
      SectionMenu->prevOption();
    }

    Background->render();
    TopBar->render();
    SectionMenu->render();
    StateInfo->render();
    GameplayTime->render();

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

void CGameplayMenu::setOpacity(u8 value)
{

}

//! Toggles visibility of the menu
void CGameplayMenu::toggle()
{
  if (Visible) {
    Visible = false;
  } else {
    Visible = true;
  }
}

bool CGameplayMenu::isVisible()
{
  return Visible;
}

CMenu* CGameplayMenu::getSectionMenu()
{
  return SectionMenu;
}

void CGameplayMenu::goToWeaponMenu()
{
  WpMenu = new CWeaponMenu();
}

void CGameplayMenu::goToSpiritMenu()
{

}

void CGameplayMenu::goToItemMenu()
{

}

void CGameplayMenu::goToMapMenu()
{

}

void CGameplayMenu::goToStatusMenu()
{

}

void CGameplayMenu::goToDimensionMenu()
{

}

void CGameplayMenu::goToTalesMenu()
{

}

void CGameplayMenu::goToMonstersMenu()
{

}

void CGameplayMenu::goToSettingsMenu()
{

}

CGameplayMenu::~CGameplayMenu()
{
  delete Background;
  delete TopBar;
  delete SectionMenu;
  delete StateInfo;
  delete GameplayTime;
}

}
}
}
