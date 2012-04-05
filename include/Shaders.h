/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_SHADERS_H__
#define __IS06_SHADERS_H__

class Shaders
{
  public:
    Shaders();
    void createMaterials(video::IGPUProgrammingServices* gpuManager);

    s32 diffuse;
    s32 ice;
    s32 metal;
    s32 glass;
    s32 verticalBlur;
    s32 horizontalBlur;
};

#endif
