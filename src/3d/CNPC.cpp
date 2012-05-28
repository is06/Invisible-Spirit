/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/core.h"
#include "../../include/engine/CDialogInterface.h"
#include "../../include/3d/CCharacter.h"
#include "../../include/3d/CNPC.h"

namespace is06
{
namespace n3D
{

//! Initializations
CNPC::CNPC(const string& meshFile, const string& animationFile) : CCharacter(meshFile, animationFile)
{
  NextDialogIdentifier = 0;
  CurrentTalkingDialogIdentifier = 0;
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
void CNPC::attachDialogInterface(nEngine::CDialogInterface* dialog)
{
  AttachedDialog = dialog;
}

//! Get a random dialog identifier
/**
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

//! Destructor
CNPC::~CNPC()
{

}

}
}
