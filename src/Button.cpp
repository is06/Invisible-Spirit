/******************************************************************************
Le code source d'Invisible Spirit par Thomas Noury est mis à disposition selon
les termes de la licence Creative Commons Paternité - Pas d'Utilisation
Commerciale - Partage des Conditions Initiales à l'Identique (BY-NC-SA) 3.0
Unported. Basé(e) sur une oeuvre à www.is06.com.  Les autorisations au-delà du
champ de cette licence peuvent être obtenues à http://www.is06.com.
*******************************************************************************/

#include "../include/core.h"

Button::Button(f32 x, f32 y) {
  buttonCircle = new Picture(40, 40, x, y, "resource/hud/buttonCircle.png");
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
