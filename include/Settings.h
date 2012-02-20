/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_SETTINGS_H__
#define __IS06_SETTINGS_H__

using namespace irr;
using namespace std;

class Settings
{
  public:
    Settings();
    ~Settings();

    string& getParamString(const string& groupName, const string& paramName);
    s32 getParamInt(const string& groupName, const string& paramName);

  private:
    map<string, SettingsGroup*> data;
    fstream fileStream;
};

#endif
