/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_CHARACTER_ANIMATION_IDENTIFIER_H__
#define __IS06_CHARACTER_ANIMATION_IDENTIFIER_H__

namespace is06
{
namespace nEngine
{

//! 3D character animation enumeration
enum ECharacterAnimationIdentifier
{
  ECA_STAND,
  ECA_WALK,
  ECA_WALK_FASTER,
  ECA_RUN,
  ECA_MINI_JUMP,
  ECA_JUMP,
  ECA_FALL,
  ECA_CROUCH,
  ECA_HIT_FRONT,
  ECA_HIT_BEHIND,
  ECA_HIT_LEFT,
  ECA_HIT_RIGHT,
  ECA_THROWN_FRONT,
  ECA_THROWN_BEHIND,
  ECA_THROWN_LEFT,
  ECA_THROWN_RIGHT,
  ECA_RISES,
  ECA_WAIT,
  ECA_BORED,
  ECA_CLIMB_UP,
  ECA_CLIMB_DOWN,
  ECA_CLIMB_LEFT,
  ECA_CLIMB_RIGHT,
  ECA_OUT_WATER,
  ECA_FLOAT,
  ECA_SWIM,

  ECA_ATTACK,
  ECA_GUARD
};

}
}

#endif
