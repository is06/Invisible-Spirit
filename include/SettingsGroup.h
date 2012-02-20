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

class SettingsGroup
{
  public:
    SettingsGroup(const string& newName);

    void setName(const string& newName);
    string& getName();

    map<string, string>& getParams();

  private:
    string name;
    map<string, string> params;
};

#endif
