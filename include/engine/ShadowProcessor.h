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
#include "../shader/PostRenderSurface.h"

using namespace irr;
using namespace std;

class ShadowProcessor
{
  public:
    ShadowProcessor();
    ~ShadowProcessor();

    void render();

    void setEntity(scene::ISceneNode* node, ShadowMode mode);
    void removeEntity(scene::ISceneNode* node);

  private:
    void renderCastingNodes();
    void renderReceivingNodes();

    map<scene::ISceneNode*, Shadow> shadows;
    map<scene::ISceneNode*, Shadow>::iterator shadowsIt;

    video::ITexture* shadowMap;
};

#endif
