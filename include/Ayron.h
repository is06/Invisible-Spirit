/******************************************************************************
Le code source d'Invisible Spirit par Thomas Noury est mis à disposition selon
les termes de la licence Creative Commons Paternité - Pas d'Utilisation
Commerciale - Partage des Conditions Initiales à l'Identique (BY-NC-SA) 3.0
Unported. Basé(e) sur une oeuvre à www.is06.com.  Les autorisations au-delà du
champ de cette licence peuvent être obtenues à http://www.is06.com.
*******************************************************************************/

#ifndef __IS06_AYRON_H__
#define __IS06_AYRON_H__

class Ayron : public Character {
  public:
    Ayron(Camera* cam);

    void render();

    // Déplacements par le joueur
    void goLeft(f32 speed);
    void goRight(f32 speed);
    void goForward(f32 speed);
    void goBackward(f32 speed);

    // Gravité
    void fall();
    void raise();
    void jump();

    // Collisions avec les murs
    void moveOpposite();
    void moveSlide(f32 angle);

  private:
    void updateCoords(f32 deltaU, f32 speed);

    Camera* linkedCam;
};

#endif
