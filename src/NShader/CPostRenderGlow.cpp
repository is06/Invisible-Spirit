/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/core.h"
#include "../../include/NEngine/NCore/CGame.h"
#include "../../include/NEngine/NResource/CSettings.h"
#include "../../include/NShader/CPostRenderGlow.h"
#include "../../include/NScene/CScene.h"

using namespace irr;

namespace is06 { namespace NShader {

CPostRenderGlow::CPostRenderGlow() : CPostRenderShader()
{
    BackBufferColor = video::SColor(255, 255, 255, 255);
    bool rendererIsDirect3D = (NEngine::NCore::CGame::getSettings()->getParamString("display", "renderer") == "direct3d");

    // Render to target texture resolution quality
    u32 texture_quality = NEngine::NCore::CGame::getSettings()->getParamInt("glow", "texture_quality");
    switch (texture_quality) {
        case 1: texture_quality = 64; break;  // 16KB
        default:
        case 2: texture_quality = 128; break; // 64KB
        case 3: texture_quality = 256; break; // 256KB
        case 4: texture_quality = 512; break; // 1MB
        case 5: texture_quality = 1024; break; // 4MB
    }

    u32 depth_quality = NEngine::NCore::CGame::getSettings()->getParamInt("glow", "depth_quality");
    video::ECOLOR_FORMAT textureColorFormat = video::ECF_R5G6B5;
    // Render target texture 32-bit only with OpenGL
    if (depth_quality == 32 && !rendererIsDirect3D) {
        textureColorFormat = video::ECF_R8G8B8;
    }

    Material.AntiAliasing = false;
    Texture = NEngine::NCore::CGame::getVideoDriver()->addRenderTargetTexture(core::dimension2du(texture_quality, texture_quality), "GlowRTT", textureColorFormat);
    Material.setTexture(0, Texture);
}

//! Render post render quad (FlatElement) two times (one for each shader pass)
/**
 * Calling render of parent class results in an execution of both vertex and fragment shader
 * First pass : horizontal blur
 * Second pass : vertical blur
 */
void CPostRenderGlow::render()
{
    // Perform first pass (horizontal blur)
    Material.MaterialType = (video::E_MATERIAL_TYPE)NEngine::NCore::CGame::Shaders.HorizontalBlur;
    CFlatElement::render();

    if (Texture) {
        NEngine::NCore::CGame::getVideoDriver()->setRenderTarget(Texture, true, true, BackBufferColor);
        // Darken non glowing entities
        applyEffectsToEntities();
        // Draw the whole scene
        NEngine::NCore::CGame::getSceneManager()->drawAll();
        // Perform second pass (vertical blur)
        Material.MaterialType = (video::E_MATERIAL_TYPE)NEngine::NCore::CGame::Shaders.VerticalBlur;
        CFlatElement::render();
        // Restore lighting material of all darkened entities
        removeEffectsToEntities();
        // Reset render target to main display viewport
        NEngine::NCore::CGame::getVideoDriver()->setRenderTarget(video::ERT_FRAME_BUFFER, false, true, 0);
    }
}

CPostRenderGlow::~CPostRenderGlow()
{

}

}}
