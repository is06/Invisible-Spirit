/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/Game.h"
#include "../../include/Keyboard.h"
#include "../../include/Gamepad.h"
#include "../../include/Save.h"
#include "../../include/scene/Scene.h"

using namespace irr;
using namespace std;

bool Scene::inMapEditingMode;

/**
 * Instanciate required object interfaces such as keyboard or music so we can
 * use them in all scenes
 */
Scene::Scene()
{
  startTime = Game::getCurrentTime();
  timeElapsed = 0.0f;

  cam = NULL;
  keyboard = new Keyboard();
  gamepad = new Gamepad();
  music = Game::getMusicReference();
  globalTranslations = Game::getGlobalTranslations();
}

/**
 * Event test of all scenes in the game
 * (global events)
 */
void Scene::events()
{
  speedFactor = Game::getSpeedFactor();
  timeElapsed = (Game::getCurrentTime() - startTime) / 1000.0f;
  gameSave->setInteger(11, (u32)timeElapsed); // 11 = Total game time

/*
  if (keyboard->pressed(KEY_CONTROL, EVENT_ONCE) && keyboard->pressed(KEY_KEY_D, EVENT_ONCE)) {
    Game::debugOption.display.hidePostRender = true;
  }
*/
}

void Scene::setSaveSlot(Save* saveSlot)
{
  gameSave = saveSlot;
}

/**
 * Returns current active camera
 * @return Camera*
 */
Camera* Scene::getActiveCamera()
{
  return cam;
}

/**
 * This method is called every cycle after the event test method (or main loop
 * for scenes)
 * This method can handle post render events like map editor
 */
void Scene::postRender()
{

}

/**
 * This destructor removes interfaces and flushes texture and mesh cache
 */
Scene::~Scene()
{
  Game::getVideoDriver()->removeAllTextures();
  Game::getSceneManager()->getMeshCache()->clear();
  delete keyboard;
  delete gamepad;
}
