/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_CHARACTER_ANIMATION_IDENTIFIER_H__
#define __IS06_CHARACTER_ANIMATION_IDENTIFIER_H__

namespace is06 { namespace N3D { namespace NCharacter {

//! 3D character animation enumeration
enum ECharacterAnimationIdentifier
{
  ANIM_STAND,
  ANIM_WALK,
  ANIM_WALK_FASTER,
  ANIM_RUN,
  ANIM_MINI_JUMP,
  ANIM_JUMP,
  ANIM_FALL,
  ANIM_CROUCH,
  ANIM_HIT_FRONT,
  ANIM_HIT_BEHIND,
  ANIM_HIT_LEFT,
  ANIM_HIT_RIGHT,
  ANIM_THROWN_FRONT,
  ANIM_THROWN_BEHIND,
  ANIM_THROWN_LEFT,
  ANIM_THROWN_RIGHT,
  ANIM_RISES,
  ANIM_WAIT,
  ANIM_BORED,
  ANIM_CLIMB_UP,
  ANIM_CLIMB_DOWN,
  ANIM_CLIMB_LEFT,
  ANIM_CLIMB_RIGHT,
  ANIM_OUT_WATER,
  ANIM_FLOAT,
  ANIM_SWIM,

  ANIM_ATTACK,
  ANIM_GUARD
};

}}}

#endif
