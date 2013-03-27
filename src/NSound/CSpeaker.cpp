/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/core.h"
#include "../../include/NEngine/NCore/CGame.h"
#include "../../include/NEngine/NResource/CResourceManager.h"
#include "../../include/NSound/CSpeaker.h"
#include "../../include/NSound/CSoundManager.h"

namespace is06 { namespace NSound {

//! Constructor
CSpeaker::CSpeaker(const string& streamFile, const core::vector3df& initPos, const string& text, f32 radius) : NEngine::NCore::CEntity()
{
  video::ITexture* iconTexture = NEngine::NResource::CResourceManager::loadTexture("resource/debug/icons/speaker.bmp");

  Icon = NEngine::NCore::CGame::getSceneManager()->addBillboardSceneNode(0, core::dimension2df(1.0f, 1.0f), initPos);
  Icon->setMaterialTexture(0, iconTexture);

  //@TODO: text
  //gui::IGUIFont* font = Game::getDebugGUI()->addFont();
  //textBB = Game::getSceneManager()->addBillboardTextSceneNode(0, text, 0, core::dimension2df(1.0f, 1.0f), core::vector3df(initPos.X, initPos.Y + 1.0f, initPos.Z));

  Position.x = initPos.X;
  Position.y = initPos.Y;
  Position.z = initPos.Z;

  // Sound stream creation
  FMOD_System_CreateStream(NEngine::NCore::CGame::getSoundManager()->getSystem(), streamFile.c_str(), FMOD_3D | FMOD_HARDWARE | FMOD_LOOP_NORMAL, 0, &SoundPtr);

  // Setting 3D position
  FMOD_Channel_Set3DAttributes(ChannelPtr, &Position, NULL);

  // Play
  play();
}

//! Update function for event testing
void CSpeaker::update()
{

}

//! Returns the current position of the 3D speaker
/**
 * \return FMOD_VECTOR
 */
const FMOD_VECTOR& CSpeaker::getPosition() const
{
  return Position;
}

//! Returns the current position of the 3D speaker
/**
 * \return vector3df
 */
core::vector3df CSpeaker::getPositionVector()
{
  return core::vector3df(
    Position.x,
    Position.y,
    Position.z
  );
}

//! Changes the position of the 3D speaker
/**
 * \param FMOD_VECTOR position the new position
 */
void CSpeaker::setPosition(const FMOD_VECTOR& position)
{
  Position = position;
}

//! Changes the position of the 3D speaker
/**
 * \param vector3df position the new position
 */
void CSpeaker::setPosition(const core::vector3df& position)
{
  Position.x = position.X;
  Position.y = position.Y;
  Position.z = position.Z;
}

//! Plays the sound from the speaker
void CSpeaker::play()
{
  FMOD_System_PlaySound(NEngine::NCore::CGame::getSoundManager()->getSystem(), FMOD_CHANNEL_FREE, SoundPtr, 0, &ChannelPtr);
  FMOD_Channel_SetPaused(ChannelPtr, false);
}

//! Pauses the current sound
void CSpeaker::pause()
{
  FMOD_Channel_SetPaused(ChannelPtr, true);
}

//! Resumes the current sound
void CSpeaker::resume()
{
  FMOD_Channel_SetPaused(ChannelPtr, false);
}

//! Stops the current sound
void CSpeaker::stop()
{
  FMOD_Channel_Stop(ChannelPtr);
}

//! Changes the volume of the speaker
void CSpeaker::setVolume(f32 val)
{
  FMOD_Channel_SetVolume(ChannelPtr, val);
}

//! Destructor
CSpeaker::~CSpeaker()
{
  Icon->remove();
  //textBB->remove();

  stop();
  FMOD_Sound_Release(SoundPtr);
}

}}
