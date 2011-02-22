/******************************************************************************
Le code source d'Invisible Spirit par Thomas Noury est mis à disposition selon
les termes de la licence Creative Commons Paternité - Pas d'Utilisation
Commerciale - Partage des Conditions Initiales à l'Identique (BY-NC-SA) 3.0
Unported. Basé(e) sur une oeuvre à www.is06.com.  Les autorisations au-delà du
champ de cette licence peuvent être obtenues à http://www.is06.com.
*******************************************************************************/

#include "core.h"

using namespace irr;

SettingsGroup::SettingsGroup(const core::stringc& newName) {
  setName(newName);
}

void SettingsGroup::setName(const core::stringc& newName) {
  name = newName;
}

map<core::stringc, core::stringc>& SettingsGroup::getParams() {
  return params;
}

core::stringc& SettingsGroup::getName() {
  return name;
}
