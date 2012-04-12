/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../include/ref/core.h"
#include "../include/Shaders.h"
#include "../include/shader/DiffuseShaderCallback.h"
#include "../include/shader/IceShaderCallback.h"

namespace is06
{
namespace shader
{

CShaders::CShaders()
{
  Diffuse = 0;
  Ice = 0;
  Metal = irr::video::EMT_SOLID;
  Glass = irr::video::EMT_SOLID;
  HorizontalBlur = 0;
  VerticalBlur = 0;
}

void CShaders::createMaterials(irr::video::IGPUProgrammingServices* gpuManager)
{
  std::string directory = "glsl";
  if (engine::CGame::getVideoDriver()->getDriverType() == irr::video::EDT_DIRECT3D9) {
    directory = "hlsl";
  }

  if (gpuManager) {
    // Shader Diffuse (2D Elements)
    CDiffuseShaderCallback* diffuseCallback = new CDiffuseShaderCallback();
    std::string vertexProgram = "resource/shader/" + directory + "/diffuse.vert";
    std::string pixelProgram = "resource/shader/" + directory + "/diffuse.frag";
    Diffuse = gpuManager->addHighLevelShaderMaterialFromFiles(
      vertexProgram.c_str(), "mainVS", irr::video::EVST_VS_1_1,
      pixelProgram.c_str(), "mainPS", irr::video::EPST_PS_1_1,
      diffuseCallback, irr::video::EMT_TRANSPARENT_ALPHA_CHANNEL
    );
    diffuseCallback->drop();

    // Ice shader
    CIceShaderCallback* iceCallback = new CIceShaderCallback();
    vertexProgram = "resource/shader/" + directory + "/ice.vert";
    pixelProgram = "resource/shader/" + directory + "/ice.frag";
    Ice = gpuManager->addHighLevelShaderMaterialFromFiles(
      vertexProgram.c_str(), "mainVS", irr::video::EVST_VS_1_1,
      pixelProgram.c_str(), "mainPS", irr::video::EPST_PS_1_1,
      iceCallback, irr::video::EMT_SOLID
    );
    iceCallback->drop();

    // Horizontal Blur Shader
    vertexProgram = "resource/shader/" + directory + "/blur.vert";
    pixelProgram = "resource/shader/" + directory + "/hBlur.frag";
    HorizontalBlur = gpuManager->addHighLevelShaderMaterialFromFiles(
      vertexProgram.c_str(), "mainVS", irr::video::EVST_VS_1_1,
      pixelProgram.c_str(), "mainPS", irr::video::EPST_PS_1_1,
      0, irr::video::EMT_SOLID
    );

    // Vertical Blur Shader
    pixelProgram = "resource/shader/" + directory + "/vBlur.frag";
    VerticalBlur = gpuManager->addHighLevelShaderMaterialFromFiles(
      vertexProgram.c_str(), "mainVS", irr::video::EVST_VS_1_1,
      pixelProgram.c_str(), "mainPS", irr::video::EPST_PS_1_1,
      0, irr::video::EMT_SOLID
    );
  }
}

}
}
