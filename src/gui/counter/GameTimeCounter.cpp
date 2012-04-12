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

namespace is06
{
namespace hud
{

CGameTimeCounter::CGameTimeCounter() : CCounter()
{
  CounterText = new CText(
    "---",
    engine::CGame::ScreenPos.Left + 100,
    engine::CGame::ScreenPos.Bottom + 80,
    FONT_STANDARD_48
  );
}

void CGameTimeCounter::render()
{
  updateValues(engine::CGame::getCurrentSave()->getInteger(21));
  updateDigits();
  CounterText->render();
}

void CGameTimeCounter::updateValues(irr::s32 time)
{
  Oss.clear();
  Oss.str("");

  Hours = "";
  irr::u32 hoursInt = time / 3600;
  irr::u32 hoursInMinutes = (hoursInt * 60);
  if (hoursInt < 10) {
    Hours += "00";
  } else if (hoursInt < 100) {
    Hours += "0";
  }
  Oss << hoursInt;
  Hours += Oss.str();

  Oss.clear();
  Oss.str("");

  Minutes = "";
  irr::u32 minutesInt = (time - hoursInMinutes) / 60;
  irr::u32 minutesInSeconds = (minutesInt * 60);
  if (minutesInt < 10) {
    Minutes += "0";
  }
  Oss << minutesInt;
  Minutes += Oss.str();

  Oss.clear();
  Oss.str("");

  Seconds = "";
  irr::u32 secondsInt = (time - hoursInMinutes - minutesInSeconds);
  if (secondsInt < 10) {
    Seconds += "0";
  }
  Oss << secondsInt;
  Seconds += Oss.str();
}

void CGameTimeCounter::updateDigits()
{
  //cout << hours + ":" + minutes + ":" + seconds << endl;
  CounterText->setText(Hours + ":" + Minutes + ":" + Seconds);
}

void CGameTimeCounter::hide()
{
  //counterText->hide();
}

void CGameTimeCounter::show()
{
  //counterText->show();
}

void CGameTimeCounter::setOpacity(irr::u8 value)
{
  //counterText->setOpacity(value);
}

CGameTimeCounter::~CGameTimeCounter()
{

}

}
}
