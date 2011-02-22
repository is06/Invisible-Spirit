/**************************************************************************************
Le code source d'Invisible Spirit par Thomas Noury est mis à disposition selon les
termes de la licence Creative Commons Paternité - Pas d'Utilisation Commerciale -
Partage des Conditions Initiales à l'Identique 3.0 Unported.
Basé(e) sur une oeuvre à www.is06.com.  Les autorisations au-delà du champ de
cette licence peuvent être obtenues à http://www.is06.com.
***************************************************************************************/

#include "core.h"

using namespace std;
using namespace irr;

/**
 * Initialise l'objet
 */
EventManager::EventManager() : IEventReceiver() {
  for(u32 i = 0; i < KEY_KEY_CODES_COUNT; i++) {
    keyDown[i] = false;
    keyOnce[i] = false;
  }

  anyDown = false;
  anyOnce = false;
}

/**
 * Se produit lorsqu'un événement Irrlicht se produit
 * @param SEvent& event l'objet SEvent de l'événement actif
 * @return bool si un événement se produit
 */
bool EventManager::OnEvent(const SEvent& event) {
  if(event.EventType == EET_KEY_INPUT_EVENT) {
    anyDown = keyDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
  } else if(event.EventType == EET_MOUSE_INPUT_EVENT) {
    mouseLeftDown = event.MouseInput.isLeftPressed();
    mouseRightDown = event.MouseInput.isRightPressed();
    mousePosition = core::position2di(event.MouseInput.X, event.MouseInput.Y);
  } else if(event.EventType == EET_JOYSTICK_INPUT_EVENT) {
    // Axes
    f32 lXAxis = (event.JoystickEvent.Axis[SEvent::SJoystickEvent::AXIS_X] + 100) / 32768.0f;
    f32 lYAxis = ((event.JoystickEvent.Axis[SEvent::SJoystickEvent::AXIS_Y] + 100) / 32768.0f) * -1;
    f32 rXAxis = (event.JoystickEvent.Axis[SEvent::SJoystickEvent::AXIS_U] + 100) / 32768.0f;
    f32 rYAxis = ((event.JoystickEvent.Axis[SEvent::SJoystickEvent::AXIS_R] + 100) / 32768.0f) * -1;

    // Croix multidirectionnelle
    povValue = event.JoystickEvent.POV;

    // Boutons
    buttonStates = event.JoystickEvent.ButtonStates;

    // Calcul de l'angle
    if(lXAxis != 0) {
      if(lXAxis < 0) leftJoystickAngle = core::radToDeg(core::PI + atan(lYAxis/lXAxis));
      else {
        if(lYAxis < 0) leftJoystickAngle = core::radToDeg(2*core::PI + atan(lYAxis/lXAxis));
        else leftJoystickAngle = core::radToDeg(atan(lYAxis/lXAxis));
      }
    } else {
      leftJoystickAngle = 0;
    }
    if(rXAxis != 0) {
      if(rXAxis < 0) rightJoystickAngle = core::radToDeg(core::PI + atan(rYAxis/rXAxis));
      else {
        if(rYAxis < 0) rightJoystickAngle = core::radToDeg(2*core::PI + atan(rYAxis/rXAxis));
        else rightJoystickAngle = core::radToDeg(atan(rYAxis/rXAxis));
      }
    } else {
      rightJoystickAngle = 0;
    }

    leftJoystickXAxis = lXAxis * 127;
    leftJoystickYAxis = lYAxis * 127;
    rightJoystickXAxis = rXAxis * 127;
    rightJoystickYAxis = rYAxis * 127;

    if(leftJoystickXAxis > 127) leftJoystickXAxis = 127;
    if(leftJoystickXAxis < -127) leftJoystickXAxis = -127;
    if(leftJoystickYAxis > 127) leftJoystickYAxis = 127;
    if(leftJoystickYAxis < -127) leftJoystickYAxis = -127;
    if(rightJoystickXAxis > 127) rightJoystickXAxis = 127;
    if(rightJoystickXAxis < -127) rightJoystickXAxis = -127;
    if(rightJoystickYAxis > 127) rightJoystickYAxis = 127;
    if(rightJoystickYAxis < -127) rightJoystickYAxis = -127;

    // Calcul de la force d'inclinaison
    if(fabs(lXAxis) > 0.05f) {
      if(lXAxis > 0) lXAxis = (lXAxis * 255);
      else lXAxis = (fabs(lXAxis) * 255);
    } else {
      lXAxis = 0;
    }
    if(fabs(lYAxis) > 0.05f) {
      if(lYAxis > 0) lYAxis = (lYAxis * 255);
      else lYAxis = (fabs(lYAxis) * 255);
    } else {
      lYAxis = 0;
    }
    if(fabs(rXAxis) > 0.05f) {
      if(rXAxis > 0) rXAxis = (rXAxis * 255);
      else rXAxis = (fabs(rXAxis) * 255);
    } else {
      rXAxis = 0;
    }
    if(fabs(rYAxis) > 0.05f) {
      if(rYAxis > 0) rYAxis = (rYAxis * 255);
      else rYAxis = (fabs(rYAxis) * 255);
    } else {
      rYAxis = 0;
    }
    if(lXAxis > 255) lXAxis = 255;
    if(lYAxis > 255) lYAxis = 255;
    if(rXAxis > 255) rXAxis = 255;
    if(rYAxis > 255) rYAxis = 255;
    leftJoystickForce = core::max_(core::round_(lXAxis), core::round_(lYAxis));
    rightJoystickForce = core::max_(core::round_(rXAxis), core::round_(rYAxis));
  }
  return false;
}

/**
 *
 */
bool EventManager::isKeyDown(EKEY_CODE code) {
  return keyDown[code];
}

bool EventManager::isKeyDownOnce(EKEY_CODE code) {
  if(!keyOnce[code]) {
    if(isKeyDown(code)) {
      keyOnce[code] = true;
      return true;
    }
  } else {
    if(!isKeyDown(code)) {
      keyOnce[code] = false;
    }
  }
  return false;
}

bool EventManager::anyKeyDown() {
  return anyDown;
}

bool EventManager::anyKeyDownOnce() {
  if(!anyOnce) {
    if(anyKeyDown()) {
      anyOnce = true;
      return true;
    }
  } else {
    if(!anyKeyDown()) {
      anyOnce = false;
    }
  }
  return false;
}

u8 EventManager::getLeftJoystickForce() {
  return leftJoystickForce;
}

f32 EventManager::getLeftJoystickAngle() {
  return leftJoystickAngle;
}

s8 EventManager::getLeftJoystickXAxis() {
  return (s8)leftJoystickXAxis;
}

s8 EventManager::getLeftJoystickYAxis() {
  return (s8)leftJoystickYAxis;
}

u8 EventManager::getRightJoystickForce() {
  return rightJoystickForce;
}

f32 EventManager::getRightJoystickAngle() {
  return rightJoystickAngle;
}

s8 EventManager::getRightJoystickXAxis() {
  return (s8)rightJoystickXAxis;
}

s8 EventManager::getRightJoystickYAxis() {
  return (s8)rightJoystickYAxis;
}

u16 EventManager::getPressedButtons() {
  return buttonStates;
}

u32 EventManager::getPovValue() {
  return povValue;
}

bool EventManager::click() {
  if(!mouseLeftOnce) {
    if(mouseLeftDown) {
      mouseLeftOnce = true;
      return true;
    }
  } else {
    if(!mouseLeftDown) {
      mouseLeftOnce = false;
    }
  }
  return false;
}

const core::position2di& EventManager::getMousePosition() const {
  return mousePosition;
}

