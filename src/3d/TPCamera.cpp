/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/3d/TPCamera.h"

using namespace irr;
using namespace std;

/**
 * Sets the third-person camera and defines its default properties
 */
TPCamera::TPCamera() : Camera()
{
  UAxis = (3 * core::PI) / 2;
  height = 1.8f;
  distance = 4.0f;
}

/**
 * Links a Character entity to the camera
 * @param Character* pointer to a character
 */
void TPCamera::linkEntity(Character* entity)
{
  linkedEntity = entity;
}

/**
 * Camera update and render method
 * This method sets the camera position relative to the character and player moves
 */
void TPCamera::render()
{
  Camera::render();

  f32 x = linkedEntity->getNode()->getPosition().X + distance * cos(UAxis);
  f32 z = linkedEntity->getNode()->getPosition().Z + distance * sin(UAxis);

  irrCam->setTarget(core::vector3df(
    linkedEntity->getNode()->getPosition().X,
    linkedEntity->getNode()->getPosition().Y + 0.8,
    linkedEntity->getNode()->getPosition().Z
  ));
  irrCam->setPosition(core::vector3df(
    x,
    linkedEntity->getNode()->getPosition().Y + height,
    z
  ));
}

/**
 *
 */
void TPCamera::goLeft(f32 speed)
{
  UAxis -= (speed / 60.0f);
  if (UAxis < 0) {
    UAxis = 2 * core::PI;
  }
}

/**
 *
 */
void TPCamera::goRight(f32 speed)
{
  UAxis += (speed / 60.0f);
  if (UAxis > (2 * core::PI)) {
    UAxis = 0;
  }
}

/**
 *
 */
void TPCamera::goFar(f32 speed)
{
  if (height < 3.3) {
    height += (speed / 50.0f);
  }
  if (height > 3.3) {
    height = 3.3;
  }
  if (distance < 5.5) {
    distance += (speed / 50.0f);
  } else {
    distance = 5.5;
  }
}

/**
 *
 */
void TPCamera::goNear(f32 speed)
{
  if (height > 0.3) {
    height -= (speed / 50.0f);
  }
  if (height < 0.3) {
    height = 0.3;
  }
  if (distance > 2.5) {
    distance -= (speed / 50.0f);
  } else {
    distance = 2.5;
  }
}

/**
 *
 */
f32 TPCamera::getDistance()
{
  return distance;
}
