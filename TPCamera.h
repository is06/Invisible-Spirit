/**************************************************************************************
Le code source d'Invisible Spirit par Thomas Noury est mis à disposition selon les
termes de la licence Creative Commons Paternité - Pas d'Utilisation Commerciale -
Partage des Conditions Initiales à l'Identique 3.0 Unported.
Basé(e) sur une oeuvre à www.is06.com.  Les autorisations au-delà du champ de
cette licence peuvent être obtenues à http://www.is06.com.
***************************************************************************************/

#ifndef __IS06_TPCAMERA_H__
#define __IS06_TPCAMERA_H__

class TPCamera : public Camera {
  public:
    TPCamera();

    void render();

    void goLeft(s8 speed);
    void goRight(s8 speed);
    void goFar(s8 speed);
    void goNear(s8 speed);

    void linkEntity(Ayron* entity);
    f32 getDistance();

  private:
    Ayron* linkedEntity;
    f32 UAxis;
    f32 height;
    f32 distance;
};

#endif
