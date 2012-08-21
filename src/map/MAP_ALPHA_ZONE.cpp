/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/core.h"
#include "../../include/engine/CGame.h"
#include "../../include/engine/CKeyboard.h"
#include "../../include/engine/CTranslation.h"
#include "../../include/3d/CLevelMesh.h"
#include "../../include/3d/CPlayableCharacter.h"
#include "../../include/3d/COmniLight.h"
#include "../../include/3d/CDirectLight.h"
#include "../../include/3d/CTeleporter.h"
#include "../../include/3d/CNPC.h"
#include "../../include/engine/CDialogInterface.h"
#include "../../include/sound/CMusicReference.h"
#include "../../include/sound/CSpeaker.h"
#include "../../include/map/MAP_ALPHA_ZONE.h"

using namespace irr;

namespace is06
{
namespace nMap
{

//! Alpha Zone constructor
MAP_ALPHA_ZONE::MAP_ALPHA_ZONE() : nScene::CSceneGameplay()
{
  // Main Player
  Hero->setCharacter(nEngine::EPCT_AYRON);

  // Local Translations
  SceneTranslations = new nEngine::CTranslation("MAP_ALPHA_ZONE.ist");

  // Map Section Mesh
  loadMapSection("alphazone", "main", core::vector3df(0.0f, 0.0f, 0.0f));

  // Multi-layers music example
  //music->play("bodhum");
  //music->unmuteSequence("bodhum", 1);
  //music->muteSequence("bodhum", 2);

  // 3D Speaker example
  //spk = new Speaker(STREAM_TEST, core::vector3df(0,1,0), "hola", 10);

  // Omni Light example
  //lt = new OmniLight();

  // Dialogs
  Dialog = new nEngine::CDialogInterface("MAP_ALPHA_ZONE.isd", SceneTranslations, Control);

  // Glow shader example
  //glowShader = new PostRenderGlow();
  //addToEntityList(level);

  // Direct Light
  DLight = n3D::CDirectLight::create();
  ShadowProcessor->addDirectLight(DLight);

  // Hud
  MiniMap->setMap(nHud::EMMI_ALPHA_ZONE);
  MiniMap->setWorldSize(120.0f);

  // Simple Skybox
  // TODO: Dynamic skybox with day/light system
  setSkyBox("test");

  // Cinemascope mode (black stripes)
  //Cinemascope->slideIn(1.0f);

  //ToDungeonSensor = new n3D::CTeleporter(10.0f, 10.0f, 1.0f, core::vector3df(0.0f, 0.0f, 0.0f), nScene::ESI_MAP_DUNGEON_1);

  // NPC creation
  NPC1 = new n3D::CNPC();
  // Add NPC to the interface -> Hero will be able to speak to the NPC
  NPCInterface->addNPC(NPC1);
}

//! Alpha Zone events
void MAP_ALPHA_ZONE::events()
{
  nScene::CSceneGameplay::events();




  /*
  if (Hero->collidesWithSensor(ToDungeonSensor)) {
    nEngine::CGame::changeScene(nScene::ESI_MAP_DUNGEON_1);
  }
  */

  // Dialogs interface
  /*
  // Start a dialog
  if (Control->commandEntered(nEngine::ECI_PLAYER_GUARD, nEngine::EET_ONCE)) {
    Dialog->start("norya_first_start");
  }
  // Trigger when a dialog finishes
  if (Dialog->finished()) {

  }
  */

  // Object rendering
  //spk->render();
  //lt->render();

  // Multi-layer music events
  // When pressing W, sequence 1 (normal) is played
  /*
  if (Keyboard->pressed(KEY_KEY_W, nEngine::EVENT_ONCE)) {
    Music->unmuteSequence("bodhum", 1);
    Music->muteSequence("bodhum", 2);
  }
  // When pressing X, sequence 2 (aggressive mix) is played
  if (Keyboard->pressed(KEY_KEY_X, nEngine::EVENT_ONCE)) {
    Music->unmuteSequence("bodhum", 2);
    Music->muteSequence("bodhum", 1);
  }
  */
}

//! Post-rendering (example: glow shader)
void MAP_ALPHA_ZONE::postRender()
{
  nScene::CSceneGameplay::postRender();

  //glowShader->render();
}

//! Player HUD render
void MAP_ALPHA_ZONE::hudRender()
{
  nScene::CSceneGameplay::hudRender();
}

//! Delete all created pointers
MAP_ALPHA_ZONE::~MAP_ALPHA_ZONE()
{
  // Level Mesh collision clear
  Level[0]->clearMeshCollision();

  delete NPC1;

  // 3D Speaker deletion
  //delete spk;

  // Omni Light deletion
  //delete lt;

  // Glow shader deletion
  //delete glowShader;

  //delete ToDungeonSensor;
}

}
}
