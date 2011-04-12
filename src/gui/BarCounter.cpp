/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"

using namespace std;
using namespace irr;

BarCounter::BarCounter(s32 init, s32 min, s32 max, f32 x, f32 y, f32 w, f32 h, BarStyle style) : Counter(init, min, max) {
  core::stringc texturePath = "resource/hud/bar/";

  switch(style) {
    case BAR_STYLE_LIFE: texturePath.append("life.bmp"); break;
    default: texturePath.append("default.bmp"); break;
  }

  bar = new Picture(x, y, w, h, texturePath);
}

void BarCounter::render() {
  bar->render();
}

BarCounter::~BarCounter() {
  delete bar;
}
