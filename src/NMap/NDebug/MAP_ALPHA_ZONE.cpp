/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/Engine/core.h"
#include "../../../include/Engine/CGame.h"
#include "../../../include/Engine/Control/CKeyboard.h"
#include "../../../include/Engine/Resource/CTranslation.h"
#include "../../../include/3D/CLevelMesh.h"
#include "../../../include/3D/Character/CPlayable.h"
#include "../../../include/3D/Light/COmni.h"
#include "../../../include/3D/Light/CDirect.h"
#include "../../../include/3D/Sensor/CTeleporter.h"
#include "../../../include/3D/Character/CNPC.h"
#include "../../../include/Engine/Gameplay/CDialogInterface.h"
#include "../../../include/Sound/CMusicReference.h"
#include "../../../include/Sound/CSpeaker.h"
#include "../../../include/Map/Debug/MAP_ALPHA_ZONE.h"

using namespace irr;

namespace is06
{
namespace NMap
{
namespace NDebug
{

//! Alpha Zone constructor
MAP_ALPHA_ZONE::MAP_ALPHA_ZONE() : NScene::CSceneGameplay()
{
  // Main Player
  Hero->setCharacter(NEngine::NGameplay::EPCT_CUBE);

  // Local Translations
  SceneTranslations = new NEngine::NResource::CTranslation("MAP_ALPHA_ZONE.ist");

  // Map Section Mesh
  MapSections->loadSection("alphazone", "main", core::vector3df(0.0f, 0.0f, 0.0f));

  // Multi-layers music example
  //Music->play("bodhum");
  //Music->unmuteSequence("bodhum", 1);
  //Music->muteSequence("bodhum", 2);

  // 3D Speaker example
  //Spk = new NSound::CSpeaker("path/to/a/file", core::vector3df(0,1,0), "speaker_debug_text", 10);

  // Omni Light example
  //Lt = new N3D::COmniLight();

  // Scene dialog loading
  Dialog = new NEngine::NGameplay::CDialogInterface("MAP_ALPHA_ZONE.isd", SceneTranslations, Control);

  // Glow shader example
  //GlowShader = new NShader::CPostRenderGlow();
  //GlowShader->addEntityForEffect(MapSections->getSection(0), NShader::EFFECT_DARKEN);
  //GlowShader->addEntityForEffect(Hero, NShader::EFFECT_DARKEN);

  // Direct Light (spot with shadow map system, work in progress)
  // This one is buggy: we don't see the meshes
  //DLight = N3D::CDirectLight::create();
  //ShadowProcessor->addDirectLight(DLight);

  // Hud
  MiniMap->setMap(NHud::EMMI_ALPHA_ZONE);
  MiniMap->setWorldSize(120.0f);

  // Sky (3d box)
  Sky = new N3D::CSky("test");

  // Cinemascope mode (black stripes)
  //Cinemascope->slideIn(1.0f);

  // Teleporter example
  // This teleporter moves the hero to another map (dungeon 1)
  //ToDungeonSensor = new N3D::CTeleporter(10.0f, 10.0f, 1.0f, core::vector3df(0.0f, 0.0f, 0.0f), NScene::ESI_MAP_DUNGEON_1);

  // NPC creation
  //NPC1 = new N3D::CNPC();
  // Add NPC to the interface -> Hero will be able to speak to the NPC
  //NPCInterface->addNPC(NPC1);
}

void MAP_ALPHA_ZONE::loadingSequence()
{
  NScene::CSceneGameplay::loadingSequence();
}

void MAP_ALPHA_ZONE::start()
{
  NScene::CSceneGameplay::start();
  //cout << "Loading sequence finished, scene started" << endl;
}

//! Alpha Zone events
void MAP_ALPHA_ZONE::events()
{
  NScene::CSceneGameplay::events();

  /*
  if (Hero->collidesWithSensor(ToDungeonSensor)) {
    NEngine::CGame::changeScene(NScene::ESI_MAP_DUNGEON_1);
  }
  */

  // Dialogs interface
  /*
  // Start a dialog
  if (Control->commandEntered(NEngine::ECI_PLAYER_GUARD, NEngine::EET_ONCE)) {
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
  if (Keyboard->pressed(KEY_KEY_W, NEngine::EVENT_ONCE)) {
    Music->unmuteSequence("bodhum", 1);
    Music->muteSequence("bodhum", 2);
  }
  // When pressing X, sequence 2 (aggressive mix) is played
  if (Keyboard->pressed(KEY_KEY_X, NEngine::EVENT_ONCE)) {
    Music->unmuteSequence("bodhum", 2);
    Music->muteSequence("bodhum", 1);
  }
  */
}

//! Post-rendering (example: glow shader)
void MAP_ALPHA_ZONE::postRender()
{
  NScene::CSceneGameplay::postRender();
  //GlowShader->render();
}

//! Player HUD render
void MAP_ALPHA_ZONE::hudRender()
{
  NScene::CSceneGameplay::hudRender();
}

//! Delete all created pointers
MAP_ALPHA_ZONE::~MAP_ALPHA_ZONE()
{
  // Level Mesh collision clear
  MapSections->clearMeshCollision(0);

  //delete NPC1;
  //delete Spk;
  //delete Lt;
  //delete GlowShader;
  //delete ToDungeonSensor;
}

}
}
}
