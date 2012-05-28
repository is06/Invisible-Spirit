/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/core.h"
#include "../../include/3d/CPlayableCharacter.h"
#include "../../include/3d/CCamera.h"
#include "../../include/3d/CCharacter.h"

using namespace irr;

namespace is06
{
namespace n3D
{

//! PlayableCharacter entity constructor: defines which mesh to load and set the initial direction
/**
 * \param Camera* cam pointer to a Camera to link to PlayableCharacter
 */
CPlayableCharacter::CPlayableCharacter(CCamera* cam, nEngine::EPlayableCharacterType type) : CCharacter("resource/mesh/character/ayron.b3d", "resource/mesh/character/ayron.isa")
{
  // Linking third-person camera
  LinkedCam = cam;

  // Start direction
  MainNode->setRotation(core::vector3df(
    MainNode->getRotation().X,
    cam->getNode()->getRotation().Y - core::radToDeg(core::PI),
    MainNode->getRotation().Z
  ));

  //MainNode->setMaterialFlag(video::EMF_WIREFRAME, true);

  MainNode->animateJoints();

  // Properties
  Controlable = true;
  JumpDelta = 0.0f;
  FallDelta = 0.0f;
  Gravity = 0.1f;
  JumpStrength = 0.15f;
  FloorSensorWidth = 0.4f;
  WallSensorWidth = 0.5f;
}

//! Update function, called every cycle
void CPlayableCharacter::update()
{
  CCharacter::update();
}

//! Called while PlayableCharacter's floor raycast is NOT in collision with the floor
void CPlayableCharacter::fall(f32 factor)
{
  if (!Jumping) {
    if (FallDelta < JumpStrength) {
      FallDelta += (factor * Gravity);
    }
    MainNode->setPosition(core::vector3df(
      MainNode->getPosition().X,
      MainNode->getPosition().Y - FallDelta,
      MainNode->getPosition().Z
    ));
  }
}

//! Called while PlayableCharacter's floor raycast is in collision with the floor
void CPlayableCharacter::raise()
{
  if (Falling) {
    // PlayableCharacter is hitting the floor
    FallDelta = 0.0f;
    Falling = false;
  }
  MainNode->setPosition(core::vector3df(
    MainNode->getPosition().X,
    MainNode->getPosition().Y + 0.005,
    MainNode->getPosition().Z
  ));
}

//! Called when the player wants PlayableCharacter to jump
void CPlayableCharacter::jump()
{
  if (Jumping) {
    JumpDelta -= Gravity;
    if (JumpDelta <= 0) {
      Jumping = false;
      Falling = true;
    }
    MainNode->setPosition(core::vector3df(
      MainNode->getPosition().X,
      MainNode->getPosition().Y + JumpDelta,
      MainNode->getPosition().Z
    ));
  }
}

void CPlayableCharacter::setJumpDelta(f32 value)
{
  JumpDelta = value;
}

f32 CPlayableCharacter::getJumpDelta()
{
  return JumpDelta;
}

f32 CPlayableCharacter::getJumpStrength()
{
  return JumpStrength;
}

//! Applies an opposite force to PlayableCharacter in order to stop it against a wall
void CPlayableCharacter::moveOpposite(const core::vector3df& normal)
{
  f32 angle = (atan2(normal.X, normal.Z) * -1) + (nEngine::PI_D2);

  MainNode->setPosition(core::vector3df(
    MainNode->getPosition().X + (cos(angle) * (0.05f / 1024.0f)),
    MainNode->getPosition().Y,
    MainNode->getPosition().Z + (sin(angle) * (0.05f / 1024.0f))
  ));
}

//! Move PlayableCharacter to the left from camera
/**
 * \param f32 speed movement speed
 */
void CPlayableCharacter::goLeft(f32 speed)
{
  updateCoords(0, speed);
}

//! Move PlayableCharacter to the right from camera
/**
 * \param f32 speed movement speed
 */
void CPlayableCharacter::goRight(f32 speed)
{
  updateCoords(core::PI, speed);
}

//! Move PlayableCharacter forward from camera
/**
 * \param f32 speed movement speed
 */
void CPlayableCharacter::goForward(f32 speed)
{
  updateCoords((nEngine::PI_D2), speed);
}

//! Move PlayableCharacter backward from camera
/**
 * \param f32 speed movement speed
 */
void CPlayableCharacter::goBackward(f32 speed)
{
  updateCoords(nEngine::PI_M3D2, speed);
}

//! Update PlayableCharacter's coordinates when the player wants to move him
/**
 * \param f32 deltaU direction value
 * \param f32 speed speed value
 */
void CPlayableCharacter::updateCoords(f32 deltaU, f32 speed)
{
  f32 x = cos(core::degToRad(LinkedCam->getNode()->getRotation().Y) + deltaU);
  f32 z = sin(core::degToRad(LinkedCam->getNode()->getRotation().Y) + deltaU);
  MainNode->setPosition(core::vector3df(
    MainNode->getPosition().X + ((x * -1) * (speed / 32.0f)),
    MainNode->getPosition().Y,
    MainNode->getPosition().Z + (z * (speed / 32.0f))
  ));
}

void CPlayableCharacter::toggleControl()
{
  if (Controlable) {
    Controlable = false;
  } else {
    Controlable = true;
  }
}

//! Returns true if the player has control
bool CPlayableCharacter::hasControl()
{
  return Controlable;
}

}
}
