/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_3D_CHARACTER_NPC_H__
#define __IS06_3D_CHARACTER_NPC_H__

#include "CCharacter.h"
#include "../../NEngine/NGameplay/CDialogInterface.h"

namespace is06 { namespace N3D { namespace NCharacter {

//! Non-Playable Characters entity base class
class CNPC : public CCharacter
{
public:
    CNPC();
    ~CNPC();

    void setCharacter(const string& characterId);
    void update();
    void talk(const string& dialogIdentifier) const;
    void attachDialogInterface(NEngine::NGameplay::CDialogInterface* dialog);
    const string& getRandomTalkingDialogIdentifier(bool avoidDoubles = false);
    const string& getNextTalkingDialogIdentifier();
    f32 getDistanceFrom(CCharacter* character);

protected:
    NEngine::NGameplay::CDialogInterface* AttachedDialog;
    map<u16, string> DialogIdentifierList;
    u16 NextDialogIdentifier;
    u16 CurrentTalkingDialogIdentifier;
};

}}}

#endif
