#ifndef __IS06_LIGHT_H__
#define __IS06_LIGHT_H__

#include "../../include/engine/Entity.h"

namespace is06
{
namespace model
{

//! Base class for lights
class CLight : public engine::CEntity
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
