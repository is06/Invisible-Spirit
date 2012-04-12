/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_MENU_OPTION_H__
#define __IS06_MENU_OPTION_H__

#include "../../Hud.h"

#include "../../../enums/styles/MenuIcon.h"
#include "../../../enums/styles/MenuStyle.h"

namespace is06
{
namespace hud
{

class CMenuOption : public CHud
{
  public:
    CMenuOption(EMenuIcon icon, const std::string& title = "[Option]", irr::f32 x = 0, irr::f32 y = 0, EMenuStyle style = MENU_STYLE_STD);
    virtual ~CMenuOption();

    virtual void render();

    void setHover(bool isHover);
    void setEnabled(bool isEnabled);
    void setSelectable(bool isSelectable);
    void show();
    void hide();
    void setOpacity(irr::u8 value);

  protected:
    EMenuIcon CurrentIcon;
    CText* Label;
    CWindow* Box;

    bool Hover;
    bool Enabled;
    bool Visible;
    bool Selectable;
};

}
}

#endif
