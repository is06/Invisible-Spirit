/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_PICTURE_H__
#define __IS06_PICTURE_H__

using namespace irr;

class Picture : public Hud {
  public:
    Picture();
    Picture(f32 w, f32 h, f32 x, f32 y, const core::stringc& filePath);
    Picture(const core::dimension2df& newSize, const core::position2df& newPos, const core::stringc& filePath);
    ~Picture();

    void render();

    void setSize(f32 w, f32 h);
    void setPosition(f32 x, f32 y);

    void startUVAnimation(f32 uSpeed, f32 vSpeed);
    void stopUVAnimation();

    void hide();
    void show();
    void setOpacity(u8 value);

  private:
    void construct(f32 w, f32 h, f32 x, f32 y, const core::stringc& filePath);

    video::ITexture* texture;
    video::SMaterial material;
    video::S3DVertex vertices[4];

    core::dimension2df size;
    core::position2df pos;
    core::vector2df animSpeed;

    bool isVisible;
    u8 opacity;

    const static f32 FAR = 0.1f;
    const static f32 COEFF = 3305.0f;
};

#endif
