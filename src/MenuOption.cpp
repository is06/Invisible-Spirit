/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../include/core.h"

using namespace std;
using namespace irr;

MenuOption::MenuOption(MenuIcon icon, const core::stringw& title, f32 x, f32 y) : Hud() {
  currentIcon = icon;
  currentText = new Text(title, x, y, FONT_STD_REGULAR);

  hover = false;
  enabled = true;
  visible = true;
  selectable = true;
}

void MenuOption::render() { Hud::render();
  currentText->render();
}

void MenuOption::setHover(bool isHover) {
  hover = isHover;
}

void MenuOption::setEnabled(bool isEnabled) {
  enabled = isEnabled;
}

void MenuOption::setVisible(bool isVisible) {
  visible = isVisible;
}

void MenuOption::setSelectable(bool isSelectable) {
  selectable = isSelectable;
}

MenuOption::~MenuOption() {
  delete currentText;
}
