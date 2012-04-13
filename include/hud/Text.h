/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_TEXT_H__
#define __IS06_TEXT_H__

#include "Hud.h"

#include "FontStyle.h"
#include "TextAlignment.h"

namespace is06
{
namespace hud
{

class CText : public CHud
{
  public:
    CText(const string& str = "[Text]", f32 x = 0, f32 y = 0, hud::EFontStyle style = hud::FONT_STANDARD_48, u8 speed = 0);
    ~CText();

    void render();
    void setSize(u8 size);
    void setText(const string& str);
    void setPosition(const core::position2df& position);
    void nextChar();
    void updateTiles();
    void setSideBounds(f32 left, f32 right);
    void setAlign(ETextAlignment align);
    void show();
    void hide();
    void setOpacity(u8 value);
    void skip();
    bool finished();

  private:
    CTextFont* Font;
    core::position2df Pos;
    core::position2df CurrentCharPos;
    string TextStr;
    vector<CTextChar> CharList;
    vector<CTextChar>::iterator CharIt;
    u8 CurrentSize;
    u8 CurrentSpeed;
    u16 CurrentDisplayChar;
    u16 CurrentTextLength;
    u16 CurrentLineNumber;
    map<u16, u16> LineWidthList;
    f32 LeftBound;
    f32 RightBound;
    hud::ETextAlignment CurrentAlign;
    bool TextFinished;

    engine::CTimer* SpeedTimer;
};

}
}

#endif
