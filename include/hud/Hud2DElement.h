/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_HUD_2D_ELEMENT_H__
#define __IS06_HUD_2D_ELEMENT_H__

#include "Hud.h"

namespace is06
{
namespace nHud
{

//! A simili-2D HUD element (3D screen-aligned quad), also used for post render effects
class CHud2DElement : public CHud
{
  public:
    CHud2DElement(f32 x, f32 y, f32 w, f32 h);
    virtual ~CHud2DElement();

    virtual void render() = 0;

    void setSize(f32 w, f32 h);
    void setPosition(f32 x, f32 y);
    void setTextureOffset(const core::vector2df& min, const core::vector2df& max);

    void addX(f32 val);
    void addY(f32 val);
    void subX(f32 val);
    void subY(f32 val);
    void setX(f32 val);
    void setY(f32 val);

    f32 getX();
    f32 getY();
    f32 getWidth();
    f32 getHeight();

    void setWidth(f32 val);
    void setHeight(f32 val);

    void hide();
    void show();
    void setOpacity(u8 value);
    void diffuse(video::SColor color);

    void startUVAnimation(f32 uSpeed, f32 vSpeed);
    void stopUVAnimation();

  protected:
    void drawPolygons();

    video::ITexture* Texture;
    video::SMaterial Material;
    video::S3DVertex Vertices[4];

    core::dimension2df Size;
    core::position2df Position;
    core::vector2df AnimSpeed;
    core::vector2df MinTextureOffset;
    core::vector2df MaxTextureOffset;

    bool Visible;
    u8 Opacity;

    const static f32 FAR = 0.1f;
    const static f32 COEFF = 4954.94f;

    static u16 Indices[];
    static core::matrix4 Mat;
};

}
}

#endif
