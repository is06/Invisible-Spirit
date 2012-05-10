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
#include "../../include/engine/GamepadButton.h"
#include "../../include/engine/GamepadDirection.h"

using namespace irr;

namespace is06
{
namespace nEngine
{

//! Constructor: Keyboard and Gamepad initialization
CPlayerControl::CPlayerControl()
{
  Keyboard = new CKeyboard();
  Gamepad = new CGamepad();
}

//! Returns true if a specific command is entered
bool CPlayerControl::commandEntered(ECommandIdentifier command, EEventType eventType)
{
  bool value = false;

  switch (command) {
    case COMMAND_MENU_LEFT:
      value = (Keyboard->pressed(KEY_LEFT, eventType) || Gamepad->buttonPressed(GP_DIR_LEFT, eventType));
      break;
    case COMMAND_MENU_RIGHT:
      value = (Keyboard->pressed(KEY_RIGHT, eventType) || Gamepad->buttonPressed(GP_DIR_RIGHT, eventType));
      break;
    case COMMAND_MENU_DOWN:
      value = (Keyboard->pressed(KEY_DOWN, eventType) || Gamepad->buttonPressed(GP_DIR_BOTTOM, eventType));
      break;
    case COMMAND_MENU_UP:
      value = (Keyboard->pressed(KEY_UP, eventType) || Gamepad->buttonPressed(GP_DIR_TOP, eventType));
      break;
    case COMMAND_MENU_OK:
    case COMMAND_DIALOG_ACTION:
      value = (Keyboard->pressed(KEY_SPACE, eventType) || Gamepad->buttonPressed(GP_BUTTON_A, eventType));
      break;
    case COMMAND_OPEN_MENU:
      value = (Keyboard->pressed(KEY_KEY_D, eventType) || Gamepad->buttonPressed(GP_BUTTON_Y, eventType));
      break;
    case COMMAND_PLAYER_JUMP:
    case COMMAND_MENU_BACK:
      value = (Keyboard->pressed(KEY_KEY_V, eventType) || Gamepad->buttonPressed(GP_BUTTON_B, eventType));
      break;
    case COMMAND_PLAYER_GUARD:
      value = (Keyboard->pressed(KEY_KEY_X, eventType) || Gamepad->buttonPressed(GP_BUTTON_X, eventType));
      break;
    case COMMAND_PLAYER_ATTACK:
      value = (Keyboard->pressed(KEY_KEY_C, eventType) || Gamepad->buttonPressed(GP_BUTTON_A, eventType));
      break;
    case COMMAND_COUNT:
      break;
  }

  return value;
}

f32 CPlayerControl::getPlayerDirection()
{
  if (Keyboard->pressed(KEY_UP) || Keyboard->pressed(KEY_DOWN) || Keyboard->pressed(KEY_LEFT) || Keyboard->pressed(KEY_RIGHT)) {
    return Keyboard->getDirectionAngle();
  }
  if (fabs(Gamepad->getLeftJoystickXAxis()) > 35 || fabs(Gamepad->getLeftJoystickYAxis()) > 35) {
    return Gamepad->getLeftJoystickAngle();
  }

  return 0.0f;
}

f32 CPlayerControl::getPlayerXAxis()
{
  if (Keyboard->pressed(KEY_LEFT) || Keyboard->pressed(KEY_RIGHT)) {
    return Keyboard->getDirectionXAxis();
  }
  if (fabs(Gamepad->getLeftJoystickXAxis()) > 35) {
    return Gamepad->getLeftJoystickXAxis();
  }

  return 0.0f;
}

f32 CPlayerControl::getPlayerYAxis()
{
  if (Keyboard->pressed(KEY_UP) || Keyboard->pressed(KEY_DOWN)) {
    return Keyboard->getDirectionYAxis();
  }
  if (fabs(Gamepad->getLeftJoystickYAxis()) > 35) {
    return Gamepad->getLeftJoystickYAxis();
  }

  return 0.0f;
}

f32 CPlayerControl::getCameraXAxis()
{
  if (Keyboard->pressed(KEY_KEY_J)) {
    return -100.0f;
  }
  if (Keyboard->pressed(KEY_KEY_L)) {
    return 100.0f;
  }
  if (fabs(Gamepad->getRightJoystickXAxis()) > 35) {
    return Gamepad->getRightJoystickXAxis();
  }

  return 0.0f;
}

f32 CPlayerControl::getCameraYAxis()
{
  if (Keyboard->pressed(KEY_KEY_I)) {
    return 100.0f;
  }
  if (Keyboard->pressed(KEY_KEY_K)) {
    return -100.0f;
  }
  if (fabs(Gamepad->getRightJoystickYAxis()) > 35) {
    return Gamepad->getRightJoystickYAxis();
  }

  return 0.0f;
}

CPlayerControl::~CPlayerControl()
{
  delete Keyboard;
  delete Gamepad;
}

}
}

