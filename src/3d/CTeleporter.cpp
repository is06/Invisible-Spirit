/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/3d/CTeleporter.h"

using namespace irr;

namespace is06
{
namespace n3D
{

CTeleporter::CTeleporter(f32 width, f32 height, f32 depth, const core::vector3df& position, nScene::ESceneIdentifier destination)
: CSensor(width, height, depth, position)
{
  Destination = destination;
}

void CTeleporter::update()
{
  CSensor::update();
}

void CTeleporter::setDestination(nScene::ESceneIdentifier id)
{
  Destination = id;
}

CTeleporter::~CTeleporter()
{

}

}
}
