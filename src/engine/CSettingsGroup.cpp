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
  setName(name);
}

//! Changes the name of the group
void CSettingsGroup::setName(const string& name)
{
  Name = name;
}

//! Returns all params (strings) for this group
map<string, string>& CSettingsGroup::getParams()
{
  return Params;
}

//! Returns the name of the settings group
string& CSettingsGroup::getName()
{
  return Name;
}

}
}
