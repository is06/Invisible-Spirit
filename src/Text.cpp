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
  currentSize = 24;
  font = new TextFont(style);
  currentCharPos = pos = core::dimension2df(x, y);
  updateTiles();
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
void Text::setSize(u8 size) {
  currentSize = size;
  updateTiles();
}

/**
 *
 */
void Text::updateTiles() {
  charList.clear();
  currentCharPos = pos;
  const wchar_t* cs = textStr.c_str();
  for(u16 i = 0; i < textStr.size(); i++) {
    if(cs[i] == '\n') {
      currentCharPos.X = pos.X;
      currentCharPos.Y -= (currentSize - (currentSize / 8));
    } else {
      charList.push_back(TextChar(cs[i], currentCharPos.X, currentCharPos.Y, currentSize, font));
    }
  }
}

/**
 *
 */
Text::~Text() {
  delete font;
}
