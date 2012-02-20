/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/gui/Text.h"
#include "../../include/gui/Counter.h"
#include "../../include/gui/GameTimeCounter.h"

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
  hours = L"";
  u32 hoursInt = time / 3600;
  u32 hoursInMinutes = (hoursInt * 60);
  if (hoursInt < 10) {
    hours += L"0";
  }
  hours += hoursInt;

  minutes = L"";
  u32 minutesInt = (time - hoursInMinutes) / 60;
  u32 minutesInSeconds = (minutesInt * 60);
  if (minutesInt < 10) {
    minutes += L"0";
  }
  minutes += minutesInt;

  seconds = L"";
  u32 secondsInt = (time - hoursInMinutes - minutesInSeconds);
  if (secondsInt < 10) {
    seconds += L"0";
  }
  seconds += secondsInt;
}

void GameTimeCounter::updateDigits()
{
  counterText->setText(hours + L":" + minutes + L":" + seconds);
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
