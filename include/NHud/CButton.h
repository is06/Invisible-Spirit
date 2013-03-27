/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_HUD_BUTTON_BUTTON_H__
#define __IS06_HUD_BUTTON_BUTTON_H__

#include "../../NEngine/NControl/ECommandIdentifier.h"
#include "../NCore/CHudEntity.h"

namespace is06 { namespace NHud { namespace NButton {

//! Graphical representation of a button in the HUD gameplay interface
class CButton : public NCore::CHudEntity
{
public:
  CButton(f32 x, f32 y);
  virtual ~CButton();

  virtual void render() = 0;

  void changeCommand(NEngine::NControl::ECommandIdentifier newCommand);
  void hide();
  void show();
  void setOpacity(f32 value);
  void addOpacity(f32 value);
  void subOpacity(f32 value);
  f32 getOpacity();

protected:
  NPrimitive::CPicture* ButtonCircle;
  f32 Opacity;
};

}}}

#endif
