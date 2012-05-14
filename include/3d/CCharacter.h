/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_CHARACTER_H__
#define __IS06_CHARACTER_H__

#include "CAnimatedModel.h"

namespace is06
{
namespace n3D
{

//! A living Character animated model class for both player or npc
class CCharacter : public CAnimatedModel
{
  public:
    CCharacter();
    CCharacter(const string& meshFile, const string& animationFile);

    virtual void update();
    void setJumping(bool value);
    void setFalling(bool value);
    void setWalking(bool value);
    void setTalking(bool value);
    bool isJumping();
    bool isFalling();
    bool isWalking();
    bool isTalking();

  protected:
    bool Jumping;
    bool Falling;
    bool Walking;
    bool Talking;
    f32 JumpStrength;
};

}
}

#endif
