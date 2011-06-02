/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"

using namespace irr;
using namespace std;

/**
 *
 */
Speaker::Speaker(StreamIdentifier, const core::vector3df& initPos, const core::stringw& text, f32 radius) : Entity() {
  video::ITexture* iconTexture = Game::getVideoDriver()->getTexture("resource/debug/icons/speaker.bmp");

  icon = Game::getSceneManager()->addBillboardSceneNode(0, core::dimension2df(1.0f, 1.0f), initPos);
  icon->setMaterialTexture(0, iconTexture);

  //@TODO: text
  //gui::IGUIFont* font = Game::getDebugGUI()->addFont();
  //textBB = Game::getSceneManager()->addBillboardTextSceneNode(0, text, 0, core::dimension2df(1.0f, 1.0f), core::vector3df(initPos.X, initPos.Y + 1.0f, initPos.Z));

  position.x = initPos.X;
  position.y = initPos.Y;
  position.z = initPos.Z;

  // Sound stream creation
  FMOD_System_CreateStream(Game::getSoundManager()->getSystem(), "sp_a2_laser_chaining_l3.mp3", FMOD_3D | FMOD_HARDWARE | FMOD_LOOP_NORMAL, 0, &soundPtr);

  // Setting 3D position
  FMOD_Channel_Set3DAttributes(channelPtr, &position, NULL);

  // Play
  play();
}

void Speaker::render() { Entity::render();

}

const FMOD_VECTOR& Speaker::getPosition() const {
  return position;
}

core::vector3df Speaker::getPositionVector() {
  return core::vector3df(
    position.x,
    position.y,
    position.z
  );
}

void Speaker::setPosition(const FMOD_VECTOR& newPos) {
  position = newPos;
}

void Speaker::setPosition(const core::vector3df& newPos) {
  position.x = newPos.X;
  position.y = newPos.Y;
  position.z = newPos.Z;
}

void Speaker::play() {
  FMOD_System_PlaySound(Game::getSoundManager()->getSystem(), FMOD_CHANNEL_FREE, soundPtr, 0, &channelPtr);
  FMOD_Channel_SetPaused(channelPtr, false);
}

void Speaker::pause() {
  FMOD_Channel_SetPaused(channelPtr, true);
}

void Speaker::resume() {
  FMOD_Channel_SetPaused(channelPtr, false);
}

void Speaker::stop() {
  FMOD_Channel_Stop(channelPtr);
}

void Speaker::setVolume(f32 val) {

}

Speaker::~Speaker() {
  icon->remove();
  //textBB->remove();

  stop();
  FMOD_Sound_Release(soundPtr);
}
