/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_PICTURE_H__
#define __IS06_PICTURE_H__

#include "Hud2DElement.h"

namespace is06
{
namespace hud
{

class CPicture : public CHud2DElement
{
  public:
    CPicture(irr::f32 x = 0, irr::f32 y = 0, irr::f32 w = 32, irr::f32 h = 32, const std::string& filePath = "resource/hud/default.bmp");
    ~CPicture();

    void render();
    void loadSecondTexture(const std::string& filePath);
    void changeTexture(const std::string& filePath);
};

}
}

#endif

