/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_HUD_WINDOW_WINDOW_H__
#define __IS06_HUD_WINDOW_WINDOW_H__

#include "../NCore/CHudEntity.h"
#include "EWindowStyle.h"

namespace is06 { namespace NHud { namespace NWindow {

class CWindow : public NCore::CHudEntity
{
public:
  CWindow(f32 x = 0, f32 y = 0, f32 w = 150, f32 h = 100, f32 borderWidth = 4, EWindowStyle style = EWS_STD);
  ~CWindow();

  void render();
  void show();
  void hide();
  void setOpacity(f32 value);
  void addOpacity(f32 value);
  void subOpacity(f32 value);
  f32 getOpacity();

private:
  void applyStyleStd(f32 x = 0, f32 y = 0, f32 w = 150, f32 h = 100, f32 borderWidth = 4);
  void applyStyleNone();

  core::position2df Pos;
  core::dimension2df Size;

  NPrimitive::CPicture* CornerTL;
  NPrimitive::CPicture* CornerTR;
  NPrimitive::CPicture* CornerBL;
  NPrimitive::CPicture* CornerBR;
  NPrimitive::CPicture* SideTop;
  NPrimitive::CPicture* SideLeft;
  NPrimitive::CPicture* SideRight;
  NPrimitive::CPicture* SideBottom;
  NPrimitive::CPicture* Center;
};

}}}

#endif
