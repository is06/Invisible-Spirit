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
