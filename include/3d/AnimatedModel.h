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

namespace is06
{
namespace model
{

class CAnimatedModel : public CModelEntity
{
  public:
    CAnimatedModel();
    CAnimatedModel(const std::string& meshFile, const std::string& animationFile);
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
    void turnX(irr::f32 speed);
    void turnY(irr::f32 speed);
    void turnZ(irr::f32 speed);
    void moveX(irr::f32 speed);
    void moveY(irr::f32 speed);
    void moveZ(irr::f32 speed);

    irr::video::SMaterial& getMaterial();
    void createNode(const irr::core::vector3df& initPosition);
    irr::scene::IAnimatedMeshSceneNode* getNode();

    // Collision detection
    bool collidesWithStatic(model::CStaticModel* other);
    bool collidesWithAnimated(model::CAnimatedModel* other);
    bool collidesWithPlaneSensor(model::CPlaneSensor* sensor, engine::EEventType type = engine::EVENT_ALWAYS);
    bool isInBoxSensor(model::CBoxSensor* sensor, engine::EEventType type = engine::EVENT_ALWAYS);
    irr::f32 getFloorCollision(model::CStaticModel* other);
    irr::f32 getWallCollision(engine::ERayType type, model::CStaticModel* other, irr::core::vector3df& normal);

    // Animations
    void loadAnimation(const std::string& fileName);
    void setCurrentAnimation(irr::s32 id, irr::f32 speed = 30.0f);
    void pauseAnimation();
    void playAnimation();
    void setAnimationSpeed(irr::f32 value);
    bool currentAnimationFinished();
    bool animationFinished(irr::s32 id);

    // Shadows
    void setShadowMode(engine::EShadowMode mode = engine::SHADOW_MODE_CAST);

  protected:
    irr::f32 FloorSensorWidth;
    irr::f32 WallSensorWidth;

    irr::scene::IAnimatedMeshSceneNode* MainNode;

  private:
    irr::s32 CurrentAnimationId;
    irr::f32 CurrentAnimationSpeed;
    std::map<irr::s32, model::SMeshAnimationInfo> AnimationList;
    std::map<model::CSensor*, bool> SensorOnce;
};

}
}

#endif
