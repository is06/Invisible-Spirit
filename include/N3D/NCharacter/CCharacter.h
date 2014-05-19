/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_3D_CHARACTER_CHARACTER_H__
#define __IS06_3D_CHARACTER_CHARACTER_H__

#include "../NPrimitive/CAnimatedModel.h"

namespace is06 { namespace N3D { namespace NCharacter {

//! A living Character animated model class for both player or npc
class CCharacter : public NPrimitive::CAnimatedModel
{
public:
    CCharacter();

    virtual void update();
    void setCharacterModel(const string& characterId);

    // Gravity
    void fall(f32 factor);
    void raise();
    void jump();

    void setJumpDelta(f32 value);
    f32 getJumpDelta();
    void setJumpStrength(f32 value);
    f32 getJumpStrength();

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
    f32 JumpDelta;
    f32 FallDelta;
    f32 Gravity;
};

}}}

#endif
