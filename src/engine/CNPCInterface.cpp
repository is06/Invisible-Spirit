/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/CNPCInterface.h"

namespace is06
{
namespace nEngine
{

CNPCInterface::CNPCInterface()
{

}

//! TODO
void CNPCInterface::addNPC(n3D::CNPC* npc)
{
  NPCList.push_back(npc);
}

//! TODO
n3D::CNPC* CNPCInterface::getNearestNPC(n3D::CCharacter* character)
{
  // Parcours du vector et calcul de la distance avec le personnage passé en paramètre
  return NULL;
}

CNPCInterface::~CNPCInterface()
{

}

}
}
