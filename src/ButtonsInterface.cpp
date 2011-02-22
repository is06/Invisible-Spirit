/******************************************************************************
Le code source d'Invisible Spirit par Thomas Noury est mis à disposition selon
les termes de la licence Creative Commons Paternité - Pas d'Utilisation
Commerciale - Partage des Conditions Initiales à l'Identique (BY-NC-SA) 3.0
Unported. Basé(e) sur une oeuvre à www.is06.com.  Les autorisations au-delà du
champ de cette licence peuvent être obtenues à http://www.is06.com.
*******************************************************************************/

#include "../include/core.h"

using namespace std;

ButtonsInterface::ButtonsInterface() {
  menu = new TextButton(Game::screenPos.left + 70, Game::screenPos.bottom + 110);
  defense = new IconButton(Game::screenPos.left + 30, Game::screenPos.bottom + 70);
  jump = new IconButton(Game::screenPos.left + 110, Game::screenPos.bottom + 70);
  command = new IconTextButton(Game::screenPos.left + 70, Game::screenPos.bottom + 30);
}

void ButtonsInterface::render() {
  menu->render();
  defense->render();
  jump->render();
  command->render();
}

void ButtonsInterface::hide() {
  menu->hide();
  defense->hide();
  jump->hide();
  command->hide();
}

void ButtonsInterface::show() {
  menu->show();
  defense->show();
  jump->show();
  command->show();
}

void ButtonsInterface::setOpacity(u8 value) {
  menu->setOpacity(value);
  defense->setOpacity(value);
  jump->setOpacity(value);
  command->setOpacity(value);
}

ButtonsInterface::~ButtonsInterface() {
  delete menu;
  delete defense;
  delete jump;
  delete command;
}
