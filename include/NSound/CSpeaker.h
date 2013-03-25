/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_SPEAKER_H__
#define __IS06_SPEAKER_H__

#include "../Engine/CEntity.h"

namespace is06 { namespace NSound {

//! 3D sound speaker entity that can be attached to a 3D graphical entity
class CSpeaker : public NEngine::CEntity
{
public:
  CSpeaker(const string& streamFile, const core::vector3df& initPos, const string& text = "speaker", f32 radius = 10.0f);
  ~CSpeaker();

  void update();

  const FMOD_VECTOR& getPosition() const;
  core::vector3df getPositionVector();

  void setPosition(const FMOD_VECTOR& newPos);
  void setPosition(const core::vector3df& newPos);

  void play();
  void stop();
  void pause();
  void resume();
  void setVolume(f32 val);

private:
  scene::IBillboardSceneNode* Icon;
  scene::IBillboardTextSceneNode* TextBB;

  FMOD_CHANNEL* ChannelPtr;
  FMOD_SOUND* SoundPtr;

  FMOD_VECTOR Position;
};

}}

#endif
