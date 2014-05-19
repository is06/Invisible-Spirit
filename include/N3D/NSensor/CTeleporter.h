/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_3D_SENSOR_TELEPORTER_H__
#define __IS06_3D_SENSOR_TELEPORTER_H__

#include "../../NScene/ESceneIdentifier.h"
#include "../NSensor/CBoxSensor.h"
#include "EPlaneType.h"

namespace is06 { namespace N3D { namespace NSensor {

//! A teleporter sensor
class CTeleporter : public CBoxSensor
{
public:
    CTeleporter(f32 width, f32 height, f32 depth, const core::vector3df& position, NScene::ESceneIdentifier destination);
    ~CTeleporter();

    void update();

    void setDestination(NScene::ESceneIdentifier id);

private:
    NScene::ESceneIdentifier Destination;
};

}}}

#endif
