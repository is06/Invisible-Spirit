/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_HUD_2D_ELEMENT_H__
#define __IS06_HUD_2D_ELEMENT_H__

class Hud2DElement : public Hud {
  public:
    Hud2DElement(f32 x, f32 y, f32 w, f32 h);
    virtual ~Hud2DElement();

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

    void hide();
    void show();
    void setOpacity(u8 value);

    void startUVAnimation(f32 uSpeed, f32 vSpeed);
    void stopUVAnimation();

  protected:
    void drawPolygons();

    video::ITexture* texture;
    video::SMaterial material;
    video::S3DVertex vertices[4];

    core::dimension2df size;
    core::position2df pos;
    core::vector2df animSpeed;
    core::vector2df minTextureOffset;
    core::vector2df maxTextureOffset;

    bool isVisible;
    u8 opacity;

    const static f32 FAR = 0.1f;
    const static f32 COEFF = 3305.0f;
};

#endif
