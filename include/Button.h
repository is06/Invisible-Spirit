/******************************************************************************
Le code source d'Invisible Spirit par Thomas Noury est mis à disposition selon
les termes de la licence Creative Commons Paternité - Pas d'Utilisation
Commerciale - Partage des Conditions Initiales à l'Identique (BY-NC-SA) 3.0
Unported. Basé(e) sur une oeuvre à www.is06.com.  Les autorisations au-delà du
champ de cette licence peuvent être obtenues à http://www.is06.com.
*******************************************************************************/

#ifndef __IS06_BUTTON_H__
#define __IS06_BUTTON_H__

class Button {
  public:
    Button(f32 x, f32 y);
    virtual ~Button();

    virtual void render() = 0;

    void changeCommand(CommandIdentifier newCommand);
    void hide();
    void show();
    void setOpacity(u8 value);

  protected:
    Picture* buttonCircle;
};

#endif
