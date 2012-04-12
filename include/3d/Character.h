/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_CHARACTER_H__
#define __IS06_CHARACTER_H__

#include "../../include/3d/AnimatedModel.h"

namespace is06
{
namespace model
{

class CCharacter : public CAnimatedModel
{
  public:
    CCharacter(const std::string& meshFile, const std::string& animationFile);

    virtual void update();

    bool IsJumping;
    bool IsFalling;
    bool IsWalking;
    bool IsTalking;

  protected:
    irr::f32 JumpStrength;
};

}
}

#endif
