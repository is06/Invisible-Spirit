/******************************************************************************
Le code source d'Invisible Spirit par Thomas Noury est mis à disposition selon
les termes de la licence Creative Commons Paternité - Pas d'Utilisation
Commerciale - Partage des Conditions Initiales à l'Identique (BY-NC-SA) 3.0
Unported. Basé(e) sur une oeuvre à www.is06.com.  Les autorisations au-delà du
champ de cette licence peuvent être obtenues à http://www.is06.com.
*******************************************************************************/

#ifndef __IS06_GAMEPLAY_INTERFACE_H__
#define __IS06_GAMEPLAY_INTERFACE_H__

class GameplayInterface {
  public:
    GameplayInterface();
    ~GameplayInterface();

    void render();
    void hide();
    void show();
    void setOpacity(u8 value);

    ButtonsInterface* buttons;
};

#endif
