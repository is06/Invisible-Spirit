/******************************************************************************
Le code source d'Invisible Spirit par Thomas Noury est mis à disposition selon
les termes de la licence Creative Commons Paternité - Pas d'Utilisation
Commerciale - Partage des Conditions Initiales à l'Identique (BY-NC-SA) 3.0
Unported. Basé(e) sur une oeuvre à www.is06.com.  Les autorisations au-delà du
champ de cette licence peuvent être obtenues à http://www.is06.com.
*******************************************************************************/

#ifndef __IS06_SETTINGS_H__
#define __IS06_SETTINGS_H__

using namespace irr;
using namespace std;

class Settings {
  public:
    Settings();
    ~Settings();

    core::stringc& getParamString(const core::stringc& groupName, const core::stringc& paramName);
    s32 getParamInt(const core::stringc& groupName, const core::stringc& paramName);

  private:
    map<core::stringc, SettingsGroup*> data;
    fstream fileStream;
};

#endif
