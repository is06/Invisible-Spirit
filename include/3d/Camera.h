/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_CAMERA_H__
#define __IS06_CAMERA_H__

#include "../../include/3d/Character.h"
#include "../../include/Entity.h"

namespace is06
{
namespace model
{

class CCamera : public engine::CEntity
{
  public:
    CCamera();

    virtual void update() = 0;

    virtual void linkEntity(CCharacter* entityToLink) = 0;
    virtual irr::f32 getDistance() = 0;

    void turnX(irr::f32 speed);
    void turnY(irr::f32 speed);
    void turnZ(irr::f32 speed);
    void moveX(irr::f32 speed);
    void moveY(irr::f32 speed);
    void moveZ(irr::f32 speed);
    irr::f32 getX();
    irr::f32 getY();
    irr::f32 getZ();

    virtual void goLeft(irr::f32 speed) = 0;
    virtual void goRight(irr::f32 speed) = 0;
    virtual void goFar(irr::f32 speed) = 0;
    virtual void goNear(irr::f32 speed) = 0;

    void setPosition(const irr::core::vector3df& pos);
    void setRotation(const irr::core::vector3df& rot);
    irr::scene::ICameraSceneNode* getNode();
    const irr::core::vector3df& getLastPosition() const;

    void toggleControl();
    void setControl(bool val);
    bool hasControl();

  protected:
    irr::scene::ICameraSceneNode* IrrCam;
    bool Controlable;
    irr::core::vector3df LastPosition;
};

}
}

#endif
