/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/core.h"
#include "../../include/engine/Gamepad.h"
#include "../../include/engine/Game.h"
#include "../../include/engine/EventManager.h"

namespace is06
{
namespace nEngine
{

/**
 * Constructeur de l'interface, ne fait rien de particulier
 */
CGamepad::CGamepad()
{

}

/**
 * Retourne la force d'inclinaison du joystick gauche de la manette
 * @return u8 un entier de la valeur d'inclinaison
 */
u8 CGamepad::getLeftJoystickForce()
{
  return CGame::getEventManager()->getLeftJoystickForce();
}

/**
 * Retourne l'angle d'inclinaison du joystick gauche de la manette
 * @return f32 l'angle en degrés
 */
f32 CGamepad::getLeftJoystickAngle()
{
  return CGame::getEventManager()->getLeftJoystickAngle();
}

/**
 * Retourn la valeur de l'axe X du joystick gauche de la manette
 * @return s8 un entier de la valeur de l'axe entre -128 (gauche) et 127 (droite)
 */
s8 CGamepad::getLeftJoystickXAxis()
{
  return CGame::getEventManager()->getLeftJoystickXAxis();
}

/**
 * Retourn la valeur de l'axe Y du joystick gauche de la manette
 * @return s8 un entier de la valeur de l'axe entre -128 (bas) et 127 (haut)
 */
s8 CGamepad::getLeftJoystickYAxis()
{
  return CGame::getEventManager()->getLeftJoystickYAxis();
}

/**
 * Retourne la force d'inclinaison du joystick droit de la manette
 * @return u8 un entier de la valeur d'inclinaison
 */
u8 CGamepad::getRightJoystickForce()
{
  return CGame::getEventManager()->getRightJoystickForce();
}

/**
 * Retourne l'angle d'inclinaison du joystick droit de la manette
 * @return f32 l'angle en degrés
 */
f32 CGamepad::getRightJoystickAngle()
{
  return CGame::getEventManager()->getRightJoystickAngle();
}

/**
 * Retourn la valeur de l'axe X du joystick droit de la manette
 * @return s8 un entier de la valeur de l'axe entre -128 (gauche) et 127 (droite)
 */
s8 CGamepad::getRightJoystickXAxis()
{
  return CGame::getEventManager()->getRightJoystickXAxis();
}

/**
 * Retourn la valeur de l'axe Y du joystick droit de la manette
 * @return s8 un entier de la valeur de l'axe entre -128 (bas) et 127 (haut)
 */
s8 CGamepad::getRightJoystickYAxis()
{
  return CGame::getEventManager()->getRightJoystickYAxis();
}

/**
 * Détermine si une combinaison de boutons de la manette est actuellement pressée
 * @param u16 buttons la combinaison (addition) de un ou plusieurs boutons spécifiés dans l'enum GamepadButton
 * @return bool si la combinaison spécifiée est bien pressée
 */
bool CGamepad::buttonPressed(u16 buttons, EEventType type)
{
  if (type == EVENT_ONCE) {
    if (!ButtonOnce[buttons]) {
      if (CGame::getEventManager()->getPressedButtons() == buttons) {
        ButtonOnce[buttons] = true;
        return true;
      }
    } else {
      if (CGame::getEventManager()->getPressedButtons() != buttons) {
        ButtonOnce[buttons] = false;
      }
    }
    return false;
  } else {
    return (CGame::getEventManager()->getPressedButtons() == buttons);
  }
}

/**
 * Détermine si une direction précise est appuyée sur la croix directionnelle de la manette
 * @param GamepadDirection direction la direction spécifiée dans l'enum GamepadDirection
 * @return bool si la direction spécifiée est bien appuyée
 */
bool CGamepad::dirPressed(EGamepadDirection direction, EEventType type)
{
  if (type == EVENT_ONCE) {
    if (!DirectionOnce[direction]) {
      if ((s32)CGame::getEventManager()->getPovValue() == direction) {
        DirectionOnce[direction] = true;
        return true;
      }
    } else {
      if ((s32)CGame::getEventManager()->getPovValue() != direction) {
        DirectionOnce[direction] = false;
      }
    }
    return false;
  } else {
    return ((s32)CGame::getEventManager()->getPovValue() == direction);
  }
}

}
}
