/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_PAUSE_SCREEN_H__
#define __IS06_PAUSE_SCREEN_H__

#include "CHud.h"
#include "CPauseSubScreenItems.h"
#include "CPauseSubScreenMap.h"
#include "CPauseSubScreenMonsters.h"
#include "CPauseSubScreenSettings.h"
#include "CPauseSubScreenSpirits.h"
#include "CPauseSubScreenStatus.h"
#include "CPauseSubScreenStory.h"
#include "CPauseSubScreenWeapons.h"

namespace is06
{
namespace nHud
{
namespace nPauseScreen
{

//! The main gameplay menu
class CPauseScreen : public CHud
{
  public:
    CPauseScreen(nEngine::CTranslation* translation, nEngine::CPlayerControl* control);
    ~CPauseScreen();

    void render();
    void toggle();
    void show();
    void hide();
    void setOpacity(u8 value);

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
    nEngine::CPlayerControl* Control;
    nEngine::CTranslation* GlobalTranslations;
    CPicture* Background;
    CPicture* TopBar;
    CMenu* SectionMenu;
    CPlayerState* StateInfo;
    CGameTimeCounter* GameplayTime;
    //DigitCounter* moneyCounter;

    // Sub screens
    CPauseSubScreenWeapons* WeaponsSubScreen;
    CPauseSubScreenSpirits* SpiritsSubScreen;
    CPauseSubScreenItems* ItemsSubScreen;
    CPauseSubScreenMap* MapSubScreen;
    CPauseSubScreenStatus* StatusSubScreen;
    CPauseSubScreenStory* StorySubScreen;
    CPauseSubScreenMonsters* MonstersSubScreen;
    CPauseSubScreenSettings* SettingsSubScreen;

    bool Visible;
};

}
}
}

#endif
