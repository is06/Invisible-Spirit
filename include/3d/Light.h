#ifndef __IS06_LIGHT_H__
#define __IS06_LIGHT_H__

#include "../../include/engine/Entity.h"

namespace is06
{
namespace n3D
{

//! Base class for lights
class CLight : public nEngine::CEntity
{
  public:
    CLight();
    ~CLight();

    void update();

  private:
    scene::ILightSceneNode* Node;
    scene::IBillboardSceneNode* Icon;
};

}
}

#endif
