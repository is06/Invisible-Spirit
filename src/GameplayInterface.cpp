/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../include/core.h"

GameplayInterface::GameplayInterface() {
  buttons = new ButtonsInterface();
}

void GameplayInterface::render() {
  buttons->render();
}

void GameplayInterface::hide() {
  buttons->hide();
}

void GameplayInterface::show() {
  buttons->show();
}

void GameplayInterface::setOpacity(u8 value) {
  buttons->setOpacity(value);
}

GameplayInterface::~GameplayInterface() {
  delete buttons;
}
