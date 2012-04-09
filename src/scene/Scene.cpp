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
#include "../../include/3d/ModelEntity.h"
#include "../../include/gui/Picture.h"
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

  // Temporary picture to avoid a strange bug in hud rendering (first picture to render badly positionned)
  dummy = new Picture(-5000, -5000, 0, 0);

  //shadows = new ShadowProcessor();

  debugInfo = Game::getDebugGUI()->addStaticText(L"", core::recti(core::vector2di(0, 0), core::vector2di(200, 20)), false, false, 0, 0, false);
  debugInfo->setOverrideColor(video::SColor(255, 255, 255, 255));

  backBufferColor = video::SColor(255, 0, 0, 0);
}

/**
 * Event test of all scenes in the game
 * (global events)
 */
void Scene::events()
{
  speedFactor = Game::getSpeedFactor();
  timeElapsed = (Game::getCurrentTime() - startTime) / 1000.0f;
  //gameSave->setInteger(11, (u32)timeElapsed); // 11 = Total game time

  generateDebugInfo();

/*
  if (keyboard->pressed(KEY_CONTROL, EVENT_ONCE) && keyboard->pressed(KEY_KEY_D, EVENT_ONCE)) {
    Game::debugOption.display.hidePostRender = true;
  }
*/
}

void Scene::generateDebugInfo()
{
  core::stringw debugText = "";
  debugText += "Texture count: ";
  debugText += Game::getVideoDriver()->getTextureCount();
  debugText += "\nMesh count: ";
  debugText += Game::getSceneManager()->getMeshCache()->getMeshCount();

  debugInfo->setText(debugText.c_str());
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
 * @todo
 */
void Scene::postRender()
{
  dummy->render();
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
void Scene::darkenNonGlowingEntities()
{
  Game::getSceneManager()->setAmbientLight(video::SColorf(0.0f, 0.0f, 0.0f));

  // @todo : turn off all lights

  for (entityListIt = entityList.begin(); entityListIt != entityList.end(); entityListIt++) {
    entityListIt->first->darken();
  }
}

/**
 * @todo
 */
void Scene::revealNonGlowingEntities()
{
  Game::getSceneManager()->setAmbientLight(video::SColorf(1.0f, 1.0f, 1.0f));

  // @todo : turn on all lights

  for (entityListIt = entityList.begin(); entityListIt != entityList.end(); entityListIt++) {
    entityListIt->first->undarken();
  }
}

/**
 * @todo
 */
void Scene::addToEntityList(ModelEntity* entity)
{
  entityList[entity] = false;
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

const video::SColor& Scene::getBackBufferColor() const
{
  return backBufferColor;
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
  delete dummy;

  //delete shadows;
}
