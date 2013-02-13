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
  CgTest = video::EMT_SOLID;

  Ice = 0;
  Metal = video::EMT_SOLID;
  Glass = video::EMT_SOLID;
  HorizontalBlur = 0;
  VerticalBlur = 0;
}

void CShaders::createMaterials(video::IGPUProgrammingServices* gpuManager)
{
  if (gpuManager) {
    // Cg Test shader
    CgTest = gpuManager->addHighLevelShaderMaterialFromFiles(
      "resource/Shader/cgtest.vertex.cg", "mainVS", video::EVST_VS_2_0,
      "resource/Shader/cgtest.pixel.cg", "mainPS", video::EPST_PS_2_0,
      0, video::EMT_SOLID, 0, video::EGSL_CG
    );

    // Ice shader
    /*
    CIceShaderCallback* iceCallback = new CIceShaderCallback();
    Ice = gpuManager->addHighLevelShaderMaterialFromFiles(
      "resource/Shader/ice.vertex.cg", "mainVS", video::EVST_VS_2_0,
      "resource/Shader/ice.pixel.cg", "mainPS", video::EPST_PS_2_0,
      iceCallback, video::EMT_SOLID, 0, video::EGSL_CG
    );
    iceCallback->drop();
    */

    // Horizontal Blur Shader
    CBlurShaderCallback* blurCallback = new CBlurShaderCallback();
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
    /*
    CDepthShaderCallback* depthCallback = new CDepthShaderCallback();
    vertexProgram = "resource/Shader/shadowmap_pass1.vertex.cg";
    pixelProgram = "resource/Shader/shadowmap_pass1.pixel.cg";
    ShadowMapPass1 = gpuManager->addHighLevelShaderMaterialFromFiles(
      vertexProgram.c_str(), "mainVS", video::EVST_VS_2_0,
      pixelProgram.c_str(), "mainPS", video::EPST_PS_2_0,
      depthCallback, video::EMT_SOLID, 0, video::EGSL_CG
    );
    */
    // Shadow map pass 2
    /*
    CShadowShaderCallback* shadowCallback = new CShadowShaderCallback();
    vertexProgram = "resource/Shader/shadowmap_pass2.vertex.cg";
    pixelProgram = "resource/Shader/shadowmap_pass2.pixel.cg";
    ShadowMapPass2 = gpuManager->addHighLevelShaderMaterialFromFiles(
      vertexProgram.c_str(), "mainVS", video::EVST_VS_2_0,
      pixelProgram.c_str(), "mainPS", video::EPST_PS_2_0,
      shadowCallback, video::EMT_SOLID, 0, video::EGSL_CG
    );
    */
  }
}

}
}
