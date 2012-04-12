/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/gui/TextFont.h"
#include "../../include/Game.h"

namespace is06
{
namespace hud
{

/**
 * Constructor, defines current font style and get the appropriate texture
 * @param FontStyle style
 */
CTextFont::CTextFont(EFontStyle style)
{
  CurrentStyle = style;
  getFontDataFromStyle(style);
  getTextureFromStyle(style);
}

/**
 * Returns the font Irrlicht material structure
 * @return video::SMaterial& reference to the font material
 */
irr::video::SMaterial& CTextFont::getMaterial()
{
  return FontMaterial;
}

/**
 * Returns the offset of the specified character
 * @param u8 code decimal code of the character
 * @return u8& reference to the offset value
 */
irr::u8& CTextFont::getCharOffset(irr::u8 code)
{
  return Offset[code];
}

/**
 * Reset current character table to standard (one-byte character)
 */
void CTextFont::resetToStandard()
{
  getTextureFromStyle(CurrentStyle);
}

/**
 * Loads another texture in order to get multi-byte character (UTF-8)
 * @param u8 number the number of the table (example: 195 for latin acutes characters)
 */
void CTextFont::changeExtTexture(irr::u8 number)
{
  getTextureFromStyle(CurrentStyle, number);
}

/**
 * Reads font characters size and offset
 * @param const std::string& dataFilePath the path of the font data file
 */
void CTextFont::readFontData(const std::string& dataFilePath)
{
  std::fstream fileStream(dataFilePath.c_str(), std::ios::in);
  std::string currentCode;
  std::string currentWidth;
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
        Offset[atoi(currentCode.c_str())] = atoi(currentWidth.c_str());
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
EFontStyle CTextFont::getCurrentStyle()
{
  return CurrentStyle;
}

void CTextFont::getFontDataFromStyle(EFontStyle style)
{
  std::string filePath = "resource/hud/font/";

  switch (style) {
    case FONT_STANDARD_48: filePath += "standard_48"; break;
    default: filePath += "standard_48"; break;
  }

  std::string dataPath = filePath + ".isf";
  readFontData(dataPath);
}

/**
 * Changes current character texture from a style and eventually an extended texture
 * for multi-byte characters (UTF-8)
 * @param FontStyle style
 * @param u8 extTexture the number of the table (example: 195 for latin acutes characters)
 */
void CTextFont::getTextureFromStyle(EFontStyle style, irr::u8 extTexture)
{
  std::string filePath = "resource/hud/font/";

  switch (style) {
    case FONT_STANDARD_48: filePath += "standard_48"; break;
    default: filePath += "standard_48"; break;
  }

  std::string texturePath = filePath;
  if (extTexture) {
    irr::s32 textureNumber = extTexture;
    texturePath += "_";
    std::stringstream oss;
    oss << textureNumber;
    texturePath += oss.str();
  }

  texturePath += ".png";

  FontTexture = engine::CGame::getVideoDriver()->getTexture(texturePath.c_str());
  FontMaterial.setTexture(0, FontTexture);
  FontMaterial.Lighting = false;
}

/**
 * Destructor
 */
CTextFont::~CTextFont()
{
  FontTexture = NULL;
}

}
}
