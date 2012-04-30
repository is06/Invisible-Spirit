/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/core.h"
#include "../../include/3d/Character.h"
#include "../../include/3d/AnimatedModel.h"

namespace is06
{
namespace n3D
{

CCharacter::CCharacter() : CAnimatedModel()
{

}

CCharacter::CCharacter(const string& meshFile, const string& animationFile) : CAnimatedModel(meshFile, animationFile)
{
  Jumping = false;
  Falling = true;
  Walking = false;
  Talking = false;

  JumpStrength = 0.0f;
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

/**
 * Fonction de mise à jour de tous les personnages
 */
void CCharacter::update()
{
  CAnimatedModel::update();
}

}
}
