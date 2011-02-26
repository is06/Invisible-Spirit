/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_SETTINGS_GROUP_H__
#define __IS06_SETTINGS_GROUP_H__

using namespace irr;
using namespace std;

class SettingsGroup {
  public:
    SettingsGroup(const core::stringc& newName);

    void setName(const core::stringc& newName);
    core::stringc& getName();

    map<core::stringc, core::stringc>& getParams();

  private:
    core::stringc name;
    map<core::stringc, core::stringc> params;
};

#endif
