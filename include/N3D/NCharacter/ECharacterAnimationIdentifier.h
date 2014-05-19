/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_3D_CHARACTER_CHARACTER_ANIMATION_IDENTIFIER_H__
#define __IS06_3D_CHARACTER_CHARACTER_ANIMATION_IDENTIFIER_H__

namespace is06 { namespace N3D { namespace NCharacter {

//! 3D character animation enumeration
enum ECharacterAnimationIdentifier
{
    ECAI_STAND,
    ECAI_WALK,
    ECAI_WALK_FASTER,
    ECAI_RUN,
    ECAI_MINI_JUMP,
    ECAI_JUMP,
    ECAI_FALL,
    ECAI_CROUCH,
    ECAI_HIT_FRONT,
    ECAI_HIT_BEHIND,
    ECAI_HIT_LEFT,
    ECAI_HIT_RIGHT,
    ECAI_THROWN_FRONT,
    ECAI_THROWN_BEHIND,
    ECAI_THROWN_LEFT,
    ECAI_THROWN_RIGHT,
    ECAI_RISES,
    ECAI_WAIT,
    ECAI_BORED,
    ECAI_CLIMB_UP,
    ECAI_CLIMB_DOWN,
    ECAI_CLIMB_LEFT,
    ECAI_CLIMB_RIGHT,
    ECAI_OUT_WATER,
    ECAI_FLOAT,
    ECAI_SWIM,
    ECAI_ATTACK,
    ECAI_GUARD
};

}}}

#endif
