/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_MAP_ALPHA_ZONE__
#define __IS06_MAP_ALPHA_ZONE__

#include "../../include/scene/SceneGameplay.h"
#include "../../include/shader/PostRenderGlow.h"

namespace is06
{
namespace map
{

class MAP_ALPHA_ZONE : public scene::CSceneGameplay
{
  public:
    MAP_ALPHA_ZONE();
    ~MAP_ALPHA_ZONE();

    void events();
    void postRender();
    void hudRender();

  private:
    sound::CSpeaker* Spk;
    model::COmniLight* Lt;

    shader::CPostRenderGlow* GlowShader;
};

}
}

#endif
