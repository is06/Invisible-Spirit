/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_TRANSLATION_H__
#define __IS06_TRANSLATION_H__

namespace is06
{
namespace engine
{

class CTranslation
{
  public:
    CTranslation(const std::string& filePath);

    const std::string& getTranslation(const std::string& identifier) const;

  private:
    void loadTextData(const std::string& fullPath);
    std::string Notfound;

    std::map<std::string, std::string> TextData;
};

}
}

#endif
