/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_SCENE_SCENE_GAMEPLAY_H__
#define __IS06_SCENE_SCENE_GAMEPLAY_H__

#include "CScene.h"
#include "../NHud/NPart/CHudPart.h"
#include "../NHud/NPart/CMiniMap.h"
#include "../NHud/NPauseScreen/CPauseScreen.h"
#include "../NEngine/NGameplay/CNPCInterface.h"
#include "../NEngine/NGameplay/CMapSectionInterface.h"

namespace is06 { namespace NScene {

//! All gameplay scenes
class CSceneGameplay : public CScene
{
public:
  CSceneGameplay();
  virtual ~CSceneGameplay();
  virtual void events();
  virtual void postRender();
  virtual void hudRender();
  virtual void loadingSequence();
  virtual void start();

  void loadingScreen();

protected:
  virtual void everySecond();

  N3D::NCharacter::CPlayableCharacter* Hero;

  NHud::NPart::CHudPart* HudEnsemble;
  NHud::NPart::CEnergy* HudEnergyEnsemble;
  NHud::NPart::CMiniMap* MiniMap;
  NHud::NCounter::CWorldTime* WorldTime;
  NHud::NPauseScreen::CPauseScreen* PauseScreen;

  NEngine::NGameplay::CMapSectionInterface* MapSections;
  NEngine::NGameplay::CNPCInterface* NPCInterface;
  NEngine::NTime::CTimer* EverySecondTimer;

private:
  void manageCameraControl();
  void manageCharacterJumps();
  void manageCharacterMovements();
  void manageCharacterCollisions();
  void manageCharacterNPCInteraction();
  void manageMenuControl();
  void switchLevelMeshes();

  bool QuitIsFading;
};

}}

#endif
