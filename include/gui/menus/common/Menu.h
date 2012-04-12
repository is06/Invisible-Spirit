/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_MENU_H__
#define __IS06_MENU_H__

#include "../../Hud.h"

#include "../../../enums/styles/MenuStyle.h"
#include "../../../enums/styles/MenuIcon.h"

namespace is06
{
namespace hud
{

class CMenu : public CHud
{
  public:
    CMenu(irr::f32 x = 0, irr::f32 y = 0, irr::f32 width = 150, irr::u8 height = 8, EMenuStyle style = MENU_STYLE_STD);
    virtual ~CMenu();

    virtual void render();

    void addOption(EMenuIcon icon = MENU_ICON_NONE, const std::string& title = "[Option]");
    void removeOption(irr::u16 index);
    CMenuOption* getOption(irr::u16 index);

    irr::u16 getCurrentOption();

    void nextOption();
    void prevOption();
    void firstOption();
    void lastOption();
    void show();
    void hide();
    void setOpacity(irr::u8 value);

  protected:
    CPicture* Cursor;

    std::map<irr::u16, CMenuOption*> Options;
    std::map<irr::u16, CMenuOption*>::iterator OptionsIt;
    irr::u16 LastInsertedIndex;
    irr::u16 DefaultOption;
    irr::u16 CurrentOption;
    irr::core::position2df Pos;
    irr::f32 CurrentWidth;
    irr::u8 CurrentHeight;

    EMenuStyle CurrentStyle;

    bool LoopMode;
};

}
}

#endif
