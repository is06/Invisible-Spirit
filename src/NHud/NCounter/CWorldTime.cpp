/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/core.h"
#include "../../../include/NHud/NText/CText.h"
#include "../../../include/NHud/NCounter/CCounter.h"
#include "../../../include/NHud/NCounter/CWorldTime.h"

namespace is06 { namespace NHud { namespace NCounter {

//! \todo comment this function
CWorldTime::CWorldTime() : CCounter()
{
  CounterText = new NText::CText();
}

//! \todo write this function
void CWorldTime::render()
{

}

//! \todo comment this function
void CWorldTime::render(s32 totalGameTime)
{
  updateValues(totalGameTime);
  updateDigits();
}

//! \todo comment this function
void CWorldTime::updateValues(s32 time)
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
void CWorldTime::updateDigits()
{
  CounterText->setText(Hours + ":" + Minutes);
}

//! \todo write this function
void CWorldTime::hide()
{
  CounterText->hide();
}

//! \todo write this function
void CWorldTime::show()
{
  CounterText->show();
}

//! \todo write this function
void CWorldTime::setOpacity(f32 value)
{
  CounterText->setOpacity(value);
}

//! \todo write this function
void CWorldTime::addOpacity(f32 value)
{
  CounterText->addOpacity(value);
}

//! \todo write this function
void CWorldTime::subOpacity(f32 value)
{
  CounterText->subOpacity(value);
}

f32 CWorldTime::getOpacity()
{
  return CounterText->getOpacity();
}

CWorldTime::~CWorldTime() {}

}}}
