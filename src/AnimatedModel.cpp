/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../include/core.h"

using namespace irr;
using namespace std;

/**
 * 3D Animated model constructor
 */
AnimatedModel::AnimatedModel() : ModelEntity() {

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
 * Cast a ray from the center of the model to the bottom of it in order to compute
 * collision with the floor. A value greater than 1.0f means that the model does not
 * collide with the floor. A value lower than 1.0f means we need to raise the model
 * @param StaticModel* other pointer to the static object which collides with the animated model
 * @return f32 collision depth with the floor (distance between the floor and the center of the model)
 */
f32 AnimatedModel::getFloorCollision(StaticModel* other) {
  f32 normals[3];
  s32 faceId;

  // origin: center of the model
  core::vector3df origin(
    mainNode->getPosition().X,
    mainNode->getPosition().Y,
    mainNode->getPosition().Z
  );
  // end: bottom of the model
  core::vector3df end(
    mainNode->getPosition().X,
    mainNode->getPosition().Y - 1.0f,
    mainNode->getPosition().Z
  );

  return NewtonCollisionRayCast(
    NewtonBodyGetCollision(other->getMainBody()),
    &origin.X,
    &end.X,
    normals,
    &faceId
  );
}

/**
 * Not documented yet, sorry :/
 */
f32 AnimatedModel::getWallCollisionP(
  StaticModel* other,
  core::vector3df& origin,
  core::vector3df& end,
  core::vector3df& normal
) {
  NewtonCollision* otherBodyCollision = NewtonBodyGetCollision(other->getMainBody());

  s32 faceId;

  f32 xPoint = mainNode->getPosition().X - 0.5f * cos(core::degToRad(mainNode->getRotation().Y));
  f32 zPoint = mainNode->getPosition().Z + 0.5f * sin(core::degToRad(mainNode->getRotation().Y));

  origin = core::vector3df(
    xPoint,
    mainNode->getPosition().Y,
    zPoint
  );

  xPoint = xPoint - 1.0f * cos(core::degToRad(mainNode->getRotation().Y) - (core::PI / 2));
  zPoint = zPoint + 1.0f * sin(core::degToRad(mainNode->getRotation().Y) - (core::PI / 2));

  end = core::vector3df(
    xPoint,
    mainNode->getPosition().Y,
    zPoint
  );

  f32 ray = NewtonCollisionRayCast(otherBodyCollision, &origin.X, &end.X, &normal.X, &faceId);

  return ray;
}

/**
 * Not documented yet, sorry :/
 */
f32 AnimatedModel::getWallCollisionQ(
  StaticModel* other,
  core::vector3df& origin,
  core::vector3df& end,
  core::vector3df& normal
) {

  NewtonCollision* otherBodyCollision = NewtonBodyGetCollision(other->getMainBody());

  s32 faceId;

  f32 xPoint = mainNode->getPosition().X - 0.5f * cos(core::degToRad(mainNode->getRotation().Y) + core::PI);
  f32 zPoint = mainNode->getPosition().Z + 0.5f * sin(core::degToRad(mainNode->getRotation().Y) + core::PI);

  origin = core::vector3df(
    xPoint,
    mainNode->getPosition().Y,
    zPoint
  );

  xPoint = xPoint - 1.0f * cos(core::degToRad(mainNode->getRotation().Y) - (core::PI / 2));
  zPoint = zPoint + 1.0f * sin(core::degToRad(mainNode->getRotation().Y) - (core::PI / 2));

  end = core::vector3df(
    xPoint,
    mainNode->getPosition().Y,
    zPoint
  );

  f32 ray = NewtonCollisionRayCast(otherBodyCollision, &origin.X, &end.X, &normal.X, &faceId);

  return ray;
}

/**
 * Under construction
 */
bool AnimatedModel::collidesWithAnimated(AnimatedModel* other) {
  return false;
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
