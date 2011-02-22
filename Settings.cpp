/******************************************************************************
Le code source d'Invisible Spirit par Thomas Noury est mis à disposition selon
les termes de la licence Creative Commons Paternité - Pas d'Utilisation
Commerciale - Partage des Conditions Initiales à l'Identique (BY-NC-SA) 3.0
Unported. Basé(e) sur une oeuvre à www.is06.com.  Les autorisations au-delà du
champ de cette licence peuvent être obtenues à http://www.is06.com.
*******************************************************************************/

#include "core.h"

using namespace irr;
using namespace std;

Settings::Settings() {
  fstream fileStream("settings.ini", ios::in | ios::out);
  if(fileStream) {
    c8 current;
    bool inGroupNameDeclaration = false;
    bool inParamNameDeclaration = false;
    bool inParamValueExtraction = false;
    core::stringc groupName = "";
    core::stringc paramName = "";
    core::stringc paramValue = "";
    u32 linePosition = 0;

    while(fileStream.get(current)) {
      //========================================
      // Création de groupes
      if(inGroupNameDeclaration) {
        if(current != ']') {
          // Adding character to Group Name
          groupName.append(current);
        } else {
          // Group Creation
          data[groupName] = new SettingsGroup(groupName);
          inGroupNameDeclaration = false;
        }
      }
      //========================================
      // Création de paramètres
      else {
        if(inParamNameDeclaration) {
          if(current == '=') {
            // Starting Param Value Extraction
            inParamNameDeclaration = false;
            inParamValueExtraction = true;
            paramValue = "";
            linePosition++;
            continue;
          } else if(current == ' ' || current == '\t') {
            linePosition++;
            continue;
          } else {
            // Adding character to Param Name
            paramName.append(current);
          }
        }

        if(inParamValueExtraction && (current == '\n' || current == '\r')) {
          inParamNameDeclaration = false;
          inParamValueExtraction = false;
          if(data[groupName]) {
            // Param Creation
            data[groupName]->getParams()[paramName] = paramValue;
          }
          linePosition = -1;
        } else if(current == '\n' || current == '\r') {
          linePosition = -1;
        }

        if(inParamValueExtraction) {
          // Adding character to Param Value
          paramValue.append(current);
        }
      }

      if(linePosition == 0 && current == '[' && !inGroupNameDeclaration) {
        // Starting Group Declaration
        inGroupNameDeclaration = true;
        groupName = "";
      }

      if(linePosition == 0 && !inParamNameDeclaration && !inGroupNameDeclaration && current != '\n' && current != '\r') {
        // Starting Param Name Declaration
        inParamNameDeclaration = true;
        paramName = "";
        // Adding character to Param Name
        paramName.append(current);
      }

      linePosition++;
    }
  }
}

core::stringc& Settings::getParamString(const core::stringc& groupName, const core::stringc& paramName) {
  return data[groupName]->getParams()[paramName];
}

s32 Settings::getParamInt(const core::stringc& groupName, const core::stringc& paramName) {
  if(data[groupName]) {
    return (s32)atoi(data[groupName]->getParams()[paramName].c_str());
  } else {
    return 0;
  }
}

Settings::~Settings() {
  fileStream.close();
}
