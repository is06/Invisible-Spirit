/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_ANIMATED_MODEL_H__
#define __IS06_ANIMATED_MODEL_H__

#include "ModelEntity.h"

#include "../enums/engine/RayType.h"
#include "MeshAnimationInfo.h"

using namespace irr;
using namespace std;

class AnimatedModel : public ModelEntity {
  public:
    AnimatedModel();
    virtual ~AnimatedModel();

    virtual void render();

    void setVisible(bool value);
    void hide();
    void show();
    void setGhost(bool value);
    void setWireFrame(bool value);
    void setDebugData(bool value);

    video::SMaterial& getMaterial();
    void createNode(const core::vector3df& initPosition);
    scene::IAnimatedMeshSceneNode* getNode();

    // Détection de collisions
    bool collidesWithStatic(StaticModel* other);
    bool collidesWithAnimated(AnimatedModel* other);
    f32 getFloorCollision(StaticModel* other);
    f32 getWallCollision(RayType type, StaticModel* other, core::vector3df& normal);

    // Animations
    void setCurrentAnimation(const core::stringc& name);
    void pauseAnimation();
    void playAnimation();
    void setAnimationSpeed(f32 value);
    bool animationFinished();

  protected:
    f32 floorSensorWidth;
    f32 wallSensorWidth;

    scene::IAnimatedMeshSceneNode* mainNode;

  private:
    core::stringc currentAnimationName;
    f32 currentAnimationSpeed;
    map<core::stringc, MeshAnimationInfo> animationList;
};

#endif
