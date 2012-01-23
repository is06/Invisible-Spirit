/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/Game.h"
#include "../../include/3d/AnimatedModel.h"
#include "../../include/3d/StaticModel.h"

using namespace irr;
using namespace std;

/**
 * 3D Animated model constructor
 */
AnimatedModel::AnimatedModel() : ModelEntity() {
  mainNode = NULL;
}

/**
 * Update and render function of 3D animated models
 */
void AnimatedModel::render() { ModelEntity::render();

}

/**
 * Creates the animated node and add it to Irrlicht's scene manager
 * @param vector3df& initPosition reference to the node initial position
 */
void AnimatedModel::createNode(const core::vector3df& initPosition) {
  mainNode = Game::getSceneManager()->addAnimatedMeshSceneNode((scene::IAnimatedMesh*)mainMesh);
  mainNode->setMaterialFlag(video::EMF_LIGHTING, false);
  mainNode->setPosition(initPosition);
}

/**
 * Returns the Irrlicht node
 * @return IAnimatedMeshSceneNode* entity's node
 */
scene::IAnimatedMeshSceneNode* AnimatedModel::getNode() {
  return mainNode;
}

/**
 * Returns Irrlicht material
 */
video::SMaterial& AnimatedModel::getMaterial() {
  return mainNode->getMaterial(0);
}

/**
 * Hides the object
 */
void AnimatedModel::hide() {
  mainNode->setVisible(false);
}

/**
 * Shows the object
 */
void AnimatedModel::show() {
  mainNode->setVisible(true);
}

/**
 * Sets the visibility of the object and disables collisions
 */
void AnimatedModel::setVisible(bool value) {
  mainNode->setVisible(value);
}

/**
 * Makes the object ghost so it will be invisible and will react to collisions
 */
void AnimatedModel::setGhost(bool value) {
  mainNode->setMaterialFlag(video::EMF_FRONT_FACE_CULLING, !value);
}

/**
 *
 */
void AnimatedModel::setWireFrame(bool value) {
  mainNode->setMaterialFlag(video::EMF_WIREFRAME, value);
}

/**
 *
 */
void AnimatedModel::setDebugData(bool value) {
  mainNode->setDebugDataVisible(value);
}

/**
 * Returns true if the animated model collides with a static model defined by other
 * @param StaticModel* other pointer to the static object which collides with the animated model
 * @return bool true if collision
 */
bool AnimatedModel::collidesWithStatic(StaticModel* other) {
  NewtonBody* otherBody = other->getMainBody();

  f32 mainBodyMatrix[16] = {};
  f32 otherBodyMatrix[16] = {};

  NewtonBodyGetMatrix(mainBody, mainBodyMatrix);
  NewtonBodyGetMatrix(otherBody, otherBodyMatrix);

  f32 contacts[3];
  f32 normals[3];
  f32 penetration[3];

  s32 res = NewtonCollisionCollide(
    Game::getNewtonWorld(),
    64,
    NewtonBodyGetCollision(mainBody),
    mainBodyMatrix,
    NewtonBodyGetCollision(otherBody),
    otherBodyMatrix,
    contacts,
    normals,
    penetration,
    0
  );

  return (res > 0);
}

/**
 * Casts 4 rays from the center of the chacter to the bottom and returns the minimum value of
 * floor collision
 * @return f32 (collision between 0.0f and 1.0f)
 */
f32 AnimatedModel::getFloorCollision(StaticModel* other) {
  f32 normals[3];
  f32 xPoint, zPoint;
  s32 faceId;

  //   B
  // C-+-A
  //   D
  f32 rayA, rayB, rayC, rayD;

  // A
  xPoint = mainNode->getPosition().X - floorSensorWidth * cos(core::degToRad(mainNode->getRotation().Y));
  zPoint = mainNode->getPosition().Z + floorSensorWidth * sin(core::degToRad(mainNode->getRotation().Y));
  core::vector3df origin(xPoint, mainNode->getPosition().Y, zPoint);
  core::vector3df end(xPoint, mainNode->getPosition().Y - 1.0f, zPoint);
  rayA = NewtonCollisionRayCast(NewtonBodyGetCollision(other->getMainBody()), &origin.X, &end.X, normals, &faceId);
  //_draw_line(origin, end);

  // B
  xPoint = mainNode->getPosition().X - floorSensorWidth * cos(core::degToRad(mainNode->getRotation().Y) - (core::PI / 2));
  zPoint = mainNode->getPosition().Z + floorSensorWidth * sin(core::degToRad(mainNode->getRotation().Y) - (core::PI / 2));
  origin = core::vector3df(xPoint, mainNode->getPosition().Y, zPoint);
  end = core::vector3df(xPoint, mainNode->getPosition().Y - 1.0f, zPoint);
  rayB = NewtonCollisionRayCast(NewtonBodyGetCollision(other->getMainBody()), &origin.X, &end.X, normals, &faceId);
  //_draw_line(origin, end);

  // C
  xPoint = mainNode->getPosition().X - floorSensorWidth * cos(core::degToRad(mainNode->getRotation().Y) + (core::PI));
  zPoint = mainNode->getPosition().Z + floorSensorWidth * sin(core::degToRad(mainNode->getRotation().Y) + (core::PI));
  origin = core::vector3df(xPoint, mainNode->getPosition().Y, zPoint);
  end = core::vector3df(xPoint, mainNode->getPosition().Y - 1.0f, zPoint);
  rayC = NewtonCollisionRayCast(NewtonBodyGetCollision(other->getMainBody()), &origin.X, &end.X, normals, &faceId);
  //_draw_line(origin, end);

  // D
  xPoint = mainNode->getPosition().X - floorSensorWidth * cos(core::degToRad(mainNode->getRotation().Y) + (core::PI / 2));
  zPoint = mainNode->getPosition().Z + floorSensorWidth * sin(core::degToRad(mainNode->getRotation().Y) + (core::PI / 2));
  origin = core::vector3df(xPoint, mainNode->getPosition().Y, zPoint);
  end = core::vector3df(xPoint, mainNode->getPosition().Y - 1.0f, zPoint);
  rayD = NewtonCollisionRayCast(NewtonBodyGetCollision(other->getMainBody()), &origin.X, &end.X, normals, &faceId);
  //_draw_line(origin, end);

  f32 minAB = core::min_(rayA, rayB);
  f32 minCD = core::min_(rayC, rayD);

  return core::min_(minAB, minCD);
}

