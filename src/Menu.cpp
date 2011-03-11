/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../include/core.h"

using namespace std;
using namespace irr;

Menu::Menu(f32 x, f32 y, f32 width, u8 height) : Hud() {
  lastInsertedIndex = 0;
  currentOption = 0;
  defaultOption = 0;

  currentWidth = width;
  currentHeight = height;
  pos = core::position2df(x, y);

  loopMode = false;

  cursor = new Picture(32, 32, x, y);
}

void Menu::render() { Hud::render();
  BOOST_FOREACH(MenuOptionMap::value_type op, options) {
    op.second->render();
  }
  cursor->render();
}

void Menu::addOption(MenuIcon icon, const core::stringw& title) {
  f32 posY = pos.Y + (lastInsertedIndex * -1 * 32);
  options.insert(make_pair(lastInsertedIndex, new MenuOption(icon, title, pos.X, posY)));
  lastInsertedIndex++;
}

void Menu::nextOption() {
  if(loopMode) {
    if(currentOption > options.size()) {
      currentOption = 0;
      currentOption++;
      cursor->subY(32);
    }
  } else {
    if(currentOption < options.size() - 1) {
      currentOption++;
      cursor->subY(32);
    }
  }
}

void Menu::prevOption() {
  if(loopMode) {
    if(currentOption <= 0) {
      currentOption = options.size();
      currentOption--;
      cursor->addY(32);
    }
  } else {
    if(currentOption > 0) {
      currentOption--;
      cursor->addY(32);
    }
  }
}

void Menu::firstOption() {
  currentOption = 0;
}

void Menu::lastOption() {
  currentOption = options.size() - 1;
}

/**
 * TODO
 */
void Menu::removeOption(u16 index) {
  /*
  options.erase(index);
  lastInsertedIndex = 0;
  for(optionsIt = options.begin(); optionsIt != options.end(); ++optionsIt) {
    *optionsIt = make_pair(lastInsertedIndex, optionsIt->second);
    lastInsertedIndex++;
  }
  */
}

/**
 * TODO
 */
MenuOption* Menu::getOption(u16 index) {
  return options[index];
}

u16 Menu::getCurrentOption() {
  return currentOption;
}

Menu::~Menu() {
  delete cursor;
}
