/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/core.h"
#include "../../include/engine/Settings.h"
#include "../../include/engine/SettingsGroup.h"

namespace is06
{
namespace nEngine
{

/**
 * Reads the settings.ini file and stores all parameters value in a map
 */
CSettings::CSettings()
{
  fstream fileStream("settings.ini", ios::in);
  if (fileStream) {
    char current;
    bool inGroupNameDeclaration = false;
    bool inParamNameDeclaration = false;
    bool inParamValueExtraction = false;
    bool inComment = false;
    string groupName = "";
    string paramName = "";
    string paramValue = "";
    u32 linePosition = 0;

    while (fileStream.get(current)) {
      if (linePosition == 0 && current == '#') {
        inComment = true;
        continue;
      }

      if (!inComment) {
        //========================================
        // Group creation
        if (inGroupNameDeclaration) {
          if (current != ']') {
            // Adding character to Group Name
            groupName += current;
          } else {
            // Group Creation
            Data[groupName] = new CSettingsGroup(groupName);
            inGroupNameDeclaration = false;
          }
        }
        //========================================
        // Parameter creation
        else {
          if (inParamNameDeclaration) {
            if (current == '=') {
              // Starting Param Value Extraction
              inParamNameDeclaration = false;
              inParamValueExtraction = true;
              paramValue = "";
              linePosition++;
              continue;
            } else if (current == ' ' || current == '\t') {
              linePosition++;
              continue;
            } else {
              // Adding character to Param Name
              paramName += current;
            }
          }

          if (inParamValueExtraction && (current == '\n' || current == '\r')) {
            inParamNameDeclaration = false;
            inParamValueExtraction = false;
            if (Data[groupName]) {
              // Param Creation
              Data[groupName]->getParams()[paramName] = paramValue;
            }
            linePosition = -1;
          } else if (current == '\n' || current == '\r') {
            linePosition = -1;
          }

          if (inParamValueExtraction) {
            // Adding character to Param Value
            paramValue += current;
          }
        }

        if (linePosition == 0 && current == '[' && !inGroupNameDeclaration) {
          // Starting Group Declaration
          inGroupNameDeclaration = true;
          groupName = "";
        }

        if (linePosition == 0 && !inParamNameDeclaration && !inGroupNameDeclaration && current != '\n' && current != '\r') {
          // Starting Param Name Declaration
          inParamNameDeclaration = true;
          paramName = "";
          // Adding character to Param Name
          paramName += current;
        }
      } else {
        if (current == '\n' || current == '\r') {
          inComment = false;
          linePosition = -1;
        }
      }

      linePosition++;
    }
  }
  fileStream.close();
}

/**
 * Returns the string value of a parameter
 * @param const string& groupName the name of the group of parameters
 * @param const string& paramName the name of the parameter
 * @return string& a reference of the value
 */
string& CSettings::getParamString(const string& groupName, const string& paramName)
{
  return Data[groupName]->getParams()[paramName];
}

/**
 * Returns the integer value of a parameter
 * @param const string& groupName the name of the group of parameters
 * @param const string& paramName the name of the parameter
 * @return s32 the value
 */
s32 CSettings::getParamInt(const string& groupName, const string& paramName)
{
  s32 value = 0;
  if (Data[groupName]) {
    istringstream iss(Data[groupName]->getParams()[paramName]);
    iss >> value;
    return value;
  } else {
    return 0;
  }
}

CSettings::~CSettings()
{

}

}
}
