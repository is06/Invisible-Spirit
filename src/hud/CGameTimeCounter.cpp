/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/core.h"
#include "../../include/engine/CGame.h"
#include "../../include/engine/CSave.h"
#include "../../include/hud/CText.h"
#include "../../include/hud/CCounter.h"
#include "../../include/hud/CGameTimeCounter.h"

namespace is06
{
namespace nHud
{

CGameTimeCounter::CGameTimeCounter() : CCounter()
{
  CounterText = new CText(
    "---",
    nEngine::CGame::ScreenPos.Left + 100,
    nEngine::CGame::ScreenPos.Bottom + 80,
    EFS_STANDARD_48
  );
}

void CGameTimeCounter::render()
{
  updateValues(nEngine::CGame::getCurrentSave()->getInteger(21));
  updateDigits();
  CounterText->render();
}

void CGameTimeCounter::updateValues(s32 time)
{
  Oss.clear();
  Oss.str("");

  Hours = "";
  u32 hoursInt = time / 3600;
  u32 hoursInMinutes = (hoursInt * 60);
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
  u32 minutesInt = (time - hoursInMinutes) / 60;
  u32 minutesInSeconds = (minutesInt * 60);
  if (minutesInt < 10) {
    Minutes += "0";
  }
  Oss << minutesInt;
  Minutes += Oss.str();

  Oss.clear();
  Oss.str("");

  Seconds = "";
  u32 secondsInt = (time - hoursInMinutes - minutesInSeconds);
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

void CGameTimeCounter::setOpacity(u8 value)
{
  //counterText->setOpacity(value);
}

CGameTimeCounter::~CGameTimeCounter()
{

}

}
}
