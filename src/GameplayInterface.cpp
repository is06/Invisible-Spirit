/******************************************************************************
Le code source d'Invisible Spirit par Thomas Noury est mis à disposition selon
les termes de la licence Creative Commons Paternité - Pas d'Utilisation
Commerciale - Partage des Conditions Initiales à l'Identique (BY-NC-SA) 3.0
Unported. Basé(e) sur une oeuvre à www.is06.com.  Les autorisations au-delà du
champ de cette licence peuvent être obtenues à http://www.is06.com.
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
