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
#include "../../include/hud/CPauseScreen.h"
#include "../../include/hud/CMenu.h"
#include "../../include/hud/CMenuOption.h"
#include "../../include/hud/CPicture.h"
#include "../../include/hud/CPlayerState.h"
#include "../../include/hud/CGameTimeCounter.h"

namespace is06
{
namespace nHud
{
namespace nPauseScreen
{

//! All elements creation
CPauseScreen::CPauseScreen(nEngine::CTranslation* translation, nEngine::CPlayerControl* control)
{
  // Properties
  Visible = false;

  // Sub Screens pointers
  WeaponsSubScreen = NULL;
  SpiritsSubScreen = NULL;
  ItemsSubScreen = NULL;
  MapSubScreen = NULL;
  StatusSubScreen = NULL;
  StorySubScreen = NULL;
  MonstersSubScreen = NULL;
  SettingsSubScreen = NULL;

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
void CPauseScreen::render()
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

    if (WeaponsSubScreen) {
      WeaponsSubScreen->render();
    }
    if (SpiritsSubScreen) {
      SpiritsSubScreen->render();
    }
    if (ItemsSubScreen) {
      ItemsSubScreen->render();
    }
    if (MapSubScreen) {
      MapSubScreen->render();
    }
    if (StatusSubScreen) {
      StatusSubScreen->render();
    }
    if (StorySubScreen) {
      StorySubScreen->render();
    }
    if (MonstersSubScreen) {
      MonstersSubScreen->render();
    }
    if (SettingsSubScreen) {
      SettingsSubScreen->render();
    }
  }
}

//! \todo write this function
void CPauseScreen::show()
{

}

//! \todo write this function
void CPauseScreen::hide()
{

}

//! \todo write this function
void CPauseScreen::setOpacity(u8 value)
{

}

//! Toggles visibility of the menu
void CPauseScreen::toggle()
{
  if (Visible) {
    Visible = false;
  } else {
    Visible = true;
  }
}

//! \todo comment this function
bool CPauseScreen::isVisible()
{
  return Visible;
}

//! \todo comment this function
CMenu* CPauseScreen::getSectionMenu()
{
  return SectionMenu;
}

//! \todo comment this function
void CPauseScreen::goToWeaponMenu()
{
  WeaponsSubScreen = new CPauseSubScreenWeapons();
}

//! \todo write this function
void CPauseScreen::goToSpiritMenu()
{

}

//! \todo write this function
void CPauseScreen::goToItemMenu()
{

}

//! \todo write this function
void CPauseScreen::goToMapMenu()
{

}

//! \todo write this function
void CPauseScreen::goToStatusMenu()
{

}

//! \todo write this function
void CPauseScreen::goToDimensionMenu()
{

}

//! \todo write this function
void CPauseScreen::goToTalesMenu()
{

}

//! \todo write this function
void CPauseScreen::goToMonstersMenu()
{

}

//! \todo write this function
void CPauseScreen::goToSettingsMenu()
{

}

//! \todo comment this function
CPauseScreen::~CPauseScreen()
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
