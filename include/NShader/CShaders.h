/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_SHADER_SHADERS_H__
#define __IS06_SHADER_SHADERS_H__

namespace is06 { namespace NShader {

//! Shader material type identifiers for use in 3D graphical entities
class CShaders
{
public:
  CShaders();
  void createMaterials(video::IGPUProgrammingServices* gpuManager);

  s32 Ice;
  s32 Metal;
  s32 Glass;
  s32 VerticalBlur;
  s32 HorizontalBlur;
  s32 ShadowMapPass1;
  s32 ShadowMapPass2;
};

}
}

#endif
