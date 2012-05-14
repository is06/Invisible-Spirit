/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_MENU_H__
#define __IS06_MENU_H__

#include "CHud.h"
#include "EMenuStyle.h"
#include "EMenuIcon.h"

namespace is06
{
namespace nHud
{

class CMenu : public CHud
{
  public:
    CMenu(f32 x = 0, f32 y = 0, f32 width = 150, u8 height = 8, EMenuStyle style = MENU_STYLE_STD);
    virtual ~CMenu();

    virtual void render();

    void addOption(EMenuIcon icon = MENU_ICON_NONE, const string& title = "[Option]");
    void removeOption(u16 index);
    CMenuOption* getOption(u16 index);

    u16 getCurrentOption();

    void nextOption();
    void prevOption();
    void firstOption();
    void lastOption();
    void show();
    void hide();
    void setOpacity(u8 value);

  protected:
    CPicture* Cursor;

    map<u16, CMenuOption*> Options;
    map<u16, CMenuOption*>::iterator OptionsIt;
    u16 LastInsertedIndex;
    u16 DefaultOption;
    u16 CurrentOption;
    core::position2df Position;
    f32 Width;
    u8 Height;

    EMenuStyle Style;

    bool LoopMode;
};

}
}

#endif
