/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_ENGINE_CONTROL_PLAYER_CONTROL_H__
#define __IS06_ENGINE_CONTROL_PLAYER_CONTROL_H__

#include "CKeyboard.h"
#include "CGamepad.h"
#include "ECommandIdentifier.h"
#include "../NEvent/EEventType.h"

namespace is06 { namespace NEngine { namespace NControl {

//! Interface for player control regardless the type of controller
class CPlayerControl
{
public:
  CPlayerControl(bool gamepadActive);
  ~CPlayerControl();

  bool commandEntered(NControl::ECommandIdentifier command, NEvent::EEventType eventType=NEvent::EET_ALWAYS);

  f32 getPlayerDirection();
  f32 getPlayerXAxis();
  f32 getPlayerYAxis();

  f32 getCameraXAxis();
  f32 getCameraYAxis();

private:
  NControl::CKeyboard* Keyboard;
  NControl::CGamepad* Gamepad;

  bool CommandOnce[NControl::ECI_COUNT];
  bool GamepadActive;
};

}}}

#endif
