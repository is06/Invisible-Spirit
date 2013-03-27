/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_HUD_TEXT_TEXT_FONT_H__
#define __IS06_HUD_TEXT_TEXT_FONT_H__

#include "EFontStyle.h"

namespace is06 { namespace NHud { namespace NText {

class CTextFont
{
public:
  CTextFont(EFontStyle style);
  ~CTextFont();

  video::SMaterial& getMaterial();
  u8& getCharOffset(u8 code);
  EFontStyle getCurrentStyle();

  void resetToStandard();
  void changeExtTexture(u8 number);

private:
  void readFontData(const string& dataFilePath);
  void getFontDataFromStyle(EFontStyle style);
  void getTextureFromStyle(EFontStyle style, u8 extTexture=0);

  video::ITexture* FontTexture;
  video::SMaterial FontMaterial;
  EFontStyle CurrentStyle;
  map<u32, u8> Offset;
};

}}}

#endif
