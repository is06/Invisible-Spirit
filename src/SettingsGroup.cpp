/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../include/ref/core.h"
#include "../include/SettingsGroup.h"

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
