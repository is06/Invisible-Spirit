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

using namespace irr;
using namespace std;

/**
 * PlayableCharacter entity constructor: defines which mesh to load and set the initial direction
 * @param Camera* cam pointer to a Camera to link to PlayableCharacter
 */
PlayableCharacter::PlayableCharacter(Camera* cam) : Character()
{
  controlable = true;
  jumpDelta = 0.0f;
  fallDelta = 0.0f;
  gravity = 0.1f;
  jumpStrength = 0.15f;

  floorSensorWidth = 0.4f;
  wallSensorWidth = 0.5f;

  // Loading mesh
  loadMesh("resource/mesh/character/cube.obj");
  loadAnimation("resource/mesh/character/cube.isa");
  createNode(core::vector3df(-3, 1, -4));
  linkedCam = cam;

  // Start direction
  mainNode->setRotation(core::vector3df(
    mainNode->getRotation().X,
    cam->getNode()->getRotation().Y - core::radToDeg(core::PI),
    mainNode->getRotation().Z
  ));
}

/**
 * Render function, called every cycle
 */
void PlayableCharacter::render()
{
  Character::render();
}

/**
 * Called while PlayableCharacter's floor raycast is NOT in collision with the floor
 */
void PlayableCharacter::fall(f32 factor)
{
  if (!isJumping) {
    if (fallDelta < jumpStrength) {
      fallDelta += (factor * gravity);
    }
    mainNode->setPosition(core::vector3df(
      mainNode->getPosition().X,
      mainNode->getPosition().Y - fallDelta,
      mainNode->getPosition().Z
    ));
  }
}

/**
 * Called while PlayableCharacter's floor raycast is in collision with the floor
 */
void PlayableCharacter::raise()
{
  if (isFalling) {
    // PlayableCharacter is hitting the floor
    fallDelta = 0.0f;
    isFalling = false;
  }
  mainNode->setPosition(core::vector3df(
    mainNode->getPosition().X,
    mainNode->getPosition().Y + 0.005,
    mainNode->getPosition().Z
  ));
}

/**
 * Called when the player wants PlayableCharacter to jump
 */
void PlayableCharacter::jump()
{
  if (isJumping) {
    jumpDelta -= gravity;
    if (jumpDelta <= 0) {
      isJumping = false;
      isFalling = true;
    }
    mainNode->setPosition(core::vector3df(
      mainNode->getPosition().X,
      mainNode->getPosition().Y + jumpDelta,
      mainNode->getPosition().Z
    ));
  }
}

/**
 *
 */
void PlayableCharacter::setJumpDelta(f32 value)
{
  jumpDelta = value;
}

/**
 *
 */
f32 PlayableCharacter::getJumpDelta()
{
  return jumpDelta;
}

/**
 *
 */
f32 PlayableCharacter::getJumpStrength()
{
  return jumpStrength;
}

/**
 * Applies an opposite force to PlayableCharacter in order to stop it against a wall
 * Function still under development
 */
void PlayableCharacter::moveOpposite(const core::vector3df& normal)
{
  f32 angle = (atan2(normal.X, normal.Z) * -1) + (core::PI / 2);

  mainNode->setPosition(core::vector3df(
    mainNode->getPosition().X + (cos(angle) * (0.05f / 1024.0f)),
    mainNode->getPosition().Y,
    mainNode->getPosition().Z + (sin(angle) * (0.05f / 1024.0f))
  ));
}

/**
 * Move PlayableCharacter to the left from camera
 * @param f32 speed movement speed
 */
void PlayableCharacter::goLeft(f32 speed)
{
  updateCoords(0, speed);
}

/**
 * Move PlayableCharacter to the right from camera
 * @param f32 speed movement speed
 */
void PlayableCharacter::goRight(f32 speed)
{
  updateCoords(core::PI, speed);
}

/**
 * Move PlayableCharacter forward from camera
 * @param f32 speed movement speed
 */
void PlayableCharacter::goForward(f32 speed)
{
  updateCoords((core::PI / 2), speed);
}

/**
 * Move PlayableCharacter backward from camera
 * @param f32 speed movement speed
 */
void PlayableCharacter::goBackward(f32 speed)
{
  updateCoords((3 * core::PI / 2), speed);
}

/**
 * Update PlayableCharacter's coordinates when the player wants to move him
 * @param f32 deltaU direction value
 * @param f32 speed speed value
 */
void PlayableCharacter::updateCoords(f32 deltaU, f32 speed)
{
  f32 x = cos(core::degToRad(linkedCam->getNode()->getRotation().Y) + deltaU);
  f32 z = sin(core::degToRad(linkedCam->getNode()->getRotation().Y) + deltaU);
  mainNode->setPosition(core::vector3df(
    mainNode->getPosition().X + ((x * -1) * (speed / 32.0f)),
    mainNode->getPosition().Y,
    mainNode->getPosition().Z + (z * (speed / 32.0f))
  ));
}

void PlayableCharacter::toggleControl()
{
  if (controlable) {
    controlable = false;
  } else {
    controlable = true;
  }
}

/**
 * Returns true if the player has control
 */
bool PlayableCharacter::hasControl()
{
  return controlable;
}
