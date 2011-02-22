/******************************************************************************
Le code source d'Invisible Spirit par Thomas Noury est mis à disposition selon
les termes de la licence Creative Commons Paternité - Pas d'Utilisation
Commerciale - Partage des Conditions Initiales à l'Identique (BY-NC-SA) 3.0
Unported. Basé(e) sur une oeuvre à www.is06.com.  Les autorisations au-delà du
champ de cette licence peuvent être obtenues à http://www.is06.com.
*******************************************************************************/

#ifndef __IS06_CHARACTER_H__
#define __IS06_CHARACTER_H__

class Character : public AnimatedModel {
  public:
    Character();

    virtual void render();

    bool isJumping;
    bool isFalling;
    bool isWalking;
    bool isTalking;

  protected:
    f32 jumpStrength;
};

#endif
