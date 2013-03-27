/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/core.h"
#include "../../include/NEngine/NCore/CGame.h"
#include "../../include/NEngine/NControl/CKeyboard.h"
#include "../../include/NEngine/NControl/CGamepad.h"
#include "../../include/NEngine/NGameplay/CDialogInterface.h"
#include "../../include/NEngine/NSave/CSave.h"
#include "../../include/N3D/NPrimitive/CModelEntity.h"
#include "../../include/NHud/NPrimitive/CPicture.h"
#include "../../include/NHud/NPrimitive/CQuad.h"
#include "../../include/NScene/CScene.h"

using namespace irr;

namespace is06 { namespace NScene {

//! Instanciate required object interfaces such as player control or music so we can use them in all scenes
CScene::CScene()
{
  StartTime = NEngine::NCore::CGame::getCurrentTime();
  SceneTime = 0.0f;

  Camera = NULL;
  SceneTranslations = NULL;
  Dialog = NULL;
  Sky = NULL;
  Control = new NEngine::NControl::CPlayerControl(false);

  Music = NEngine::NCore::CGame::getMusicReference();
  GlobalTranslations = NEngine::NCore::CGame::getGlobalTranslations();
  InFader = NEngine::NCore::CGame::getDebugGUI()->addInOutFader();
  OutFader = NEngine::NCore::CGame::getDebugGUI()->addInOutFader();

  // Temporary picture to avoid a strange bug in hud rendering (first picture to render badly positionned)
  Dummy = new NHud::NPrimitive::CPicture(-5000, -5000, 0, 0);

  // Cinemascope elements
  Cinemascope = new NHud::NPart::CCinemascopeMode();

  //ShadowProcessor = new NEngine::CShadowProcessor(Camera);

  DebugInfo = NEngine::NCore::CGame::getDebugGUI()->addStaticText(L"", core::recti(core::vector2di(0, 0), core::vector2di(200, 20)), false, false, 0, 0, false);
  DebugInfo->setOverrideColor(video::SColor(255, 255, 255, 255));
  //DebugConsole = new NDebug::CDebugConsole();

  BackBufferColor = video::SColor(255, 0, 0, 0);
}

//! Event test of all scenes in the game (global events)
void CScene::events()
{
  SpeedFactor = NEngine::NCore::CGame::getSpeedFactor();
  SceneTime = (NEngine::NCore::CGame::getCurrentTime() - StartTime) / 1000.0f;
  //GameSave->setInteger(11, (u32)SceneTime); // 11 = Total game time

  generateDebugInfo();

  // Debug console
  /*
  DebugConsole->render();
  if (Control->commandEntered(NEngine::ECI_DEBUG_CONSOLE_EXECUTE, NEngine::NEvent::EET_ONCE)) {
    DebugConsole->executeCurrentCommand();
  }
  */
}

//! Loads all meshes and textures that will be used in the scene
void CScene::loadingSequence()
{

}

//! Displays the generic loading screen (for all type of scene)
void CScene::startLoadingScreen()
{

}

//! Hides the generic loading screen
void CScene::stopLoadingScreen()
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
  debugText += NEngine::NCore::CGame::getVideoDriver()->getTextureCount();
  debugText += "\nMesh count: ";
  debugText += NEngine::NCore::CGame::getSceneManager()->getMeshCache()->getMeshCount();

  DebugInfo->setText(debugText.c_str());
}

//! \todo comment this function
void CScene::setSaveSlot(NEngine::NSave::CSave* saveSlot)
{
  GameSave = saveSlot;
}

//! Returns current active camera
/**
 * \return Camera*
 */
N3D::NCamera::CCamera* CScene::getActiveCamera()
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

NScene::ELoadingStatus CScene::getLoadingStatus()
{
  return LoadingStatus;
}

void CScene::setLoadingStatus(NScene::ELoadingStatus status)
{
  LoadingStatus = status;
}

//! \todo comment this function
void CScene::fadeIn(f32 speed, NHud::NPrimitive::EFadeColor color)
{
  video::SColor irrColor = video::SColor(0, 0, 0, 0);

  switch(color) {
    case NHud::NPrimitive::EFC_WHITE: irrColor = video::SColor(255, 255, 255, 255); break;
    default: irrColor = video::SColor(0, 0, 0, 0); break;
  }

  InFader->setColor(irrColor);
  InFader->fadeIn(speed * 1000);
}

//! \todo comment this function
void CScene::fadeOut(f32 speed, NHud::NPrimitive::EFadeColor color)
{
  video::SColor irrColor = video::SColor(0, 0, 0, 0);

  switch(color) {
    case NHud::NPrimitive::EFC_WHITE: irrColor = video::SColor(255, 255, 255, 255); break;
    default: irrColor = video::SColor(0, 0, 0, 0); break;
  }

  OutFader->setColor(irrColor);
  OutFader->fadeOut(speed * 1000);
}

//! \todo comment this function
NShader::CShadowProcessor* CScene::getShadowProcessor()
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

  NEngine::NCore::CGame::getVideoDriver()->removeAllTextures();
  NEngine::NCore::CGame::getSceneManager()->getMeshCache()->clear();

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

}}
