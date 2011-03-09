/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../include/core.h"

using namespace irr;
using namespace std;

MainStateInfo::MainStateInfo() : Hud() {
  label = new Text();
  info = new Text();
  gauge = new BarCounter(60, 0, 100, 150, 10, 150, 150, BAR_STYLE_LIFE);
}

void MainStateInfo::render() { Hud::render();
  label->render();
  info->render();
  gauge->render();
}

MainStateInfo::~MainStateInfo() {
  delete label;
  delete info;
  delete gauge;
}
