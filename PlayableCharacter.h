/**************************************************************************************
Le code source d'Invisible Spirit par Thomas Noury est mis à disposition selon les
termes de la licence Creative Commons Paternité - Pas d'Utilisation Commerciale -
Partage des Conditions Initiales à l'Identique 3.0 Unported.
Basé(e) sur une oeuvre à www.is06.com.  Les autorisations au-delà du champ de
cette licence peuvent être obtenues à http://www.is06.com.
***************************************************************************************/

#ifndef __IS06_PLAYABLE_CHARACTER_H__
#define __IS06_PLAYABLE_CHARACTER_H__

using namespace irr;

class PlayableCharacter : public Character {
  public:
    PlayableCharacter();

    virtual void render();

    bool isAttacking;

  protected:
};

#endif
