/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_ANIMATED_MODEL_H__
#define __IS06_ANIMATED_MODEL_H__

#include "../engine/RayType.h"
#include "../engine/EventType.h"
#include "../engine/CharacterAnimationIdentifier.h"
#include "ModelEntity.h"
#include "MeshAnimationInfo.h"
#include "BoxSensor.h"

namespace is06
{
namespace model
{

//! 3D Animated model entity for characters, enemies and other mesh-animated stuff
class CAnimatedModel : public CModelEntity
{
  public:
    CAnimatedModel();
    CAnimatedModel(const string& meshFile, const string& animationFile);
    virtual ~CAnimatedModel();

    virtual void update();
    virtual void shaderRender();

    void setVisible(bool value);
    void hide();
    void show();
    void setGhost(bool value);
    void setWireFrame(bool value);
    void setDebugData(bool value);
    void darken();
    void undarken();

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
    bool collidesWithStatic(model::CStaticModel* other);
    bool collidesWithAnimated(model::CAnimatedModel* other);
    bool collidesWithPlaneSensor(model::CPlaneSensor* sensor, engine::EEventType type = engine::EVENT_ALWAYS);
    bool isInBoxSensor(model::CBoxSensor* sensor, engine::EEventType type = engine::EVENT_ALWAYS);
    f32 getFloorCollision(model::CStaticModel* other);
    f32 getWallCollision(engine::ERayType type, model::CStaticModel* other, core::vector3df& normal);

    // Animations
    void loadAnimation(const string& fileName);
    void setCurrentAnimation(s32 id, f32 speed = 30.0f);
    void pauseAnimation();
    void playAnimation();
    void setAnimationSpeed(f32 value);
    bool currentAnimationFinished();
    bool animationFinished(s32 id);

    // Shadows
    void setShadowMode(engine::EShadowMode mode = engine::SHADOW_MODE_CAST);

  protected:
    f32 FloorSensorWidth;
    f32 WallSensorWidth;

    scene::IAnimatedMeshSceneNode* MainNode;

  private:
    s32 CurrentAnimationId;
    f32 CurrentAnimationSpeed;
    map<s32, model::SMeshAnimationInfo> AnimationList;
    map<model::CSensor*, bool> SensorOnce;
};

}
}

#endif
