#include "core.h"

using namespace irr;

PlayerControl::PlayerControl() {
  gamepad = new Gamepad();
  keyboard = new Keyboard();
}

f32 PlayerControl::getDirection() {
  // Clavier
  if(keyboard->pressed(KEY_LEFT)) {
    if(keyboard->pressed(KEY_UP)) {
      return core::radToDeg((3 * core::PI) / 4);
    } else if(keyboard->pressed(KEY_DOWN)) {
      return core::radToDeg((5 * core::PI) / 4);
    } else {
      return core::radToDeg(core::PI);
    }
  } else if(keyboard->pressed(KEY_RIGHT)) {
    if(keyboard->pressed(KEY_UP)) {
      return core::radToDeg(core::PI / 4);
    } else if(keyboard->pressed(KEY_DOWN)) {
      return core::radToDeg((7 * core::PI) / 4);
    } else {
      return 0.0f;
    }
  }
  if(keyboard->pressed(KEY_UP)) {
    if(keyboard->pressed(KEY_LEFT)) {
      return core::radToDeg((3 * core::PI) / 4);
    } else if(keyboard->pressed(KEY_RIGHT)) {
      return core::radToDeg(core::PI / 4);
    } else {
      return core::radToDeg(core::PI / 2);
    }
  } else if(keyboard->pressed(KEY_DOWN)) {
    if(keyboard->pressed(KEY_LEFT)) {
      return core::radToDeg((5 * core::PI) / 4);
    } else if(keyboard->pressed(KEY_RIGHT)) {
      return core::radToDeg((7 * core::PI) / 4);
    } else {
      return core::radToDeg((3 * core::PI) / 2);
    }
  }

  if(fabs(gamepad->getLeftJoystickXAxis()) > 35 || fabs(gamepad->getLeftJoystickYAxis()) > 35) {
    return gamepad->getLeftJoystickAngle();
  }
}

bool PlayerControl::pressed(GameplayControlButtons buttons, EventType type) {
  switch(buttons) {
    case CB_BUTTON_COMMAND: return keyboard->pressed(KEY_KEY_C, type); break;
    case CB_BUTTON_JUMP: return keyboard->pressed(KEY_KEY_V, type); break;
    case CB_BUTTON_DEFENSE: return keyboard->pressed(KEY_KEY_X, type); break;
    case CB_BUTTON_MENU: return keyboard->pressed(KEY_KEY_D, type); break;
  }
}
