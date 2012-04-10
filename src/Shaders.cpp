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

using namespace irr;

Shaders::Shaders()
{
  diffuse = 0;
  ice = 0;
  metal = video::EMT_SOLID;
  glass = video::EMT_SOLID;
  horizontalBlur = 0;
  verticalBlur = 0;
}

void Shaders::createMaterials(video::IGPUProgrammingServices* gpuManager)
{
  string directory = "glsl";
  if (Game::getVideoDriver()->getDriverType() == video::EDT_DIRECT3D9) {
    directory = "hlsl";
  }

  if (gpuManager) {
    // Shader Diffuse (2D Elements)
    DiffuseShaderCallback* diffuseCallback = new DiffuseShaderCallback();
    string vertexProgram = "resource/shader/" + directory + "/diffuse.vert";
    string pixelProgram = "resource/shader/" + directory + "/diffuse.frag";
    diffuse = gpuManager->addHighLevelShaderMaterialFromFiles(
      vertexProgram.c_str(), "mainVS", video::EVST_VS_1_1,
      pixelProgram.c_str(), "mainPS", video::EPST_PS_1_1,
      diffuseCallback, video::EMT_TRANSPARENT_ALPHA_CHANNEL
    );
    diffuseCallback->drop();

    // Ice shader
    IceShaderCallback* iceCallback = new IceShaderCallback();
    vertexProgram = "resource/shader/" + directory + "/ice.vert";
    pixelProgram = "resource/shader/" + directory + "/ice.frag";
    ice = gpuManager->addHighLevelShaderMaterialFromFiles(
      vertexProgram.c_str(), "mainVS", video::EVST_VS_1_1,
      pixelProgram.c_str(), "mainPS", video::EPST_PS_1_1,
      iceCallback, video::EMT_SOLID
    );
    iceCallback->drop();

    // Horizontal Blur Shader
    vertexProgram = "resource/shader/" + directory + "/blur.vert";
    pixelProgram = "resource/shader/" + directory + "/hBlur.frag";
    horizontalBlur = gpuManager->addHighLevelShaderMaterialFromFiles(
      vertexProgram.c_str(), "mainVS", video::EVST_VS_1_1,
      pixelProgram.c_str(), "mainPS", video::EPST_PS_1_1,
      0, video::EMT_SOLID
    );

    // Vertical Blur Shader
    pixelProgram = "resource/shader/" + directory + "/vBlur.frag";
    verticalBlur = gpuManager->addHighLevelShaderMaterialFromFiles(
      vertexProgram.c_str(), "mainVS", video::EVST_VS_1_1,
      pixelProgram.c_str(), "mainPS", video::EPST_PS_1_1,
      0, video::EMT_SOLID
    );
  }
}
