/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"

using namespace irr;
using namespace std;

DebugMenu::DebugMenu(s32 menuX, DebugMenu* parent) {
  parentMenu = parent;
  coordX = menuX;
  browseable = false;
  visible = false;
  currentOption = 0;
  nextOptionID = 0;
  nextOptionY = 10;
}

void DebugMenu::events() {
  if(visible) {
    for(optionsIt = options.begin(); optionsIt != options.end(); optionsIt++) {
      optionsIt->second->events();
    }
    for(subMenusIt = subMenus.begin(); subMenusIt != subMenus.end(); subMenusIt++) {
      subMenusIt->second->events();
    }
    if(browseable) {
      if(Game::getEventManager()->isKeyDownOnce(KEY_DOWN)) {
        nextOption();
      }
      if(Game::getEventManager()->isKeyDownOnce(KEY_UP)) {
        prevOption();
      }
      if(Game::getEventManager()->isKeyDownOnce(KEY_SPACE)) {
        enter();
      }
      if(Game::getEventManager()->isKeyDownOnce(KEY_ESCAPE)) {
        returnParent();
      }
    }
  }
}

void DebugMenu::setBrowseable(bool value) {
  browseable = value;
}

void DebugMenu::setVisible(bool value) {
  visible = value;
}

void DebugMenu::addOption(const core::stringc& text, DebugMenuOptionType type, f32 minValue, f32 maxValue) {
  options[nextOptionID] = new DebugMenuOption(text, coordX, nextOptionY, type);
  options[nextOptionID]->setMin(minValue);
  options[nextOptionID]->setMax(maxValue);
  if(nextOptionID == 0) {
    options[nextOptionID]->setSelected(true);
  }
  if(type == DEBUG_MENU_OPTION_COLOR) {

  }
  if(type == DEBUG_MENU_OPTION_SUB) {
    subMenus[nextOptionID] = new DebugMenu(coordX + 80, this);
  }

  nextOptionID++;
  nextOptionY+= 12;
}

void DebugMenu::nextOption() {
  options[currentOption]->setSelected(false);
  currentOption++;
  if(currentOption >= options.size()) {
    currentOption = 0;
  }
  options[currentOption]->setSelected(true);
}

void DebugMenu::prevOption() {
  options[currentOption]->setSelected(false);
  currentOption--;
  if(currentOption <= -1) {
    currentOption = options.size() - 1;
  }
  options[currentOption]->setSelected(true);
}

s32 DebugMenu::getCurrentOption() {
  return currentOption;
}

DebugMenu* DebugMenu::getSubMenu(s32 optionID) {
  return subMenus[optionID];
}

DebugMenuOption* DebugMenu::getOption(s32 optionID) {
  return options[optionID];
}

void DebugMenu::removeAllOptions() {
  for(u32 i = 0; i < options.size(); i++) {
    delete options[i];
    options.erase(i);
  }
  nextOptionID = 0;
  nextOptionY = 10;
}

void DebugMenu::enter() {
  if(options[currentOption]->getType() == DEBUG_MENU_OPTION_SUB) {
    // On désactive le menu en cours
    setBrowseable(false);
    // On active le menu enfant
    cout << "activate sub menu " << currentOption << endl;
    subMenus[currentOption]->setVisible(true);
    subMenus[currentOption]->setBrowseable(true);
  }
}

void DebugMenu::returnParent() {
  setBrowseable(false);
  setVisible(false);
  parentMenu->setBrowseable(true);
}

DebugMenu::~DebugMenu() {

}
