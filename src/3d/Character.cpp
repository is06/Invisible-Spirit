/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/3d/Character.h"
#include "../../include/3d/AnimatedModel.h"

namespace is06
{
namespace model
{

/**
 * Constructeur
 */
CCharacter::CCharacter(const std::string& meshFile, const std::string& animationFile) : CAnimatedModel(meshFile, animationFile)
{
  IsJumping = false;
  IsFalling = true;
  IsWalking = false;
  IsTalking = false;

  JumpStrength = 0.0f;
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
