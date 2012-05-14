/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_RAY_TYPE_H__
#define __IS06_RAY_TYPE_H__

namespace is06
{
namespace nEngine
{

//! Ray type enumeration for wall and floor collisions
enum ERayType
{
  RAY_WALL_P,
  RAY_WALL_Q,
  RAY_FLOOR_A,
  RAY_FLOOR_B,
  RAY_FLOOR_C,
  RAY_FLOOR_D
};

}
}

#endif
