/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_GAMEPLAY_MENU_H__
#define __IS06_GAMEPLAY_MENU_H__

#include "Hud.h"
#include "DimensionMenu.h"
#include "ItemMenu.h"
#include "MapMenu.h"
#include "MonstersMenu.h"
#include "SettingsMenu.h"
#include "SpiritMenu.h"
#include "StatusMenu.h"
#include "TalesMenu.h"
#include "WeaponMenu.h"

namespace is06
{
namespace nHud
{
namespace nMenu
{

//! The main gameplay menu
class CGameplayMenu : public CHud
{
  public:
    CGameplayMenu(nEngine::CTranslation* translation, nEngine::CPlayerControl* control);
    ~CGameplayMenu();

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

    // Sub menus
    CWeaponMenu* WpMenu;
    CSpiritMenu* SpMenu;
    CItemMenu* ItMenu;
    CMapMenu* MpMenu;
    CStatusMenu* StMenu;
    CDimensionMenu* DmMenu;
    CTalesMenu* TlMenu;
    CMonstersMenu* MnMenu;
    CSettingsMenu* SeMenu;

    bool Visible;
};

}
}
}

#endif