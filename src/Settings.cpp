/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../include/ref/core.h"
#include "../include/Settings.h"
#include "../include/SettingsGroup.h"

using namespace irr;
using namespace std;

Settings::Settings()
{
  fstream fileStream("settings.ini", ios::in);
  if (fileStream) {
    char current;
    bool inGroupNameDeclaration = false;
    bool inParamNameDeclaration = false;
    bool inParamValueExtraction = false;
    string groupName = "";
    string paramName = "";
    string paramValue = "";
    u32 linePosition = 0;

    while (fileStream.get(current)) {
      //========================================
      // Group creation
      if (inGroupNameDeclaration) {
        if (current != ']') {
          // Adding character to Group Name
          groupName += current;
        } else {
          // Group Creation
          data[groupName] = new SettingsGroup(groupName);
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
          if (data[groupName]) {
            // Param Creation
            data[groupName]->getParams()[paramName] = paramValue;
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

      linePosition++;
    }
  }
  fileStream.close();
}

string& Settings::getParamString(const string& groupName, const string& paramName)
{
  return data[groupName]->getParams()[paramName];
}

s32 Settings::getParamInt(const string& groupName, const string& paramName)
{
  if (data[groupName]) {
    return (s32)atoi(data[groupName]->getParams()[paramName].c_str());
  } else {
    return 0;
  }
}

Settings::~Settings()
{

}
