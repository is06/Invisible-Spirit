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

//! \todo comment this function
CWorldTimeCounter::CWorldTimeCounter() : CCounter()
{
  CounterText = new CText();
}

//! \todo write this function
void CWorldTimeCounter::render()
{

}

//! \todo comment this function
void CWorldTimeCounter::render(s32 totalGameTime)
{
  updateValues(totalGameTime);
  updateDigits();
}

//! \todo comment this function
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

//! \todo comment this function
void CWorldTimeCounter::updateDigits()
{
  CounterText->setText(Hours + ":" + Minutes);
}

//! \todo write this function
void CWorldTimeCounter::hide()
{

}

//! \todo write this function
void CWorldTimeCounter::show()
{

}

//! \todo write this function
void CWorldTimeCounter::setOpacity(u8 value)
{

}

CWorldTimeCounter::~CWorldTimeCounter() {}

}
}
