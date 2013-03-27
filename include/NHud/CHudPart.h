/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_HUD_PART_HUD_PART_H__
#define __IS06_HUD_PART_HUD_PART_H__

#include "CHud.h"

namespace is06 { namespace NHud { namespace NPart {

//! The whole HUD gameplay interface (buttons, energy...)
class CHudPart : public CHud
{
public:
  CHudPart();
  ~CHudPart();

  void render();
  void hide();
  void show();
  void setOpacity(f32 value);
  void addOpacity(f32 value);
  void subOpacity(f32 value);
  f32 getOpacity();

  NEnsemble::CCommands* Buttons;
  NEnsemble::CEnergy* Energy;

protected:
  f32 Opacity;
};

}}}

#endif
