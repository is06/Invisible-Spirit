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
namespace model
{

class CNPC : public CCharacter
{
  public:
    CNPC(const std::string& meshFile, const std::string& animationFile);
    ~CNPC();

    void update();
    void talk(const std::string& dialogIdentifier) const;
    void attachDialogInterface(engine::CDialogInterface* dialog);
    const std::string& getRandomTalkingDialogIdentifier(bool avoidDoubles = false);
    const std::string& getNextTalkingDialogIdentifier();

  protected:
    engine::CDialogInterface* AttachedDialog;
    std::map<irr::u16, std::string> DialogIdentifierList;
    irr::u16 NextDialogIdentifier;
    irr::u16 CurrentTalkingDialogIdentifier;
};

}
}

#endif
