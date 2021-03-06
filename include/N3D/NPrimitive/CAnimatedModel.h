/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_3D_PRIMITIVE_ANIMATED_MODEL_H__
#define __IS06_3D_PRIMITIVE_ANIMATED_MODEL_H__

#include "../NCollision/ERayType.h"
#include "../NCharacter/ECharacterAnimationIdentifier.h"
#include "../../NEngine/NEvent/EEventType.h"
#include "CModelEntity.h"
#include "CStaticModel.h"
#include "SMeshAnimationInfo.h"

namespace is06 { namespace N3D { namespace NPrimitive {

//! 3D Animated model entity for characters, enemies and other mesh-animated stuff
class CAnimatedModel : public CModelEntity
{
public:
  CAnimatedModel();
  virtual ~CAnimatedModel();

  virtual void update();
  virtual void shaderRender();

  void createModel(const string& meshFile, const string& animationFile);
  void setVisible(bool value);
  void hide();
  void show();
  void setWireFrame(bool value);
  void setDebugData(bool value);
  void darken();
  void undarken();
  void lighten();
  void unlighten();
  void textureSwitch();

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
  bool collidesWithStatic(CStaticModel* other);
  bool collidesWithAnimated(CAnimatedModel* other);
  bool collidesWithSensor(NSensor::CBoxSensor* boxSensor, NEngine::NEvent::EEventType type);
  bool collidesWithSensor(NSensor::CPlaneSensor* planeSensor, NEngine::NEvent::EEventType type);
  f32 getFloorCollision(CStaticModel* other);
  f32 getWallCollision(NCollision::ERayType type, CStaticModel* other, core::vector3df& normal);

  // Animations
  void loadAnimation(const string& fileName);
  void setCurrentAnimation(s32 id, f32 speed = 30.0f);
  void pauseAnimation();
  void playAnimation();
  void setAnimationSpeed(f32 value);
  bool currentAnimationFinished();
  bool animationFinished(s32 id);

  // Shadows
  void setShadowMode(NShader::EShadowMode mode = NShader::ESM_CAST);

protected:
  f32 FloorSensorWidth;
  f32 WallSensorWidth;

  scene::IAnimatedMeshSceneNode* MainNode;

private:
  s32 CurrentAnimationId;
  f32 CurrentAnimationSpeed;
  map<s32, N3D::NPrimitive::SMeshAnimationInfo> AnimationList;
  map<N3D::NSensor::CSensor*, bool> SensorOnce;
};

}}}

#endif
