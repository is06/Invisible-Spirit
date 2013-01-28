/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/Engine/core.h"
#include "../../../include/Engine/CGame.h"
#include "../../../include/Engine/CSave.h"
#include "../../../include/Hud/CText.h"
#include "../../../include/Hud/CCounter.h"
#include "../../../include/Hud/Counter/CGameTime.h"

namespace is06
{
namespace NHud
{
namespace NCounter
{

//! \todo comment this function
CGameTime::CGameTime() : CCounter()
{
  CounterText = new CText(
    "---",
    NEngine::CGame::ScreenPos.Hud.Left + 100,
    NEngine::CGame::ScreenPos.Hud.Bottom + 80,
    EFS_STANDARD_48
  );
}

//! \todo comment this function
void CGameTime::render()
{
  updateValues(NEngine::CGame::getCurrentSave()->getInteger(21));
  updateDigits();
  CounterText->render();
}

//! \todo comment this function
void CGameTime::updateValues(s32 time)
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

//! \todo comment this function
void CGameTime::updateDigits()
{
  CounterText->setText(Hours + ":" + Minutes + ":" + Seconds);
}

//! \todo write this function
void CGameTime::hide()
{
  CounterText->hide();
}

//! \todo write this function
void CGameTime::show()
{
  CounterText->show();
}

//! \todo write this function
void CGameTime::setOpacity(f32 value)
{
  CounterText->setOpacity(value);
}

//! \todo write this function
void CGameTime::addOpacity(f32 value)
{
  CounterText->addOpacity(value);
}

//! \todo write this function
void CGameTime::subOpacity(f32 value)
{
  CounterText->subOpacity(value);
}

f32 CGameTime::getOpacity()
{
  return CounterText->getOpacity();
}

CGameTime::~CGameTime() {}

}
}
}
