/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/Engine/core.h"
#include "../../include/3D/CMapPart.h"
#include "../../include/3D/CStaticModel.h"

namespace is06 { namespace N3D { namespace NPart {

//! Constructor
CMapPart::CMapPart() : CStaticModel()
{

}

//! Update method, called every cycle for event testing
void CMapPart::update()
{
  CStaticModel::update();
}

//! Loads the collision mask for this model from a dedicate file (newton serialization)
void CMapPart::loadCollisionMask()
{

}

//! Destructor
CMapPart::~CMapPart()
{

}

}}}
