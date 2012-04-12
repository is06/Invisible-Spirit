/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_WINDOW_H__
#define __IS06_WINDOW_H__

#include "Hud.h"

#include "../enums/styles/WindowStyle.h"

namespace is06
{
namespace hud
{

class CWindow : public CHud
{
  public:
    CWindow(irr::f32 x = 0, irr::f32 y = 0, irr::f32 w = 150, irr::f32 h = 100, irr::f32 borderWidth = 4, EWindowStyle style = WIN_STYLE_STD);
    ~CWindow();

    void render();
    void show();
    void hide();
    void setOpacity(irr::u8 value);

  private:
    void applyStyleStd(irr::f32 x = 0, irr::f32 y = 0, irr::f32 w = 150, irr::f32 h = 100, irr::f32 borderWidth = 4);
    void applyStyleNone();

    irr::core::position2df Pos;
    irr::core::dimension2df Size;

    CPicture* CornerTL;
    CPicture* CornerTR;
    CPicture* CornerBL;
    CPicture* CornerBR;
    CPicture* SideTop;
    CPicture* SideLeft;
    CPicture* SideRight;
    CPicture* SideBottom;
    CPicture* Center;
};

}
}

#endif
