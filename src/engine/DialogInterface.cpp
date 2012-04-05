/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/Game.h"
#include "../../include/Translation.h"
#include "../../include/gui/Text.h"
#include "../../include/engine/DialogInterface.h"

using namespace std;

/**
 *
 */
DialogInterface::DialogInterface(const string& filePath, Translation* translation)
{
  if (!translation) {
    Game::fatalError(ERRCODE_60);
  }

  currentTranslation = translation;
  currentMessageNumber = 0;
  currentMessageText = NULL;

  string fullPath = "resource/text/";

  switch (Game::getCurrentLocale()) {
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
  loadDialogData(fullPath);
}

/**
 *
 */
void DialogInterface::render()
{
  if (currentMessageText) {
    currentMessageText->render();
  }
}

/**
 * @todo
 */
void DialogInterface::loadDialogData(const string& fullPath)
{
  fstream fileStream(fullPath.c_str(), ios::in);

  if (fileStream) {
    char current = 0;
    string dialogIdentifier = "";
    string textIdentifier = "";
    bool inIdentifierDeclaration = true;
    bool inTextDeclaration = false;

    while (fileStream.get(current)) {
      if (current == '=') {
        // Add dialog to list
        cout << "create new dialog (" << dialogIdentifier << ")" << endl;
        dialogList[dialogIdentifier] = Dialog(dialogIdentifier);
        inTextDeclaration = true;
        inIdentifierDeclaration = false;
        textIdentifier = "";
        continue;
      }
      if (current == ';') {
        // Add text to the dialog
        cout << "adding text to the dialog (" << textIdentifier << ")" << endl;
        dialogList[dialogIdentifier].addMessage(currentTranslation->getTranslation(textIdentifier));
        textIdentifier = "";
        continue;
      }
      if (current == '\n' || current == '\r') {
        inIdentifierDeclaration = true;
        inTextDeclaration = false;
        dialogIdentifier = "";
        continue;
      }

      if (inIdentifierDeclaration) {
        dialogIdentifier += current;
      }
      if (inTextDeclaration) {
        textIdentifier += current;
      }
    }
  }
}

/**
 *
 */
void DialogInterface::start(const string& dialogIdentifier)
{
  createMessage(dialogIdentifier, 0);
}

/**
 *
 */
void DialogInterface::createMessage(const string& dialogIdentifier, u16 messageNumber)
{
  //cout << "Try to create dialog message '" << messageList[number] << "'" << endl;

  currentMessageText = new Text(dialogList[dialogIdentifier].getMessage(messageNumber));
}

/**
 *
 */
void DialogInterface::nextMessage()
{

}

/**
 *
 */
void DialogInterface::goToMessage(u32 number)
{

}

/**
 * @todo
 */
bool DialogInterface::finished()
{
  return false;
}

/**
 *
 */
DialogInterface::~DialogInterface()
{

}
