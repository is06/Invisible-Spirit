/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_DIALOG_INTERFACE_H__
#define __IS06_DIALOG_INTERFACE_H__

#include "Dialog.h"

using namespace std;

class DialogInterface
{
  public:
    DialogInterface(const string& filePath, Translation* translation);
    ~DialogInterface();

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

    u16 currentMessageNumber;
    map<string, Dialog> dialogList;
    Text* currentMessageText;
    Translation* currentTranslation;
};

#endif
