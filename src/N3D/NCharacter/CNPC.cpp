/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/core.h"
#include "../../../include/NEngine/NGameplay/CDialogInterface.h"
#include "../../../include/N3D/NCharacter/CCharacter.h"
#include "../../../include/N3D/NCharacter/CNPC.h"

namespace is06 { namespace N3D { namespace NCharacter {

//! Initializations
CNPC::CNPC() : CCharacter()
{
  NextDialogIdentifier = 0;
  CurrentTalkingDialogIdentifier = 0;
}

//! Changes the 3d model for this character
void CNPC::setCharacter(const string& characterId)
{
  CCharacter::setCharacterModel(characterId);
}

//! Rendering and events method
void CNPC::update()
{
  CCharacter::update();
}

//! Execute the talk action for this NPC
void CNPC::talk(const string& dialogIdentifier) const
{
  AttachedDialog->start(dialogIdentifier);
}

//! Attaches a dialog interface object to this NPC
void CNPC::attachDialogInterface(NEngine::NGameplay::CDialogInterface* dialog)
{
  AttachedDialog = dialog;
}

//! Get a random dialog identifier
/**
 * \todo manage avoidDoubles parameter
 * \param bool avoidDoubles
 * \return const string&
 */
const string& CNPC::getRandomTalkingDialogIdentifier(bool avoidDoubles)
{
  return DialogIdentifierList[CurrentTalkingDialogIdentifier];
}

//! Get the next dialog identifier
/**
 * \return const string&
 */
const string& CNPC::getNextTalkingDialogIdentifier()
{
  CurrentTalkingDialogIdentifier++;
  return DialogIdentifierList[CurrentTalkingDialogIdentifier];
}

//! Returns the distance between the NPC and an other character
/**
 * \todo write this function
 */
f32 CNPC::getDistanceFrom(CCharacter* character)
{
  return 0.0f;
}

//! Destructor
CNPC::~CNPC()
{

}

}}}
