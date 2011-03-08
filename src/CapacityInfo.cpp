/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../include/core.h"

using namespace std;
using namespace irr;

CapacityInfo::CapacityInfo() : Hud() {
  icon = new Picture(32, 32, 0, 0, "resource/hud/default.bmp");
  value = new Text(L"32", 10, 10, FONT_STD_REGULAR);
}

void CapacityInfo::render() { Hud::render();

}

CapacityInfo::~CapacityInfo() {
  delete icon;
  delete value;
}
