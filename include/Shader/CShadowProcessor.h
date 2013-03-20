/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_SHADOW_PROCESSOR_H__
#define __IS06_SHADOW_PROCESSOR_H__

#include "CShadow.h"
#include "EShadowMode.h"

using namespace std;

namespace is06
{
namespace NEngine
{

//! Interface for creating shadow maps
class CShadowProcessor
{
  public:
    CShadowProcessor(N3D::CCamera* mainCamera);
    ~CShadowProcessor();

    void render();

    void addDirectLight(N3D::NLight::CDirect* light);
    void setMainCamera(N3D::CCamera* camera);

  private:
    void createDepthRenderTargetTexture();
    void drawDepthOnTexture();

    vector<N3D::NLight::CDirect*> Lights;
    vector<N3D::NLight::CDirect*>::iterator LightsIt;

    N3D::CCamera* MainCamera;
    video::ITexture* DepthMap;
    NHud::CPicture* DepthMapHud;
};

}
}

#endif
