/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_HUD_PART_CINEMASCOPE_MODE_H__
#define __IS06_HUD_PART_CINEMASCOPE_MODE_H__

#include "../NCore/CHudEntity.h"

namespace is06 { namespace NHud { namespace NPart {

class CCinemascopeMode : public NCore::CHudEntity
{
public:
  CCinemascopeMode();
  ~CCinemascopeMode();

  void render();
  void render(f32 speedFactor);
  void show();
  void hide();
  void setOpacity(f32 value);
  void addOpacity(f32 value);
  void subOpacity(f32 value);
  f32 getOpacity();
  void fadeIn(f32 speed);
  void fadeOut(f32 speed);
  void slideIn(f32 speed);
  void slideOut(f32 speed);

private:
  NPrimitive::CQuad* Bars[2];
  bool FadingIn;
  bool FadingOut;
  bool SlidingIn;
  bool SlidingOut;
  f32 FadeValue;
  f32 FadeSpeed;
  f32 SlideSpeed;
  f32 Opacity;
};

}}}

#endif
