/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/core.h"
#include "../../include/shader/Shaders.h"
#include "../../include/shader/DiffuseShaderCallback.h"
#include "../../include/shader/IceShaderCallback.h"
#include "../../include/shader/DepthShaderCallback.h"
#include "../../include/shader/ShadowShaderCallback.h"

using namespace irr;

namespace is06
{
namespace nShader
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
  if (nEngine::CGame::getVideoDriver()->getDriverType() == video::EDT_DIRECT3D9) {
    directory = "hlsl";
  }

  if (gpuManager) {
    string vertexProgram = "";
    string pixelProgram = "";

    // Shader Diffuse (2D Elements)
    /*
    CDiffuseShaderCallback* diffuseCallback = new CDiffuseShaderCallback();
    string vertexProgram = "resource/shader/" + directory + "/diffuse.vert";
    string pixelProgram = "resource/shader/" + directory + "/diffuse.frag";
    Diffuse = gpuManager->addHighLevelShaderMaterialFromFiles(
      vertexProgram.c_str(), "mainVS", video::EVST_VS_1_1,
      pixelProgram.c_str(), "mainPS", video::EPST_PS_1_1,
      diffuseCallback, video::EMT_TRANSPARENT_ALPHA_CHANNEL
    );
    diffuseCallback->drop();

    // Ice shader
    CIceShaderCallback* iceCallback = new CIceShaderCallback();
    vertexProgram = "resource/shader/" + directory + "/ice.vert";
    pixelProgram = "resource/shader/" + directory + "/ice.frag";
    Ice = gpuManager->addHighLevelShaderMaterialFromFiles(
      vertexProgram.c_str(), "mainVS", video::EVST_VS_1_1,
      pixelProgram.c_str(), "mainPS", video::EPST_PS_1_1,
      iceCallback, video::EMT_SOLID
    );
    iceCallback->drop();
    */

    // Horizontal Blur Shader
    vertexProgram = "resource/shader/" + directory + "/blur.vert";
    pixelProgram = "resource/shader/" + directory + "/hBlur.frag";
    HorizontalBlur = gpuManager->addHighLevelShaderMaterialFromFiles(
      vertexProgram.c_str(), "mainVS", video::EVST_VS_1_1,
      pixelProgram.c_str(), "mainPS", video::EPST_PS_1_1,
      0, video::EMT_SOLID
    );

    // Vertical Blur Shader
    pixelProgram = "resource/shader/" + directory + "/vBlur.frag";
    VerticalBlur = gpuManager->addHighLevelShaderMaterialFromFiles(
      vertexProgram.c_str(), "mainVS", video::EVST_VS_1_1,
      pixelProgram.c_str(), "mainPS", video::EPST_PS_1_1,
      0, video::EMT_SOLID
    );

    // Shadow map pass 1 (depth buffer emulation)
    /*
    CDepthShaderCallback* depthCallback = new CDepthShaderCallback();
    vertexProgram = "resource/shader/" + directory + "/shadow_map_pass1.vert";
    pixelProgram = "resource/shader/" + directory + "/shadow_map_pass1.frag";
    ShadowMapPass1 = gpuManager->addHighLevelShaderMaterialFromFiles(
      vertexProgram.c_str(), "mainVS", video::EVST_VS_2_0,
      pixelProgram.c_str(), "mainPS", video::EPST_PS_2_0,
      depthCallback, video::EMT_SOLID
    );

    // Shadow map pass 2
    CShadowShaderCallback* shadowCallback = new CShadowShaderCallback();
    vertexProgram = "resource/shader/" + directory + "/shadow_map_pass2.vert";
    pixelProgram = "resource/shader/" + directory + "/shadow_map_pass2.frag";
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
