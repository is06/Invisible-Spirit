/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../include/core.h"

using namespace std;
using namespace irr;

BarCounter::BarCounter(s32 init, s32 min, s32 max) : Counter(init, min, max) {
  bar = new Picture();
}

void BarCounter::render() {
  bar->render();
}

BarCounter::~BarCounter() {
  delete bar;
}
