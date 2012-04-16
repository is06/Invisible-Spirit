/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_SETTINGS_H__
#define __IS06_SETTINGS_H__

namespace is06
{
namespace nEngine
{

//! Settings interface containing groups
class CSettings
{
  public:
    CSettings();
    ~CSettings();

    string& getParamString(const string& groupName, const string& paramName);
    s32 getParamInt(const string& groupName, const string& paramName);

  private:
    map<string, CSettingsGroup*> Data;
    fstream FileStream;
};

}
}

#endif
