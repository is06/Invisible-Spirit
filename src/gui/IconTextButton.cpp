/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/gui/IconTextButton.h"

IconTextButton::IconTextButton(f32 x, f32 y) : Button(x, y) {
  //text = new Text(textMsg);
  //icon = new Picture(40, 40, x - 2, y + 2, "resource/hud/calibrage.bmp");
}

void IconTextButton::render() { Button::render();
  //text->render();
  //icon->render();
}

void Button::changeCommand(CommandIdentifier newCommand) {
  switch(newCommand) {
    default:
      //icon->change("resource/hud/fireCommand.bmp");
    break;
  }
}

IconTextButton::~IconTextButton() {
  //delete text;
  //delete icon;
}
