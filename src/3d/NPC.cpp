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

/**
 * Initializations
 */
NPC::NPC(const string& meshFile, const string& animationFile) : Character(meshFile, animationFile)
{
  nextDialogIdentifier = 0;
  currentTalkingDialogIdentifier = 0;
}

/**
 * Rendering and events method
 */
void NPC::update()
{
  Character::update();
}

/**
 * Execute the talk action for this NPC
 */
void NPC::talk(const string& dialogIdentifier) const
{
  attachedDialog->start(dialogIdentifier);
}

/**
 * Attaches a dialog interface object to this NPC
 */
void NPC::attachDialogInterface(DialogInterface* dialog)
{
  attachedDialog = dialog;
}

/**
 * Get a random dialog identifier
 * @param bool avoidDoubles
 * @return const string&
 */
const string& NPC::getRandomTalkingDialogIdentifier(bool avoidDoubles)
{
  return dialogIdentifierList[currentTalkingDialogIdentifier];
}

/**
 * Get the next dialog identifier
 * @return const string&
 */
const string& NPC::getNextTalkingDialogIdentifier()
{
  currentTalkingDialogIdentifier++;
  return dialogIdentifierList[currentTalkingDialogIdentifier];
}

/**
 * Destructor
 */
NPC::~NPC()
{

}
