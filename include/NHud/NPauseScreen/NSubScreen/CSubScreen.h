/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_HUD_PAUSE_SCREEN_SUB_SCREEN_SUB_SCREEN_H__
#define __IS06_HUD_PAUSE_SCREEN_SUB_SCREEN_SUB_SCREEN_H__

#include "../../NCore/CHudEntity.h"

namespace is06 { namespace NHud { namespace NPauseScreen { namespace NSubScreen {

//! The base class for all gameplay sub-menus
class CSubScreen : public NCore::CHudEntity {
public:
  CSubScreen();
  ~CSubScreen();

  virtual void render();
  virtual void show();
  virtual void hide();
  virtual void setOpacity(f32 value);
  virtual void addOpacity(f32 value);
  virtual void subOpacity(f32 value);
  virtual f32 getOpacity();

protected:
  f32 Opacity;
};

}}}}

#endif
