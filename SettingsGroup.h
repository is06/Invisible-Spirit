/******************************************************************************
Le code source d'Invisible Spirit par Thomas Noury est mis à disposition selon
les termes de la licence Creative Commons Paternité - Pas d'Utilisation
Commerciale - Partage des Conditions Initiales à l'Identique (BY-NC-SA) 3.0
Unported. Basé(e) sur une oeuvre à www.is06.com.  Les autorisations au-delà du
champ de cette licence peuvent être obtenues à http://www.is06.com.
*******************************************************************************/

#ifndef __IS06_SETTINGS_GROUP_H__
#define __IS06_SETTINGS_GROUP_H__

using namespace irr;
using namespace std;

class SettingsGroup {
  public:
    SettingsGroup(const core::stringc& newName);

    void setName(const core::stringc& newName);
    core::stringc& getName();

    map<core::stringc, core::stringc>& getParams();

  private:
    core::stringc name;
    map<core::stringc, core::stringc> params;
};

#endif
