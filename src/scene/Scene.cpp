/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/Keyboard.h"
#include "../../include/Gamepad.h"
#include "../../include/debug/MapEditor.h"
#include "../../include/Game.h"
#include "../../include/scene/Scene.h"

using namespace irr;
using namespace std;

bool Scene::inMapEditingMode;

/**
 * Initialise un objet Camera ainsi que les interfaces d'�v�nements comme le clavier ou la manette
 */
Scene::Scene() {
  cam = NULL;
  //control = new PlayerControl();

  keyboard = new Keyboard();
  gamepad = new Gamepad();

  timeElapsed = 0.0f;

  mapEditor = new MapEditor();

  globalTranslations = Game::getGlobalTranslations();
}

/**
 * Fonction de test des �v�nements de toutes les sc�nes du jeu
 * (Ev�nements globaux)
 */
void Scene::events() {
  speedFactor = Game::getSpeedFactor();
  timeElapsed += 0.016666666666f;
}

Camera* Scene::getActiveCamera() {
  return cam;
}

void Scene::postRender() {
  if(keyboard->pressed(KEY_F12, EVENT_ONCE)) {
    mapEditor->toggle();
  }
  if(mapEditor->isRunning()) {
    mapEditor->events();
  }
}

/**
 *
 */
Scene::~Scene() {
  Game::getVideoDriver()->removeAllTextures();
  Game::getSceneManager()->getMeshCache()->clear();
  //delete control;
  delete keyboard;
  delete gamepad;
  delete mapEditor;
}
