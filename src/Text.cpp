/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../include/core.h"

using namespace std;
using namespace irr;

/**
 *
 */
Text::Text(const core::stringw& str, f32 x, f32 y, FontStyle style) : Hud() {
  textStr = str;
  font = new TextFont(style);
  currentCharPos = pos = core::dimension2df(x, y);
  const wchar_t* cs = textStr.c_str();
  for(u16 i = 0; i < str.size(); i++) {
    if(cs[i] == '\n') {
      currentCharPos.X = x;
      currentCharPos.Y -= 28;
    } else {
      charList.push_back(TextChar(cs[i], currentCharPos.X, currentCharPos.Y, font));
    }
  }
}

/**
 *
 */
void Text::render() { Hud::render();
  for(charIt = charList.begin(); charIt != charList.end(); charIt++) {
    charIt->render();
  }
}

/**
 *
 */
Text::~Text() {
  delete font;
}
