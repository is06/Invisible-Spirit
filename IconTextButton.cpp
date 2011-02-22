/******************************************************************************
Le code source d'Invisible Spirit par Thomas Noury est mis à disposition selon
les termes de la licence Creative Commons Paternité - Pas d'Utilisation
Commerciale - Partage des Conditions Initiales à l'Identique (BY-NC-SA) 3.0
Unported. Basé(e) sur une oeuvre à www.is06.com.  Les autorisations au-delà du
champ de cette licence peuvent être obtenues à http://www.is06.com.
*******************************************************************************/

#include "core.h"

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
