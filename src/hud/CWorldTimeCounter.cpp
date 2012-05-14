/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/core.h"
#include "../../include/hud/CText.h"
#include "../../include/hud/CCounter.h"
#include "../../include/hud/CWorldTimeCounter.h"

namespace is06
{
namespace nHud
{

CWorldTimeCounter::CWorldTimeCounter() : CCounter()
{
  CounterText = new CText();
}

void CWorldTimeCounter::render()
{

}

void CWorldTimeCounter::render(s32 totalGameTime)
{
  updateValues(totalGameTime);
  updateDigits();
}

void CWorldTimeCounter::updateValues(s32 time)
{
  Hours = "";
  u32 hoursInt = time / 60;
  u32 hoursInMinutes = (hoursInt * 60);
  if (hoursInt < 10) {
    Hours += "0";
  }
  Hours += hoursInt;

  Minutes = "";
  u32 minutesInt = (time - hoursInMinutes);
  if (minutesInt < 10) {
    Minutes += "0";
  }
  Minutes += minutesInt;
}

void CWorldTimeCounter::updateDigits()
{
  CounterText->setText(Hours + ":" + Minutes);
}

void CWorldTimeCounter::hide()
{

}

void CWorldTimeCounter::show()
{

}

void CWorldTimeCounter::setOpacity(u8 value)
{

}

CWorldTimeCounter::~CWorldTimeCounter()
{

}

}
}
