/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/core.h"
#include "../../include/engine/CGame.h"
#include "../../include/engine/CSettings.h"
#include "../../include/scene/CScene.h"
#include "../../include/sound/CSpeaker.h"
#include "../../include/3d/CAnimatedModel.h"
#include "../../include/3d/CStaticModel.h"
#include "../../include/3d/CSensor.h"

using namespace irr;

namespace is06
{
namespace n3D
{

//! Default constructor
CAnimatedModel::CAnimatedModel() : CModelEntity()
{
  MainNode = NULL;
  MainBody = NULL;
}

//! Update function of 3D animated models
void CAnimatedModel::update()
{
  CModelEntity::update();

  // Attached speaker position update
  if (AttachedSpeaker) {
    AttachedSpeaker->setPosition(MainNode->getPosition());
  }
}

//! Shader render method
void CAnimatedModel::shaderRender()
{
  MainNode->render();
}

void CAnimatedModel::createModel(const string& meshFile, const string& animationFile)
{
  loadMesh(meshFile);
  loadAnimation(animationFile);
  createNode(core::vector3df(0, 1, 0));
}

//! Turns the model relative to the X axis
void CAnimatedModel::turnX(f32 speed)
{
  MainNode->setRotation(core::vector3df(
    MainNode->getRotation().X + (speed * nEngine::CGame::getSpeedFactor()),
    MainNode->getRotation().Y,
    MainNode->getRotation().Z
  ));
}

//! Turns the model relative to the Y axis
void CAnimatedModel::turnY(f32 speed)
{
  MainNode->setRotation(core::vector3df(
    MainNode->getRotation().X,
    MainNode->getRotation().Y + (speed * nEngine::CGame::getSpeedFactor()),
    MainNode->getRotation().Z
  ));
}

//! Turns the model relative to the Z axis
void CAnimatedModel::turnZ(f32 speed)
{
  MainNode->setRotation(core::vector3df(
    MainNode->getRotation().X,
    MainNode->getRotation().Y,
    MainNode->getRotation().Z + (speed * nEngine::CGame::getSpeedFactor())
  ));
}

//! Move the model relative to the X axis
void CAnimatedModel::moveX(f32 speed)
{
  MainNode->setPosition(core::vector3df(
    MainNode->getPosition().X + (speed * nEngine::CGame::getSpeedFactor()),
    MainNode->getPosition().Y,
    MainNode->getPosition().Z
  ));
}

//! Move the model relative to the Y axis
void CAnimatedModel::moveY(f32 speed)
{
  MainNode->setPosition(core::vector3df(
    MainNode->getPosition().X,
    MainNode->getPosition().Y + (speed * nEngine::CGame::getSpeedFactor()),
    MainNode->getPosition().Z
  ));
}

//! Move the model relative to the Z axis
void CAnimatedModel::moveZ(f32 speed)
{
  MainNode->setPosition(core::vector3df(
    MainNode->getPosition().X,
    MainNode->getPosition().Y,
    MainNode->getPosition().Z + (speed * nEngine::CGame::getSpeedFactor())
  ));
}

//! Creates the animated node and add it to Irrlicht's scene manager
/**
 * \param vector3df& initPosition reference to the node initial position
 */
void CAnimatedModel::createNode(const core::vector3df& initPosition)
{
  MainNode = nEngine::CGame::getSceneManager()->addAnimatedMeshSceneNode((scene::IAnimatedMesh*)MainMesh);

  if (MainNode) {
    MainNode->setMaterialFlag(video::EMF_LIGHTING, false);
    MainNode->setMaterialFlag(video::EMF_ANTI_ALIASING, (nEngine::CGame::Settings->getParamString("model", "anti_aliasing") == "enabled"));
    MainNode->setPosition(initPosition);
  } else {
    nEngine::CGame::fatalError(nDebug::EEC_CODE_30);
  }
}

//! Returns the Irrlicht node
/**
 * \return IAnimatedMeshSceneNode* entity's node
 */
scene::IAnimatedMeshSceneNode* CAnimatedModel::getNode()
{
  return MainNode;
}

//! Returns Irrlicht material
video::SMaterial& CAnimatedModel::getMaterial()
{
  return MainNode->getMaterial(0);
}

//! Hides the object
void CAnimatedModel::hide()
{
  MainNode->setVisible(false);
}

//! Shows the object
void CAnimatedModel::show()
{
  MainNode->setVisible(true);
}

//! Sets the visibility of the object and disables collisions
void CAnimatedModel::setVisible(bool value)
{
  MainNode->setVisible(value);
}

//! Makes the object ghost so it will be invisible but will reacts to collisions
void CAnimatedModel::setGhost(bool value)
{
  MainNode->setMaterialFlag(video::EMF_FRONT_FACE_CULLING, !value);
}

//! Sets the wireframe mode for this model
void CAnimatedModel::setWireFrame(bool value)
{
  MainNode->setMaterialFlag(video::EMF_WIREFRAME, value);
}

//! Shows irrlicht debug data for this model
void CAnimatedModel::setDebugData(bool value)
{
  MainNode->setDebugDataVisible(value);
}

/**
 *
 */
void CAnimatedModel::darken()
{
  MainNode->setMaterialFlag(video::EMF_LIGHTING, true);
}

/**
 *
 */
void CAnimatedModel::undarken()
{
  MainNode->setMaterialFlag(video::EMF_LIGHTING, false);
}

//! Returns true if the animated model collides with a static model defined by other
/**
 * \param StaticModel* other pointer to the static object which collides with the animated model
 * \return bool true if collision
 */
bool CAnimatedModel::collidesWithStatic(CStaticModel* other)
{
  NewtonBody* otherBody = other->getMainBody();

  f32 mainBodyMatrix[16] = {};
  f32 otherBodyMatrix[16] = {};

  NewtonBodyGetMatrix(MainBody, mainBodyMatrix);
  NewtonBodyGetMatrix(otherBody, otherBodyMatrix);

  f32 contacts[3];
  f32 normals[3];
  f32 penetration[3];

  s32 res = NewtonCollisionCollide(
    nEngine::CGame::getNewtonWorld(),
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

//! Casts 4 rays from the center of the chacter to the bottom and returns the minimum value of floor collision
/**
 * \return f32 (collision between 0.0f and 1.0f)
 */
f32 CAnimatedModel::getFloorCollision(CStaticModel* other)
{
  f32 normals[3];
  f32 xPoint, zPoint;
  s32 faceId;

  //   B
  // C-+-A
  //   D
  f32 rayA, rayB, rayC, rayD;

  // A
  xPoint = MainNode->getPosition().X - FloorSensorWidth * cos(core::degToRad(MainNode->getRotation().Y));
  zPoint = MainNode->getPosition().Z + FloorSensorWidth * sin(core::degToRad(MainNode->getRotation().Y));
  core::vector3df origin(xPoint, MainNode->getPosition().Y, zPoint);
  core::vector3df end(xPoint, MainNode->getPosition().Y - 1.0f, zPoint);
  rayA = NewtonCollisionRayCast(NewtonBodyGetCollision(other->getMainBody()), &origin.X, &end.X, normals, &faceId);
  //_draw_line(origin, end);

  // B
  xPoint = MainNode->getPosition().X - FloorSensorWidth * cos(core::degToRad(MainNode->getRotation().Y) - (core::PI / 2));
  zPoint = MainNode->getPosition().Z + FloorSensorWidth * sin(core::degToRad(MainNode->getRotation().Y) - (core::PI / 2));
  origin = core::vector3df(xPoint, MainNode->getPosition().Y, zPoint);
  end = core::vector3df(xPoint, MainNode->getPosition().Y - 1.0f, zPoint);
  rayB = NewtonCollisionRayCast(NewtonBodyGetCollision(other->getMainBody()), &origin.X, &end.X, normals, &faceId);
  //_draw_line(origin, end);

  // C
  xPoint = MainNode->getPosition().X - FloorSensorWidth * cos(core::degToRad(MainNode->getRotation().Y) + (core::PI));
  zPoint = MainNode->getPosition().Z + FloorSensorWidth * sin(core::degToRad(MainNode->getRotation().Y) + (core::PI));
  origin = core::vector3df(xPoint, MainNode->getPosition().Y, zPoint);
  end = core::vector3df(xPoint, MainNode->getPosition().Y - 1.0f, zPoint);
  rayC = NewtonCollisionRayCast(NewtonBodyGetCollision(other->getMainBody()), &origin.X, &end.X, normals, &faceId);
  //_draw_line(origin, end);

  // D
  xPoint = MainNode->getPosition().X - FloorSensorWidth * cos(core::degToRad(MainNode->getRotation().Y) + (core::PI / 2));
  zPoint = MainNode->getPosition().Z + FloorSensorWidth * sin(core::degToRad(MainNode->getRotation().Y) + (core::PI / 2));
  origin = core::vector3df(xPoint, MainNode->getPosition().Y, zPoint);
  end = core::vector3df(xPoint, MainNode->getPosition().Y - 1.0f, zPoint);
  rayD = NewtonCollisionRayCast(NewtonBodyGetCollision(other->getMainBody()), &origin.X, &end.X, normals, &faceId);
  //_draw_line(origin, end);

  f32 minAB = core::min_(rayA, rayB);
  f32 minCD = core::min_(rayC, rayD);

  return core::min_(minAB, minCD);
}

f32 CAnimatedModel::getWallCollision(nEngine::ERayType type, CStaticModel* other, core::vector3df& normal)
{
  NewtonCollision* otherBodyCollision = NewtonBodyGetCollision(other->getMainBody());

  s32 faceId;
  f32 xPoint;
  f32 zPoint;

  // xPoint and zPoint are destination points of the ray
  if (type == nEngine::ERT_WALL_P) {
    // P Ray (left)
    xPoint = MainNode->getPosition().X - 0.5f * cos(core::degToRad(MainNode->getRotation().Y));
    zPoint = MainNode->getPosition().Z + 0.5f * sin(core::degToRad(MainNode->getRotation().Y));
  } else {
    // Q Ray (right)
    xPoint = MainNode->getPosition().X - 0.5f * cos(core::degToRad(MainNode->getRotation().Y) + core::PI);
    zPoint = MainNode->getPosition().Z + 0.5f * sin(core::degToRad(MainNode->getRotation().Y) + core::PI);
  }

  core::vector3df origin = core::vector3df(
    xPoint,
    MainNode->getPosition().Y,
    zPoint
  );

  xPoint = xPoint - 1.0f * cos(core::degToRad(MainNode->getRotation().Y) - nEngine::PI_D2);
  zPoint = zPoint + 1.0f * sin(core::degToRad(MainNode->getRotation().Y) - nEngine::PI_D2);

  core::vector3df end = core::vector3df(
    xPoint,
    MainNode->getPosition().Y,
    zPoint
  );

  return NewtonCollisionRayCast(otherBodyCollision, &origin.X, &end.X, &normal.X, &faceId);
}

bool CAnimatedModel::collidesWithAnimated(CAnimatedModel* other)
{
  return false;
}

//! Returns true if the object is in the box sensor
bool CAnimatedModel::collidesWithSensor(CSensor* sensor, nEngine::EEventType type)
{
  bool inside = sensor->getBox().isPointInside(MainNode->getPosition());
  if (type == nEngine::EET_ONCE) {
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

//! Loads the animation data file specified in parameter
/**
 * \param string the animation data file name path
 */
void CAnimatedModel::loadAnimation(const string& fileName)
{
  fstream fileStream(fileName.c_str(), ios::in);

  if (fileStream) {
    bool inAnimNumberDeclaration = true;
    bool inAnimStartDeclaration = false;
    bool inAnimEndDeclaration = false;
    bool inAnimLoopedDeclaration = false;

    char current = 0;
    s32 nr = 0;
    string animNumber("");
    string startFrame("");
    string endFrame("");
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
        nr = (s32)atoi(animNumber.c_str());
        AnimationList[nr].StartFrame = (s32)atoi(startFrame.c_str());
        AnimationList[nr].EndFrame = (s32)atoi(endFrame.c_str());
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

//! Sets the current animation
void CAnimatedModel::setCurrentAnimation(s32 id, f32 speed)
{
  CurrentAnimationId = id;
  CurrentAnimationSpeed = speed;

  n3D::SMeshAnimationInfo anim = AnimationList[id];

  u32 startFrame = anim.StartFrame;
  u32 endFrame = anim.EndFrame;

  MainNode->setCurrentFrame(startFrame);
  MainNode->setFrameLoop(startFrame, endFrame);
  MainNode->setLoopMode(anim.Looped);

  playAnimation();
}

//! Pauses the current animation (speed = 0.0f)
void CAnimatedModel::pauseAnimation()
{
  MainNode->setAnimationSpeed(0.0f);
}

//! Plays the current animation at current speed
void CAnimatedModel::playAnimation()
{
  MainNode->setAnimationSpeed(CurrentAnimationSpeed);
}

//! Sets the current animation speed
void CAnimatedModel::setAnimationSpeed(f32 value)
{
  MainNode->setAnimationSpeed(value);
}

//! Returns true if the current animation is finished
bool CAnimatedModel::currentAnimationFinished()
{
  return animationFinished(CurrentAnimationId);
}

//! Returns true if a specific animation is finished
bool CAnimatedModel::animationFinished(s32 id)
{
  return (MainNode->getFrameNr() == AnimationList[id].EndFrame);
}

void CAnimatedModel::setShadowMode(nEngine::EShadowMode mode)
{
  nEngine::CGame::getCurrentScene()->getShadowProcessor()->setEntity(MainNode, mode);
}

//! Destructor, removes the main node
CAnimatedModel::~CAnimatedModel()
{
  if (MainNode) {
    MainNode->remove();
    MainNode = NULL;
  }
  if (MainBody) {
    delete MainBody;
  }
}

}
}
