/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_TRANSLATION_H__
#define __IS06_TRANSLATION_H__

using namespace std;
using namespace irr;

class Translation
{
  public:
    Translation(const string& filePath);

    const wstring& getTranslation(const string& identifier) const;

  private:
    void loadTextData(const string& fullPath);
    wstring notfound;

    map<string, wstring> textData;
};

#endif
