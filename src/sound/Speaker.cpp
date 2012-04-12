/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/sound/Speaker.h"
#include "../../include/Game.h"
#include "../../include/sound/SoundManager.h"

namespace is06
{
namespace sound
{

/**
 *
 */
CSpeaker::CSpeaker(StreamIdentifier, const irr::core::vector3df& initPos, const std::string& text, irr::f32 radius) : engine::CEntity()
{
  irr::video::ITexture* iconTexture = engine::CGame::getVideoDriver()->getTexture("resource/debug/icons/speaker.bmp");

  Icon = engine::CGame::getSceneManager()->addBillboardSceneNode(0, irr::core::dimension2df(1.0f, 1.0f), initPos);
  Icon->setMaterialTexture(0, iconTexture);

  //@TODO: text
  //gui::IGUIFont* font = Game::getDebugGUI()->addFont();
  //textBB = Game::getSceneManager()->addBillboardTextSceneNode(0, text, 0, core::dimension2df(1.0f, 1.0f), core::vector3df(initPos.X, initPos.Y + 1.0f, initPos.Z));

  Position.x = initPos.X;
  Position.y = initPos.Y;
  Position.z = initPos.Z;

  // Sound stream creation
  FMOD_System_CreateStream(engine::CGame::getSoundManager()->getSystem(), "sp_a2_laser_chaining_l3.mp3", FMOD_3D | FMOD_HARDWARE | FMOD_LOOP_NORMAL, 0, &SoundPtr);

  // Setting 3D position
  FMOD_Channel_Set3DAttributes(ChannelPtr, &Position, NULL);

  // Play
  play();
}

void CSpeaker::update()
{
  //Entity::render();
}

const FMOD_VECTOR& CSpeaker::getPosition() const
{
  return Position;
}

irr::core::vector3df CSpeaker::getPositionVector()
{
  return irr::core::vector3df(
    Position.x,
    Position.y,
    Position.z
  );
}

void CSpeaker::setPosition(const FMOD_VECTOR& position)
{
  Position = position;
}

void CSpeaker::setPosition(const irr::core::vector3df& position)
{
  Position.x = position.X;
  Position.y = position.Y;
  Position.z = position.Z;
}

void CSpeaker::play()
{
  FMOD_System_PlaySound(engine::CGame::getSoundManager()->getSystem(), FMOD_CHANNEL_FREE, SoundPtr, 0, &ChannelPtr);
  FMOD_Channel_SetPaused(ChannelPtr, false);
}

void CSpeaker::pause()
{
  FMOD_Channel_SetPaused(ChannelPtr, true);
}

void CSpeaker::resume()
{
  FMOD_Channel_SetPaused(ChannelPtr, false);
}

void CSpeaker::stop()
{
  FMOD_Channel_Stop(ChannelPtr);
}

void CSpeaker::setVolume(irr::f32 val)
{

}

CSpeaker::~CSpeaker()
{
  Icon->remove();
  //textBB->remove();

  stop();
  FMOD_Sound_Release(SoundPtr);
}

}
}
