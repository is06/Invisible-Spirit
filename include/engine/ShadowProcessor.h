/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_SHADOW_PROCESSOR_H__
#define __IS06_SHADOW_PROCESSOR_H__

#include "Shadow.h"
#include "../enums/engine/ShadowMode.h"
//#include "../shader/PostRenderShadow.h"

using namespace std;

namespace is06
{
namespace engine
{

class CShadowProcessor
{
  public:
    CShadowProcessor();
    ~CShadowProcessor();

    void render();

    void setEntity(irr::scene::ISceneNode* node, engine::EShadowMode mode);
    void removeEntity(irr::scene::ISceneNode* node);

  private:
    void renderCastingNodes();
    void renderReceivingNodes();

    map<irr::scene::ISceneNode*, engine::CShadow> Shadows;
    map<irr::scene::ISceneNode*, engine::CShadow>::iterator ShadowsIt;

    irr::video::ITexture* ShadowMap;
};

}
}

#endif
