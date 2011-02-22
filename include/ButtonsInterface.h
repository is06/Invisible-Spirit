/******************************************************************************
Le code source d'Invisible Spirit par Thomas Noury est mis à disposition selon
les termes de la licence Creative Commons Paternité - Pas d'Utilisation
Commerciale - Partage des Conditions Initiales à l'Identique (BY-NC-SA) 3.0
Unported. Basé(e) sur une oeuvre à www.is06.com.  Les autorisations au-delà du
champ de cette licence peuvent être obtenues à http://www.is06.com.
*******************************************************************************/

#ifndef __IS06_BUTTONS_INTERFACE_H__
#define __IS06_BUTTONS_INTERFACE_H__

class ButtonsInterface {
  public:
    ButtonsInterface();
    ~ButtonsInterface();

    void render();
    void hide();
    void show();
    void setOpacity(u8 value);

    Button* command;
    Button* jump;
    Button* defense;
    Button* menu;
};

#endif
