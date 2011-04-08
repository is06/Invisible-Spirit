/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_CAMERA_H__
#define __IS06_CAMERA_H__

using namespace irr;

class Camera {
  public:
    Camera();

    virtual void render();

    virtual void linkEntity(Ayron* entityToLink) = 0;
    virtual f32 getDistance() = 0;

    virtual void goLeft(f32 speed) = 0;
    virtual void goRight(f32 speed) = 0;
    virtual void goFar(f32 speed) = 0;
    virtual void goNear(f32 speed) = 0;

    void setPosition(const core::vector3df& pos);
    void setRotation(const core::vector3df& rot);
    scene::ICameraSceneNode* getNode();

    void toggleControl();
    void setControl(bool val);
    bool hasControl();

  protected:
    scene::ICameraSceneNode* irrCam;
    bool controlable;
};

#endif
