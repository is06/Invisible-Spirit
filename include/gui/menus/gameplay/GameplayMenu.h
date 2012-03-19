/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_GAMEPLAY_MENU_H__
#define __IS06_GAMEPLAY_MENU_H__

#include "../../Hud.h"
#include "DimensionMenu.h"
#include "ItemMenu.h"
#include "MapMenu.h"
#include "MonstersMenu.h"
#include "SettingsMenu.h"
#include "SpiritMenu.h"
#include "StatusMenu.h"
#include "TalesMenu.h"
#include "WeaponMenu.h"

using namespace irr;
using namespace std;

class GameplayMenu : public Hud
{
  public:
    GameplayMenu(Translation* trans);
    ~GameplayMenu();

    void render(Keyboard* keyboard);
    void toggle();

    void goToWeaponMenu();
    void goToSpiritMenu();
    void goToItemMenu();
    void goToMapMenu();
    void goToStatusMenu();
    void goToDimensionMenu();
    void goToTalesMenu();
    void goToMonstersMenu();
    void goToSettingsMenu();

    Menu* getSectionMenu();

    bool isVisible;

  private:
    Translation* globalTranslations;
    Picture* background;
    Picture* topBar;
    Menu* sectionMenu;
    PlayerState* stateInfo;
    GameTimeCounter* gameplayTime;
    //DigitCounter* moneyCounter;

    // Sub menus
    WeaponMenu* wpMenu;
    SpiritMenu* spMenu;
    ItemMenu* itMenu;
    MapMenu* mpMenu;
    StatusMenu* stMenu;
    DimensionMenu* dmMenu;
    TalesMenu* tlMenu;
    MonstersMenu* mnMenu;
    SettingsMenu* seMenu;
};

#endif
