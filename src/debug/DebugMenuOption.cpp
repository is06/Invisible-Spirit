/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"

using namespace irr;
using namespace std;

DebugMenuOption::DebugMenuOption(const core::stringw& text, s32 coordY) {
  selectable = true;
  selected = false;
  cout << "[DEBUG] Added option" << endl;
  currentText = text;
  guiElement = Game::getDebugGUI()->addStaticText(text.c_str(), core::recti(10, coordY, 260, coordY + 10), false);
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
  guiElement->remove();
}
