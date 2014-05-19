/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_HUD_TEXT_TEXT_CHAR_H__
#define __IS06_HUD_TEXT_TEXT_CHAR_H__

#include "../NPrimitive/CFlatElement.h"

namespace is06 { namespace NHud { namespace NText {

//! A text character (component of Text)
class CTextChar : public NPrimitive::CFlatElement
{
public:
  CTextChar(u8 code, f32& x, f32& y, u8 size, CTextFont* font, bool visible = true, u8 extTexture=0);
  ~CTextChar();

  void render();

private:
  CTextFont* FontStyle;
};

}}}

#endif
