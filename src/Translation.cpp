/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../include/ref/core.h"
#include "../include/Translation.h"
#include "../include/Game.h"

using namespace irr;
using namespace std;

Translation::Translation(const string& filePath)
{
  string fullPath = "resource/text/";
  notfound = "[not_found]";

  switch (Game::getCurrentLocale())
  {
    case LOCALE_FRE_FR:
    case LOCALE_FRE_BE:
    case LOCALE_FRE_CA:
    case LOCALE_FRE_CH:
      fullPath += "fre-FR";
      break;
    default:
      fullPath += "eng-GB";
      break;
  }

  fullPath += "/" + filePath;
  loadTextData(fullPath);
}

void Translation::loadTextData(const string& fullPath)
{
  //cout << "Translation file loaded : " << fullPath.c_str() << endl;

  ifstream textFile(fullPath.c_str(), ios::in);
  if (textFile) {
    //cout << "Processing translation file..." << endl;
    char currentChar;
    bool inTextIdentifier = true;
    bool inTextValue = false;
    string identifier = "";
    string value = "";

    while (textFile.get(currentChar)) {
      if (currentChar == '\n' || currentChar == '\r') {
        // Nouvelle traduction
        if (identifier != "") {
          //cout << "Added translation (" << identifier.c_str() << ") = (" << value.c_str() << ")" << endl;
          textData[identifier] = value;
        }
        identifier = "";
        value = "";
        inTextValue = false;
        inTextIdentifier = true;
      } else {
        if (inTextValue) {
          value += currentChar;
        }
        if (inTextIdentifier) {
          if (currentChar == '=') {
            // Passage de l'identifiant a la valeur
            inTextIdentifier = false;
            inTextValue = true;
          } else {
            identifier += static_cast<char>(currentChar);
          }
        }
      }
    }
    textFile.close();
  }
}

const string& Translation::getTranslation(const string& identifier) const
{
  //cout << "'" << textData.find(identifier) << "' <-> '" << textData.end() << "'" << endl;
  if (textData.find(identifier) == textData.end()) {
    //cout << "translation not found: '" << identifier.c_str() << "'" << endl;
    return notfound;
  } else {
    return textData.find(identifier)->second;
  }
}
