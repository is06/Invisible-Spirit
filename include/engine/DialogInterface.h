/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_DIALOG_INTERFACE_H__
#define __IS06_DIALOG_INTERFACE_H__

#include "../ref/core.h"

using namespace std;

class DialogInterface
{
  public:
    DialogInterface(const string& filePath, Translation* translation);
    ~DialogInterface();

    void render();
    void loadDialogData(const string& fullPath);
    void start(const string& dialogIdentifier);
    void createMessage(u32 number);
    void deleteCurrentMessage();
    void nextMessage();
    void goToMessage(u32 number);
    void getMessageNumber(const string& identifier);
    bool finished();
    const string& getIdentifier() const;

  private:
    string identifier;
    map<u32, string> messageList;
    u32 currentMessageNumber;
    Text* currentMessage;
    Translation* currentTranslation;
};

#endif