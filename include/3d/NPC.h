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

namespace is06
{
namespace n3D
{

//! Non-Playable Characters entity base class
class CNPC : public CCharacter
{
  public:
    CNPC(const string& meshFile, const string& animationFile);
    ~CNPC();

    void update();
    void talk(const string& dialogIdentifier) const;
    void attachDialogInterface(nEngine::CDialogInterface* dialog);
    const string& getRandomTalkingDialogIdentifier(bool avoidDoubles = false);
    const string& getNextTalkingDialogIdentifier();

  protected:
    nEngine::CDialogInterface* AttachedDialog;
    map<u16, string> DialogIdentifierList;
    u16 NextDialogIdentifier;
    u16 CurrentTalkingDialogIdentifier;
};

}
}

#endif
