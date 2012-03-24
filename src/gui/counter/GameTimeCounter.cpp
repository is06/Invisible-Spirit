/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/ref/core.h"
#include "../../../include/Game.h"
#include "../../../include/save/Save.h"
#include "../../../include/gui/Text.h"
#include "../../../include/gui/counter/Counter.h"
#include "../../../include/gui/counter/GameTimeCounter.h"

using namespace irr;
using namespace std;

GameTimeCounter::GameTimeCounter() : Counter()
{
  counterText = new Text("---", Game::screenPos.left + 100, Game::screenPos.bottom + 80, FONT_STANDARD_48);
}

void GameTimeCounter::render()
{
  updateValues(Game::getCurrentSave()->getInteger(21));
  updateDigits();
  counterText->render();
}

void GameTimeCounter::updateValues(s32 time)
{
  oss.clear();
  oss.str("");

  hours = "";
  u32 hoursInt = time / 3600;
  u32 hoursInMinutes = (hoursInt * 60);
  if (hoursInt < 10) {
    hours += "00";
  } else if (hoursInt < 100) {
    hours += "0";
  }
  oss << hoursInt;
  hours += oss.str();

  oss.clear();
  oss.str("");

  minutes = "";
  u32 minutesInt = (time - hoursInMinutes) / 60;
  u32 minutesInSeconds = (minutesInt * 60);
  if (minutesInt < 10) {
    minutes += "0";
  }
  oss << minutesInt;
  minutes += oss.str();

  oss.clear();
  oss.str("");

  seconds = "";
  u32 secondsInt = (time - hoursInMinutes - minutesInSeconds);
  if (secondsInt < 10) {
    seconds += "0";
  }
  oss << secondsInt;
  seconds += oss.str();
}

void GameTimeCounter::updateDigits()
{
  //cout << hours + ":" + minutes + ":" + seconds << endl;
  counterText->setText(hours + ":" + minutes + ":" + seconds);
}

void GameTimeCounter::hide()
{
  //counterText->hide();
}

void GameTimeCounter::show()
{
  //counterText->show();
}

void GameTimeCounter::setOpacity(u8 value)
{
  //counterText->setOpacity(value);
}

GameTimeCounter::~GameTimeCounter()
{

}
