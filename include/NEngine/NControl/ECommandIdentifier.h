/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_ENGINE_CONTROL_COMMAND_IDENTIFIER_H__
#define __IS06_ENGINE_CONTROL_COMMAND_IDENTIFIER_H__

namespace is06 { namespace NEngine { namespace NControl {

//! Enumeration for player control
enum ECommandIdentifier
{
  ECI_MENU_UP,
  ECI_MENU_DOWN,
  ECI_MENU_LEFT,
  ECI_MENU_RIGHT,
  ECI_MENU_OK,
  ECI_MENU_BACK,

  ECI_PLAYER_JUMP,
  ECI_PLAYER_GUARD,
  ECI_PLAYER_ATTACK,
  ECI_OPEN_MENU,

  ECI_DIALOG_ACTION,

  ECI_DEBUG_CONSOLE_EXECUTE,

  ECI_COUNT
};

}}}

#endif
