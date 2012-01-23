/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/Game.h"
#include "../../include/gui/BarCounter.h"
#include "../../include/gui/EnergyInterface.h"

using namespace std;

EnergyInterface::EnergyInterface() : Hud() {
  hpBar = new BarCounter(100, 0, 100, (Game::screenPos.right - 170), (Game::screenPos.bottom + 30), 150, 4, BAR_STYLE_LIFE);
  mpBar = new BarCounter(100, 0, 100, (Game::screenPos.right - 120), (Game::screenPos.bottom + 20), 100, 4, BAR_STYLE_LIFE);
}

void EnergyInterface::render() { Hud::render();
  hpBar->render();
  mpBar->render();
}

void EnergyInterface::hide() {
  //hpBar->hide();
  //mpBar->hide();
}

void EnergyInterface::show() {
  //hpBar->show();
  //mpBar->show();
}

void EnergyInterface::setOpacity(u8 value) {
  //hpBar->setOpacity(value);
  //mpBar->setOpacity(value);
}

EnergyInterface::~EnergyInterface() {
  delete hpBar;
  delete mpBar;
}

