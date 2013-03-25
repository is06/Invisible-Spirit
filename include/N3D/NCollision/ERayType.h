/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_RAY_TYPE_H__
#define __IS06_RAY_TYPE_H__

namespace is06 { namespace N3D { namespace NCollision {

//! Ray type enumeration for wall and floor collisions
enum ERayType
{
  ERT_WALL_P,
  ERT_WALL_Q,
  ERT_FLOOR_A,
  ERT_FLOOR_B,
  ERT_FLOOR_C,
  ERT_FLOOR_D
};

}}}

#endif
