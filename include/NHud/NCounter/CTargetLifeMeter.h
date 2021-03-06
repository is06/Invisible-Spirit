/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_HUD_COUNTER_TARGET_LIFE_METER_H__
#define __IS06_HUD_COUNTER_TARGET_LIFE_METER_H__

#include "../../NEngine/NControl/ECommandIdentifier.h"
#include "../NCore/CHudEntity.h"

namespace is06 { namespace NHud { namespace NCounter {

//! A life meter (with horizontal bar) usually for enemies on the screen
class CTargetLifeMeter : public NCore::CHudEntity
{
public:
  CTargetLifeMeter(s32 init, s32 min, s32 max);
  ~CTargetLifeMeter();

  void render(const core::vector3df& targetPosition);
  void updateValue(const s32& value);

private:
  NPrimitive::CPicture* BarBack;
  NCounter::CBarMeter* Gauge;
  NText::CText* Label;
};

}}}

#endif
