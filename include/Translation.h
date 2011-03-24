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

class Translation {
  public:
    Translation(const core::stringc& filePath);
    ~Translation();

    const core::stringw& getTranslation(const core::stringc& identifier) const;

  private:
    void loadTextData(const core::stringc& fullPath);
    core::stringw notfound;

    map<core::stringc, core::stringw> textData;
};

#endif
