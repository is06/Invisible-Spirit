/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/gui/Text.h"
#include "../../include/gui/TextFont.h"
#include "../../include/gui/TextChar.h"
#include "../../include/Timer.h"

using namespace std;
using namespace irr;

/**
 *
 */
Text::Text(const string& str, f32 x, f32 y, FontStyle style, u8 speed) : Hud()
{
  textStr = str;
  currentSize = 48;
  currentSpeed = speed;
  charList.clear();
  font = new TextFont(style);
  currentCharPos = pos = core::dimension2df(x, y);
  currentDisplayChar = 0;
  updateTiles();

  speedTimer = NULL;
  if (currentSpeed > 0) {
    speedTimer = new Timer(0.01f, boost::bind(&Text::nextChar, this), str.size());
  }
}

/**
 *
 */
void Text::render()
{
  Hud::render();
  if (currentSpeed > 0) {
    speedTimer->update();
  }
  for (charIt = charList.begin(); charIt != charList.end(); charIt++) {
    charIt->render();
  }
}

/**
 *
 */
void Text::setSize(u8 size)
{
  currentSize = size;
  updateTiles();
}

void Text::setText(const string& str)
{
  textStr = str;
  updateTiles();
}

void Text::setPosition(const core::position2df& position)
{
  pos = position;
}

void Text::nextChar()
{
  charList[currentDisplayChar].show();
  currentDisplayChar++;
}

/**
 *
 */
void Text::updateTiles()
{
  charList.clear();
  currentCharPos = pos;
  const char* cs = textStr.c_str();
  u8 nextUtf8Table = 0;
  for (u16 i = 0; i < textStr.size(); i++) {
    if (cs[i] == '\n') {
      currentCharPos.X = pos.X;
      currentCharPos.Y -= (currentSize - (currentSize));
    } else {
      // The first byte is 110xxxxx: this means the character is stored with two bytes (utf-8)
      // Thanks to Christopho (https://github.com/christopho) for this trick
      if ((cs[i] & 0xE0) == 0xC0) {
        //cout << "Multi-byte utf-8 character found!" << static_cast<int>(cs[i]) << endl;
        nextUtf8Table = cs[i];
      } else {
        if (!nextUtf8Table) {
          // Standard character
          charList.push_back(TextChar(cs[i], currentCharPos.X, currentCharPos.Y, currentSize, font, (currentSpeed == 0)));
        } else {
          // Extended utf-8 character
          charList.push_back(TextChar(cs[i], currentCharPos.X, currentCharPos.Y, currentSize, font, (currentSpeed == 0), nextUtf8Table));
          nextUtf8Table = 0;
        }
      }
    }
  }
}

/**
 *
 */
Text::~Text()
{
  delete font;
  if (speedTimer) {
    delete speedTimer;
  }
}
