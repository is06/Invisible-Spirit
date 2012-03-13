/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/Game.h"
#include "../../include/engine/Dialog.h"

using namespace std;

/**
 *
 */
Dialog::Dialog(const string& filePath)
{
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
void Dialog::render()
{

}

/**
 * @todo
 */
void Dialog::loadDialogData(const string& fullPath)
{

}

/**
 *
 */
void Dialog::start(const string& dialogIdentifier)
{

}

/**
 *
 */
bool Dialog::finished()
{
  return false;
}

/**
 *
 */
Dialog::~Dialog()
{

}
