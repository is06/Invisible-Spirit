/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/3d/TPCamera.h"

namespace is06
{
namespace model
{

/**
 * Sets the third-person camera and defines its default properties
 */
CTPCamera::CTPCamera() : CCamera()
{
  UAxis = (3 * irr::core::PI) / 2;
  Height = 1.8f;
  Distance = 4.0f;
}

/**
 * Links a Character entity to the camera
 * @param Character* pointer to a character
 */
void CTPCamera::linkEntity(CCharacter* entity)
{
  LinkedEntity = entity;
}

/**
 * Camera update method
 * This method sets the camera position relative to the character and player moves
 */
void CTPCamera::update()
{
  CCamera::update();

  irr::f32 x = LinkedEntity->getNode()->getPosition().X + Distance * cos(UAxis);
  irr::f32 z = LinkedEntity->getNode()->getPosition().Z + Distance * sin(UAxis);

  IrrCam->setTarget(irr::core::vector3df(
    LinkedEntity->getNode()->getPosition().X,
    LinkedEntity->getNode()->getPosition().Y + 0.8,
    LinkedEntity->getNode()->getPosition().Z
  ));
  IrrCam->setPosition(irr::core::vector3df(
    x,
    LinkedEntity->getNode()->getPosition().Y + Height,
    z
  ));
}

/**
 *
 */
void CTPCamera::goLeft(irr::f32 speed)
{
  UAxis -= (speed / 60.0f);
  if (UAxis < 0) {
    UAxis = 2 * irr::core::PI;
  }
}

/**
 *
 */
void CTPCamera::goRight(irr::f32 speed)
{
  UAxis += (speed / 60.0f);
  if (UAxis > (2 * irr::core::PI)) {
    UAxis = 0;
  }
}

/**
 *
 */
void CTPCamera::goFar(irr::f32 speed)
{
  if (Height < 3.3) {
    Height += (speed / 50.0f);
  }
  if (Height > 3.3) {
    Height = 3.3;
  }
  if (Distance < 5.5) {
    Distance += (speed / 50.0f);
  } else {
    Distance = 5.5;
  }
}

/**
 *
 */
void CTPCamera::goNear(irr::f32 speed)
{
  if (Height > 0.3) {
    Height -= (speed / 50.0f);
  }
  if (Height < 0.3) {
    Height = 0.3;
  }
  if (Distance > 2.5) {
    Distance -= (speed / 50.0f);
  } else {
    Distance = 2.5;
  }
}

/**
 *
 */
irr::f32 CTPCamera::getDistance()
{
  return Distance;
}

}
}
