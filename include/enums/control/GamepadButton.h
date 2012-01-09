/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_GAMEPAD_BUTTON_H__
#define __IS06_GAMEPAD_BUTTON_H__

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

#endif
