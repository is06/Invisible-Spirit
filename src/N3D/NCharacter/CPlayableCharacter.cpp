/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/core.h"
#include "../../../include/NEngine/NCore/CGame.h"
#include "../../../include/N3D/NCharacter/CCharacter.h"
#include "../../../include/N3D/NCharacter/CPlayableCharacter.h"
#include "../../../include/N3D/NCamera/CCamera.h"

using namespace irr;

namespace is06 { namespace N3D { namespace NCharacter {

//! PlayableCharacter entity constructor: defines which mesh to load and set the initial direction
/**
 * \param Camera* cam pointer to a Camera to link to PlayableCharacter
 */
CPlayableCharacter::CPlayableCharacter(NCamera::CCamera* cam) : CCharacter()
{
  // Linking third-person camera
  LinkedCam = cam;

  // Properties
  Controlable = true;
  JumpDelta = 0.0f;
  FallDelta = 0.0f;
  Gravity = 0.1f;
  JumpStrength = 0.15f;
  FloorSensorWidth = 0.4f;
  WallSensorWidth = 0.5f;
}

//! Changes the 3d model for this character
void CPlayableCharacter::setCharacter(N3D::NCharacter::EPlayableCharacterType type)
{
  // 3D Model type
  string modelId;
  switch (type) {
    case N3D::NCharacter::EPCT_AYRON:
      modelId = "ayron";
      break;
    default:
      modelId = "default";
      break;
  }

  CCharacter::setCharacterModel(modelId);

  // Start direction
  if (MainNode != NULL) {
    updateDirectionFromAngle(1.0f);
    //MainNode->setMaterialFlag(video::EMF_WIREFRAME, true);
    //MainNode->animateJoints();
  }
}

//! Update function, called every cycle
void CPlayableCharacter::update()
{
  CCharacter::update();
}

//! Applies an opposite force to PlayableCharacter in order to stop it against a wall
void CPlayableCharacter::moveOpposite(const core::vector3df& normal)
{
  f32 angle = (atan2(normal.X, normal.Z) * -1) + (NEngine::PI_D2);

  if (MainNode != NULL) {
    MainNode->setPosition(core::vector3df(
      MainNode->getPosition().X + (cos(angle) * (0.05f / 1024.0f)),
      MainNode->getPosition().Y,
      MainNode->getPosition().Z + (sin(angle) * (0.05f / 1024.0f))
    ));
  }
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
  updateCoords((NEngine::PI_D2), speed);
}

//! Move PlayableCharacter backward from camera
/**
 * \param f32 speed movement speed
 */
void CPlayableCharacter::goBackward(f32 speed)
{
  updateCoords(NEngine::PI_M3D2, speed);
}

//! Updates the model direction from a specified angle
void CPlayableCharacter::updateDirectionFromAngle(f32 angle)
{
  if (MainNode != NULL) {
    MainNode->setRotation(core::vector3df(
      MainNode->getRotation().X,
      LinkedCam->getNode()->getRotation().Y - (angle + core::radToDeg(NEngine::PI_D2)),
      MainNode->getRotation().Z
    ));
  }
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

  if (MainNode != NULL) {
    MainNode->setPosition(core::vector3df(
      MainNode->getPosition().X + ((x * -1) * (speed / 32.0f)),
      MainNode->getPosition().Y,
      MainNode->getPosition().Z + (z * (speed / 32.0f))
    ));
  }
}

//! Toggles the player control
void CPlayableCharacter::toggleControl()
{
  if (Controlable) {
    Controlable = false;
  } else {
    Controlable = true;
  }
}

//! Enables/Disabled player control
void CPlayableCharacter::setControl(bool active)
{
  Controlable = active;
}

//! Returns true if the player has control
bool CPlayableCharacter::hasControl()
{
  return Controlable;
}

}}}
