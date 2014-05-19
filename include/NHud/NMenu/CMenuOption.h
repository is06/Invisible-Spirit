/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_HUD_MENU_MENU_OPTION_H__
#define __IS06_HUD_MENU_MENU_OPTION_H__

#include "../NCore/CHudEntity.h"
#include "EMenuIcon.h"
#include "EMenuStyle.h"

namespace is06 { namespace NHud { namespace NMenu {

//! An option in a menu
class CMenuOption : public NCore::CHudEntity
{
public:
  CMenuOption(EMenuIcon icon, const string& title = "[Option]", f32 x = 0, f32 y = 0, EMenuStyle style = EMS_STD);
  virtual ~CMenuOption();

  virtual void render();

  void setHover(bool value);
  void setEnabled(bool value);
  void setSelectable(bool value);
  void show();
  void hide();
  void setOpacity(f32 value);
  void addOpacity(f32 value);
  void subOpacity(f32 value);
  f32 getOpacity();

protected:
  EMenuIcon Icon;
  NText::CText* Label;
  NWindow::CWindow* Box;

  f32 Opacity;
  bool Hover;
  bool Enabled;
  bool Visible;
  bool Selectable;
};

}}}

#endif
