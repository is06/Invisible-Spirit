/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"

using namespace irr;
using namespace std;

bool Scene::inMapEditingMode;

/**
 * Initialise un objet Camera ainsi que les interfaces d'événements comme le clavier ou la manette
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
 * Fonction de test des événements de toutes les scènes du jeu
 * (Evénements globaux)
 */
void Scene::events() {
  speedFactor = Game::getSpeedFactor();
  timeElapsed += 0.016666666666f;
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
