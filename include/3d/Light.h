#ifndef __IS06_LIGHT_H__
#define __IS06_LIGHT_H__

#include "../../include/Entity.h"

namespace is06
{
namespace model
{

class CLight : public engine::CEntity
{
  public:
    CLight();
    ~CLight();

    void update();

  private:
    irr::scene::ILightSceneNode* Node;
    irr::scene::IBillboardSceneNode* Icon;
};

}
}

#endif
