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
  currentSize = 24;
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
  for (u16 i = 0; i < textStr.size(); i++) {
    if (cs[i] == '\n') {
      currentCharPos.X = pos.X;
      currentCharPos.Y -= (currentSize - (currentSize / 8));
    } else {
      charList.push_back(TextChar(cs[i], currentCharPos.X, currentCharPos.Y, currentSize, font, (currentSpeed == 0)));
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
