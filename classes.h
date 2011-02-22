/**************************************************************************************
Le code source d'Invisible Spirit par Thomas Noury est mis à disposition selon les
termes de la licence Creative Commons Paternité - Pas d'Utilisation Commerciale -
Partage des Conditions Initiales à l'Identique 3.0 Unported.
Basé(e) sur une oeuvre à www.is06.com.  Les autorisations au-delà du champ de
cette licence peuvent être obtenues à http://www.is06.com.
***************************************************************************************/

#ifndef __IS06_CLASSES_H__
#define __IS06_CLASSES_H__

class Game;
class EventManager;

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
class HUDEntity;
class Counter;
class BarCounter;
class DigitCounter;
class IconCounter;

// Newton

// Modèles 3D
class ModelEntity;

// Modèles 3D animés
class AnimatedModel;
class Character;
class PlayableCharacter;
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

#include "EventManager.h"

#include "Keyboard.h"
#include "Gamepad.h"

#include "Scene.h"
#include "SceneGameplay.h"

#include "Entity.h"
#include "ModelEntity.h"
#include "AnimatedModel.h"
#include "Character.h"
#include "PlayableCharacter.h"
#include "Ayron.h"
#include "StaticModel.h"
#include "LevelMesh.h"

#include "Camera.h"
#include "TPCamera.h"

#endif
