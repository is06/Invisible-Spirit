/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_PAUSE_SCREEN_H__
#define __IS06_PAUSE_SCREEN_H__

#include "CHud.h"
#include "PauseScreen/SubScreen/CItems.h"
#include "PauseScreen/SubScreen/CMap.h"
#include "PauseScreen/SubScreen/CMonsters.h"
#include "PauseScreen/SubScreen/CSettings.h"
#include "PauseScreen/SubScreen/CSpirits.h"
#include "PauseScreen/SubScreen/CStatus.h"
#include "PauseScreen/SubScreen/CStory.h"
#include "PauseScreen/SubScreen/CWeapons.h"

namespace is06 { namespace NHud { namespace NPauseScreen {

//! The main gameplay menu
class CPauseScreen : public CHud
{
public:
  CPauseScreen(NEngine::NResource::CTranslation* translation, NEngine::CPlayerControl* control);
  ~CPauseScreen();

  void render();
  void toggle();
  void show();
  void hide();
  void setOpacity(f32 value);
  void addOpacity(f32 value);
  void subOpacity(f32 value);
  f32 getOpacity();

  void goToWeaponMenu();
  void goToSpiritMenu();
  void goToItemMenu();
  void goToMapMenu();
  void goToStatusMenu();
  void goToDimensionMenu();
  void goToTalesMenu();
  void goToMonstersMenu();
  void goToSettingsMenu();

  CMenu* getSectionMenu();

  bool isVisible();

private:
  NEngine::CPlayerControl* Control;
  NEngine::NResource::CTranslation* GlobalTranslations;
  CPicture* Background;
  CPicture* TopBar;
  CMenu* SectionMenu;
  CPlayerState* StateInfo;
  NCounter::CGameTime* GameplayTime;
  //DigitCounter* moneyCounter;

  // Sub screens
  NPauseScreen::NSubScreen::CWeapons* WeaponsSubScreen;
  NPauseScreen::NSubScreen::CSpirits* SpiritsSubScreen;
  NPauseScreen::NSubScreen::CItems* ItemsSubScreen;
  NPauseScreen::NSubScreen::CMap* MapSubScreen;
  NPauseScreen::NSubScreen::CStatus* StatusSubScreen;
  NPauseScreen::NSubScreen::CStory* StorySubScreen;
  NPauseScreen::NSubScreen::CMonsters* MonstersSubScreen;
  NPauseScreen::NSubScreen::CSettings* SettingsSubScreen;

  f32 Opacity;
  bool Visible;
};

}}}

#endif
