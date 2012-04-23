/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/core.h"
#include "../../include/engine/Game.h"
#include "../../include/engine/Keyboard.h"
#include "../../include/engine/Translation.h"
#include "../../include/3d/LevelMesh.h"
#include "../../include/3d/PlayableCharacter.h"
#include "../../include/3d/OmniLight.h"
#include "../../include/engine/DialogInterface.h"
#include "../../include/sound/MusicReference.h"
#include "../../include/sound/Speaker.h"
#include "../../include/map/MAP_ALPHA_ZONE.h"

namespace is06
{
namespace nMap
{

/**
 * Alpha Zone constructor
 */
MAP_ALPHA_ZONE::MAP_ALPHA_ZONE() : nScene::CSceneGameplay()
{
  BackBufferColor = video::SColor(255, 255, 255, 255);

  // Local Translations
  SceneTranslations = new nEngine::CTranslation("MAP_ALPHA_ZONE.ist");

  // Level Mesh
  Level->loadMesh("resource/mesh/level/alphazone.obj");
  Level->createNode(core::vector3df(0, 0, 0));
  Level->loadMeshCollision();
  Level->hide();

  Ayron->hide();

  // Multi-layers music example
  //music->play("bodhum");
  //music->unmuteSequence("bodhum", 1);
  //music->muteSequence("bodhum", 2);

  //music->play("boss");

  // 3D Speaker example
  //spk = new Speaker(STREAM_TEST, core::vector3df(0,1,0), "hola", 10);

  // Omni Light example
  //lt = new OmniLight();

  // Dialogs
  Dialog = new nEngine::CDialogInterface("MAP_ALPHA_ZONE.isd", SceneTranslations, Control);

  // Glow shader example
  //glowShader = new PostRenderGlow();
  //addToEntityList(level);
}

/**
 * Alpha Zone events
 */
void MAP_ALPHA_ZONE::events()
{
  nScene::CSceneGameplay::events();

  if (Control->commandEntered(nEngine::COMMAND_PLAYER_GUARD, nEngine::EVENT_ONCE)) {
    Dialog->start("norya_first_start");

    /*
    if (dialog->finished()) {

    }
    */
  }

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

/**
 * Post-rendering (example: glow shader)
 */
void MAP_ALPHA_ZONE::postRender()
{
  nScene::CSceneGameplay::postRender();

  //glowShader->render();
}

/**
 * Player HUD render
 */
void MAP_ALPHA_ZONE::hudRender()
{
  nScene::CSceneGameplay::hudRender();
}

/**
 * Delete all created pointers
 */
MAP_ALPHA_ZONE::~MAP_ALPHA_ZONE()
{
  // Level Mesh collision clear
  Level->clearMeshCollision();

  // 3D Speaker deletion
  //delete spk;

  // Omni Light deletion
  //delete lt;

  // Glow shader deletion
  //delete glowShader;
}

}
}
