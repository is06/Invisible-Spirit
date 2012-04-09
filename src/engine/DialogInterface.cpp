/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/Game.h"
#include "../../include/Keyboard.h"
#include "../../include/Translation.h"
#include "../../include/gui/Text.h"
#include "../../include/gui/Picture.h"
#include "../../include/engine/DialogInterface.h"

using namespace std;
using namespace irr;

/**
 *
 */
DialogInterface::DialogInterface(const string& filePath, Translation* translation, Keyboard* kb)
{
  keyboard = kb;

  messageDisplaying = false;
  messageFinished = false;
  dialogFinished = false;

  if (!translation) {
    Game::fatalError(ERRCODE_60);
  }

  currentTranslation = translation;
  currentMessageNumber = 0;
  currentMessageText = NULL;

  backWindow = new Picture(0, Game::screenPos.bottom + 68, 1280, 136, "resource/hud/window/dialog_back.png");

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
  // Background of dialog
  backWindow->render();

  // Text
  if (currentMessageText) {
    currentMessageText->render();

    // Dialog finished
    if (!dialogFinished && messageFinished && currentMessageNumber >= dialogList[currentDialogIdentifier].getMessageCount() - 1) {
      cout << "dialog finished" << endl;
      dialogFinished = true;
    }

    if (messageDisplaying && currentMessageText->finished()) {
      messageDisplaying = false;
      messageFinished = true;
      cout << "message finished" << endl;
    }

    // Display all message quickly
    if (messageDisplaying && keyboard->pressed(KEY_SPACE, EVENT_ONCE)) {
      cout << "skipping message" << endl;
      currentMessageText->skip();
      messageDisplaying = false;
      messageFinished = true;
    }

    // Go to next message (only if entirely displayed)
    if (messageFinished && keyboard->pressed(KEY_SPACE, EVENT_ONCE)) {
      cout << "go to next message" << endl;
      messageFinished = false;
      messageDisplaying = true;
      if (!dialogFinished) {
        nextMessage();
      }
    }
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
        //cout << "create new dialog (" << dialogIdentifier << ")" << endl;
        dialogList[dialogIdentifier] = Dialog(dialogIdentifier);
        inTextDeclaration = true;
        inIdentifierDeclaration = false;
        textIdentifier = "";
        continue;
      }
      if (current == ';') {
        // Add text to the dialog
        //cout << "adding text to the dialog (" << textIdentifier << ") => (" << currentTranslation->getTranslation(textIdentifier) << ")" << endl;
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
  currentDialogIdentifier = dialogIdentifier;
  createMessage(dialogIdentifier, 0);
  messageDisplaying = true;
}

/**
 *
 */
void DialogInterface::createMessage(const string& dialogIdentifier, u16 messageNumber)
{
  currentMessageText = new Text(dialogList[dialogIdentifier].getMessage(messageNumber), -350, Game::screenPos.bottom + 100, FONT_STANDARD_48, 25);
}

/**
 *
 */
void DialogInterface::nextMessage()
{
  delete currentMessageText;
  currentMessageNumber++;
  createMessage(currentDialogIdentifier, currentMessageNumber);
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
  delete backWindow;
}
