/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/core.h"
#include "../../include/engine/Game.h"
#include "../../include/engine/Keyboard.h"
#include "../../include/engine/Gamepad.h"
#include "../../include/engine/DialogInterface.h"
#include "../../include/engine/Save.h"
#include "../../include/model/ModelEntity.h"
#include "../../include/hud/Picture.h"
#include "../../include/screen/Scene.h"

namespace is06
{
namespace screen
{

bool CScene::InMapEditingMode;

/**
 * Instanciate required object interfaces such as keyboard or music so we can
 * use them in all scenes
 */
CScene::CScene()
{
  StartTime = engine::CGame::getCurrentTime();
  TimeElapsed = 0.0f;

  Camera = NULL;
  SceneTranslations = NULL;
  Dialog = NULL;
  Keyboard = new engine::CKeyboard();
  Gamepad = new engine::CGamepad();

  Music = engine::CGame::getMusicReference();
  GlobalTranslations = engine::CGame::getGlobalTranslations();
  InFader = engine::CGame::getDebugGUI()->addInOutFader();
  OutFader = engine::CGame::getDebugGUI()->addInOutFader();

  // Temporary picture to avoid a strange bug in hud rendering (first picture to render badly positionned)
  Dummy = new hud::CPicture(-5000, -5000, 0, 0);

  //shadows = new ShadowProcessor();

  DebugInfo = engine::CGame::getDebugGUI()->addStaticText(L"", core::recti(core::vector2di(0, 0), core::vector2di(200, 20)), false, false, 0, 0, false);
  DebugInfo->setOverrideColor(video::SColor(255, 255, 255, 255));

  BackBufferColor = video::SColor(255, 0, 0, 0);
}

/**
 * Event test of all scenes in the game
 * (global events)
 */
void CScene::events()
{
  SpeedFactor = engine::CGame::getSpeedFactor();
  TimeElapsed = (engine::CGame::getCurrentTime() - StartTime) / 1000.0f;
  //gameSave->setInteger(11, (u32)timeElapsed); // 11 = Total game time

  generateDebugInfo();

/*
  if (keyboard->pressed(KEY_CONTROL, EVENT_ONCE) && keyboard->pressed(KEY_KEY_D, EVENT_ONCE)) {
    Game::debugOption.display.hidePostRender = true;
  }
*/
}

void CScene::generateDebugInfo()
{
  core::stringw debugText = "";
  debugText += "Texture count: ";
  debugText += engine::CGame::getVideoDriver()->getTextureCount();
  debugText += "\nMesh count: ";
  debugText += engine::CGame::getSceneManager()->getMeshCache()->getMeshCount();

  DebugInfo->setText(debugText.c_str());
}

/**
 * @todo
 */
void CScene::setSaveSlot(engine::CSave* saveSlot)
{
  GameSave = saveSlot;
}

/**
 * Returns current active camera
 * @return Camera*
 */
model::CCamera* CScene::getActiveCamera()
{
  return Camera;
}

/**
 * @todo
 */
void CScene::postRender()
{
  Dummy->render();
}

/**
 * This method is called every cycle after the event test method (or main loop
 * for scenes)
 * This method can handle post render events like map editor
 */
void CScene::hudRender()
{
  //shadows->render();

  if (Dialog) {
    Dialog->render();
  }
}

/**
 * @todo
 */
void CScene::darkenNonGlowingEntities()
{
  engine::CGame::getSceneManager()->setAmbientLight(video::SColorf(0.0f, 0.0f, 0.0f));

  // @todo : turn off all lights

  for (EntityListIt = EntityList.begin(); EntityListIt != EntityList.end(); EntityListIt++) {
    EntityListIt->first->darken();
  }
}

/**
 * @todo
 */
void CScene::revealNonGlowingEntities()
{
  engine::CGame::getSceneManager()->setAmbientLight(video::SColorf(1.0f, 1.0f, 1.0f));

  // @todo : turn on all lights

  for (EntityListIt = EntityList.begin(); EntityListIt != EntityList.end(); EntityListIt++) {
    EntityListIt->first->undarken();
  }
}

/**
 * @todo
 */
void CScene::addToEntityList(model::CModelEntity* entity)
{
  EntityList[entity] = false;
}

/**
 * @todo
 */
void CScene::fadeIn(f32 speed, engine::EFadeColor color)
{
  InFader->setColor(video::SColor(0, 0, 0, 0));
  InFader->fadeIn(speed * 1000);
}

/**
 * @todo
 */
void CScene::fadeOut(f32 speed, engine::EFadeColor color)
{
  OutFader->setColor(video::SColor(0, 0, 0, 0));
  OutFader->fadeOut(speed * 1000);
}

/**
 * @todo
 */
engine::CShadowProcessor* CScene::getShadowProcessor()
{
  return Shadows;
}

const video::SColor& CScene::getBackBufferColor() const
{
  return BackBufferColor;
}

/**
 * This destructor removes interfaces and flushes texture and mesh cache
 */
CScene::~CScene()
{
  InFader->remove();
  OutFader->remove();

  engine::CGame::getVideoDriver()->removeAllTextures();
  engine::CGame::getSceneManager()->getMeshCache()->clear();

  if (Dialog) {
    delete Dialog;
  }

  delete Keyboard;
  delete Gamepad;
  delete Dummy;

  //delete shadows;
}

}
}
