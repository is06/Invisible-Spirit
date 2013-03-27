/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/N3D/NSensor/CTeleporter.h"

using namespace irr;

namespace is06 { namespace N3D { namespace NSensor {

//! Constructor
CTeleporter::CTeleporter(f32 width, f32 height, f32 depth, const core::vector3df& position, NScene::ESceneIdentifier destination)
: CSensor(width, height, depth, position)
{
  Destination = destination;
}

//! Update function called every cycle for event testing
void CTeleporter::update()
{
  CSensor::update();
}

//! Changes the destination scene of the teleporter
void CTeleporter::setDestination(NScene::ESceneIdentifier id)
{
  Destination = id;
}

//! Destructor
CTeleporter::~CTeleporter()
{

}

}}}
