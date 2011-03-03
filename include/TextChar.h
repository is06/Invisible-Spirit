/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_TEXT_CHAR_H__
#define __IS06_TEXT_CHAR_H__

using namespace std;
using namespace irr;

class TextChar : public Hud2DElement {
  public:
    TextChar(u8 code, f32& x, f32& y, u8 size, TextFont* font);
    ~TextChar();

    void render();

  private:
    TextFont* fontStyle;
};

#endif
