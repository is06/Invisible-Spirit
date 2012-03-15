/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_ANIMATED_MODEL_H__
#define __IS06_ANIMATED_MODEL_H__

#include "../enums/engine/RayType.h"
#include "../enums/engine/EventType.h"
#include "../enums/engine/CharacterAnimationIdentifier.h"
#include "ModelEntity.h"
#include "MeshAnimationInfo.h"
#include "BoxSensor.h"

using namespace irr;
using namespace std;

class AnimatedModel : public ModelEntity
{
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

    // Movements
    void turnX(f32 speed);
    void turnY(f32 speed);
    void turnZ(f32 speed);
    void moveX(f32 speed);
    void moveY(f32 speed);
    void moveZ(f32 speed);

    video::SMaterial& getMaterial();
    void createNode(const core::vector3df& initPosition);
    scene::IAnimatedMeshSceneNode* getNode();

    // Collision detection
    bool collidesWithStatic(StaticModel* other);
    bool collidesWithAnimated(AnimatedModel* other);
    bool collidesWithPlaneSensor(PlaneSensor* sensor, EventType type = EVENT_ALWAYS);
    bool isInBoxSensor(BoxSensor* sensor, EventType type = EVENT_ALWAYS);
    f32 getFloorCollision(StaticModel* other);
    f32 getWallCollision(RayType type, StaticModel* other, core::vector3df& normal);

    // Animations
    void loadAnimation(const string& fileName);
    void setCurrentAnimation(s32 id, f32 speed = 30.0f);
    void pauseAnimation();
    void playAnimation();
    void setAnimationSpeed(f32 value);
    bool currentAnimationFinished();
    bool animationFinished(s32 id);

    // Shadows
    void setShadowMode(ShadowMode mode = SHADOW_MODE_CAST);

  protected:
    f32 floorSensorWidth;
    f32 wallSensorWidth;

    scene::IAnimatedMeshSceneNode* mainNode;

  private:
    s32 currentAnimationId;
    f32 currentAnimationSpeed;
    map<s32, MeshAnimationInfo> animationList;
};

#endif
