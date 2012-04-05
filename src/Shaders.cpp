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
  if (gpuManager) {
    // Shader Diffuse (2D Elements)
    DiffuseShaderCallback* diffuseCallback = new DiffuseShaderCallback();
    diffuse = gpuManager->addHighLevelShaderMaterialFromFiles(
      "resource/shader/diffuse.vert", "vertexMain", video::EVST_VS_1_1,
      "resource/shader/diffuse.frag", "pixelMain", video::EPST_PS_1_1,
      diffuseCallback, video::EMT_TRANSPARENT_ALPHA_CHANNEL
    );
    diffuseCallback->drop();

    // Ice shader
    IceShaderCallback* iceCallback = new IceShaderCallback();
    ice = gpuManager->addHighLevelShaderMaterialFromFiles(
      "resource/shader/ice.vert", "vertexMain", video::EVST_VS_1_1,
      "resource/shader/ice.frag", "pixelMain", video::EPST_PS_1_1,
      iceCallback, video::EMT_SOLID
    );
    iceCallback->drop();

    // Horizontal Blur Shader
    horizontalBlur = gpuManager->addHighLevelShaderMaterialFromFiles(
      "resource/shader/blur.vert", "vertexMain", video::EVST_VS_1_1,
      "resource/shader/hBlur.frag", "pixelMain", video::EPST_PS_1_1,
      0, video::EMT_SOLID
    );

    // Vertical Blur Shader
    verticalBlur = gpuManager->addHighLevelShaderMaterialFromFiles(
      "resource/shader/blur.vert", "vertexMain", video::EVST_VS_1_1,
      "resource/shader/vBlur.frag", "pixelMain", video::EPST_PS_1_1,
      0, video::EMT_SOLID
    );
  }
}
