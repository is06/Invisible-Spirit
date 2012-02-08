/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../include/ref/core.h"
#include "../include/Gamepad.h"
#include "../include/Game.h"
#include "../include/EventManager.h"

using namespace std;

/**
 * Constructeur de l'interface, ne fait rien de particulier
 */
Gamepad::Gamepad()
{

}

/**
 * Retourne la force d'inclinaison du joystick gauche de la manette
 * @return u8 un entier de la valeur d'inclinaison
 */
u8 Gamepad::getLeftJoystickForce()
{
  return Game::getEventManager()->getLeftJoystickForce();
}

/**
 * Retourne l'angle d'inclinaison du joystick gauche de la manette
 * @return f32 l'angle en degrés
 */
f32 Gamepad::getLeftJoystickAngle()
{
  return Game::getEventManager()->getLeftJoystickAngle();
}

/**
 * Retourn la valeur de l'axe X du joystick gauche de la manette
 * @return s8 un entier de la valeur de l'axe entre -128 (gauche) et 127 (droite)
 */
s8 Gamepad::getLeftJoystickXAxis()
{
  return Game::getEventManager()->getLeftJoystickXAxis();
}

/**
 * Retourn la valeur de l'axe Y du joystick gauche de la manette
 * @return s8 un entier de la valeur de l'axe entre -128 (bas) et 127 (haut)
 */
s8 Gamepad::getLeftJoystickYAxis()
{
  return Game::getEventManager()->getLeftJoystickYAxis();
}

/**
 * Retourne la force d'inclinaison du joystick droit de la manette
 * @return u8 un entier de la valeur d'inclinaison
 */
u8 Gamepad::getRightJoystickForce()
{
  return Game::getEventManager()->getRightJoystickForce();
}

/**
 * Retourne l'angle d'inclinaison du joystick droit de la manette
 * @return f32 l'angle en degrés
 */
f32 Gamepad::getRightJoystickAngle()
{
  return Game::getEventManager()->getRightJoystickAngle();
}

/**
 * Retourn la valeur de l'axe X du joystick droit de la manette
 * @return s8 un entier de la valeur de l'axe entre -128 (gauche) et 127 (droite)
 */
s8 Gamepad::getRightJoystickXAxis()
{
  return Game::getEventManager()->getRightJoystickXAxis();
}

/**
 * Retourn la valeur de l'axe Y du joystick droit de la manette
 * @return s8 un entier de la valeur de l'axe entre -128 (bas) et 127 (haut)
 */
s8 Gamepad::getRightJoystickYAxis()
{
  return Game::getEventManager()->getRightJoystickYAxis();
}

/**
 * Détermine si une combinaison de boutons de la manette est actuellement pressée
 * @param u16 buttons la combinaison (addition) de un ou plusieurs boutons spécifiés dans l'enum GamepadButton
 * @return bool si la combinaison spécifiée est bien pressée
 */
bool Gamepad::buttonPressed(u16 buttons, EventType type)
{
  if (type == EVENT_ONCE) {
    if (!buttonOnce[buttons]) {
      if (Game::getEventManager()->getPressedButtons() == buttons) {
        buttonOnce[buttons] = true;
        return true;
      }
    } else {
      if (Game::getEventManager()->getPressedButtons() != buttons) {
        buttonOnce[buttons] = false;
      }
    }
    return false;
  } else {
    return (Game::getEventManager()->getPressedButtons() == buttons);
  }
}

/**
 * Détermine si une direction précise est appuyée sur la croix directionnelle de la manette
 * @param GamepadDirection direction la direction spécifiée dans l'enum GamepadDirection
 * @return bool si la direction spécifiée est bien appuyée
 */
bool Gamepad::dirPressed(GamepadDirection direction, EventType type)
{
  if (type == EVENT_ONCE) {
    if (!directionOnce[direction]) {
      if ((s32)Game::getEventManager()->getPovValue() == direction) {
        directionOnce[direction] = true;
        return true;
      }
    } else {
      if ((s32)Game::getEventManager()->getPovValue() != direction) {
        directionOnce[direction] = false;
      }
    }
    return false;
  } else {
    return ((s32)Game::getEventManager()->getPovValue() == direction);
  }
}
