/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_CLASSES_H__
#define __IS06_CLASSES_H__

// Main classes
class Game;
class EventManager;
class Settings;
class SettingsGroup;
class Timer;
class Translation;
class Entity;
class Save;
class Keyboard;
class Mouse;
class Gamepad;

// Scnees
class Scene;
class SceneGameplay;
class SceneMenu;

// GUI
class Hud;
class Hud2DElement;
class Counter;
class BarCounter;
class DigitCounter;
class IconCounter;
class Picture;
class Animation;
class Text;
class TextChar;
class TextFont;
class Window;
class GameplayInterface;
class ButtonsInterface;
class Button;
class TextButton;
class IconButton;
class IconTextButton;
class Menu;
class MenuOption;
class GameplayMenu;
class MainStateInfo;
class CapacityInfo;
class PlayerState;

// 3D
class ModelEntity;
class AnimatedModel;
class Character;
class Ayron;
class NPC;
class Enemy;
class StaticModel;
class LevelMesh;
class Camera;
class TPCamera;
class Light;
class Speaker;

// Shaders
class OpacityShaderCallback;
class PostRenderGlow;

// Sound
class SoundManager;

// Main classes
#include "../Game.h"
#include "../Settings.h"
#include "../SettingsGroup.h"
#include "../EventManager.h"
#include "../Translation.h"
#include "../Timer.h"
#include "../Entity.h"
#include "../Save.h"
#include "../Keyboard.h"
#include "../Gamepad.h"

// Scenes
#include "../scene/Scene.h"
#include "../scene/SceneMenu.h"
#include "../scene/SceneGameplay.h"

// GUI
#include "../gui/Hud.h"
#include "../gui/Hud2DElement.h"
#include "../gui/Text.h"
#include "../gui/TextChar.h"
#include "../gui/TextFont.h"
#include "../gui/Picture.h"
#include "../gui/Counter.h"
#include "../gui/BarCounter.h"
#include "../gui/GameplayInterface.h"
#include "../gui/ButtonsInterface.h"
#include "../gui/Button.h"
#include "../gui/IconButton.h"
#include "../gui/TextButton.h"
#include "../gui/IconTextButton.h"
#include "../gui/Menu.h"
#include "../gui/MenuOption.h"
#include "../gui/Window.h"
#include "../gui/MainStateInfo.h"
#include "../gui/CapacityInfo.h"
#include "../gui/PlayerState.h"
#include "../gui/GameplayMenu.h"

// 3D
#include "../3d/ModelEntity.h"
#include "../3d/AnimatedModel.h"
#include "../3d/Character.h"
#include "../3d/Ayron.h"
#include "../3d/StaticModel.h"
#include "../3d/LevelMesh.h"
#include "../3d/Camera.h"
#include "../3d/TPCamera.h"

// Shaders
#include "../shader/PostRenderGlow.h"

// Sound
#include "../sound/SoundManager.h"

#endif
