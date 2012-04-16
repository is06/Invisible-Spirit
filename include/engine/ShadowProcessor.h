/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_SHADOW_PROCESSOR_H__
#define __IS06_SHADOW_PROCESSOR_H__

#include "Shadow.h"
#include "ShadowMode.h"

using namespace std;

namespace is06
{
namespace nEngine
{

//! Interface for creating shadow maps
class CShadowProcessor
{
  public:
    CShadowProcessor();
    ~CShadowProcessor();

    void render();

    void setEntity(scene::ISceneNode* node, nEngine::EShadowMode mode);
    void removeEntity(scene::ISceneNode* node);

  private:
    void renderCastingNodes();
    void renderReceivingNodes();

    map<scene::ISceneNode*, nEngine::CShadow> Shadows;
    map<scene::ISceneNode*, nEngine::CShadow>::iterator ShadowsIt;

    video::ITexture* ShadowMap;
};

}
}

#endif
