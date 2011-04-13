/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"

Button::Button(f32 x, f32 y) {
  buttonCircle = new Picture(x, y, 40, 40, "resource/hud/button/buttonCircle.png");
}

void Button::render() {
  buttonCircle->render();
}

void Button::hide() {
  buttonCircle->hide();
}

void Button::show() {
  buttonCircle->show();
}

void Button::setOpacity(u8 value) {
  buttonCircle->setOpacity(value);
}

Button::~Button() {
  delete buttonCircle;
}
