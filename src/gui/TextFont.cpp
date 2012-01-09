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
 *
 */
TextFont::TextFont(FontStyle style) {
  core::stringc filePath = "resource/hud/font/";

  switch(style) {
    case FONT_STD_CLASSIC_REGULAR: filePath.append("std_classic_regular"); break;
    case FONT_COND_CLASSIC_REGULAR: filePath.append("cond_classic_regular"); break;
    case FONT_EXT_CLASSIC_REGULAR: filePath.append("ext_classic_regular"); break;
    case FONT_STD_CLASSIC_BOLD: filePath.append("std_classic_bold"); break;
    case FONT_COND_CLASSIC_BOLD: filePath.append("cond_classic_bold"); break;
    case FONT_EXT_CLASSIC_BOLD: filePath.append("ext_classic_bold"); break;

    case FONT_STD_SHADED_REGULAR: filePath.append("std_shaded_regular"); break;
    case FONT_COND_SHADED_REGULAR: filePath.append("cond_shaded_regular"); break;
    case FONT_EXT_SHADED_REGULAR: filePath.append("ext_shaded_regular"); break;
    case FONT_STD_SHADED_BOLD: filePath.append("std_shaded_bold"); break;
    case FONT_COND_SHADED_BOLD: filePath.append("cond_shaded_bold"); break;
    case FONT_EXT_SHADED_BOLD: filePath.append("ext_shaded_bold"); break;

    case FONT_STD_BORDER_SHADED_REGULAR: filePath.append("std_border_shaded_regular"); break;
    case FONT_COND_BORDER_SHADED_REGULAR: filePath.append("cond_border_shaded_regular"); break;
    case FONT_EXT_BORDER_SHADED_REGULAR: filePath.append("ext_border_shaded_regular"); break;
    case FONT_STD_BORDER_SHADED_BOLD: filePath.append("std_border_shaded_bold"); break;
    case FONT_COND_BORDER_SHADED_BOLD: filePath.append("cond_border_shaded_bold"); break;
    case FONT_EXT_BORDER_SHADED_BOLD: filePath.append("ext_border_shaded_bold"); break;

    case FONT_LOCATION_TITLE_REGULAR: filePath.append("location_title_regular"); break;
    case FONT_DIALOG_NAME_TITLE_REGULAR: filePath.append("dialog_name_regular"); break;

    default: break;
  }

  core::stringc texturePath = filePath;

  core::stringc dataPath = filePath;
  texturePath.append(".png");
  dataPath.append(".dat");

  readFontData(dataPath);

  fontTexture = Game::getVideoDriver()->getTexture(texturePath);
  fontMaterial.setTexture(0, fontTexture);
  fontMaterial.Lighting = false;
}

/**
 *
 */
video::SMaterial& TextFont::getMaterial() {
  return fontMaterial;
}

u8& TextFont::getCharOffset(u8 code) {
  return offset[code];
}

/**
 *
 */
void TextFont::readFontData(const core::stringc& dataFilePath) {
  // Lecture des information de taille
  fstream fileStream(dataFilePath.c_str(), ios::in);
  core::stringc currentCode;
  core::stringc currentWidth;
  c8 currentChar;
  bool inReadingCode = true;
  bool inReadingWidth = false;

  if(fileStream) {
    while(fileStream.get(currentChar)) {
      // Lecture du code
      if(inReadingCode && currentChar != ' ' && currentChar != '\n' && currentChar != '\r') {
        currentCode.append(currentChar);
      } else if(inReadingCode && currentChar == ' ') {
        inReadingCode = false;
        inReadingWidth = true;
      }

      // Lecture de la largeur
      if(inReadingWidth && currentChar != ' ' && currentChar != '\n' && currentChar != '\r') {
        currentWidth.append(currentChar);
      }

      // Nouvelle ligne
      if(currentChar == '\n') {
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
 *
 */
TextFont::~TextFont() {
  fontTexture = NULL;

}
