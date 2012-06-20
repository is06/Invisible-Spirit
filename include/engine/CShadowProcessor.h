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
namespace nEngine
{

//! Interface for creating shadow maps
class CShadowProcessor
{
  public:
    CShadowProcessor(n3D::CCamera* mainCamera);
    ~CShadowProcessor();

    void render();

    void addDirectLight(n3D::CDirectLight* light);
    void setMainCamera(n3D::CCamera* camera);

  private:
    void createDepthRenderTargetTexture();
    void drawDepthOnTexture();

    vector<n3D::CDirectLight*> Lights;
    vector<n3D::CDirectLight*>::iterator LightsIt;

    n3D::CCamera* MainCamera;
    video::ITexture* DepthMap;
    nHud::CPicture* DepthMapHud;
};

}
}

#endif
