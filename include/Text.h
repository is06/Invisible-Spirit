/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_TEXT_H__
#define __IS06_TEXT_H__

using namespace std;
using namespace irr;

class Text : public Hud {
  public:
    Text(const core::stringw& str, f32 x, f32 y, FontStyle style = FONT_STD_REGULAR);
    ~Text();

    void render();

  private:
    TextFont* font;
    core::position2df pos;
    core::position2df currentCharPos;
    core::stringw textStr;
    vector<TextChar> charList;
    vector<TextChar>::iterator charIt;

};

#endif
