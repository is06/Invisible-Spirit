/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_ENGINE_GAMEPLAY_DIALOG_INTERFACE_H__
#define __IS06_ENGINE_GAMEPLAY_DIALOG_INTERFACE_H__

#include "CDialog.h"

using namespace irr;
using namespace std;

namespace is06 { namespace NEngine { namespace NGameplay {

//! Interface for dialogs that can be used in scenes and maps
class CDialogInterface
{
public:
  CDialogInterface(const string& filePath, NEngine::NResource::CTranslation* translation, NEngine::CPlayerControl* control);
  ~CDialogInterface();

  void render();
  void start(const string& dialogIdentifier);
  void skip();
  void quit();
  void nextMessage();
  void goToMessage(u32 number);
  bool finished();

private:
  void loadDialogData(const string& fullPath);
  void createMessage(const string& dialogIdentifier, u16 messageNumber=0);

  bool MessageDisplaying;
  bool MessageFinished;
  bool DialogFinished;

  u16 CurrentMessageNumber;
  string CurrentDialogIdentifier;
  NHud::CText* CurrentMessageText;
  NHud::CPicture* BackWindow;
  NEngine::NGameplay::TDialogMap DialogList;
  NEngine::NResource::CTranslation* CurrentTranslation;
  NEngine::CPlayerControl* Control;
};

}}}

#endif
