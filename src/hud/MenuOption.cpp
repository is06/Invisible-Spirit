/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/core.h"
#include "../../include/hud/MenuOption.h"
#include "../../include/hud/Window.h"
#include "../../include/hud/Text.h"

namespace is06
{
namespace hud
{

CMenuOption::CMenuOption(EMenuIcon icon, const string& title, f32 x, f32 y, EMenuStyle style) : CHud()
{
  Icon = icon;

  EWindowStyle boxStyle = WIN_STYLE_STD;
  EFontStyle fontStyle = FONT_STANDARD_48;

  switch (style) {
    case MENU_STYLE_STD:
      boxStyle = WIN_STYLE_STD;
      fontStyle = FONT_STANDARD_48;
      break;
    case MENU_STYLE_TITLE:
      boxStyle = WIN_STYLE_NONE;
      fontStyle = FONT_STANDARD_48;
      break;
    default:
      boxStyle = WIN_STYLE_NONE;
      fontStyle = FONT_STANDARD_48;
      break;
  }

  Box = new CWindow(x + 75, y, 150, 28, 3, boxStyle);
  Label = new CText(title, x + 6, y, fontStyle);

  Hover = false;
  Enabled = true;
  Visible = true;
  Selectable = true;
}

void CMenuOption::render()
{
  CHud::render();
  Box->render();
  Label->render();
}

void CMenuOption::setHover(bool value)
{
  Hover = value;
}

void CMenuOption::setEnabled(bool value)
{
  Enabled = value;
  if (Enabled) {
    setOpacity(255);
  } else {
    setOpacity(128);
  }
}

void CMenuOption::setSelectable(bool value)
{
  Selectable = value;
}

void CMenuOption::show()
{
  Visible = true;
  Label->show();
}

void CMenuOption::hide()
{
  Visible = false;
  Label->hide();
}

void CMenuOption::setOpacity(u8 value)
{
  Label->setOpacity(value);
}

CMenuOption::~CMenuOption()
{
  delete Label;
  delete Box;
}

}
}
