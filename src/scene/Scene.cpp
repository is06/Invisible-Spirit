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
#include "../../include/save/Save.h"
#include "../../include/scene/Scene.h"
#include "../../include/engine/DialogInterface.h"

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
  sceneTranslations = NULL;
  dialog = NULL;
  keyboard = new Keyboard();
  gamepad = new Gamepad();

  music = Game::getMusicReference();
  globalTranslations = Game::getGlobalTranslations();
  inFader = Game::getDebugGUI()->addInOutFader();
  outFader = Game::getDebugGUI()->addInOutFader();

  //shadows = new ShadowProcessor();
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

/**
 * @todo
 */
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
 *
 */
void Scene::postRender()
{

}

/**
 * This method is called every cycle after the event test method (or main loop
 * for scenes)
 * This method can handle post render events like map editor
 */
void Scene::hudRender()
{
  //shadows->render();

  if (dialog) {
    dialog->render();
  }
}

/**
 * @todo
 */
void Scene::fadeIn(f32 speed, FadeColor color)
{
  inFader->setColor(video::SColor(0, 0, 0, 0));
  inFader->fadeIn(speed * 1000);
}

/**
 * @todo
 */
void Scene::fadeOut(f32 speed, FadeColor color)
{
  outFader->setColor(video::SColor(0, 0, 0, 0));
  outFader->fadeOut(speed * 1000);
}

/**
 * @todo
 */
ShadowProcessor* Scene::getShadowProcessor()
{
  return shadows;
}

/**
 * This destructor removes interfaces and flushes texture and mesh cache
 */
Scene::~Scene()
{
  inFader->remove();
  outFader->remove();

  Game::getVideoDriver()->removeAllTextures();
  Game::getSceneManager()->getMeshCache()->clear();

  if (dialog) {
    delete dialog;
  }

  delete keyboard;
  delete gamepad;

  //delete shadows;
}
