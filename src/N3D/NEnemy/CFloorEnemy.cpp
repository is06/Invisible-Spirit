/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/core.h"
#include "../../../include/N3D/NEnemy/CEnemy.h"
#include "../../../include/N3D/NEnemy/CFloorEnemy.h"

namespace is06 { namespace N3D { namespace NEnemy {

//! Constructor
CFloorEnemy::CFloorEnemy() : CEnemy()
{

}

//! Update function called every cycle for event testing
void CFloorEnemy::update()
{
  CEnemy::update();
}

//! Destructor
CFloorEnemy::~CFloorEnemy()
{

}

}}}
