/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/engine/DialogInterface.h"
#include "../../include/3d/Character.h"
#include "../../include/3d/NPC.h"

namespace is06
{
namespace model
{

/**
 * Initializations
 */
CNPC::CNPC(const std::string& meshFile, const std::string& animationFile) : CCharacter(meshFile, animationFile)
{
  NextDialogIdentifier = 0;
  CurrentTalkingDialogIdentifier = 0;
}

/**
 * Rendering and events method
 */
void CNPC::update()
{
  CCharacter::update();
}

/**
 * Execute the talk action for this NPC
 */
void CNPC::talk(const std::string& dialogIdentifier) const
{
  AttachedDialog->start(dialogIdentifier);
}

/**
 * Attaches a dialog interface object to this NPC
 */
void CNPC::attachDialogInterface(engine::CDialogInterface* dialog)
{
  AttachedDialog = dialog;
}

/**
 * Get a random dialog identifier
 * @param bool avoidDoubles
 * @return const std::string&
 */
const std::string& CNPC::getRandomTalkingDialogIdentifier(bool avoidDoubles)
{
  return DialogIdentifierList[CurrentTalkingDialogIdentifier];
}

/**
 * Get the next dialog identifier
 * @return const std::string&
 */
const std::string& CNPC::getNextTalkingDialogIdentifier()
{
  CurrentTalkingDialogIdentifier++;
  return DialogIdentifierList[CurrentTalkingDialogIdentifier];
}

/**
 * Destructor
 */
CNPC::~CNPC()
{

}

}
}
