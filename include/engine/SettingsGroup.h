/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_SETTINGS_GROUP_H__
#define __IS06_SETTINGS_GROUP_H__

namespace is06
{
namespace nEngine
{

//! SettingsGroup element class containing params
class CSettingsGroup
{
  public:
    CSettingsGroup(const string& newName);

    void setName(const string& newName);
    string& getName();

    map<string, string>& getParams();

  private:
    string Name;
    map<string, string> Params;
};

}
}

#endif
