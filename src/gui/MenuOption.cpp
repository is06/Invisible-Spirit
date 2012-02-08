/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/gui/MenuOption.h"
#include "../../include/gui/Window.h"
#include "../../include/gui/Text.h"

using namespace std;
using namespace irr;

MenuOption::MenuOption(MenuIcon icon, const core::stringw& title, f32 x, f32 y, MenuStyle style) : Hud()
{
  currentIcon = icon;

  WindowStyle boxStyle = WIN_STYLE_STD;
  FontStyle fontStyle = FONT_STD_CLASSIC_REGULAR;

  switch (style) {
    case MENU_STYLE_STD:
      boxStyle = WIN_STYLE_STD;
      fontStyle = FONT_STD_CLASSIC_REGULAR;
      break;
    case MENU_STYLE_TITLE:
      boxStyle = WIN_STYLE_NONE;
      fontStyle = FONT_STD_BORDER_SHADED_REGULAR;
      break;
    default:
      boxStyle = WIN_STYLE_NONE;
      fontStyle = FONT_STD_CLASSIC_REGULAR;
      break;
  }

  box = new Window(x + 75, y, 150, 28, 3, boxStyle);
  currentText = new Text(title, x + 6, y, fontStyle);

  hover = false;
  enabled = true;
  visible = true;
  selectable = true;
}

void MenuOption::render()
{
  Hud::render();
  box->render();
  currentText->render();
}

void MenuOption::setHover(bool isHover)
{
  hover = isHover;
}

void MenuOption::setEnabled(bool isEnabled)
{
  enabled = isEnabled;
}

void MenuOption::setVisible(bool isVisible)
{
  visible = isVisible;
}

void MenuOption::setSelectable(bool isSelectable)
{
  selectable = isSelectable;
}

MenuOption::~MenuOption()
{
  delete currentText;
  delete box;
}
