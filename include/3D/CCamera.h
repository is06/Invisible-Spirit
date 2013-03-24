/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_CAMERA_H__
#define __IS06_CAMERA_H__

#include "CCharacter.h"
#include "../Engine/CEntity.h"

namespace is06
{
namespace N3D
{

//! Main abstract Camera class
class CCamera : public NEngine::CEntity
{
  public:
    CCamera();
    virtual ~CCamera();

    virtual void update() = 0;

    virtual void linkEntity(CCharacter* entityToLink) = 0;
    virtual f32 getDistance() = 0;

    void turnX(f32 speed);
    void turnY(f32 speed);
    void turnZ(f32 speed);
    void moveX(f32 speed);
    void moveY(f32 speed);
    void moveZ(f32 speed);
    f32 getX();
    f32 getY();
    f32 getZ();

    virtual void goLeft(f32 speed) = 0;
    virtual void goRight(f32 speed) = 0;
    virtual void goFar(f32 speed) = 0;
    virtual void goNear(f32 speed) = 0;

    void setPosition(const core::vector3df& pos);
    void setRotation(const core::vector3df& rot);
    scene::ICameraSceneNode* getNode();
    const core::vector3df& getLastPosition() const;

    void toggleControl();
    void setControl(bool val);
    bool hasControl();

  protected:
    scene::ICameraSceneNode* IrrCam;
    bool Controlable;
    core::vector3df LastPosition;
};

}
}

#endif
