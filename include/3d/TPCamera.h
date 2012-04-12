/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_TPCAMERA_H__
#define __IS06_TPCAMERA_H__

#include "../../include/3d/Camera.h"

namespace is06
{
namespace model
{

class CTPCamera : public CCamera
{
  public:
    CTPCamera();

    void update();

    void goLeft(irr::f32 speed);
    void goRight(irr::f32 speed);
    void goFar(irr::f32 speed);
    void goNear(irr::f32 speed);

    void linkEntity(CCharacter* entity);
    irr::f32 getDistance();

  private:
    CCharacter* LinkedEntity;
    irr::f32 UAxis;
    irr::f32 Height;
    irr::f32 Distance;
};

}
}

#endif
