/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_ENUMS_H__
#define __IS06_ENUMS_H__

/**
 * Types de collision pour associer à un body Newton
 */
enum CollisionType {
  COLLISION_CHARACTER,
  COLLISION_MESH
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

/**
 * Liste des commandes associables à un bouton d'interface joueur
 */
enum CommandIdentifier {
  CMD_FIRE,
  CMD_FIRE2,
  CMD_FIRE3,
  CMD_ICE,
  CMD_ICE2,
  CMD_ICE3
};

/**
 *
 */
enum GameplayControlButtons {
  CB_BUTTON_COMMAND,
  CB_BUTTON_DEFENSE,
  CB_BUTTON_JUMP,
  CB_BUTTON_MENU,
  CB_BUTTON_PAUSE,
  CB_BUTTON_QUIT
};

/**
 *
 */
enum RayType {
  RAY_WALL_P,
  RAY_WALL_Q,
  RAY_FLOOR_A,
  RAY_FLOOR_B,
  RAY_FLOOR_C,
  RAY_FLOOR_D
};

/**
 *
 */
enum MenuStyle {
  MENU_STYLE_TITLE,
  MENU_STYLE_HOME,
  MENU_STYLE_EQUIPMENT
};

/**
 *
 */
enum MenuIcon {
  MENU_ICON_NONE,
  MENU_ICON_BLANK,
  MENU_ICON_SWORD,
  MENU_ICON_SHIELD
};

/**
 *
 */
enum FontStyle {
  FONT_STD_REGULAR
};

/**
 *
 */
enum WindowStyle {
  WIN_STYLE_STD
};

/**
 *
 */
enum BarStyle {
  BAR_STYLE_DEFAULT,
  BAR_STYLE_LIFE
};

enum TimerCallback {
  TIMER_CALLBACK_DEFAULT,
  TIMER_CALLBACK_HELLO,
  TIMER_CALLBACK_NEXT_CHAR
};

enum SceneIdentifier {
  SCENE_MENU,
  SCENE_MAP_ALPHA_ZONE,
  SCENE_MAP_CANYON
};

enum LocaleIdentifier {
  LOCALE_ENG_GB,
  LOCALE_ENG_US,
  LOCALE_FRE_FR,
  LOCALE_FRE_CA,
  LOCALE_FRE_BE,
  LOCALE_FRE_CH,
  LOCALE_GER_DE,
  LOCALE_CAT_ES,
  LOCALE_ITA_IT,
  LOCALE_POR_PT,
  LOCALE_DUT_NL,
  LOCALE_JPN_JP
};

enum ElementType {
  ELMTYPE_MAGIC_FIRE,
  ELMTYPE_MAGIC_ICE,
  ELMTYPE_MAGIC_EARTH,
  ELMTYPE_MAGIC_THUNDER,
  ELMTYPE_MAGIC_WATER,
  ELMTYPE_MAGIC_LIGHT,
  ELMTYPE_MAGIC_DARK,

  ELMTYPE_STATE_STATS,

  ELMTYPE_NEUTRAL
};

#endif
