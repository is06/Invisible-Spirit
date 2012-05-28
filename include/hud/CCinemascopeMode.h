/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_CINEMASCOPE_MODE_H__
#define __IS06_CINEMASCOPE_MODE_H__

#include "CHud.h"

namespace is06
{
namespace nHud
{

class CCinemascopeMode : public CHud
{
  public:
    CCinemascopeMode();
    ~CCinemascopeMode();

    void render();
    void render(f32 speedFactor);
    void show();
    void hide();
    void setOpacity(u8 value);
    void fadeIn(f32 speed);
    void fadeOut(f32 speed);
    void slideIn(f32 speed);
    void slideOut(f32 speed);

  private:
    CQuad* Bars[2];
    bool FadingIn;
    bool FadingOut;
    bool SlidingIn;
    bool SlidingOut;
    f32 FadeValue;
    f32 FadeSpeed;
    f32 SlideValue;
    f32 SlideSpeed;
};

}
}

#endif
