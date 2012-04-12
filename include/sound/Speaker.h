/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_SPEAKER_H__
#define __IS06_SPEAKER_H__

#include "../Entity.h"

#include "../enums/sound/StreamIdentifier.h"

namespace is06
{
namespace sound
{

class CSpeaker : public engine::CEntity
{
  public:
    CSpeaker(StreamIdentifier stream, const irr::core::vector3df& initPos, const std::string& text = "speaker", irr::f32 radius = 10.0f);
    ~CSpeaker();

    void update();

    const FMOD_VECTOR& getPosition() const;
    irr::core::vector3df getPositionVector();

    void setPosition(const FMOD_VECTOR& newPos);
    void setPosition(const irr::core::vector3df& newPos);

    void play();
    void stop();
    void pause();
    void resume();
    void setVolume(irr::f32 val);

  private:
    irr::scene::IBillboardSceneNode* Icon;
    irr::scene::IBillboardTextSceneNode* TextBB;

    FMOD_CHANNEL* ChannelPtr;
    FMOD_SOUND* SoundPtr;

    FMOD_VECTOR Position;
};

}
}

#endif
