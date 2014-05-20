/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/core.h"
#include "../../include/NEngine/NCore/CGame.h"
#include "../../include/NEngine/NResource/CSettings.h"
#include "../../include/NShader/CShadowProcessor.h"
#include "../../include/NScene/CScene.h"
#include "../../include/NHud/NPrimitive/CPicture.h"

using namespace irr;

namespace is06 { namespace NShader {

//! Constructor
CShadowProcessor::CShadowProcessor(N3D::NCamera::CCamera* mainCamera)
{
    DepthMap = NULL;
    DepthMapHud = new NHud::NPrimitive::CPicture(128, 128, 0, 0);

    setMainCamera(mainCamera);
    createDepthRenderTargetTexture();
}

void CShadowProcessor::addDirectLight(N3D::NLight::CDirectLight* light)
{
    Lights.push_back(light);
}

void CShadowProcessor::setMainCamera(N3D::NCamera::CCamera* camera)
{
    MainCamera = camera;
}

void CShadowProcessor::createDepthRenderTargetTexture()
{
    bool rendererIsDirect3D = (NEngine::NCore::CGame::getSettings()->getParamString("display", "renderer") == "direct3d");

    // Render to target texture quality from settings.ini
    u32 textureQuality = NEngine::NCore::CGame::getSettings()->getParamInt("shadows", "texture_quality");
    switch (textureQuality) {
        case 1: textureQuality = 64; break;  // 4K
        default:
        case 2: textureQuality = 128; break; // 16K
        case 3: textureQuality = 256; break; // 65K
        case 4: textureQuality = 512; break; // 256K
        case 5: textureQuality = 1024; break; // 1M
    }

    // Depth texture quality from settings.ini
    u32 depthQuality = NEngine::NCore::CGame::getSettings()->getParamInt("shadows", "depth_quality");
    video::ECOLOR_FORMAT depthTextureQuality = video::ECF_R16F;
    if (depthQuality == 32 && !rendererIsDirect3D) {
        depthTextureQuality = video::ECF_R32F;
    }

    DepthMap = NEngine::NCore::CGame::getVideoDriver()->addRenderTargetTexture(core::dimension2du(depthQuality, depthQuality), "RTDepthMapRTTT9", depthTextureQuality);
    DepthMapHud->setRenderTarget(DepthMap);
}

void CShadowProcessor::render()
{
    drawDepthOnTexture();
}

void CShadowProcessor::drawDepthOnTexture()
{
    NEngine::NCore::CGame::getVideoDriver()->setRenderTarget(DepthMap, true, true, video::SColor(255,255,255,255));
    DepthMapHud->render();
    NEngine::NCore::CGame::getVideoDriver()->setRenderTarget(video::ERT_FRAME_BUFFER, false, true, NEngine::NCore::CGame::getCurrentScene()->getBackBufferColor());
}

//! Destructor
CShadowProcessor::~CShadowProcessor()
{
    delete DepthMapHud;
}

}}
