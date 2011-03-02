/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../include/core.h"

using namespace std;
using namespace irr;

TextFont::TextFont(FontStyle style) {
  core::stringc filePath = "resource/hud/font/";

  switch(style) {
    case FONT_STD_REGULAR: filePath.append("std_regular.png"); break;
  }

  fontFile = Game::getVideoDriver()->getTexture(filePath);
}

TextFont::~TextFont() {
  fontFile = NULL;
}
