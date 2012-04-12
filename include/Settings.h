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
namespace engine
{

class CSettings
{
  public:
    CSettings();
    ~CSettings();

    std::string& getParamString(const std::string& groupName, const std::string& paramName);
    irr::s32 getParamInt(const std::string& groupName, const std::string& paramName);

  private:
    std::map<std::string, CSettingsGroup*> Data;
    std::fstream FileStream;
};

}
}

#endif
