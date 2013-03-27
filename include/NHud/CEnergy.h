/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_HUD_PART_ENERGY_H__
#define __IS06_HUD_PART_ENERGY_H__

#include "../CHud.h"

namespace is06 { namespace NHud { namespace NPart {

//! The HUD energy interface
class CEnergy : public CHud
{
public:
  CEnergy();
  ~CEnergy();

  void render();
  void hide();
  void show();
  void setOpacity(f32 value);
  void addOpacity(f32 value);
  void subOpacity(f32 value);
  f32 getOpacity();

  NCounter::CBar* HpBar;
  //CBarCounter* MpBar;
  //CSpiritCounter* SpiritPower;

  f32 Opacity;
};

}}}

#endif

