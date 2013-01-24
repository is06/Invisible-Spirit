/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/Engine/core.h"
#include "../../include/3D/CCharacter.h"
#include "../../include/3D/CAnimatedModel.h"

namespace is06
{
namespace N3D
{

CCharacter::CCharacter() : CAnimatedModel()
{
  Jumping = false;
  Falling = true;
  Walking = false;
  Talking = false;

  JumpStrength = 0.0f;
}

void CCharacter::setCharacterModel(const string& characterId)
{
  string modelPath = "resource/mesh/character/" + characterId + ".b3d";
  string animationPath = "resource/mesh/character/" + characterId + ".isa";

  CAnimatedModel::createModel(modelPath, animationPath);
}

//! Called while PlayableCharacter's floor raycast is NOT in collision with the floor
void CCharacter::fall(f32 factor)
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
void CCharacter::raise()
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
void CCharacter::jump()
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

void CCharacter::setJumpDelta(f32 value)
{
  JumpDelta = value;
}

f32 CCharacter::getJumpDelta()
{
  return JumpDelta;
}

void CCharacter::setJumpStrength(f32 value)
{
  JumpStrength = value;
}

f32 CCharacter::getJumpStrength()
{
  return JumpStrength;
}

void CCharacter::setJumping(bool value)
{
  Jumping = value;
}

void CCharacter::setFalling(bool value)
{
  Falling = value;
}

void CCharacter::setWalking(bool value)
{
  Walking = value;
}

void CCharacter::setTalking(bool value)
{
  Talking = value;
}

bool CCharacter::isJumping()
{
  return Jumping;
}

bool CCharacter::isFalling()
{
  return Falling;
}

bool CCharacter::isWalking()
{
  return Walking;
}

bool CCharacter::isTalking()
{
  return Talking;
}

void CCharacter::update()
{
  CAnimatedModel::update();
}

}
}
