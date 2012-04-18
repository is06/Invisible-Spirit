/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/core.h"
#include "../../include/engine/PlayerControl.h"
#include "../../include/engine/Keyboard.h"
#include "../../include/engine/Gamepad.h"

namespace is06
{
namespace nEngine
{

CPlayerControl::CPlayerControl()
{
  Keyboard = new CKeyboard();
  Gamepad = new CGamepad();
}

bool CPlayerControl::commandEntered(ECommandIdentifier command, EEventType eventType)
{
  return false;
}

f32 CPlayerControl::getPlayerDirection()
{
  return 0.0f;
}

f32 CPlayerControl::getPlayerSpeed()
{
  return 0.0f;
}

f32 CPlayerControl::getCameraDirection()
{
  return 0.0f;
}

f32 CPlayerControl::getCameraSpeed()
{
  return 0.0f;
}

CPlayerControl::~CPlayerControl()
{
  delete Keyboard;
  delete Gamepad;
}

}
}
