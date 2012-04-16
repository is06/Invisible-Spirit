/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_ENERGY_INTERFACE_H__
#define __IS06_ENERGY_INTERFACE_H__

#include "Hud.h"

namespace is06
{
namespace nHud
{

class CEnergyInterface : public CHud
{
  public:
    CEnergyInterface();
    ~CEnergyInterface();

    void render();
    void hide();
    void show();
    void setOpacity(u8 value);

    CBarCounter* HpBar;
    //BarCounter* MpBar;
    //SpiritCounter* SpiritPower;
};

}
}

#endif

