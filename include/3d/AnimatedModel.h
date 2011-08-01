/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_ANIMATED_MODEL_H__
#define __IS06_ANIMATED_MODEL_H__

#include "ModelEntity.h"

using namespace irr;

class AnimatedModel : public ModelEntity {
  public:
    AnimatedModel();
    virtual ~AnimatedModel();

    virtual void render();

    void createNode(const core::vector3df& initPosition);

    // Détection de collisions
    bool collidesWithStatic(StaticModel* other);
    bool collidesWithAnimated(AnimatedModel* other);
    f32 getFloorCollision(StaticModel* other);
    f32 getWallCollision(RayType type, StaticModel* other, core::vector3df& normal);

  protected:
    f32 floorSensorWidth;
    f32 wallSensorWidth;
};

#endif
