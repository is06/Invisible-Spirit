/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/core.h"
#include "../../include/engine/Translation.h"
#include "../../include/engine/Game.h"

namespace is06
{
namespace nEngine
{

//! Constructor
CTranslation::CTranslation(const string& filePath)
{
  string fullPath = "resource/text/";
  Notfound = "[not_found]";

  switch (CGame::getCurrentLocale()) {
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

//! Loads all text data from file according to the current locale
void CTranslation::loadTextData(const string& fullPath)
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
          TextData[identifier] = value;
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
            identifier += currentChar;
          }
        }
      }
    }
    textFile.close();
  } else {
    //cout << "[!!] Translation file not found: " << fullPath.c_str() << endl;
  }
}

//! Returns a specific string translation
const string& CTranslation::getTranslation(const string& identifier) const
{
  //cout << "'" << textData.find(identifier) << "' <-> '" << textData.end() << "'" << endl;
  if (TextData.find(identifier) == TextData.end()) {
    //cout << "[!!] Translation not found: '" << identifier.c_str() << "'" << endl;
    return Notfound;
  } else {
    return TextData.find(identifier)->second;
  }
}

}
}
