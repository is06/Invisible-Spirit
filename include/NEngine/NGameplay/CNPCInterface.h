/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_ENGINE_GAMEPLAY_NPC_INTERFACE_H__
#define __IS06_ENGINE_GAMEPLAY_NPC_INTERFACE_H__

#include "../../3D/Character/CNPC.h"

namespace is06 { namespace NEngine { namespace NGameplay {

class CNPCInterface
{
public:
  CNPCInterface();
  ~CNPCInterface();

  void addNPC(N3D::NCharacter::CNPC* npc);
  N3D::NCharacter::CNPC* getNearestNPC(N3D::CCharacter* character);

private:
  vector<N3D::NCharacter::CNPC*> NPCList;
};

}}}

#endif
