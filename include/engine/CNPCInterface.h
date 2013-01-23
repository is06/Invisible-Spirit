/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_NPC_INTERFACE_H__
#define __IS06_NPC_INTERFACE_H__

#include "../model/CNPC.h"

namespace is06
{
namespace nEngine
{

class CNPCInterface
{
  public:
    CNPCInterface();
    ~CNPCInterface();

    void addNPC(n3D::CNPC* npc);
    n3D::CNPC* getNearestNPC(n3D::CCharacter* character);

  private:
    vector<n3D::CNPC*> NPCList;
};

}
}

#endif
