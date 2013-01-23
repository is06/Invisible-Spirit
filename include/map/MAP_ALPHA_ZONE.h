/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_MAP_ALPHA_ZONE__
#define __IS06_MAP_ALPHA_ZONE__

#include "../model/CTeleporter.h"
#include "../scene/CSceneGameplay.h"
#include "../shader/CPostRenderGlow.h"

namespace is06
{
namespace nMap
{

//! This map is for alpha version 0.1 testing purpose only
class MAP_ALPHA_ZONE : public nScene::CSceneGameplay
{
  public:
    MAP_ALPHA_ZONE();
    ~MAP_ALPHA_ZONE();

    void events();
    void postRender();
    void hudRender();
    void loadingSequence();
    void start();

  private:
    nSound::CSpeaker* Spk;
    nShader::CPostRenderGlow* GlowShader;
    n3D::COmniLight* Lt;
    n3D::CTeleporter* ToDungeonSensor;
    n3D::CDirectLight* DLight;
    n3D::CNPC* NPC1;
};

}
}

#endif
