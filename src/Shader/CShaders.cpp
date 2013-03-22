/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/Engine/core.h"
#include "../../include/Shader/CShaders.h"
#include "../../include/Shader/CDiffuseShaderCallback.h"
#include "../../include/Shader/CBlurShaderCallback.h"
#include "../../include/Shader/CDepthShaderCallback.h"
#include "../../include/Shader/CShadowShaderCallback.h"

using namespace irr;

namespace is06
{
namespace NShader
{

CShaders::CShaders()
{
  Ice = 0;
  Metal = video::EMT_SOLID;
  Glass = video::EMT_SOLID;
  HorizontalBlur = 0;
  VerticalBlur = 0;
  ShadowMapPass1 = 0;
  ShadowMapPass2 = 0;
}

//! All shader materials creation
/**
 * @param IGPUProgrammingServices gpuManager
 */
void CShaders::createMaterials(video::IGPUProgrammingServices* gpuManager)
{
  if (gpuManager) {
    CBlurShaderCallback* blurCallback = new CBlurShaderCallback();
    // Horizontal Blur Shader
    HorizontalBlur = gpuManager->addHighLevelShaderMaterialFromFiles(
      "resource/Shader/blur.vertex.cg", "mainVS", video::EVST_VS_2_0,
      "resource/Shader/horizontal_blur.pixel.cg", "mainPS", video::EPST_PS_2_0,
      blurCallback, video::EMT_TRANSPARENT_ADD_COLOR, 0, video::EGSL_CG
    );
    // Vertical Blur Shader
    VerticalBlur = gpuManager->addHighLevelShaderMaterialFromFiles(
      "resource/Shader/blur.vertex.cg", "mainVS", video::EVST_VS_2_0,
      "resource/Shader/vertical_blur.pixel.cg", "mainPS", video::EPST_PS_2_0,
      blurCallback, video::EMT_TRANSPARENT_ADD_COLOR, 0, video::EGSL_CG
    );

    // Shadow map pass 1 (depth buffer emulation)
    CDepthShaderCallback* depthCallback = new CDepthShaderCallback();
    ShadowMapPass1 = gpuManager->addHighLevelShaderMaterialFromFiles(
      "resource/Shader/shadowmap_pass1.vertex.cg", "mainVS", video::EVST_VS_2_0,
      "resource/Shader/shadowmap_pass1.pixel.cg", "mainPS", video::EPST_PS_2_0,
      depthCallback, video::EMT_SOLID, 0, video::EGSL_CG
    );

    // Shadow map pass 2
    CShadowShaderCallback* shadowCallback = new CShadowShaderCallback();
    ShadowMapPass2 = gpuManager->addHighLevelShaderMaterialFromFiles(
      "resource/Shader/shadowmap_pass2.vertex.cg", "mainVS", video::EVST_VS_2_0,
      "resource/Shader/shadowmap_pass2.pixel.cg", "mainPS", video::EPST_PS_2_0,
      shadowCallback, video::EMT_SOLID, 0, video::EGSL_CG
    );
  }
}

}
}
