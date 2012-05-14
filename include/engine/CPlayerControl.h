/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_PLAYER_CONTROL_H__
#define __IS06_PLAYER_CONTROL_H__

#include "ECommandIdentifier.h"
#include "EEventType.h"

namespace is06
{
namespace nEngine
{

class CPlayerControl
{
  public:
    CPlayerControl();
    ~CPlayerControl();

    bool commandEntered(ECommandIdentifier command, EEventType eventType=EVENT_ALWAYS);

    f32 getPlayerDirection();
    f32 getPlayerXAxis();
    f32 getPlayerYAxis();

    f32 getCameraXAxis();
    f32 getCameraYAxis();

  private:
    CKeyboard* Keyboard;
    CGamepad* Gamepad;

    bool CommandOnce[COMMAND_COUNT];
};

}
}

#endif
