/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/3d/PlayableCharacter.h"
#include "../../include/3d/Camera.h"
#include "../../include/3d/Character.h"

namespace is06
{
namespace model
{

/**
 * PlayableCharacter entity constructor: defines which mesh to load and set the initial direction
 * @param Camera* cam pointer to a Camera to link to PlayableCharacter
 */
CPlayableCharacter::CPlayableCharacter(CCamera* cam) : CCharacter("resource/mesh/character/cube.obj", "resource/mesh/character/cube.isa")
{
  Controlable = true;
  JumpDelta = 0.0f;
  FallDelta = 0.0f;
  Gravity = 0.1f;
  JumpStrength = 0.15f;

  FloorSensorWidth = 0.4f;
  WallSensorWidth = 0.5f;

  // Loading mesh
  createNode(irr::core::vector3df(-3, 1, -4));
  LinkedCam = cam;

  // Start direction
  MainNode->setRotation(irr::core::vector3df(
    MainNode->getRotation().X,
    cam->getNode()->getRotation().Y - irr::core::radToDeg(irr::core::PI),
    MainNode->getRotation().Z
  ));
}

/**
 * Update function, called every cycle
 */
void CPlayableCharacter::update()
{
  CCharacter::update();
}

/**
 * Called while PlayableCharacter's floor raycast is NOT in collision with the floor
 */
void CPlayableCharacter::fall(irr::f32 factor)
{
  if (!IsJumping) {
    if (FallDelta < JumpStrength) {
      FallDelta += (factor * Gravity);
    }
    MainNode->setPosition(irr::core::vector3df(
      MainNode->getPosition().X,
      MainNode->getPosition().Y - FallDelta,
      MainNode->getPosition().Z
    ));
  }
}

/**
 * Called while PlayableCharacter's floor raycast is in collision with the floor
 */
void CPlayableCharacter::raise()
{
  if (IsFalling) {
    // PlayableCharacter is hitting the floor
    FallDelta = 0.0f;
    IsFalling = false;
  }
  MainNode->setPosition(irr::core::vector3df(
    MainNode->getPosition().X,
    MainNode->getPosition().Y + 0.005,
    MainNode->getPosition().Z
  ));
}

/**
 * Called when the player wants PlayableCharacter to jump
 */
void CPlayableCharacter::jump()
{
  if (IsJumping) {
    JumpDelta -= Gravity;
    if (JumpDelta <= 0) {
      IsJumping = false;
      IsFalling = true;
    }
    MainNode->setPosition(irr::core::vector3df(
      MainNode->getPosition().X,
      MainNode->getPosition().Y + JumpDelta,
      MainNode->getPosition().Z
    ));
  }
}

/**
 *
 */
void CPlayableCharacter::setJumpDelta(irr::f32 value)
{
  JumpDelta = value;
}

/**
 *
 */
irr::f32 CPlayableCharacter::getJumpDelta()
{
  return JumpDelta;
}

/**
 *
 */
irr::f32 CPlayableCharacter::getJumpStrength()
{
  return JumpStrength;
}

/**
 * Applies an opposite force to PlayableCharacter in order to stop it against a wall
 * Function still under development
 */
void CPlayableCharacter::moveOpposite(const irr::core::vector3df& normal)
{
  irr::f32 angle = (atan2(normal.X, normal.Z) * -1) + (irr::core::PI / 2);

  MainNode->setPosition(irr::core::vector3df(
    MainNode->getPosition().X + (cos(angle) * (0.05f / 1024.0f)),
    MainNode->getPosition().Y,
    MainNode->getPosition().Z + (sin(angle) * (0.05f / 1024.0f))
  ));
}

/**
 * Move PlayableCharacter to the left from camera
 * @param f32 speed movement speed
 */
void CPlayableCharacter::goLeft(irr::f32 speed)
{
  updateCoords(0, speed);
}

/**
 * Move PlayableCharacter to the right from camera
 * @param f32 speed movement speed
 */
void CPlayableCharacter::goRight(irr::f32 speed)
{
  updateCoords(irr::core::PI, speed);
}

/**
 * Move PlayableCharacter forward from camera
 * @param f32 speed movement speed
 */
void CPlayableCharacter::goForward(irr::f32 speed)
{
  updateCoords((irr::core::PI / 2), speed);
}

/**
 * Move PlayableCharacter backward from camera
 * @param f32 speed movement speed
 */
void CPlayableCharacter::goBackward(irr::f32 speed)
{
  updateCoords((3 * irr::core::PI / 2), speed);
}

/**
 * Update PlayableCharacter's coordinates when the player wants to move him
 * @param f32 deltaU direction value
 * @param f32 speed speed value
 */
void CPlayableCharacter::updateCoords(irr::f32 deltaU, irr::f32 speed)
{
  irr::f32 x = cos(irr::core::degToRad(LinkedCam->getNode()->getRotation().Y) + deltaU);
  irr::f32 z = sin(irr::core::degToRad(LinkedCam->getNode()->getRotation().Y) + deltaU);
  MainNode->setPosition(irr::core::vector3df(
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

/**
 * Returns true if the player has control
 */
bool CPlayableCharacter::hasControl()
{
  return Controlable;
}

}
}
