/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/core.h"
#include "../../include/engine/CGame.h"
#include "../../include/engine/CKeyboard.h"
#include "../../include/engine/CGamepad.h"
#include "../../include/engine/CDialogInterface.h"
#include "../../include/engine/CSave.h"
#include "../../include/model/CModelEntity.h"
#include "../../include/hud/CPicture.h"
#include "../../include/hud/CQuad.h"
#include "../../include/scene/CScene.h"

using namespace irr;

namespace is06
{
namespace nScene
{

bool CScene::InMapEditingMode;

//! Instanciate required object interfaces such as player control or music so we can use them in all scenes
CScene::CScene()
{
  StartTime = nEngine::CGame::getCurrentTime();
  SceneTime = 0.0f;

  Camera = NULL;
  SceneTranslations = NULL;
  Dialog = NULL;
  Sky = NULL;
  Control = new nEngine::CPlayerControl(false);

  Music = nEngine::CGame::getMusicReference();
  GlobalTranslations = nEngine::CGame::getGlobalTranslations();
  InFader = nEngine::CGame::getDebugGUI()->addInOutFader();
  OutFader = nEngine::CGame::getDebugGUI()->addInOutFader();

  // Temporary picture to avoid a strange bug in hud rendering (first picture to render badly positionned)
  Dummy = new nHud::CPicture(-5000, -5000, 0, 0);

  // Cinemascope elements
  Cinemascope = new nHud::CCinemascopeMode();

  //ShadowProcessor = new nEngine::CShadowProcessor(Camera);

  DebugInfo = nEngine::CGame::getDebugGUI()->addStaticText(L"", core::recti(core::vector2di(0, 0), core::vector2di(200, 20)), false, false, 0, 0, false);
  DebugInfo->setOverrideColor(video::SColor(255, 255, 255, 255));
  //DebugConsole = new nDebug::CDebugConsole();

  BackBufferColor = video::SColor(255, 0, 0, 0);
}

//! Event test of all scenes in the game (global events)
void CScene::events()
{
  SpeedFactor = nEngine::CGame::getSpeedFactor();
  SceneTime = (nEngine::CGame::getCurrentTime() - StartTime) / 1000.0f;
  //GameSave->setInteger(11, (u32)SceneTime); // 11 = Total game time

  generateDebugInfo();

  // Debug console
  /*
  DebugConsole->render();
  if (Control->commandEntered(nEngine::ECI_DEBUG_CONSOLE_EXECUTE, nEngine::EET_ONCE)) {
    DebugConsole->executeCurrentCommand();
  }
  */
}

//! Loads all meshes and textures that will be used in the scene
void CScene::loadingSequence()
{

}

//! Displays the generic loading screen (for all type of scene)
void CScene::loadingScreen()
{

}

//! Called when the scene is starting
void CScene::start()
{

}

//! Displays the number of textures and meshes that are currently loaded in the scene
void CScene::generateDebugInfo()
{
  core::stringw debugText = "";
  debugText += "Texture count: ";
  debugText += nEngine::CGame::getVideoDriver()->getTextureCount();
  debugText += "\nMesh count: ";
  debugText += nEngine::CGame::getSceneManager()->getMeshCache()->getMeshCount();

  DebugInfo->setText(debugText.c_str());
}

//! \todo comment this function
void CScene::setSaveSlot(nEngine::CSave* saveSlot)
{
  GameSave = saveSlot;
}

//! Returns current active camera
/**
 * \return Camera*
 */
n3D::CCamera* CScene::getActiveCamera()
{
  return Camera;
}

//! \todo comment this function
void CScene::postRender()
{

}

//! This method is called every cycle after the event test method (or main loop for scenes). This method can handle post render events like map editor
void CScene::hudRender()
{
  Dummy->render();

  // Shadows by shadow mapping
  //ShadowProcessor->render();

  // Cinemascope stripes render
  Cinemascope->render(SpeedFactor);

  // Dialogs render
  if (Dialog) {
    Dialog->render();
  }
}

//! \todo comment this function
void CScene::fadeIn(f32 speed, nEngine::EFadeColor color)
{
  video::SColor irrColor = video::SColor(0, 0, 0, 0);

  switch(color) {
    case nEngine::EFC_WHITE: irrColor = video::SColor(255, 255, 255, 255); break;
    default: irrColor = video::SColor(0, 0, 0, 0); break;
  }

  InFader->setColor(irrColor);
  InFader->fadeIn(speed * 1000);
}

//! \todo comment this function
void CScene::fadeOut(f32 speed, nEngine::EFadeColor color)
{
  video::SColor irrColor = video::SColor(0, 0, 0, 0);

  switch(color) {
    case nEngine::EFC_WHITE: irrColor = video::SColor(255, 255, 255, 255); break;
    default: irrColor = video::SColor(0, 0, 0, 0); break;
  }

  OutFader->setColor(irrColor);
  OutFader->fadeOut(speed * 1000);
}

//! \todo comment this function
nEngine::CShadowProcessor* CScene::getShadowProcessor()
{
  return ShadowProcessor;
}

//! \todo comment this function
const video::SColor& CScene::getBackBufferColor() const
{
  return BackBufferColor;
}

//! This destructor removes interfaces and flushes texture and mesh cache
CScene::~CScene()
{
  InFader->remove();
  OutFader->remove();

  nEngine::CGame::getVideoDriver()->removeAllTextures();
  nEngine::CGame::getSceneManager()->getMeshCache()->clear();

  if (Dialog) {
    delete Dialog;
  }
  if (Sky) {
    delete Sky;
  }

  delete Control;

  delete Dummy;
  delete Cinemascope;

  //delete ShadowProcessor;

  //delete DebugConsole;
}

}
}
