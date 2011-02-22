/******************************************************************************
Le code source d'Invisible Spirit par Thomas Noury est mis à disposition selon
les termes de la licence Creative Commons Paternité - Pas d'Utilisation
Commerciale - Partage des Conditions Initiales à l'Identique (BY-NC-SA) 3.0
Unported. Basé(e) sur une oeuvre à www.is06.com.  Les autorisations au-delà du
champ de cette licence peuvent être obtenues à http://www.is06.com.
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
