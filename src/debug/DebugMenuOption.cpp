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

  currentType = type;

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

      f32 component = 0.0f;

      switch(colorComponent) {
        case DEBUG_COLOR_A: cout << "A: "; component = colorMemory.a; break;
        case DEBUG_COLOR_R: cout << "R: "; component = colorMemory.r; break;
        case DEBUG_COLOR_G: cout << "G: "; component = colorMemory.g; break;
        case DEBUG_COLOR_B: cout << "B: "; component = colorMemory.b; break;
      }

      if(Game::getEventManager()->isKeyDown(KEY_LEFT)) {
        if(component > min) {
          component -= (0.2 * Game::getSpeedFactor());
        }
      }
      if(Game::getEventManager()->isKeyDown(KEY_RIGHT)) {
        if(component < max) {
          component += (0.2 * Game::getSpeedFactor());
        }
      }

      if(component < min) component = min;
      if(component > max) component = max;

      cout << component << endl;

      switch(colorComponent) {
        case DEBUG_COLOR_A: colorMemory.a = component; break;
        case DEBUG_COLOR_R: colorMemory.r = component; break;
        case DEBUG_COLOR_G: colorMemory.g = component; break;
        case DEBUG_COLOR_B: colorMemory.b = component; break;
      }

      Game::getSceneManager()->setAmbientLight(colorMemory);

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

void DebugMenuOption::attachColor(DebugColor component, const video::SColorf& color) {
  colorMemory = color;
  colorComponent = component;
}

void DebugMenuOption::setMin(f32 value) {
  min = value;
}

void DebugMenuOption::setMax(f32 value) {
  max = value;
}

DebugMenuOptionType DebugMenuOption::getType() {
  return currentType;
}

DebugMenuOption::~DebugMenuOption() {
  cout << "[DEBUG] Deleting option" << endl;
  guiElement->remove();
}
