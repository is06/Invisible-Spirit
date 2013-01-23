/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_TPCAMERA_H__
#define __IS06_TPCAMERA_H__

#include "../../include/model/CCamera.h"

namespace is06
{
namespace n3D
{

//! A Third-Person Camera class with control functions
class CTPCamera : public CCamera
{
  public:
    CTPCamera();

    void update();

    void goLeft(f32 speed);
    void goRight(f32 speed);
    void goFar(f32 speed);
    void goNear(f32 speed);

    void linkEntity(CCharacter* entity);
    f32 getDistance();

  private:
    CCharacter* LinkedEntity;
    f32 UAxis;
    f32 Height;
    f32 Distance;
};

}
}

#endif
