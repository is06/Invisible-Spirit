/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/Engine/core.h"
#include "../../../include/Engine/CGame.h"
#include "../../../include/Engine/CPlayerControl.h"
#include "../../../include/Engine/Resource/CTranslation.h"
#include "../../../include/Engine/Gameplay/CDialogInterface.h"
#include "../../../include/Engine/Exception/CTextException.h"
#include "../../../include/Hud/CText.h"
#include "../../../include/Hud/CPicture.h"

namespace is06 { namespace NEngine { namespace NGameplay {

//! Constructor
/**
 * \section constr_usecase Constructor use case
 * \code
 * Dialog = new NEngine::CDialogInterface("MAP_ALPHA_ZONE.isd", SceneTranslations, Control);
 * \endcode
 */
CDialogInterface::CDialogInterface(const string& filePath, NResource::CTranslation* translation, CPlayerControl* control)
{
  Control = control;

  MessageDisplaying = false;
  MessageFinished = false;
  DialogFinished = false;

  if (!translation) {
    throw NException::CTextException("[E60] No local translation object for dialog interface");
  }

  CurrentTranslation = translation;
  CurrentMessageNumber = 0;
  CurrentMessageText = NULL;

  BackWindow = new NHud::CPicture(0, CGame::ScreenPos.Hud.Bottom + 68, 1280, 136, "resource/hud/window/dialog_back.png");

  string fullPath = "resource/text/";

  switch (CGame::getCurrentLocale()) {
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
  loadDialogData(fullPath);
}

//! Rendering function, must be called on every cycle
void CDialogInterface::render()
{
  // Background of dialog
  //BackWindow->render();

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
    if (MessageDisplaying && Control->commandEntered(NControl::ECI_DIALOG_ACTION, EET_ONCE)) {
      CurrentMessageText->skip();
      MessageDisplaying = false;
      MessageFinished = true;
    }

    // Go to next message (only if entirely displayed)
    if (MessageFinished && Control->commandEntered(NControl::ECI_DIALOG_ACTION, EET_ONCE)) {
      MessageFinished = false;
      MessageDisplaying = true;
      if (!DialogFinished) {
        nextMessage();
      }
    }
  }
}

//! Loads dialog data from an .isd file
void CDialogInterface::loadDialogData(const string& fullPath)
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

//! Starts a specific dialog in a scene
/**
 * \section start_usecase Start use case
 * \code
 * Dialog->start("norya_first_start");
 * \endcode
 */
void CDialogInterface::start(const string& dialogIdentifier)
{
  CurrentDialogIdentifier = dialogIdentifier;
  createMessage(dialogIdentifier, 0);
  MessageDisplaying = true;
}

//! Creates and displays a message from the dialog onto the screen
void CDialogInterface::createMessage(const string& dialogIdentifier, u16 messageNumber)
{
  CurrentMessageText = new NHud::CText(
    DialogList[dialogIdentifier].getMessage(messageNumber),
    -350,
    CGame::ScreenPos.Hud.Bottom + 100,
    NHud::EFS_STANDARD_48,
    25
  );
}

//! Go to the next message in this dialog
void CDialogInterface::nextMessage()
{
  delete CurrentMessageText;
  CurrentMessageNumber++;
  createMessage(CurrentDialogIdentifier, CurrentMessageNumber);
}

//! Go to a specific message in this dialog
void CDialogInterface::goToMessage(u32 number)
{
  delete CurrentMessageText;
  CurrentMessageNumber = number;
  createMessage(CurrentDialogIdentifier, CurrentMessageNumber);
}

//! Returns true if the current dialog is finished
bool CDialogInterface::finished()
{
  return false;
}

//! Destructor
CDialogInterface::~CDialogInterface()
{
  delete BackWindow;
}

}}}
