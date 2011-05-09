/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"

using namespace irr;
using namespace std;

DebugMenuOption::DebugMenuOption(const core::stringw& text, s32 coordX, s32 coordY, DebugMenuOptionType type) {
  selectable = true;
  selected = false;
  cout << "[DEBUG] Added option" << endl;

  switch(type) {
    case DEBUG_MENU_OPTION_LIST_ITEM:
      currentText = L" -  ";
      currentText.append(text);
    break;
    case DEBUG_MENU_OPTION_RADIO:
      currentText = L"( ) ";
      currentText.append(text);
    break;
    case DEBUG_MENU_OPTION_CHECKBOX:
      currentText = L"[ ] ";
      currentText.append(text);
    break;
    case DEBUG_MENU_OPTION_SCROLL:
      currentText = text;
      currentText.append(" [|----------] 0");
    break;
    default:
      currentText = text;
    break;
  }

  guiElement = Game::getDebugGUI()->addStaticText(text.c_str(), core::recti(coordX, coordY, coordX + 90, coordY + 10), false);
  guiElement->setOverrideColor(video::SColor(255,255,255,255));
}

void DebugMenuOption::events() {
  if(selectable) {
    if(selected) {
      guiElement->setOverrideColor(video::SColor(255,255,0,0));
    } else {
      guiElement->setOverrideColor(video::SColor(255,255,255,255));
    }
  } else {
    guiElement->setOverrideColor(video::SColor(255,100,100,100));
  }
  guiElement->draw();
}

void DebugMenuOption::setSelected(bool value) {
  selected = value;
}

void DebugMenuOption::setSelectable(bool value) {
  selectable = value;
}

DebugMenuOption::~DebugMenuOption() {
  cout << "[DEBUG] Deleting option" << endl;
  guiElement->remove();
}
