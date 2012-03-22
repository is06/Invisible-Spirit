/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/Game.h"
#include "../../include/Keyboard.h"
#include "../../include/3d/LevelMesh.h"
#include "../../include/engine/DialogInterface.h"
#include "../../include/sound/MusicReference.h"
#include "../../include/sound/Speaker.h"
#include "../../include/3d/OmniLight.h"

#include "../../include/map/MAP_ALPHA_ZONE.h"

using namespace std;
using namespace irr;

/**
 * Alpha Zone constructor
 */
MAP_ALPHA_ZONE::MAP_ALPHA_ZONE() : SceneGameplay()
{
  // Level Mesh
  level->loadMesh("resource/mesh/level/alphazone.obj");
  level->createNode(core::vector3df(0, 0, 0));
  level->loadMeshCollision();

  // Multi-layers music example
  //music->play("bodhum");
  //music->unmuteSequence("bodhum", 1);
  //music->muteSequence("bodhum", 2);

  // 3D Speaker example
  //spk = new Speaker(STREAM_TEST, core::vector3df(0,1,0), "hola", 10);

  // Omni Light example
  //lt = new OmniLight();

  // Dialogs
  dialog = new DialogInterface("MAP_ALPHA_ZONE.isd", sceneTranslations);

  // Glow shader example
  //glowShader = new PostRenderGlow();
}

/**
 * Alpha Zone events
 */
void MAP_ALPHA_ZONE::events()
{
  SceneGameplay::events();

  dialog->start("norya_first_start");
  if (dialog->finished()) {

  }

  // Object rendering
  //spk->render();
  //lt->render();

  // Multi-layer music events
  // When pressing W, sequence 2 (aggressive mix) is played
  if (keyboard->pressed(KEY_KEY_W, EVENT_ONCE)) {
    music->unmuteSequence("bodhum", 1);
    music->muteSequence("bodhum", 2);
  }
  // When pressing X, sequence 1 (normal) is played
  if (keyboard->pressed(KEY_KEY_X, EVENT_ONCE)) {
    music->unmuteSequence("bodhum", 2);
    music->muteSequence("bodhum", 1);
  }
}

/**
 * Post-rendering (example: glow shader)
 */
void MAP_ALPHA_ZONE::postRender()
{
  SceneGameplay::postRender();

  //glowShader->render();
}

/**
 * Player HUD render
 */
void MAP_ALPHA_ZONE::hudRender()
{
  SceneGameplay::hudRender();
}

/**
 * Delete all created pointers
 */
MAP_ALPHA_ZONE::~MAP_ALPHA_ZONE()
{
  // Level Mesh collision clear
  level->clearMeshCollision();

  // 3D Speaker deletion
  //delete spk;

  // Omni Light deletion
  //delete lt;

  // Glow shader deletion
  //delete glowShader;
}
