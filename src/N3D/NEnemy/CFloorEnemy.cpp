/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/core.h"
#include "../../../include/3D/CEnemy.h"
#include "../../../include/3D/Enemy/CFloor.h"

namespace is06
{
namespace N3D
{
namespace NEnemy
{

//! Constructor
CFloor::CFloor() : CEnemy()
{

}

//! Update function called every cycle for event testing
void CFloor::update()
{
  CEnemy::update();
}

//! Destructor
CFloor::~CFloor()
{

}

}
}
}
