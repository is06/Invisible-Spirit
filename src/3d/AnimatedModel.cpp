/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/Game.h"
#include "../../include/scene/Scene.h"
#include "../../include/sound/Speaker.h"
#include "../../include/3d/AnimatedModel.h"
#include "../../include/3d/StaticModel.h"

namespace is06
{
namespace model
{

/**
 * Default animated model
 */
CAnimatedModel::CAnimatedModel() : CModelEntity()
{
  CAnimatedModel("resource/mesh/character/cube.obj", "resource/mesh/character/cube.isa");
}

/**
 * 3D Animated model constructor
 */
CAnimatedModel::CAnimatedModel(const std::string& meshFile, const std::string& animationFile) : CModelEntity()
{
  loadMesh(meshFile);
  loadAnimation(animationFile);

  MainNode = NULL;
}

/**
 * Update function of 3D animated models
 */
void CAnimatedModel::update()
{
  CModelEntity::update();

  // Attached speaker position update
  if (AttachedSpeaker) {
    AttachedSpeaker->setPosition(MainNode->getPosition());
  }
}

/**
 *
 */
void CAnimatedModel::shaderRender()
{
  MainNode->render();
}

/**
 * Turns the model relative to the X axe
 */
void CAnimatedModel::turnX(irr::f32 speed)
{
  MainNode->setRotation(irr::core::vector3df(
    MainNode->getRotation().X + (speed * engine::CGame::getSpeedFactor()),
    MainNode->getRotation().Y,
    MainNode->getRotation().Z
  ));
}

/**
 * Turns the model relative to the Y axe
 */
void CAnimatedModel::turnY(irr::f32 speed)
{
  MainNode->setRotation(irr::core::vector3df(
    MainNode->getRotation().X,
    MainNode->getRotation().Y + (speed * engine::CGame::getSpeedFactor()),
    MainNode->getRotation().Z
  ));
}

/**
 * Turns the model relative to the Z axe
 */
void CAnimatedModel::turnZ(irr::f32 speed)
{
  MainNode->setRotation(irr::core::vector3df(
    MainNode->getRotation().X,
    MainNode->getRotation().Y,
    MainNode->getRotation().Z + (speed * engine::CGame::getSpeedFactor())
  ));
}

/**
 * Move the model relative to the X axe
 */
void CAnimatedModel::moveX(irr::f32 speed)
{
  MainNode->setPosition(irr::core::vector3df(
    MainNode->getPosition().X + (speed * engine::CGame::getSpeedFactor()),
    MainNode->getPosition().Y,
    MainNode->getPosition().Z
  ));
}

/**
 * Move the model relative to the Y axe
 */
void CAnimatedModel::moveY(irr::f32 speed)
{
  MainNode->setPosition(irr::core::vector3df(
    MainNode->getPosition().X,
    MainNode->getPosition().Y + (speed * engine::CGame::getSpeedFactor()),
    MainNode->getPosition().Z
  ));
}

/**
 * Move the model relative to the Z axe
 */
void CAnimatedModel::moveZ(irr::f32 speed)
{
  MainNode->setPosition(irr::core::vector3df(
    MainNode->getPosition().X,
    MainNode->getPosition().Y,
    MainNode->getPosition().Z + (speed * engine::CGame::getSpeedFactor())
  ));
}

/**
 * Creates the animated node and add it to Irrlicht's scene manager
 * @param vector3df& initPosition reference to the node initial position
 */
void CAnimatedModel::createNode(const irr::core::vector3df& initPosition)
{
  MainNode = engine::CGame::getSceneManager()->addAnimatedMeshSceneNode((irr::scene::IAnimatedMesh*)MainMesh);
  MainNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  MainNode->setPosition(initPosition);
}

/**
 * Returns the Irrlicht node
 * @return IAnimatedMeshSceneNode* entity's node
 */
irr::scene::IAnimatedMeshSceneNode* CAnimatedModel::getNode()
{
  return MainNode;
}

/**
 * Returns Irrlicht material
 */
irr::video::SMaterial& CAnimatedModel::getMaterial()
{
  return MainNode->getMaterial(0);
}

/**
 * Hides the object
 */
void CAnimatedModel::hide()
{
  MainNode->setVisible(false);
}

/**
 * Shows the object
 */
void CAnimatedModel::show()
{
  MainNode->setVisible(true);
}

/**
 * Sets the visibility of the object and disables collisions
 */
void CAnimatedModel::setVisible(bool value)
{
  MainNode->setVisible(value);
}

/**
 * Makes the object ghost so it will be invisible but will reacts to collisions
 */
void CAnimatedModel::setGhost(bool value)
{
  MainNode->setMaterialFlag(irr::video::EMF_FRONT_FACE_CULLING, !value);
}

/**
 * Sets the wireframe mode for this model
 */
void CAnimatedModel::setWireFrame(bool value)
{
  MainNode->setMaterialFlag(irr::video::EMF_WIREFRAME, value);
}

/**
 * Shows irrlicht debug data for this model
 */
void CAnimatedModel::setDebugData(bool value)
{
  MainNode->setDebugDataVisible(value);
}

/**
 *
 */
void CAnimatedModel::darken()
{
  MainNode->setMaterialFlag(irr::video::EMF_LIGHTING, true);
}

/**
 *
 */
void CAnimatedModel::undarken()
{
  MainNode->setMaterialFlag(irr::video::EMF_LIGHTING, false);
}

/**
 * Returns true if the animated model collides with a static model defined by other
 * @param StaticModel* other pointer to the static object which collides with the animated model
 * @return bool true if collision
 */
bool CAnimatedModel::collidesWithStatic(CStaticModel* other)
{
  NewtonBody* otherBody = other->getMainBody();

  irr::f32 mainBodyMatrix[16] = {};
  irr::f32 otherBodyMatrix[16] = {};

  NewtonBodyGetMatrix(MainBody, mainBodyMatrix);
  NewtonBodyGetMatrix(otherBody, otherBodyMatrix);

  irr::f32 contacts[3];
  irr::f32 normals[3];
  irr::f32 penetration[3];

  irr::s32 res = NewtonCollisionCollide(
    engine::CGame::getNewtonWorld(),
    64,
    NewtonBodyGetCollision(MainBody),
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
irr::f32 CAnimatedModel::getFloorCollision(CStaticModel* other)
{
  irr::f32 normals[3];
  irr::f32 xPoint, zPoint;
  irr::s32 faceId;

  //   B
  // C-+-A
  //   D
  irr::f32 rayA, rayB, rayC, rayD;

  // A
  xPoint = MainNode->getPosition().X - FloorSensorWidth * cos(irr::core::degToRad(MainNode->getRotation().Y));
  zPoint = MainNode->getPosition().Z + FloorSensorWidth * sin(irr::core::degToRad(MainNode->getRotation().Y));
  irr::core::vector3df origin(xPoint, MainNode->getPosition().Y, zPoint);
  irr::core::vector3df end(xPoint, MainNode->getPosition().Y - 1.0f, zPoint);
  rayA = NewtonCollisionRayCast(NewtonBodyGetCollision(other->getMainBody()), &origin.X, &end.X, normals, &faceId);
  //_draw_line(origin, end);

  // B
  xPoint = MainNode->getPosition().X - FloorSensorWidth * cos(irr::core::degToRad(MainNode->getRotation().Y) - (irr::core::PI / 2));
  zPoint = MainNode->getPosition().Z + FloorSensorWidth * sin(irr::core::degToRad(MainNode->getRotation().Y) - (irr::core::PI / 2));
  origin = irr::core::vector3df(xPoint, MainNode->getPosition().Y, zPoint);
  end = irr::core::vector3df(xPoint, MainNode->getPosition().Y - 1.0f, zPoint);
  rayB = NewtonCollisionRayCast(NewtonBodyGetCollision(other->getMainBody()), &origin.X, &end.X, normals, &faceId);
  //_draw_line(origin, end);

  // C
  xPoint = MainNode->getPosition().X - FloorSensorWidth * cos(irr::core::degToRad(MainNode->getRotation().Y) + (irr::core::PI));
  zPoint = MainNode->getPosition().Z + FloorSensorWidth * sin(irr::core::degToRad(MainNode->getRotation().Y) + (irr::core::PI));
  origin = irr::core::vector3df(xPoint, MainNode->getPosition().Y, zPoint);
  end = irr::core::vector3df(xPoint, MainNode->getPosition().Y - 1.0f, zPoint);
  rayC = NewtonCollisionRayCast(NewtonBodyGetCollision(other->getMainBody()), &origin.X, &end.X, normals, &faceId);
  //_draw_line(origin, end);

  // D
  xPoint = MainNode->getPosition().X - FloorSensorWidth * cos(irr::core::degToRad(MainNode->getRotation().Y) + (irr::core::PI / 2));
  zPoint = MainNode->getPosition().Z + FloorSensorWidth * sin(irr::core::degToRad(MainNode->getRotation().Y) + (irr::core::PI / 2));
  origin = irr::core::vector3df(xPoint, MainNode->getPosition().Y, zPoint);
  end = irr::core::vector3df(xPoint, MainNode->getPosition().Y - 1.0f, zPoint);
  rayD = NewtonCollisionRayCast(NewtonBodyGetCollision(other->getMainBody()), &origin.X, &end.X, normals, &faceId);
  //_draw_line(origin, end);

  irr::f32 minAB = irr::core::min_(rayA, rayB);
  irr::f32 minCD = irr::core::min_(rayC, rayD);

  return irr::core::min_(minAB, minCD);
}

/**
 * Not documented yet, sorry :/
 */
irr::f32 CAnimatedModel::getWallCollision(engine::ERayType type, CStaticModel* other, irr::core::vector3df& normal)
{
  NewtonCollision* otherBodyCollision = NewtonBodyGetCollision(other->getMainBody());

  irr::s32 faceId;
  irr::f32 xPoint;
  irr::f32 zPoint;

  // xPoint and zPoint are destination points of the ray
  if (type == engine::RAY_WALL_P) {
    // P Ray (left)
    xPoint = MainNode->getPosition().X - 0.5f * cos(irr::core::degToRad(MainNode->getRotation().Y));
    zPoint = MainNode->getPosition().Z + 0.5f * sin(irr::core::degToRad(MainNode->getRotation().Y));
  } else {
    // Q Ray (right)
    xPoint = MainNode->getPosition().X - 0.5f * cos(irr::core::degToRad(MainNode->getRotation().Y) + irr::core::PI);
    zPoint = MainNode->getPosition().Z + 0.5f * sin(irr::core::degToRad(MainNode->getRotation().Y) + irr::core::PI);
  }

  irr::core::vector3df origin = irr::core::vector3df(
    xPoint,
    MainNode->getPosition().Y,
    zPoint
  );

  xPoint = xPoint - 1.0f * cos(irr::core::degToRad(MainNode->getRotation().Y) - (irr::core::PI / 2));
  zPoint = zPoint + 1.0f * sin(irr::core::degToRad(MainNode->getRotation().Y) - (irr::core::PI / 2));

  irr::core::vector3df end = irr::core::vector3df(
    xPoint,
    MainNode->getPosition().Y,
    zPoint
  );

  return NewtonCollisionRayCast(otherBodyCollision, &origin.X, &end.X, &normal.X, &faceId);
}

/**
 * @todo Under construction
 */
bool CAnimatedModel::collidesWithAnimated(CAnimatedModel* other)
{
  return false;
}

/**
 * @todo Under construction
 * @todo manage event type
 */
bool CAnimatedModel::collidesWithPlaneSensor(CPlaneSensor* sensor, engine::EEventType type)
{
  return false;
}

/**
 * Returns true if the object is in the box sensor
 */
bool CAnimatedModel::isInBoxSensor(CBoxSensor* sensor, engine::EEventType type)
{
  bool inside = sensor->getBox().isPointInside(MainNode->getPosition());
  if (type == engine::EVENT_ONCE) {
    if (!SensorOnce[sensor]) {
      if (inside) {
        SensorOnce[sensor] = true;
        return true;
      }
    } else {
      if (!inside) {
        SensorOnce[sensor] = false;
      }
    }
    return false;
  } else {
    return inside;
  }
}

/**
 * Loads the animation data file specified in parameter
 * @param std::string the animation data file name path
 */
void CAnimatedModel::loadAnimation(const std::string& fileName)
{
  fstream fileStream(fileName.c_str(), ios::in);

  if (fileStream) {
    bool inAnimNumberDeclaration = true;
    bool inAnimStartDeclaration = false;
    bool inAnimEndDeclaration = false;
    bool inAnimLoopedDeclaration = false;

    char current = 0;
    irr::s32 nr = 0;
    std::string animNumber("");
    std::string startFrame("");
    std::string endFrame("");
    bool looped = true;

    while (fileStream.get(current)) {
      if (current == '=') {
        inAnimNumberDeclaration = false;
        inAnimStartDeclaration = true;
        continue;
      }
      if (current == ':') {
        if (inAnimStartDeclaration == true) {
          inAnimStartDeclaration = false;
          inAnimEndDeclaration = true;
        }
        if (inAnimEndDeclaration == true) {
          inAnimEndDeclaration = true;
          inAnimLoopedDeclaration = true;
        }
        continue;
      }
      if (current == ';') {
        inAnimLoopedDeclaration = false;
        nr = (irr::s32)atoi(animNumber.c_str());
        AnimationList[nr].StartFrame = (irr::s32)atoi(startFrame.c_str());
        AnimationList[nr].EndFrame = (irr::s32)atoi(endFrame.c_str());
        AnimationList[nr].Looped = looped;

        animNumber = "";
        startFrame = "";
        endFrame = "";
        looped = false;
        continue;
      }
      if (current == '\n' || current == '\r') {
        inAnimNumberDeclaration = true;
        continue;
      }

      if (inAnimNumberDeclaration) {
        animNumber += current;
      }
      if (inAnimStartDeclaration) {
        startFrame += current;
      }
      if (inAnimEndDeclaration) {
        endFrame += current;
      }
      if (inAnimLoopedDeclaration) {
        looped = (current == 1);
      }
    }
  }
}

/**
 * Sets the current animation
 */
void CAnimatedModel::setCurrentAnimation(irr::s32 id, irr::f32 speed)
{
  CurrentAnimationId = id;
  CurrentAnimationSpeed = speed;

  model::SMeshAnimationInfo anim = AnimationList[id];

  irr::u32 startFrame = anim.StartFrame;
  irr::u32 endFrame = anim.EndFrame;

  MainNode->setCurrentFrame(startFrame);
  MainNode->setFrameLoop(startFrame, endFrame);
  MainNode->setLoopMode(anim.Looped);

  playAnimation();
}

/**
 * Pauses the current animation (speed = 0.0f)
 */
void CAnimatedModel::pauseAnimation()
{
  MainNode->setAnimationSpeed(0.0f);
}

/**
 * Plays the current animation at current speed
 */
void CAnimatedModel::playAnimation()
{
  MainNode->setAnimationSpeed(CurrentAnimationSpeed);
}

/**
 * Sets the current animation speed
 */
void CAnimatedModel::setAnimationSpeed(irr::f32 value)
{
  MainNode->setAnimationSpeed(value);
}

/**
 * Returns true if the current animation is finished
 */
bool CAnimatedModel::currentAnimationFinished()
{
  return animationFinished(CurrentAnimationId);
}

/**
 * Returns true if a specific animation is finished
 */
bool CAnimatedModel::animationFinished(irr::s32 id)
{
  return (MainNode->getFrameNr() == AnimationList[id].EndFrame);
}

/**
 *
 */
void CAnimatedModel::setShadowMode(engine::EShadowMode mode)
{
  engine::CGame::getCurrentScene()->getShadowProcessor()->setEntity(MainNode, mode);
}

/**
 * Destructor, removes the main node
 */
CAnimatedModel::~CAnimatedModel()
{
  if (MainNode) {
    MainNode->remove();
    MainNode = NULL;
  }
}

}
}
