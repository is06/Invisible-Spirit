/******************************************************************************
Le code source d'Invisible Spirit par Thomas Noury est mis � disposition selon
les termes de la licence Creative Commons Paternit� - Pas d'Utilisation
Commerciale - Partage des Conditions Initiales � l'Identique (BY-NC-SA) 3.0
Unported. Bas�(e) sur une oeuvre � www.is06.com.  Les autorisations au-del� du
champ de cette licence peuvent �tre obtenues � http://www.is06.com.
*******************************************************************************/

#include "../include/core.h"

using namespace std;

/**
 * Constructeur de l'interface, ne fait rien de particulier
 */
Gamepad::Gamepad() {

}

/**
 * Retourne la force d'inclinaison du joystick gauche de la manette
 * @return u8 un entier de la valeur d'inclinaison
 */
u8 Gamepad::getLeftJoystickForce() {
  return Game::getEventManager()->getLeftJoystickForce();
}

/**
 * Retourne l'angle d'inclinaison du joystick gauche de la manette
 * @return f32 l'angle en degr�s
 */
f32 Gamepad::getLeftJoystickAngle() {
  return Game::getEventManager()->getLeftJoystickAngle();
}

/**
 * Retourn la valeur de l'axe X du joystick gauche de la manette
 * @return s8 un entier de la valeur de l'axe entre -128 (gauche) et 127 (droite)
 */
s8 Gamepad::getLeftJoystickXAxis() {
  return Game::getEventManager()->getLeftJoystickXAxis();
}

/**
 * Retourn la valeur de l'axe Y du joystick gauche de la manette
 * @return s8 un entier de la valeur de l'axe entre -128 (bas) et 127 (haut)
 */
s8 Gamepad::getLeftJoystickYAxis() {
  return Game::getEventManager()->getLeftJoystickYAxis();
}

/**
 * Retourne la force d'inclinaison du joystick droit de la manette
 * @return u8 un entier de la valeur d'inclinaison
 */
u8 Gamepad::getRightJoystickForce() {
  return Game::getEventManager()->getRightJoystickForce();
}

/**
 * Retourne l'angle d'inclinaison du joystick droit de la manette
 * @return f32 l'angle en degr�s
 */
f32 Gamepad::getRightJoystickAngle() {
  return Game::getEventManager()->getRightJoystickAngle();
}

/**
 * Retourn la valeur de l'axe X du joystick droit de la manette
 * @return s8 un entier de la valeur de l'axe entre -128 (gauche) et 127 (droite)
 */
s8 Gamepad::getRightJoystickXAxis() {
  return Game::getEventManager()->getRightJoystickXAxis();
}

/**
 * Retourn la valeur de l'axe Y du joystick droit de la manette
 * @return s8 un entier de la valeur de l'axe entre -128 (bas) et 127 (haut)
 */
s8 Gamepad::getRightJoystickYAxis() {
  return Game::getEventManager()->getRightJoystickYAxis();
}

/**
 * D�termine si une combinaison de boutons de la manette est actuellement press�e
 * @param u16 buttons la combinaison (addition) de un ou plusieurs boutons sp�cifi�s dans l'enum GamepadButton
 * @return bool si la combinaison sp�cifi�e est bien press�e
 */
bool Gamepad::buttonPressed(u16 buttons) {
  return (Game::getEventManager()->getPressedButtons() == buttons);
}

/**
 * D�termine si une direction pr�cise est appuy�e sur la croix directionnelle de la manette
 * @param GamepadDirection direction la direction sp�cifi�e dans l'enum GamepadDirection
 * @return bool si la direction sp�cifi�e est bien appuy�e
 */
bool Gamepad::dirPressed(GamepadDirection direction) {
  return ((s32)Game::getEventManager()->getPovValue() == direction);
}
