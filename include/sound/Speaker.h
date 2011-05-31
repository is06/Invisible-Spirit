#ifndef __IS06_SPEAKER_H__
#define __IS06_SPEAKER_H__

using namespace irr;
using namespace std;

class Speaker : public Entity {
  public:
    Speaker(StreamIdentifier stream, const core::vector3df& initPos, const core::stringw& text = L"speaker", f32 radius = 10.0f);
    ~Speaker();

    void render();

  private:
    scene::IBillboardSceneNode* icon;
    scene::IBillboardTextSceneNode* textBB;
};

#endif
