/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_SHADER_SHADOW_PROCESSOR_H__
#define __IS06_SHADER_SHADOW_PROCESSOR_H__

#include "CShadow.h"
#include "EShadowMode.h"

using namespace std;

namespace is06 { namespace NShader {

//! Interface for creating shadow maps
class CShadowProcessor
{
public:
  CShadowProcessor(N3D::NCamera::CCamera* mainCamera);
  ~CShadowProcessor();

  void render();

  void addDirectLight(N3D::NLight::CDirectLight* light);
  void setMainCamera(N3D::NCamera::CCamera* camera);

private:
  void createDepthRenderTargetTexture();
  void drawDepthOnTexture();

  vector<N3D::NLight::CDirectLight*> Lights;
  vector<N3D::NLight::CDirectLight*>::iterator LightsIt;

  N3D::NCamera::CCamera* MainCamera;
  video::ITexture* DepthMap;
  NHud::NPrimitive::CPicture* DepthMapHud;
};

}}

#endif
