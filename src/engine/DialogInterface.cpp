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

namespace is06
{
namespace engine
{

/**
 *
 */
CDialogInterface::CDialogInterface(const std::string& filePath, CTranslation* translation, CKeyboard* keyboard)
{
  Keyboard = keyboard;

  MessageDisplaying = false;
  MessageFinished = false;
  DialogFinished = false;

  if (!translation) {
    CGame::fatalError(debug::ERRCODE_60);
  }

  CurrentTranslation = translation;
  CurrentMessageNumber = 0;
  CurrentMessageText = NULL;

  BackWindow = new hud::CPicture(0, CGame::ScreenPos.Bottom + 68, 1280, 136, "resource/hud/window/dialog_back.png");

  std::string fullPath = "resource/text/";

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
  loadDialogData(fullPath);
}

/**
 *
 */
void CDialogInterface::render()
{
  // Background of dialog
  BackWindow->render();

  // Text
  if (CurrentMessageText) {
    CurrentMessageText->render();

    // Dialog finished
    if (!DialogFinished && MessageFinished && CurrentMessageNumber >= DialogList[CurrentDialogIdentifier].getMessageCount() - 1) {
      DialogFinished = true;
    }

    if (MessageDisplaying && CurrentMessageText->finished()) {
      MessageDisplaying = false;
      MessageFinished = true;
    }

    // Display all message quickly
    if (MessageDisplaying && Keyboard->pressed(irr::KEY_SPACE, EVENT_ONCE)) {
      CurrentMessageText->skip();
      MessageDisplaying = false;
      MessageFinished = true;
    }

    // Go to next message (only if entirely displayed)
    if (MessageFinished && Keyboard->pressed(irr::KEY_SPACE, EVENT_ONCE)) {
      MessageFinished = false;
      MessageDisplaying = true;
      if (!DialogFinished) {
        nextMessage();
      }
    }
  }
}

/**
 * @todo
 */
void CDialogInterface::loadDialogData(const std::string& fullPath)
{
  std::fstream fileStream(fullPath.c_str(), std::ios::in);

  if (fileStream) {
    char current = 0;
    std::string dialogIdentifier = "";
    std::string textIdentifier = "";
    bool inIdentifierDeclaration = true;
    bool inTextDeclaration = false;

    while (fileStream.get(current)) {
      if (current == '=') {
        // Add dialog to list
        //cout << "create new dialog (" << dialogIdentifier << ")" << endl;
        DialogList[dialogIdentifier] = CDialog(dialogIdentifier);
        inTextDeclaration = true;
        inIdentifierDeclaration = false;
        textIdentifier = "";
        continue;
      }
      if (current == ';') {
        // Add text to the dialog
        //cout << "adding text to the dialog (" << textIdentifier << ") => (" << currentTranslation->getTranslation(textIdentifier) << ")" << endl;
        DialogList[dialogIdentifier].addMessage(CurrentTranslation->getTranslation(textIdentifier));
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
void CDialogInterface::start(const std::string& dialogIdentifier)
{
  CurrentDialogIdentifier = dialogIdentifier;
  createMessage(dialogIdentifier, 0);
  MessageDisplaying = true;
}

/**
 *
 */
void CDialogInterface::createMessage(const std::string& dialogIdentifier, irr::u16 messageNumber)
{
  CurrentMessageText = new hud::CText(
    DialogList[dialogIdentifier].getMessage(messageNumber),
    -350,
    CGame::ScreenPos.Bottom + 100,
    hud::FONT_STANDARD_48,
    25
  );
}

/**
 *
 */
void CDialogInterface::nextMessage()
{
  delete CurrentMessageText;
  CurrentMessageNumber++;
  createMessage(CurrentDialogIdentifier, CurrentMessageNumber);
}

/**
 *
 */
void CDialogInterface::goToMessage(irr::u32 number)
{

}

/**
 * @todo
 */
bool CDialogInterface::finished()
{
  return false;
}

/**
 *
 */
CDialogInterface::~CDialogInterface()
{
  delete BackWindow;
}

}
}
