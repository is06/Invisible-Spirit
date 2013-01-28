/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/Engine/core.h"
#include "../../../include/3D/Camera/CThirdPerson.h"

namespace is06
{
namespace N3D
{
namespace NCamera
{

//! Sets the third-person camera and defines its default properties
CThirdPerson::CThirdPerson() : CCamera()
{
  LinkedEntity = NULL;
  UAxis = (3 * core::PI) / 2;
  Height = 1.8f;
  Distance = 4.0f;
}

//! Links a Character entity to the camera
/**
 * \param Character* pointer to a character
 */
void CThirdPerson::linkEntity(CCharacter* entity)
{
  LinkedEntity = entity;
}

//! This method sets the camera position relative to the character and player moves
void CThirdPerson::update()
{
  CCamera::update();

  if (LinkedEntity->getNode() != NULL) {
    f32 x = LinkedEntity->getNode()->getPosition().X + Distance * cos(UAxis);
    f32 z = LinkedEntity->getNode()->getPosition().Z + Distance * sin(UAxis);

    IrrCam->setTarget(core::vector3df(
      LinkedEntity->getNode()->getPosition().X,
      LinkedEntity->getNode()->getPosition().Y + 0.8,
      LinkedEntity->getNode()->getPosition().Z
    ));
    IrrCam->setPosition(core::vector3df(
      x,
      LinkedEntity->getNode()->getPosition().Y + Height,
      z
    ));
  }
}

//! Moves the camera to the left along the U axis
void CThirdPerson::goLeft(f32 speed)
{
  UAxis -= (speed / 60.0f);
  if (UAxis < 0) {
    UAxis = 2 * core::PI;
  }
}

//! Moves the camera to the right along the U axis
void CThirdPerson::goRight(f32 speed)
{
  UAxis += (speed / 60.0f);
  if (UAxis > (2 * core::PI)) {
    UAxis = 0;
  }
}

//! Moves the camera away from the linked entity
void CThirdPerson::goFar(f32 speed)
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

//! Moves the camera closer to the linked entity
void CThirdPerson::goNear(f32 speed)
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

//! Returns the current distance between the camera and its linked entity
f32 CThirdPerson::getDistance()
{
  return Distance;
}

}
}
}
