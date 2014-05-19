/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/N3D/NSensor/CSensor.h"

using namespace irr;

namespace is06 { namespace N3D { namespace NSensor {

//! Construcotr
CSensor::CSensor() : NEngine::NCore::CEntity()
{

}

//! Update method, called every cycle for event testing
void CSensor::update()
{
    CEntity::update();
}

//! Destructor
CSensor::~CSensor()
{

}

}}}
