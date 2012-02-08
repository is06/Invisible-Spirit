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

using namespace irr;
using namespace std;

class Speaker : public Entity
{
  public:
    Speaker(StreamIdentifier stream, const core::vector3df& initPos, const core::stringw& text = L"speaker", f32 radius = 10.0f);
    ~Speaker();

    void render();

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
    scene::IBillboardSceneNode* icon;
    scene::IBillboardTextSceneNode* textBB;

    FMOD_CHANNEL* channelPtr;
    FMOD_SOUND* soundPtr;

    FMOD_VECTOR position;
};

#endif
