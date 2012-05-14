/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/core.h"
#include "../../include/3d/CLevelMesh.h"
#include "../../include/3d/CStaticModel.h"

namespace is06
{
namespace n3D
{

CLevelMesh::CLevelMesh() : CStaticModel()
{

}

void CLevelMesh::update()
{
  CStaticModel::update();
}

void CLevelMesh::loadCollisionMask()
{

}

CLevelMesh::~CLevelMesh()
{

}

}
}
