/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_PAUSE_SUB_SCREEN_H__
#define __IS06_PAUSE_SUB_SCREEN_H__

#include "CHud.h"

namespace is06
{
namespace nHud
{
namespace nPauseScreen
{

//! The base class for all gameplay sub-menus
class CPauseSubScreen : public CHud {
  public:
    CPauseSubScreen();
    ~CPauseSubScreen();

    virtual void render();
    virtual void show();
    virtual void hide();
    virtual void setOpacity(u8 value);

  protected:

};

}
}
}

#endif
