/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_SHADERS_H__
#define __IS06_SHADERS_H__

namespace is06
{
namespace shader
{

class CShaders
{
  public:
    CShaders();
    void createMaterials(irr::video::IGPUProgrammingServices* gpuManager);

    irr::s32 Diffuse;
    irr::s32 Ice;
    irr::s32 Metal;
    irr::s32 Glass;
    irr::s32 VerticalBlur;
    irr::s32 HorizontalBlur;
};

}
}

#endif
