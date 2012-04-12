/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_TEXT_FONT_H__
#define __IS06_TEXT_FONT_H__

#include "../enums/styles/FontStyle.h"

namespace is06
{
namespace hud
{

class CTextFont
{
  public:
    CTextFont(EFontStyle style);
    ~CTextFont();

    irr::video::SMaterial& getMaterial();
    irr::u8& getCharOffset(irr::u8 code);
    EFontStyle getCurrentStyle();

    void resetToStandard();
    void changeExtTexture(irr::u8 number);

  private:
    void readFontData(const std::string& dataFilePath);
    void getFontDataFromStyle(EFontStyle style);
    void getTextureFromStyle(EFontStyle style, irr::u8 extTexture=0);

    irr::video::ITexture* FontTexture;
    irr::video::SMaterial FontMaterial;
    EFontStyle CurrentStyle;
    std::map<irr::u32, irr::u8> Offset;
};

}
}

#endif
