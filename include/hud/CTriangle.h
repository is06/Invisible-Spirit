/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_TRIANGLE_H__
#define __IS06_TRIANGLE_H__

#include "../hud/CHud.h"

using namespace irr;

namespace is06
{
namespace nHud
{

class CTriangle : public CHud
{
  public:
    CTriangle(video::SColor color);
    ~CTriangle();

    void render();
    void hide();
    void show();
    void setOpacity(u8 value);
    void setPosition(f32 x, f32 y);
    void setRotation(f32 value);

  private:
    bool Visible;
    u8 Opacity;
    video::S3DVertex Vertices[3];
    u16 Indices[3];
    core::matrix4 AbsoluteTransformation;
    video::SMaterial Material;
};

}
}

#endif
