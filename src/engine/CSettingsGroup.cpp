/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/core.h"
#include "../../include/engine/CSettingsGroup.h"

namespace is06
{
namespace nEngine
{

//! Constructor
CSettingsGroup::CSettingsGroup(const string& name)
{
  Default = "";
  setName(name);
}

//! Changes the name of the group
void CSettingsGroup::setName(const string& name)
{
  Name = name;
}

void CSettingsGroup::addParam(const string& name, const string& value)
{
  Params.insert(pair<string, string>(name, value));
}

string& CSettingsGroup::getParam(const string& name)
{
  ParamsIt = Params.find(name);
  if (ParamsIt != Params.end()) {
    return ParamsIt->second;
  } else {
    return Default;
  }
}

//! Returns the name of the settings group
const string& CSettingsGroup::getName() const
{
  return Name;
}

string& CSettingsGroup::getDefault()
{
  return Default;
}

}
}
