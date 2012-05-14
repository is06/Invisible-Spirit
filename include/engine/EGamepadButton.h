/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_GAMEPAD_BUTTON_H__
#define __IS06_GAMEPAD_BUTTON_H__

namespace is06
{
namespace nEngine
{

//! Gamepad buttons mapping enumeration
enum EGamepadButton
{
  EGB_A = 1,
  EGB_B = 2,
  EGB_X = 4,
  EGB_Y = 8,
  EGB_LB = 16,
  EGB_RB = 32,
  EGB_BACK = 64,
  EGB_START = 128,
  EGB_LSTICK = 256,
  EGB_RSTICK = 512
};

}
}

#endif
