/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/ref/core.h"
#include "../../../include/gui/Text.h"
#include "../../../include/gui/counter/Counter.h"
#include "../../../include/gui/counter/WorldTimeCounter.h"

namespace is06
{
namespace hud
{

CWorldTimeCounter::CWorldTimeCounter() : CCounter()
{
  CounterText = new CText();
}

void CWorldTimeCounter::render()
{

}

void CWorldTimeCounter::render(irr::s32 totalGameTime)
{
  updateValues(totalGameTime);
  updateDigits();
}

void CWorldTimeCounter::updateValues(irr::s32 time)
{
  Hours = "";
  irr::u32 hoursInt = time / 60;
  irr::u32 hoursInMinutes = (hoursInt * 60);
  if (hoursInt < 10) {
    Hours += "0";
  }
  Hours += hoursInt;

  Minutes = "";
  irr::u32 minutesInt = (time - hoursInMinutes);
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

void CWorldTimeCounter::setOpacity(irr::u8 value)
{

}

CWorldTimeCounter::~CWorldTimeCounter()
{

}

}
}
