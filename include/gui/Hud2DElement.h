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
namespace hud
{

class CHud2DElement : public CHud
{
  public:
    CHud2DElement(irr::f32 x, irr::f32 y, irr::f32 w, irr::f32 h);
    virtual ~CHud2DElement();

    virtual void render() = 0;

    void setSize(irr::f32 w, irr::f32 h);
    void setPosition(irr::f32 x, irr::f32 y);
    void setTextureOffset(const irr::core::vector2df& min, const irr::core::vector2df& max);

    void addX(irr::f32 val);
    void addY(irr::f32 val);
    void subX(irr::f32 val);
    void subY(irr::f32 val);
    void setX(irr::f32 val);
    void setY(irr::f32 val);

    irr::f32 getX();
    irr::f32 getY();
    irr::f32 getWidth();
    irr::f32 getHeight();

    void setWidth(irr::f32 val);
    void setHeight(irr::f32 val);

    void hide();
    void show();
    void setOpacity(irr::u8 value);
    void diffuse(irr::video::SColor color);

    void startUVAnimation(irr::f32 uSpeed, irr::f32 vSpeed);
    void stopUVAnimation();

  protected:
    void drawPolygons();

    irr::video::ITexture* Texture;
    irr::video::SMaterial Material;
    irr::video::S3DVertex Vertices[4];

    irr::core::dimension2df Size;
    irr::core::position2df Pos;
    irr::core::vector2df AnimSpeed;
    irr::core::vector2df MinTextureOffset;
    irr::core::vector2df MaxTextureOffset;

    bool IsVisible;
    irr::u8 Opacity;

    const static irr::f32 FAR = 0.1f;
    const static irr::f32 COEFF = 4954.94f;

    static irr::u16 Indices[];
    static irr::core::matrix4 Mat;
};

}
}

#endif
