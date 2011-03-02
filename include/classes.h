/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_CLASSES_H__
#define __IS06_CLASSES_H__

class Game;
class EventManager;
class Settings;
class SettingsGroup;

class OpacityShaderCallback;

// =========================================================
// INTERFACES

class Keyboard;
class Mouse;
class Gamepad;

// =========================================================
// SCENES

class Scene;
class SceneGameplay;
//class SceneMenu;
//class SceneStaffRoll;

// =========================================================
// ENTITES

class Entity;

// Interface 2D Joueur
class Hud;
class Counter;
class BarCounter;
class DigitCounter;
class IconCounter;
class Picture;
class Animation;
class Text;
class TextChar;
class TextFont;

class GameplayInterface;
class ButtonsInterface;
class Button;
class TextButton;
class IconButton;
class IconTextButton;
class Menu;
class MenuOption;

// Newton

// Modèles 3D
class ModelEntity;

// Modèles 3D animés
class AnimatedModel;
class Character;
class Ayron;
class NPC;
class Enemy;

// Modèles 3D statiques
class StaticModel;
class LevelMesh;

// Caméras
class Camera;
class TPCamera;

// Lumières
class Light;

// Hauts-parleurs
class Speaker;

#include "Game.h"
#include "Settings.h"
#include "SettingsGroup.h"
#include "EventManager.h"

#include "Keyboard.h"
#include "Gamepad.h"

#include "Scene.h"
#include "SceneGameplay.h"

#include "Entity.h"
#include "ModelEntity.h"
#include "AnimatedModel.h"
#include "Character.h"
#include "Ayron.h"
#include "StaticModel.h"
#include "LevelMesh.h"

#include "Hud.h"
#include "Text.h"
#include "TextChar.h"
#include "TextFont.h"
#include "Picture.h"
#include "GameplayInterface.h"
#include "ButtonsInterface.h"
#include "Button.h"
#include "IconButton.h"
#include "TextButton.h"
#include "IconTextButton.h"
#include "Menu.h"
#include "MenuOption.h"

#include "Camera.h"
#include "TPCamera.h"

#endif
