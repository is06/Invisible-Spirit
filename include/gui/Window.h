/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_WINDOW_H__
#define __IS06_WINDOW_H__

using namespace irr;
using namespace std;

class Window : public Hud {
  public:
    Window(f32 w = 150, f32 h = 100, f32 x = 0, f32 y = 0, f32 borderWidth = 4, WindowStyle style = WIN_STYLE_STD);
    ~Window();

    void render();

  private:
    void applyStyleStd(f32 w = 150, f32 h = 100, f32 x = 0, f32 y = 0, f32 borderWidth = 4);
    void applyStyleNone();

    core::position2df pos;
    core::dimension2df size;

    Picture* cornerTL;
    Picture* cornerTR;
    Picture* cornerBL;
    Picture* cornerBR;
    Picture* sideTop;
    Picture* sideLeft;
    Picture* sideRight;
    Picture* sideBottom;
    Picture* center;
};

#endif
