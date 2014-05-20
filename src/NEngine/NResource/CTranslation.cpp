/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/core.h"
#include "../../../include/NEngine/NResource/CTranslation.h"
#include "../../../include/NEngine/NCore/CGame.h"

namespace is06 { namespace NEngine { namespace NResource {

//! Constructor
CTranslation::CTranslation(const string& filePath)
{
    string fullPath = "resource/text/";
    Notfound = "[not_found]";

    switch (NEngine::NCore::CGame::getCurrentLocale()) {
        case ELI_FRE_FR:
        case ELI_FRE_BE:
        case ELI_FRE_CA:
        case ELI_FRE_CH:
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
    ifstream textFile(fullPath.c_str(), ios::in);
    if (textFile) {
        char currentChar;
        bool inTextIdentifier = true;
        bool inTextValue = false;
        string identifier = "";
        string value = "";

        while (textFile.get(currentChar)) {
            if (currentChar == '\n' || currentChar == '\r') {
                // Nouvelle traduction
                if (identifier != "") {
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
    if (TextData.find(identifier) == TextData.end()) {
        return Notfound;
    } else {
        return TextData.find(identifier)->second;
    }
}

}}}
