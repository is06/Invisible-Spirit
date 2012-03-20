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
class EngineException;
class EventManager;
class Settings;
class SettingsGroup;
class Timer;
class Translation;
class Entity;
class Save;
class SaveSlot;
class SaveFile;
class Keyboard;
class Mouse;
class Gamepad;

// Engine classes
class DialogInterface;

// Debug classes
class MapEditor;
class ColorProperty;

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
class GameTimeCounter;
class WorldTimeCounter;
class TargetLifeMeter;
class IconCounter;
class Picture;
class Animation;
class Text;
class TextChar;
class TextFont;
class Window;
class GameplayInterface;
class EnergyInterface;
class ButtonsInterface;
class Button;
class TextButton;
class IconButton;
class IconTextButton;
class Menu;
class MenuOption;
class GameplayMenu;
class DimensionMenu;
class ItemMenu;
class MapMenu;
class MonstersMenu;
class SettingsMenu;
class SpiritMenu;
class StatusMenu;
class TalesMenu;
class WeaponMenu;
class MainStateInfo;
class CapacityInfo;
class PlayerState;

// 3D
class ModelEntity;
class AnimatedModel;
class StaticModel;
class LevelMesh;
class Camera;
class TPCamera;
class Light;
class DirectLight;
class OmniLight;
class Sensor;
class PlaneSensor;
class BoxSensor;

// Characters
class Character;
class PlayableCharacter;
class NPC;

// Enemies
class Enemy;
class FloorEnemy;
class AirEnemy;

// Shaders
class DiffuseShaderCallback;
class PostRenderSurface;

// Sound
class SoundManager;
class Speaker;
class MusicReference;
class Music;
class MusicSequence;

#endif
