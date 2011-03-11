/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_MENU_H__
#define __IS06_MENU_H__

using namespace std;
using namespace irr;

typedef boost::unordered_map<u16, MenuOption*> MenuOptionMap;

class Menu : public Hud {
  public:
    Menu(f32 x = 0, f32 y = 0, f32 width = 150, u8 height = 8);
    virtual ~Menu();

    virtual void render();

    void addOption(MenuIcon icon = MENU_ICON_NONE, const core::stringw& title = "[Option]");
    void removeOption(u16 index);
    MenuOption* getOption(u16 index);

    u16 getCurrentOption();

    void nextOption();
    void prevOption();
    void firstOption();
    void lastOption();

  protected:
    Picture* cursor;

    MenuOptionMap options;
    u16 lastInsertedIndex;
    u16 defaultOption;
    u16 currentOption;

    core::position2df pos;
    f32 currentWidth;
    u8 currentHeight;

    bool loopMode;
};

#endif
