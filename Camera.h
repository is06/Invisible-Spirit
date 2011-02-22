/**************************************************************************************
Le code source d'Invisible Spirit par Thomas Noury est mis à disposition selon les
termes de la licence Creative Commons Paternité - Pas d'Utilisation Commerciale -
Partage des Conditions Initiales à l'Identique 3.0 Unported.
Basé(e) sur une oeuvre à www.is06.com.  Les autorisations au-delà du champ de
cette licence peuvent être obtenues à http://www.is06.com.
***************************************************************************************/

#ifndef __IS06_CAMERA_H__
#define __IS06_CAMERA_H__

using namespace irr;

class Camera {
  public:
    Camera();

    virtual void render();

    virtual void linkEntity(Ayron* entityToLink) = 0;
    virtual f32 getDistance() = 0;

    virtual void goLeft(s8 speed) = 0;
    virtual void goRight(s8 speed) = 0;
    virtual void goFar(s8 speed) = 0;
    virtual void goNear(s8 speed) = 0;

    void setPosition(const core::vector3df& pos);
    void setRotation(const core::vector3df& rot);
    scene::ISceneNode* getNode();

    bool hasControl();

  protected:
    scene::ICameraSceneNode* irrCam;
    bool controlable;
};

#endif
