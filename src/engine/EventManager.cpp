/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/core.h"
#include "../../include/engine/EventManager.h"

namespace is06
{
namespace nEngine
{

/**
 * Initializes arrays for key listening
 */
CEventManager::CEventManager() : IEventReceiver()
{
  for (u32 i = 0; i < KEY_KEY_CODES_COUNT; i++) {
    KeyDown[i] = false;
    KeyOnce[i] = false;
  }

  AnyDown = false;
  AnyOnce = false;
}

/**
 * When an Irrlicht event occurs
 * @param SEvent& event event object
 * @return bool true if an event occurs
 */
bool CEventManager::OnEvent(const SEvent& event)
{
  if (event.EventType == EET_KEY_INPUT_EVENT) {
    AnyDown = KeyDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
  } else if (event.EventType == EET_MOUSE_INPUT_EVENT) {
    MouseLeftDown = event.MouseInput.isLeftPressed();
    MouseRightDown = event.MouseInput.isRightPressed();
    MousePosition = core::position2di(event.MouseInput.X, event.MouseInput.Y);
  } else if (event.EventType == EET_GUI_EVENT) {
    GuiEvent = event.GUIEvent;
  } else if (event.EventType == EET_JOYSTICK_INPUT_EVENT) {
    // Axes
    f32 lXAxis = (event.JoystickEvent.Axis[SEvent::SJoystickEvent::AXIS_X] + 100) / 32768.0f;
    f32 lYAxis = ((event.JoystickEvent.Axis[SEvent::SJoystickEvent::AXIS_Y] + 100) / 32768.0f) * -1;
    f32 rXAxis = (event.JoystickEvent.Axis[SEvent::SJoystickEvent::AXIS_U] + 100) / 32768.0f;
    f32 rYAxis = ((event.JoystickEvent.Axis[SEvent::SJoystickEvent::AXIS_R] + 100) / 32768.0f) * -1;

    // @todo: Analog triggers
    //f32 gAxis = event.JoystickEvent.Axis[SEvent::SJoystickEvent::AXIS_Z];

    // D-pad
    PovValue = event.JoystickEvent.POV;

    // Buttons
    ButtonStates = event.JoystickEvent.ButtonStates;

    // Angle calculation
    if (lXAxis != 0) {
      if (lXAxis < 0) {
        LeftJoystickAngle = core::radToDeg(core::PI + atan(lYAxis/lXAxis));
      } else {
        if (lYAxis < 0) {
          LeftJoystickAngle = core::radToDeg(2 * core::PI + atan(lYAxis/lXAxis));
        } else {
          LeftJoystickAngle = core::radToDeg(atan(lYAxis/lXAxis));
        }
      }
    } else {
      LeftJoystickAngle = 0;
    }
    if (rXAxis != 0) {
      if (rXAxis < 0) {
        RightJoystickAngle = core::radToDeg(core::PI + atan(rYAxis/rXAxis));
      } else {
        if (rYAxis < 0) {
          RightJoystickAngle = core::radToDeg(2 * core::PI + atan(rYAxis/rXAxis));
        } else {
          RightJoystickAngle = core::radToDeg(atan(rYAxis/rXAxis));
        }
      }
    } else {
      RightJoystickAngle = 0;
    }

    LeftJoystickXAxis = lXAxis * 127;
    LeftJoystickYAxis = lYAxis * 127;
    RightJoystickXAxis = rXAxis * 127;
    RightJoystickYAxis = rYAxis * 127;

    if (LeftJoystickXAxis > 127) LeftJoystickXAxis = 127;
    if (LeftJoystickXAxis < -127) LeftJoystickXAxis = -127;
    if (LeftJoystickYAxis > 127) LeftJoystickYAxis = 127;
    if (LeftJoystickYAxis < -127) LeftJoystickYAxis = -127;
    if (RightJoystickXAxis > 127) RightJoystickXAxis = 127;
    if (RightJoystickXAxis < -127) RightJoystickXAxis = -127;
    if (RightJoystickYAxis > 127) RightJoystickYAxis = 127;
    if (RightJoystickYAxis < -127) RightJoystickYAxis = -127;

    // Calcul de la force d'inclinaison
    if (fabs(lXAxis) > 0.05f) {
      if (lXAxis > 0) {
        lXAxis = (lXAxis * 255);
      } else {
        lXAxis = (fabs(lXAxis) * 255);
      }
    } else {
      lXAxis = 0;
    }
    if (fabs(lYAxis) > 0.05f) {
      if (lYAxis > 0) {
        lYAxis = (lYAxis * 255);
      } else {
        lYAxis = (fabs(lYAxis) * 255);
      }
    } else {
      lYAxis = 0;
    }
    if (fabs(rXAxis) > 0.05f) {
      if (rXAxis > 0) {
        rXAxis = (rXAxis * 255);
      } else {
        rXAxis = (fabs(rXAxis) * 255);
      }
    } else {
      rXAxis = 0;
    }
    if(fabs(rYAxis) > 0.05f) {
      if (rYAxis > 0) {
        rYAxis = (rYAxis * 255);
      } else {
        rYAxis = (fabs(rYAxis) * 255);
      }
    } else {
      rYAxis = 0;
    }
    if (lXAxis > 255) lXAxis = 255;
    if (lYAxis > 255) lYAxis = 255;
    if (rXAxis > 255) rXAxis = 255;
    if (rYAxis > 255) rYAxis = 255;
    LeftJoystickForce = core::max_(core::round_(lXAxis), core::round_(lYAxis));
    RightJoystickForce = core::max_(core::round_(rXAxis), core::round_(rYAxis));
  }
  return false;
}

/**
 * Tests if a specific key is pressed
 * @param EKEY_CODE code the key code to test
 * @return bool true if key is pressed
 */
bool CEventManager::isKeyDown(EKEY_CODE code)
{
  return KeyDown[code];
}

/**
 * Tests if a specific key is pressed but only one time until key is released
 * @param EKEY_CODE code the key code to test
 * @return bool true if key just has been pressed
 */
bool CEventManager::isKeyDownOnce(EKEY_CODE code)
{
  if (!KeyOnce[code]) {
    if (isKeyDown(code)) {
      KeyOnce[code] = true;
      return true;
    }
  } else {
    if (!isKeyDown(code)) {
      KeyOnce[code] = false;
    }
  }
  return false;
}

/**
 * Tests if any key is pressed
 * @return bool true if any key is pressed
 */
bool CEventManager::anyKeyDown()
{
  return AnyDown;
}

/**
 * Tests if any key is pressed but only one time until key is released
 * @return bool true if any key just has been pressed
 */
bool CEventManager::anyKeyDownOnce()
{
  if (!AnyOnce) {
    if (anyKeyDown()) {
      AnyOnce = true;
      return true;
    }
  } else {
    if (!anyKeyDown()) {
      AnyOnce = false;
    }
  }
  return false;
}

/**
 * Returns the SGUIEvent object of the manager
 * @return SGUIEvent&
 */
const SEvent::SGUIEvent& CEventManager::getGUIEvent()
{
  return GuiEvent;
}

/**
 * @todo
 */
u8 CEventManager::getLeftJoystickForce()
{
  return LeftJoystickForce;
}

/**
 * @todo
 */
f32 CEventManager::getLeftJoystickAngle()
{
  return LeftJoystickAngle;
}

/**
 * @todo
 */
s8 CEventManager::getLeftJoystickXAxis()
{
  return (s8)LeftJoystickXAxis;
}

/**
 * @todo
 */
s8 CEventManager::getLeftJoystickYAxis()
{
  return (s8)LeftJoystickYAxis;
}

/**
 * @todo
 */
u8 CEventManager::getRightJoystickForce()
{
  return RightJoystickForce;
}

/**
 * @todo
 */
f32 CEventManager::getRightJoystickAngle()
{
  return RightJoystickAngle;
}

/**
 * @todo
 */
s8 CEventManager::getRightJoystickXAxis()
{
  return (s8)RightJoystickXAxis;
}

/**
 * @todo
 */
s8 CEventManager::getRightJoystickYAxis()
{
  return (s8)RightJoystickYAxis;
}

/**
 * @todo
 */
u16 CEventManager::getPressedButtons()
{
  return ButtonStates;
}

/**
 * @todo
 */
u32 CEventManager::getPovValue()
{
  return PovValue;
}

/**
 * @todo
 */
bool CEventManager::click()
{
  if (!MouseLeftOnce) {
    if (MouseLeftDown) {
      MouseLeftOnce = true;
      return true;
    }
  } else {
    if (!MouseLeftDown) {
      MouseLeftOnce = false;
    }
  }
  return false;
}

/**
 * @todo
 */
const core::position2di& CEventManager::getMousePosition() const
{
  return MousePosition;
}

}
}
