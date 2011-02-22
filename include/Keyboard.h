/******************************************************************************
Le code source d'Invisible Spirit par Thomas Noury est mis à disposition selon
les termes de la licence Creative Commons Paternité - Pas d'Utilisation
Commerciale - Partage des Conditions Initiales à l'Identique (BY-NC-SA) 3.0
Unported. Basé(e) sur une oeuvre à www.is06.com.  Les autorisations au-delà du
champ de cette licence peuvent être obtenues à http://www.is06.com.
*******************************************************************************/

#ifndef __IS06_KEYBOARD_H__
#define __IS06_KEYBOARD_H__

using namespace irr;

/**
 * Cette classe d'interface permet d'exploiter le clavier dans les scènes
 */
class Keyboard {
  public:
    bool pressed(EKEY_CODE code, EventType type = EVENT_ALWAYS);
    bool any(EventType type = EVENT_ALWAYS);
};

#endif
