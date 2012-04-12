/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../include/ref/core.h"
#include "../include/SettingsGroup.h"

namespace is06
{
namespace engine
{

CSettingsGroup::CSettingsGroup(const std::string& name)
{
  setName(name);
}

void CSettingsGroup::setName(const std::string& name)
{
  Name = name;
}

std::map<std::string, std::string>& CSettingsGroup::getParams()
{
  return Params;
}

std::string& CSettingsGroup::getName()
{
  return Name;
}

}
}
