/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_COMMAND_IDENTIFIER_H__
#define __IS06_COMMAND_IDENTIFIER_H__

namespace is06
{
namespace nEngine
{

//! Enumeration for player control
enum ECommandIdentifier
{
  COMMAND_MENU_UP,
  COMMAND_MENU_DOWN,
  COMMAND_MENU_LEFT,
  COMMAND_MENU_RIGHT,
  COMMAND_MENU_OK,
  COMMAND_MENU_BACK,

  COMMAND_PLAYER_JUMP,
  COMMAND_PLAYER_GUARD,
  COMMAND_OPEN_MENU,

  COMMAND_DIALOG_ACTION,

  COMMAND_COUNT
};

}
}

#endif
