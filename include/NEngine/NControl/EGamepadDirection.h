/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_ENGINE_CONTROL_GAMEPAD_DIRECTION_H__
#define __IS06_ENGINE_CONTROL_GAMEPAD_DIRECTION_H__

namespace is06 { namespace NEngine { namespace NControl {

//! Gamepad direction mapping enumeration
enum EGamepadDirection
{
  EGD_TOP = 0,
  EGD_TOP_RIGHT = 4500,
  EGD_RIGHT = 9000,
  EGD_BOTTOM_RIGHT = 13500,
  EGD_BOTTOM = 18000,
  EGD_BOTTOM_LEFT = 22500,
  EGD_LEFT = 27000,
  EGD_TOP_LEFT = 31500
};

}}}

#endif
