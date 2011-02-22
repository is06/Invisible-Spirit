/**************************************************************************************
Le code source d'Invisible Spirit par Thomas Noury est mis à disposition selon les
termes de la licence Creative Commons Paternité - Pas d'Utilisation Commerciale -
Partage des Conditions Initiales à l'Identique 3.0 Unported.
Basé(e) sur une oeuvre à www.is06.com.  Les autorisations au-delà du champ de
cette licence peuvent être obtenues à http://www.is06.com.
***************************************************************************************/

#ifndef __IS06_ENUMS_H__
#define __IS06_ENUMS_H__

/**
 * Types de collision pour associer à un body Bullet
 */
enum CollisionType {
  COLLISION_BOX,
  COLLISION_SPHERE,
  COLLISION_CYLINDER,
  COLLISION_MESH,

  COLLISION_TYPE_COUNT
};

/**
 * Types d'événements possibles avec les interfaces Keyboard, Mouse et Gamepad
 */
enum EventType {
  EVENT_ALWAYS = false,
  EVENT_ONCE = true
};

/**
 * Liste des commandes boutons disponibles sur l'interface Gamepad
 */
enum GamepadButton {
  GP_BUTTON_A = 1,
  GP_BUTTON_B = 2,
  GP_BUTTON_X = 4,
  GP_BUTTON_Y = 8,
  GP_BUTTON_LB = 16,
  GP_BUTTON_RB = 32,
  GP_BUTTON_BACK = 64,
  GP_BUTTON_START = 128,
  GP_BUTTON_LSTICK = 256,
  GP_BUTTON_RSTICK = 512
};

/**
 * Liste des directions disponibles sur l'interface Gamepad
 */
enum GamepadDirection {
  GP_DIR_TOP = 0,
  GP_DIR_TOP_RIGHT = 4500,
  GP_DIR_RIGHT = 9000,
  GP_DIR_BOTTOM_RIGHT = 13500,
  GP_DIR_BOTTOM = 18000,
  GP_DIR_BOTTOM_LEFT = 22500,
  GP_DIR_LEFT = 27000,
  GP_DIR_TOP_LEFT = 31500
};

#endif
