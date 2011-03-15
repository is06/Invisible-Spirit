/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../include/core.h"

using namespace irr;
using namespace std;

Translation::Translation(const core::stringc& filePath) {
  core::stringc fullPath = "resource/text/";

  LocaleIdentifier locale = LOCALE_FRE_FR; //Game::getCurrentLocale();

  switch(locale) {
    case LOCALE_FRE_FR:
    case LOCALE_FRE_BE:
    case LOCALE_FRE_CA:
    case LOCALE_FRE_CH:
      fullPath.append("fre-FR");
    break;
    default:
      fullPath.append("eng-GB");
    break;
  }

  fullPath.append("/");
  fullPath.append(filePath);

  loadTextData(fullPath);
}

void Translation::loadTextData(const core::stringc& fullPath) {
  wifstream textFile(fullPath.c_str(), ios::in);
  if(textFile) {

    wchar_t currentChar;
    bool inTextIdentifier = true;
    bool inTextValue = false;
    core::stringc identifier = "";
    core::stringw value = L"";

    while(textFile.get(currentChar)) {
      if(currentChar == '\n' || currentChar == '\r') {
        // Nouvelle traduction
        //cout << "translation added: " << identifier.c_str() << " = " << value.c_str() << endl;
        textData[identifier] = value;
        identifier = "";
        value = L"";
        inTextValue = false;
        inTextIdentifier = true;
      }
      if(inTextValue) {
        cout << currentChar << endl;
        value.append(currentChar);
      }
      if(inTextIdentifier) {
        if(currentChar == '=') {
          // Passage de l'identifiant a la valeur
          inTextIdentifier = false;
          inTextValue = true;
        } else {
          identifier.append(currentChar);
        }
      }
    }
    textFile.close();
  }
}

const core::stringw& Translation::getTranslation(const core::stringc& identifier) const {
  return textData.find(identifier)->second;
}

Translation::~Translation() {

}
