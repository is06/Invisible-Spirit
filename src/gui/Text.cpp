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
  textFinished = false;
  textStr = str;
  currentSize = 48;
  currentSpeed = speed;
  currentAlign = TEXT_ALIGN_LEFT;
  leftBound = 0;
  rightBound = 0;
  charList.clear();

  // @todo : create font outside text object to avoid useless multiple declarations
  font = new TextFont(style);
  currentCharPos = pos = core::dimension2df(x, y);
  currentDisplayChar = 0;
  updateTiles();
  currentLineNumber = 0;
  lineWidthList[0] = 0;

  speedTimer = NULL;
  if (currentSpeed > 0) {
    speedTimer = new Timer(currentSpeed / 512.0f, boost::bind(&Text::nextChar, this), str.size());
  }
}

/**
 *
 */
void Text::render()
{
  Hud::render();
  if (currentSpeed > 0) {
    if (currentDisplayChar >= currentTextLength) {
      speedTimer->stop();
    } else {
      speedTimer->update();
    }
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

/**
 *
 */
void Text::setText(const string& str)
{
  textStr = str;
  updateTiles();
}

/**
 * Sets text position
 * @param const core::position2df& position the new text position
 */
void Text::setPosition(const core::position2df& position)
{
  // Compute delta position => setting position of each character
  core::position2df delta = position - pos;
  // Modify Text container position
  pos = position;

  // Modify every character positions
  for (charIt = charList.begin(); charIt != charList.end(); charIt++) {
    charIt->setPosition(charIt->getX() + delta.X, charIt->getY() + delta.Y);
  }
}

/**
 * Shows the next character
 */
void Text::nextChar()
{
  if (currentDisplayChar < currentTextLength) {
    charList[currentDisplayChar].show();
  }
  if (!textFinished && currentDisplayChar >= (currentTextLength - 1)) {
    textFinished = true;
  }
  currentDisplayChar++;
}

void Text::skip()
{
  currentSpeed = 0;
  show();
}

/**
 * Create character list by updating every tiles
 */
void Text::updateTiles()
{
  charList.clear();
  currentCharPos = pos;
  currentTextLength = 0;
  bool escapeCharacter = false;
  const char* cs = textStr.c_str();
  u8 nextUtf8Table = 0;
  for (u16 i = 0; i < textStr.size(); i++) {
    if (escapeCharacter) {
      if (cs[i] == 'n') {
        currentLineNumber++;
        lineWidthList[currentLineNumber] = 0;
        currentCharPos.X = pos.X;
        currentCharPos.Y -= (currentSize - (currentSize / 8));
        escapeCharacter = false;
      }
    } else {
      if (cs[i] == '\\') {
        escapeCharacter = true;
        continue;
      } else {
        // The first byte is 110xxxxx: this means the character is stored with two bytes (utf-8)
        // Thanks to Christopho (https://github.com/christopho) for this trick
        if ((cs[i] & 0xE0) == 0xC0) {
          // Multi-byte utf-8 character found!
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
          currentTextLength++;
          lineWidthList[currentLineNumber] += currentSize;
          //cout << "width (" << currentLineNumber << ") => " << currentSize << endl;
        }
      }
    }
  }
}

/**
 * Sets left and right bounds for text container
 * @param f32 left left bound X coordinate
 * @param f32 right right bound X coordinate
 */
void Text::setSideBounds(f32 left, f32 right)
{
  leftBound = left;
  rightBound = right;
}

/**
 * Aligns the text in its container
 */
void Text::setAlign(TextAlignment align)
{
  currentAlign = align;

  switch (align) {
    case TEXT_ALIGN_LEFT:
      setPosition(core::dimension2df(leftBound, pos.Y));
      break;
    case TEXT_ALIGN_RIGHT:
      //setPosition(core::dimension2df((rightBound - width), pos.Y));
      break;
    case TEXT_ALIGN_CENTER:
      //setPosition(core::dimension2df((((leftBound + rightBound) / 2.0f) - (width / 2.0f)), pos.Y));
      break;
  }
}

void Text::show()
{
  for (charIt = charList.begin(); charIt != charList.end(); charIt++) {
    charIt->show();
  }
}

void Text::hide()
{
  for (charIt = charList.begin(); charIt != charList.end(); charIt++) {
    charIt->hide();
  }
}

void Text::setOpacity(u8 value)
{
  for (charIt = charList.begin(); charIt != charList.end(); charIt++) {
    charIt->setOpacity(value);
  }
}

bool Text::finished()
{
  return textFinished;
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
