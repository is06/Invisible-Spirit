#ifndef __IS06_LIGHT_H__
#define __IS06_LIGHT_H__

using namespace std;
using namespace irr;

#include "../../include/Entity.h"

class Light : public Entity {
  public:
    Light();
    ~Light();

    void render();

  private:
    scene::ILightSceneNode* node;
    scene::IBillboardSceneNode* icon;
};

#endif
