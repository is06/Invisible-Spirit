/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_ANIMATED_MODEL_H__
#define __IS06_ANIMATED_MODEL_H__

#include "../engine/ERayType.h"
#include "../engine/EEventType.h"
#include "../engine/ECharacterAnimationIdentifier.h"
#include "CModelEntity.h"
#include "SMeshAnimationInfo.h"
#include "CBoxSensor.h"

namespace is06
{
namespace n3D
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
    bool collidesWithStatic(n3D::CStaticModel* other);
    bool collidesWithAnimated(n3D::CAnimatedModel* other);
    bool collidesWithPlaneSensor(n3D::CPlaneSensor* sensor, nEngine::EEventType type = nEngine::EET_ALWAYS);
    bool isInBoxSensor(n3D::CBoxSensor* sensor, nEngine::EEventType type = nEngine::EET_ALWAYS);
    f32 getFloorCollision(n3D::CStaticModel* other);
    f32 getWallCollision(nEngine::ERayType type, n3D::CStaticModel* other, core::vector3df& normal);

    // Animations
    void loadAnimation(const string& fileName);
    void setCurrentAnimation(s32 id, f32 speed = 30.0f);
    void pauseAnimation();
    void playAnimation();
    void setAnimationSpeed(f32 value);
    bool currentAnimationFinished();
    bool animationFinished(s32 id);

    // Shadows
    void setShadowMode(nEngine::EShadowMode mode = nEngine::ESM_CAST);

  protected:
    f32 FloorSensorWidth;
    f32 WallSensorWidth;

    scene::IAnimatedMeshSceneNode* MainNode;

  private:
    s32 CurrentAnimationId;
    f32 CurrentAnimationSpeed;
    map<s32, n3D::SMeshAnimationInfo> AnimationList;
    map<n3D::CSensor*, bool> SensorOnce;
};

}
}

#endif
