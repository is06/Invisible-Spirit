/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/gui/TextFont.h"
#include "../../include/Game.h"

using namespace std;
using namespace irr;

/**
 * Constructor, defines current font style and get the appropriate texture
 * @param FontStyle style
 */
TextFont::TextFont(FontStyle style)
{
  currentStyle = style;
  getTextureFromStyle(style);
}

/**
 * Returns the font Irrlicht material structure
 * @return video::SMaterial& reference to the font material
 */
video::SMaterial& TextFont::getMaterial()
{
  return fontMaterial;
}

/**
 * Returns the offset of the specified character
 * @param u8 code decimal code of the character
 * @return u8& reference to the offset value
 */
u8& TextFont::getCharOffset(u8 code)
{
  return offset[code];
}

/**
 * Reset current character table to standard (one-byte character)
 */
void TextFont::resetToStandard()
{
  getTextureFromStyle(currentStyle);
}

/**
 * Loads another texture in order to get multi-byte character (UTF-8)
 * @param u8 number the number of the table (example: 195 for latin acutes characters)
 */
void TextFont::changeExtTexture(u8 number)
{
  getTextureFromStyle(currentStyle, number);
}

/**
 * Reads font characters size and offset
 * @param const string& dataFilePath the path of the font data file
 */
void TextFont::readFontData(const string& dataFilePath)
{
  fstream fileStream(dataFilePath.c_str(), ios::in);
  string currentCode;
  string currentWidth;
  char currentChar;
  bool inReadingCode = true;
  bool inReadingWidth = false;

  if (fileStream) {
    while (fileStream.get(currentChar)) {
      // Get code
      if (inReadingCode && currentChar != ' ' && currentChar != '\n' && currentChar != '\r') {
        currentCode += currentChar;
      } else if (inReadingCode && currentChar == ' ') {
        inReadingCode = false;
        inReadingWidth = true;
      }

      // Get width
      if (inReadingWidth && currentChar != ' ' && currentChar != '\n' && currentChar != '\r') {
        currentWidth += currentChar;
      }

      // New line
      if (currentChar == '\n') {
        offset[atoi(currentCode.c_str())] = atoi(currentWidth.c_str());
        currentCode = "";
        currentWidth = "";
        inReadingCode = true;
        inReadingWidth = false;
      }
    }
  }
}

/**
 * Returns current font style
 * @return FontStyle the current style
 */
FontStyle TextFont::getCurrentStyle()
{
  return currentStyle;
}

/**
 * Changes current character texture from a style and eventually an extended texture
 * for multi-byte characters (UTF-8)
 * @param FontStyle style
 * @param u8 extTexture the number of the table (example: 195 for latin acutes characters)
 */
void TextFont::getTextureFromStyle(FontStyle style, u8 extTexture)
{
  string filePath = "resource/hud/font/";

  switch (style) {
    case FONT_STANDARD_48: filePath += "standard_48"; break;
    default: filePath += "standard_48"; break;
  }

  string texturePath = filePath;
  if (extTexture) {
    s32 textureNumber = extTexture;
    texturePath += "_";
    ostringstream oss;
    oss << textureNumber;
    texturePath += oss.str();
  }

  texturePath += ".png";
  string dataPath = filePath + ".dat";
  readFontData(dataPath);
  fontTexture = Game::getVideoDriver()->getTexture(texturePath.c_str());
  fontMaterial.setTexture(0, fontTexture);
  fontMaterial.Lighting = false;
}

/**
 * Destructor
 */
TextFont::~TextFont()
{
  fontTexture = NULL;
}
