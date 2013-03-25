/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_SCENE_GAMEPLAY_H__
#define __IS06_SCENE_GAMEPLAY_H__

#include "CScene.h"
#include "../Hud/CHudEnsemble.h"
#include "../Hud/CMiniMap.h"
#include "../Hud/CPauseScreen.h"
#include "../Engine/Gameplay/CNPCInterface.h"
#include "../Engine/Gameplay/CMapSectionInterface.h"

namespace is06 { namespace NScene {

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

  N3D::NCharacter::CPlayable*                 Hero;

  NHud::CHudEnsemble*                         HudEnsemble;
  NHud::NEnsemble::CEnergy*                   HudEnergyEnsemble;
  NHud::CMiniMap*                             MiniMap;
  NHud::NCounter::CWorldTime*                 WorldTime;
  NHud::CPauseScreen*                         PauseScreen;

  NEngine::NGameplay::CMapSectionInterface*   MapSections;
  NEngine::NGameplay::CNPCInterface*          NPCInterface;
  NEngine::CTimer*                            EverySecondTimer;

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
