/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/Engine/core.h"
#include "../../include/Engine/CGame.h"
#include "../../include/Engine/Resource/CSettings.h"
#include "../../include/Shader/CShadowProcessor.h"
#include "../../include/Scene/CScene.h"
#include "../../include/Hud/CPicture.h"

using namespace irr;

namespace is06
{
namespace NEngine
{

//! Constructor
CShadowProcessor::CShadowProcessor(N3D::CCamera* mainCamera)
{
  DepthMap = NULL;

  setMainCamera(mainCamera);
  createDepthRenderTargetTexture();

  DepthMapHud = new NHud::CPicture(128, 128, 0, 0);
  DepthMapHud->setRenderTarget(DepthMap);
}

void CShadowProcessor::addDirectLight(N3D::NLight::CDirect* light)
{
  Lights.push_back(light);
}

void CShadowProcessor::setMainCamera(N3D::CCamera* camera)
{
  MainCamera = camera;
}

void CShadowProcessor::createDepthRenderTargetTexture()
{
  // Render to target texture quality from settings.ini
  u32 textureQuality = CGame::Settings->getParamInt("shadows", "texture_quality");
  switch (textureQuality) {
    case 1: textureQuality = 64; break;  // 4K
    default:
    case 2: textureQuality = 128; break; // 16K
    case 3: textureQuality = 256; break; // 65K
    case 4: textureQuality = 512; break; // 256K
    case 5: textureQuality = 1024; break; // 1M
  }

  // Depth texture quality from settings.ini
  u32 depthQuality = CGame::Settings->getParamInt("shadows", "depth_quality");
  video::ECOLOR_FORMAT depthTextureQuality = video::ECF_R5G6B5;
  if (depthQuality == 32) {
    depthTextureQuality = video::ECF_R8G8B8;
  }

  DepthMap = CGame::getVideoDriver()->addRenderTargetTexture(core::dimension2du(depthQuality, depthQuality), "RTT9", depthTextureQuality);
}

void CShadowProcessor::render()
{
  drawDepthOnTexture();
}

void CShadowProcessor::drawDepthOnTexture()
{
  CGame::getVideoDriver()->setRenderTarget(DepthMap, true, true, video::SColor(255,255,255,255));

  DepthMapHud->render();

  CGame::getVideoDriver()->setRenderTarget(video::ERT_FRAME_BUFFER, false, true, CGame::getCurrentScene()->getBackBufferColor());
}

//! Destructor, does nothing
CShadowProcessor::~CShadowProcessor()
{
  delete DepthMapHud;
}

}
}
