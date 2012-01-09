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

using namespace std;
using namespace irr;

class Text : public Hud {
  public:
    Text(const core::stringw& str = "[Text]", f32 x = 0, f32 y = 0, FontStyle style = FONT_STD_CLASSIC_REGULAR, u8 speed = 0);
    ~Text();

    void render();
    void setSize(u8 size);
    void setText(const core::stringw& str);
    void setPosition(const core::position2df& position);
    void updateTiles();

    void nextChar();

  private:
    TextFont* font;
    core::position2df pos;
    core::position2df currentCharPos;
    core::stringw textStr;
    vector<TextChar> charList;
    vector<TextChar>::iterator charIt;
    u8 currentSize;
    u8 currentSpeed;
    u16 currentDisplayChar;

    Timer* speedTimer;
};

#endif
