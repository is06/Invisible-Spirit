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
    case FONT_STD_REGULAR: filePath.append("std_regular"); break;
  }

  core::stringc texturePath = filePath;
  core::stringc dataPath = filePath;
  texturePath.append(".png");
  dataPath.append(".dat");

  fstream fileStream(dataPath.c_str(), ios::in);
  //char str;
  if(fileStream) {
    // TODO : trouver un moyen de lire les lignes dans un conteneur stringc
    //getline(fileStream, str);
    //cout << str << endl;
  }

  fontTexture = Game::getVideoDriver()->getTexture(texturePath);
  fontMaterial.setTexture(0, fontTexture);
  fontMaterial.Lighting = false;
}

video::SMaterial& TextFont::getMaterial() {
  return fontMaterial;
}

TextFont::~TextFont() {
  fontTexture = NULL;
}
