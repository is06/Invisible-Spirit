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
  currentTranslation = translation;
  currentMessage = NULL;

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
  if (currentMessage) {
    currentMessage->render();
  }
}

/**
 * @todo
 */
void DialogInterface::loadDialogData(const string& fullPath)
{

}

/**
 *
 */
void DialogInterface::start(const string& dialogIdentifier)
{
  identifier = dialogIdentifier;
  currentMessageNumber = 0;
  createMessage(currentMessageNumber);
}

/**
 *
 */
void DialogInterface::createMessage(u32 number)
{
  //cout << "Try to create dialog message '" << messageList[number] << "'" << endl;
  //currentMessage = new Text(currentTranslation->getTranslation(messageList[number]));
}

/**
 *
 */
void DialogInterface::deleteCurrentMessage()
{
  if (currentMessage) {
    delete currentMessage;
  }
}

/**
 *
 */
void DialogInterface::nextMessage()
{
  currentMessageNumber++;
  deleteCurrentMessage();
  createMessage(currentMessageNumber);
}

/**
 *
 */
void DialogInterface::goToMessage(u32 number)
{
  currentMessageNumber = number;
  deleteCurrentMessage();
  createMessage(currentMessageNumber);
}

/**
 * @todo
 */
void DialogInterface::getMessageNumber(const string& identifier)
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
const string& DialogInterface::getIdentifier() const
{
  return identifier;
}

/**
 *
 */
DialogInterface::~DialogInterface()
{
  if (currentMessage) {
    delete currentMessage;
  }
}
