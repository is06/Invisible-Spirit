/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/core.h"
#include "../../../include/N3D/NCharacter/CCharacter.h"
#include "../../../include/N3D/NPrimitive/CAnimatedModel.h"

namespace is06 { namespace N3D { namespace NCharacter {

//! Properties initialization
CCharacter::CCharacter() : CAnimatedModel()
{
  Jumping = false;
  Falling = true;
  Walking = false;
  Talking = false;

  JumpStrength = 0.0f;
}

//! Changes the 3d model file for this character
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

//! Changes the jump delta value
void CCharacter::setJumpDelta(f32 value)
{
  JumpDelta = value;
}

//! Returns the jump delta value
f32 CCharacter::getJumpDelta()
{
  return JumpDelta;
}

//! Changes the jump strength value
void CCharacter::setJumpStrength(f32 value)
{
  JumpStrength = value;
}

//! Returns the jump strength value
f32 CCharacter::getJumpStrength()
{
  return JumpStrength;
}

//! Changes the jumping state
void CCharacter::setJumping(bool value)
{
  Jumping = value;
}

//! Changes the falling state
void CCharacter::setFalling(bool value)
{
  Falling = value;
}

//! Changes the walking state
void CCharacter::setWalking(bool value)
{
  Walking = value;
}

//! Changes the talking state
void CCharacter::setTalking(bool value)
{
  Talking = value;
}

//! Returns true if the character is currently jumping
bool CCharacter::isJumping()
{
  return Jumping;
}

//! Returns true if the character is currently falling
bool CCharacter::isFalling()
{
  return Falling;
}

//! Returns true if the character is currently walking
bool CCharacter::isWalking()
{
  return Walking;
}

//! Returns true if the character is currently talking
bool CCharacter::isTalking()
{
  return Talking;
}

//! Update function called every cycle for event testing
void CCharacter::update()
{
  CAnimatedModel::update();
}

}}}
