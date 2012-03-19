/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/ref/core.h"
#include "../../../include/gui/Text.h"
#include "../../../include/gui/counter/Counter.h"
#include "../../../include/gui/counter/GameTimeCounter.h"

using namespace irr;
using namespace std;

GameTimeCounter::GameTimeCounter() : Counter()
{
  counterText = new Text();
}

void GameTimeCounter::render()
{

}

void GameTimeCounter::render(s32 totalGameTime)
{
  updateValues(totalGameTime);
  updateDigits();
}

void GameTimeCounter::updateValues(s32 time)
{
  hours = "";
  u32 hoursInt = time / 3600;
  u32 hoursInMinutes = (hoursInt * 60);
  if (hoursInt < 10) {
    hours += "0";
  }
  hours += hoursInt;

  minutes = "";
  u32 minutesInt = (time - hoursInMinutes) / 60;
  u32 minutesInSeconds = (minutesInt * 60);
  if (minutesInt < 10) {
    minutes += "0";
  }
  minutes += minutesInt;

  seconds = "";
  u32 secondsInt = (time - hoursInMinutes - minutesInSeconds);
  if (secondsInt < 10) {
    seconds += "0";
  }
  seconds += secondsInt;
}

void GameTimeCounter::updateDigits()
{
  counterText->setText(hours + ":" + minutes + ":" + seconds);
}

void GameTimeCounter::hide()
{

}

void GameTimeCounter::show()
{

}

void GameTimeCounter::setOpacity(u8 value)
{

}

GameTimeCounter::~GameTimeCounter()
{

}
