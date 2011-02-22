/******************************************************************************
Le code source d'Invisible Spirit par Thomas Noury est mis à disposition selon
les termes de la licence Creative Commons Paternité - Pas d'Utilisation
Commerciale - Partage des Conditions Initiales à l'Identique (BY-NC-SA) 3.0
Unported. Basé(e) sur une oeuvre à www.is06.com.  Les autorisations au-delà du
champ de cette licence peuvent être obtenues à http://www.is06.com.
*******************************************************************************/

#ifndef __IS06_ICON_BUTTON_H__
#define __IS06_ICON_BUTTON_H__

class IconButton : public Button {
  public:
    IconButton(f32 x, f32 y);
    ~IconButton();

    void render();

  protected:
    Picture* icon;
};

#endif
