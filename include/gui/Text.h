/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_TEXT_H__
#define __IS06_TEXT_H__

#include "Hud.h"

#include "../enums/styles/FontStyle.h"
#include "../enums/styles/TextAlignment.h"

namespace is06
{
namespace hud
{

class CText : public CHud
{
  public:
    CText(const std::string& str = "[Text]", irr::f32 x = 0, irr::f32 y = 0, hud::EFontStyle style = hud::FONT_STANDARD_48, irr::u8 speed = 0);
    ~CText();

    void render();
    void setSize(irr::u8 size);
    void setText(const std::string& str);
    void setPosition(const irr::core::position2df& position);
    void nextChar();
    void updateTiles();
    void setSideBounds(irr::f32 left, irr::f32 right);
    void setAlign(ETextAlignment align);
    void show();
    void hide();
    void setOpacity(irr::u8 value);
    void skip();
    bool finished();

  private:
    CTextFont* Font;
    irr::core::position2df Pos;
    irr::core::position2df CurrentCharPos;
    std::string TextStr;
    std::vector<CTextChar> CharList;
    std::vector<CTextChar>::iterator CharIt;
    irr::u8 CurrentSize;
    irr::u8 CurrentSpeed;
    irr::u16 CurrentDisplayChar;
    irr::u16 CurrentTextLength;
    irr::u16 CurrentLineNumber;
    std::map<irr::u16, irr::u16> LineWidthList;
    irr::f32 LeftBound;
    irr::f32 RightBound;
    hud::ETextAlignment CurrentAlign;
    bool TextFinished;

    engine::CTimer* SpeedTimer;
};

}
}

#endif
