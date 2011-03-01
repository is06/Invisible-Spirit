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

  loopMode = true;
}

void Menu::render() { Hud::render();

}

void Menu::addOption(const MenuOption& option) {
  options.insert(make_pair(lastInsertedIndex, option));
  lastInsertedIndex++;
}

void Menu::addOption(MenuIcon icon, const core::stringw& title) {
  options.insert(make_pair(lastInsertedIndex, MenuOption(icon, title)));
  lastInsertedIndex++;
}

void Menu::nextOption() {
  currentOption++;
}

void Menu::prevOption() {
  if(loopMode) {
    if(currentOption <= 0) {
      currentOption = options.size();
      currentOption--;
    }
  } else {
    if(currentOption > 0) {
      currentOption--;
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
MenuOption& Menu::getOption(u16 index) {
  //return options[index];
}

Menu::~Menu() {

}
