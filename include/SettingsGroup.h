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
namespace engine
{

class CSettingsGroup
{
  public:
    CSettingsGroup(const std::string& newName);

    void setName(const std::string& newName);
    std::string& getName();

    std::map<std::string, std::string>& getParams();

  private:
    std::string Name;
    std::map<std::string, std::string> Params;
};

}
}

#endif
