/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_PLAYER_CONTROL_H__
#define __IS06_PLAYER_CONTROL_H__

using namespace irr;

class PlayerControl {
  public:
    PlayerControl();

    f32 getDirection();
    bool pressed(GameplayControlButtons buttons, EventType type = EVENT_ALWAYS);


  private:
    Gamepad* gamepad;
    Keyboard* keyboard;


};

#endif
