/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/Engine/core.h"
#include "../../include/3D/CLevelMesh.h"
#include "../../include/3D/CStaticModel.h"

namespace is06
{
namespace N3D
{

//! Constructor
CLevelMesh::CLevelMesh() : CStaticModel()
{

}

//! Update method, called every cycle for event testing
void CLevelMesh::update()
{
  CStaticModel::update();
}

//! Loads the collision mask for this model from a dedicate file (newton serialization)
void CLevelMesh::loadCollisionMask()
{

}

//! Destructor
CLevelMesh::~CLevelMesh()
{

}

}
}
