/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_HUD_ENSEMBLE_H__
#define __IS06_HUD_ENSEMBLE_H__

#include "CHud.h"

namespace is06
{
namespace nHud
{

//! The whole HUD gameplay interface (buttons, energy...)
class CHudEnsemble : public CHud
{
  public:
    CHudEnsemble();
    ~CHudEnsemble();

    void render();
    void hide();
    void show();
    void setOpacity(u8 value);

    CHudEnsembleCommands* Buttons;
    CHudEnsembleEnergy* Energy;
};

}
}

#endif
