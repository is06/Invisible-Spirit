/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/Engine/core.h"
#include "../../include/Shader/CShaders.h"
#include "../../include/Shader/CDiffuseShaderCallback.h"
#include "../../include/Shader/CIceShaderCallback.h"
#include "../../include/Shader/CDepthShaderCallback.h"
#include "../../include/Shader/CShadowShaderCallback.h"

using namespace irr;

namespace is06
{
namespace NShader
{

CShaders::CShaders()
{
  Diffuse = 0;
  Ice = 0;
  Metal = video::EMT_SOLID;
  Glass = video::EMT_SOLID;
  HorizontalBlur = 0;
  VerticalBlur = 0;
}

void CShaders::createMaterials(video::IGPUProgrammingServices* gpuManager)
{
  string directory = "glsl";
  if (NEngine::CGame::getVideoDriver()->getDriverType() == video::EDT_DIRECT3D9) {
    directory = "hlsl";
  }

  if (gpuManager) {
    string vertexProgram = "";
    string pixelProgram = "";

    // Shader Diffuse (2D Elements)
    /*
    CDiffuseShaderCallback* diffuseCallback = new CDiffuseShaderCallback();
    string vertexProgram = "resource/Shader/" + directory + "/diffuse.vert";
    string pixelProgram = "resource/Shader/" + directory + "/diffuse.frag";
    Diffuse = gpuManager->addHighLevelShaderMaterialFromFiles(
      vertexProgram.c_str(), "mainVS", video::EVST_VS_1_1,
      pixelProgram.c_str(), "mainPS", video::EPST_PS_1_1,
      diffuseCallback, video::EMT_TRANSPARENT_ALPHA_CHANNEL
    );
    diffuseCallback->drop();

    // Ice shader
    CIceShaderCallback* iceCallback = new CIceShaderCallback();
    vertexProgram = "resource/Shader/" + directory + "/ice.vert";
    pixelProgram = "resource/Shader/" + directory + "/ice.frag";
    Ice = gpuManager->addHighLevelShaderMaterialFromFiles(
      vertexProgram.c_str(), "mainVS", video::EVST_VS_1_1,
      pixelProgram.c_str(), "mainPS", video::EPST_PS_1_1,
      iceCallback, video::EMT_SOLID
    );
    iceCallback->drop();
    */

    // Horizontal Blur Shader
    vertexProgram = "resource/Shader/" + directory + "/blur.vert";
    pixelProgram = "resource/Shader/" + directory + "/hBlur.frag";
    HorizontalBlur = gpuManager->addHighLevelShaderMaterialFromFiles(
      vertexProgram.c_str(), "mainVS", video::EVST_VS_1_1,
      pixelProgram.c_str(), "mainPS", video::EPST_PS_1_1,
      0, video::EMT_SOLID
    );

    // Vertical Blur Shader
    pixelProgram = "resource/Shader/" + directory + "/vBlur.frag";
    VerticalBlur = gpuManager->addHighLevelShaderMaterialFromFiles(
      vertexProgram.c_str(), "mainVS", video::EVST_VS_1_1,
      pixelProgram.c_str(), "mainPS", video::EPST_PS_1_1,
      0, video::EMT_SOLID
    );

    // Shadow map pass 1 (depth buffer emulation)
    /*
    CDepthShaderCallback* depthCallback = new CDepthShaderCallback();
    vertexProgram = "resource/Shader/" + directory + "/shadow_map_pass1.vert";
    pixelProgram = "resource/Shader/" + directory + "/shadow_map_pass1.frag";
    ShadowMapPass1 = gpuManager->addHighLevelShaderMaterialFromFiles(
      vertexProgram.c_str(), "mainVS", video::EVST_VS_2_0,
      pixelProgram.c_str(), "mainPS", video::EPST_PS_2_0,
      depthCallback, video::EMT_SOLID
    );

    // Shadow map pass 2
    CShadowShaderCallback* shadowCallback = new CShadowShaderCallback();
    vertexProgram = "resource/Shader/" + directory + "/shadow_map_pass2.vert";
    pixelProgram = "resource/Shader/" + directory + "/shadow_map_pass2.frag";
    ShadowMapPass2 = gpuManager->addHighLevelShaderMaterialFromFiles(
      vertexProgram.c_str(), "mainVS", video::EVST_VS_2_0,
      pixelProgram.c_str(), "mainPS", video::EPST_PS_2_0,
      shadowCallback, video::EMT_SOLID
    );
    */
  }
}

}
}
