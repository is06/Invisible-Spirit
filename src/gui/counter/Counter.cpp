/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/ref/core.h"
#include "../../../include/gui/counter/Counter.h"

namespace is06
{
namespace hud
{

CCounter::CCounter(irr::s32 init, irr::s32 min, irr::s32 max)
{
  MinValue = min;
  MaxValue = max;
  CurrentValue = init;
}

void CCounter::addValue(irr::s32 val)
{
  CurrentValue += val;
  if (CurrentValue > MaxValue) {
    CurrentValue = MaxValue;
  }
}

void CCounter::subValue(irr::s32 val)
{
  CurrentValue -= val;
  if (CurrentValue < MinValue) {
    CurrentValue = MinValue;
  }
}

void CCounter::setValue(irr::s32 val)
{
  CurrentValue = val;
  if (CurrentValue > MaxValue) {
    CurrentValue = MaxValue;
  }
  if (CurrentValue < MinValue) {
    CurrentValue = MinValue;
  }
}

CCounter::~CCounter()
{

}

}
}
