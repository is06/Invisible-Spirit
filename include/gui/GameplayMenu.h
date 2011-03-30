/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_GAMEPLAY_MENU_H__
#define __IS06_GAMEPLAY_MENU_H__

using namespace irr;
using namespace std;

class GameplayMenu : public Hud {
  public:
    GameplayMenu(Translation* trans);
    ~GameplayMenu();

    void render();
    void toggle();

    Menu* getSectionMenu();

    bool isVisible;

  private:
    Menu* sectionMenu;
    PlayerState* stateInfo;
    Window* mainBox;
    Translation* globalTranslations;
};

#endif
