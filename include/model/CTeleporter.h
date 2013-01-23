/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_TELEPORTER_H__
#define __IS06_TELEPORTER_H__

#include "../scene/ESceneIdentifier.h"
#include "EPlaneSensorType.h"
#include "CSensor.h"

namespace is06
{
namespace n3D
{

class CTeleporter : public CSensor
{
  public:
    CTeleporter(f32 width, f32 height, f32 depth, const core::vector3df& position, nScene::ESceneIdentifier destination);
    ~CTeleporter();

    void update();

    void setDestination(nScene::ESceneIdentifier id);

  private:
    nScene::ESceneIdentifier Destination;
};

}
}

#endif
