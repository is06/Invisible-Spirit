/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/core.h"
#include "../../../include/NHud/NCounter/CCounter.h"

namespace is06 { namespace NHud { namespace NCounter {

CCounter::CCounter(s32 init, s32 min, s32 max)
{
  MinValue = min;
  MaxValue = max;
  CurrentValue = init;
}

void CCounter::addValue(s32 val)
{
  CurrentValue += val;
  if (CurrentValue > MaxValue) {
    CurrentValue = MaxValue;
  }
}

void CCounter::subValue(s32 val)
{
  CurrentValue -= val;
  if (CurrentValue < MinValue) {
    CurrentValue = MinValue;
  }
}

void CCounter::setValue(s32 val)
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

}}}
