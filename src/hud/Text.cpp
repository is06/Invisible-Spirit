/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/core.h"
#include "../../include/engine/Timer.h"
#include "../../include/hud/Text.h"
#include "../../include/hud/TextFont.h"
#include "../../include/hud/TextChar.h"

namespace is06
{
namespace nHud
{

CText::CText(const string& str, f32 x, f32 y, EFontStyle style, u8 speed) : CHud()
{
  TextFinished = false;
  TextStr = str;
  CurrentSize = 48;
  CurrentSpeed = speed;
  CurrentAlign = TEXT_ALIGN_LEFT;
  LeftBound = 0;
  RightBound = 0;
  CharList.clear();

  // @todo : create font outside text object to avoid useless multiple declarations
  Font = new CTextFont(style);
  CurrentCharPos = Pos = core::dimension2df(x, y);
  CurrentDisplayChar = 0;
  updateTiles();
  CurrentLineNumber = 0;
  LineWidthList[0] = 0;

  SpeedTimer = NULL;
  if (CurrentSpeed > 0) {
    SpeedTimer = new nEngine::CTimer(CurrentSpeed / 512.0f, boost::bind(&CText::nextChar, this), str.size());
  }
}

/**
 *
 */
void CText::render()
{
  CHud::render();
  if (CurrentSpeed > 0) {
    if (CurrentDisplayChar >= CurrentTextLength) {
      SpeedTimer->stop();
    } else {
      SpeedTimer->update();
    }
  }
  for (CharIt = CharList.begin(); CharIt != CharList.end(); CharIt++) {
    CharIt->render();
  }
}

/**
 *
 */
void CText::setSize(u8 size)
{
  CurrentSize = size;
  updateTiles();
}

/**
 *
 */
void CText::setText(const string& str)
{
  TextStr = str;
  updateTiles();
}

/**
 * Sets text position
 * @param const core::position2df& position the new text position
 */
void CText::setPosition(const core::position2df& position)
{
  // Compute delta position => setting position of each character
  core::position2df delta = position - Pos;
  // Modify Text container position
  Pos = position;

  // Modify every character positions
  for (CharIt = CharList.begin(); CharIt != CharList.end(); CharIt++) {
    CharIt->setPosition(CharIt->getX() + delta.X, CharIt->getY() + delta.Y);
  }
}

/**
 * Shows the next character
 */
void CText::nextChar()
{
  if (CurrentDisplayChar < CurrentTextLength) {
    CharList[CurrentDisplayChar].show();
  }
  if (!TextFinished && CurrentDisplayChar >= (CurrentTextLength - 1)) {
    TextFinished = true;
  }
  CurrentDisplayChar++;
}

void CText::skip()
{
  CurrentSpeed = 0;
  show();
}

/**
 * Create character list by updating every tiles
 */
void CText::updateTiles()
{
  CharList.clear();
  CurrentCharPos = Pos;
  CurrentTextLength = 0;
  bool escapeCharacter = false;
  const char* cs = TextStr.c_str();
  u8 nextUtf8Table = 0;
  for (u16 i = 0; i < TextStr.size(); i++) {
    if (escapeCharacter) {
      if (cs[i] == 'n') {
        CurrentLineNumber++;
        LineWidthList[CurrentLineNumber] = 0;
        CurrentCharPos.X = Pos.X;
        CurrentCharPos.Y -= (CurrentSize - (CurrentSize / 8));
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
            CharList.push_back(CTextChar(cs[i], CurrentCharPos.X, CurrentCharPos.Y, CurrentSize, Font, (CurrentSpeed == 0)));
          } else {
            // Extended utf-8 character
            CharList.push_back(CTextChar(cs[i], CurrentCharPos.X, CurrentCharPos.Y, CurrentSize, Font, (CurrentSpeed == 0), nextUtf8Table));
            nextUtf8Table = 0;
          }
          CurrentTextLength++;
          LineWidthList[CurrentLineNumber] += CurrentSize;
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
void CText::setSideBounds(f32 left, f32 right)
{
  LeftBound = left;
  RightBound = right;
}

/**
 * Aligns the text in its container
 */
void CText::setAlign(ETextAlignment align)
{
  CurrentAlign = align;

  switch (align) {
    case TEXT_ALIGN_LEFT:
      setPosition(core::dimension2df(LeftBound, Pos.Y));
      break;
    case TEXT_ALIGN_RIGHT:
      //setPosition(core::dimension2df((rightBound - width), pos.Y));
      break;
    case TEXT_ALIGN_CENTER:
      //setPosition(core::dimension2df((((leftBound + rightBound) / 2.0f) - (width / 2.0f)), pos.Y));
      break;
  }
}

void CText::show()
{
  for (CharIt = CharList.begin(); CharIt != CharList.end(); CharIt++) {
    CharIt->show();
  }
}

void CText::hide()
{
  for (CharIt = CharList.begin(); CharIt != CharList.end(); CharIt++) {
    CharIt->hide();
  }
}

void CText::setOpacity(u8 value)
{
  for (CharIt = CharList.begin(); CharIt != CharList.end(); CharIt++) {
    CharIt->setOpacity(value);
  }
}

bool CText::finished()
{
  return TextFinished;
}

/**
 *
 */
CText::~CText()
{
  delete Font;
  if (SpeedTimer) {
    delete SpeedTimer;
  }
}

}
}
