/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../include/core.h"

using namespace std;
using namespace irr;

TextChar::TextChar(u8 code, f32 x, f32 y, TextFont* font) : Hud() {
  fontStyle = font;
}

void TextChar::render() { Hud::render();

}

TextChar::~TextChar() {

}
