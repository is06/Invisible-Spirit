/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_NPC_H__
#define __IS06_NPC_H__

#include "Character.h"
#include "../engine/DialogInterface.h"

using namespace std;

class NPC : public Character
{
  public:
    NPC(const string& meshFile, const string& animationFile);
    ~NPC();

    void render();
    void talk(const string& dialogIdentifier) const;
    void attachDialogInterface(DialogInterface* dialog);
    const string& getRandomTalkingDialogIdentifier(bool avoidDoubles = false);
    const string& getNextTalkingDialogIdentifier();

  protected:
    DialogInterface* attachedDialog;
    map<u16, string> dialogIdentifierList;
    u16 nextDialogIdentifier;
    u16 currentTalkingDialogIdentifier;
};

#endif
