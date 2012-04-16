/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_MAIN_STATE_INFO_H__
#define __IS06_MAIN_STATE_INFO_H__

#include "Hud.h"

namespace is06
{
namespace nHud
{

class CMainStateInfo : public CHud
{
  public:
    CMainStateInfo();
    ~CMainStateInfo();

    void render();
    void show();
    void hide();
    void setOpacity(u8 value);

  private:
    CText* Label;
    CText* Info;
    CBarCounter* Gauge;
};

}
}

#endif
