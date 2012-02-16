/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/gui/Text.h"
#include "../../include/gui/Counter.h"
#include "../../include/gui/WorldTimeCounter.h"

using namespace irr;
using namespace std;

WorldTimeCounter::WorldTimeCounter() : Counter()
{
  counterText = new Text();
}

void WorldTimeCounter::render()
{

}

void WorldTimeCounter::render(s32 totalGameTime)
{
  updateValues(totalGameTime);
  updateDigits();
}

void WorldTimeCounter::updateValues(s32 time)
{
  hours = "";
  u32 hoursInt = time / 60;
  u32 hoursInMinutes = (hoursInt * 60);
  if (hoursInt < 10) {
    hours += "0";
  }
  hours += hoursInt;

  minutes = "";
  u32 minutesInt = (time - hoursInMinutes);
  if (minutesInt < 10) {
    minutes += "0";
  }
  minutes += minutesInt;
}

void WorldTimeCounter::updateDigits()
{
  counterText->setText(hours + ":" + minutes);
}

void WorldTimeCounter::hide()
{

}

void WorldTimeCounter::show()
{

}

void WorldTimeCounter::setOpacity(u8 value)
{

}

WorldTimeCounter::~WorldTimeCounter()
{

}

