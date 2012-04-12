/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_DIALOG_INTERFACE_H__
#define __IS06_DIALOG_INTERFACE_H__

#include "Dialog.h"

namespace is06
{
namespace engine
{

class CDialogInterface
{
  public:
    CDialogInterface(const std::string& filePath, engine::CTranslation* translation, engine::CKeyboard* keyboard);
    ~CDialogInterface();

    void render();
    void start(const std::string& dialogIdentifier);
    void skip();
    void quit();
    void nextMessage();
    void goToMessage(irr::u32 number);
    bool finished();

  private:
    void loadDialogData(const std::string& fullPath);
    void createMessage(const std::string& dialogIdentifier, irr::u16 messageNumber=0);

    bool MessageDisplaying;
    bool MessageFinished;
    bool DialogFinished;

    irr::u16 CurrentMessageNumber;
    std::string CurrentDialogIdentifier;
    std::map<std::string, engine::CDialog> DialogList;
    hud::CText* CurrentMessageText;
    hud::CPicture* BackWindow;
    engine::CTranslation* CurrentTranslation;
    engine::CKeyboard* Keyboard;
};

}
}

#endif