/**
 * Not documented yet, sorry :/
 */
f32 AnimatedModel::getWallCollision(RayType type, StaticModel* other, core::vector3df& normal) {
  NewtonCollision* otherBodyCollision = NewtonBodyGetCollision(other->getMainBody());

  s32 faceId;
  f32 xPoint;
  f32 zPoint;

  // xPoint and zPoint are destination points of the ray
  if(type == RAY_WALL_P) {
    // P Ray (left)
    // xPoint = (MainNode X Position - 0.5) * cos(MainNode Y Rotation)
    // zPoint = (MainNode Z Position + 0.5) * sin(MainNode Y Rotation)
    xPoint = mainNode->getPosition().X - 0.5f * cos(core::degToRad(mainNode->getRotation().Y));
    zPoint = mainNode->getPosition().Z + 0.5f * sin(core::degToRad(mainNode->getRotation().Y));
  } else {
    // Q Ray (right)
    xPoint = mainNode->getPosition().X - 0.5f * cos(core::degToRad(mainNode->getRotation().Y) + core::PI);
    zPoint = mainNode->getPosition().Z + 0.5f * sin(core::degToRad(mainNode->getRotation().Y) + core::PI);
  }

  core::vector3df origin = core::vector3df(
    xPoint,
    mainNode->getPosition().Y,
    zPoint
  );

  xPoint = xPoint - 1.0f * cos(core::degToRad(mainNode->getRotation().Y) - (core::PI / 2));
  zPoint = zPoint + 1.0f * sin(core::degToRad(mainNode->getRotation().Y) - (core::PI / 2));

  core::vector3df end = core::vector3df(
    xPoint,
    mainNode->getPosition().Y,
    zPoint
  );

  return NewtonCollisionRayCast(otherBodyCollision, &origin.X, &end.X, &normal.X, &faceId);
}

/**
 * @todo Under construction
 */
bool AnimatedModel::collidesWithAnimated(AnimatedModel* other) {
  return false;
}

/**
 * @todo Under construction
 * @todo manage event type
 */
bool AnimatedModel::collidesWithPlaneSensor(PlaneSensor* sensor, EventType type) {
  return false;
}

/**
 * Returns true if the object is in the box sensor
 * @todo manage event type
 */
bool AnimatedModel::isInBoxSensor(BoxSensor* sensor, EventType type) {
  return sensor->getBox().isPointInside(mainNode->getPosition());
}

/**
 * Sets the current animation
 */
void AnimatedModel::setCurrentAnimation(CharacterAnimationIdentifier id, f32 speed) {
  currentAnimationId = id;
  currentAnimationSpeed = speed;

  MeshAnimationInfo anim = animationList[id];

  u32 startFrame = anim.startFrame;
  u32 endFrame = anim.endFrame;

  mainNode->setCurrentFrame(startFrame);
  mainNode->setFrameLoop(startFrame, endFrame);
  mainNode->setLoopMode(anim.looped);

  playAnimation();
}

/**
 * Pauses the current animation (speed = 0.0f)
 */
void AnimatedModel::pauseAnimation() {
  mainNode->setAnimationSpeed(0.0f);
}

/**
 * Plays the current animation at current speed
 */
void AnimatedModel::playAnimation() {
  mainNode->setAnimationSpeed(currentAnimationSpeed);
}

/**
 * Sets the current animation speed
 */
void AnimatedModel::setAnimationSpeed(f32 value) {
  mainNode->setAnimationSpeed(value);
}

/**
 * Returns true if the current animation is finished
 */
bool AnimatedModel::currentAnimationFinished() {
  return animationFinished(currentAnimationId);
}

/**
 * Returns true if a specific animation is finished
 */
bool AnimatedModel::animationFinished(CharacterAnimationIdentifier id) {
  return (mainNode->getFrameNr() == animationList[id].endFrame);
}

/**
 * Destructor, removes the main node
 */
AnimatedModel::~AnimatedModel() {
  if(mainNode) {
    mainNode->remove();
    mainNode = NULL;
  }
}
