/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/Engine/core.h"
#include "../../../include/Hud/PlayerState/CMainInfo.h"
#include "../../../include/Hud/CText.h"
#include "../../../include/Hud/Counter/CBar.h"

namespace is06
{
namespace NHud
{
namespace NPlayerState
{

CMainInfo::CMainInfo() : CHud()
{
  Label = new CText();
  Info = new CText();
  Gauge = new NCounter::CBar(60, 0, 100, 150, 150, 150, 10, EBS_LIFE);
}

void CMainInfo::render()
{
  CHud::render();
  Label->render();
  Info->render();
  Gauge->render();
}

void CMainInfo::show()
{
  Label->show();
  Info->show();
  Gauge->show();
}

void CMainInfo::hide()
{
  Label->hide();
  Info->hide();
  Gauge->hide();
}

void CMainInfo::setOpacity(u8 value)
{
  Label->setOpacity(value);
  Info->setOpacity(value);
  Gauge->setOpacity(value);
}

CMainInfo::~CMainInfo()
{
  delete Label;
  delete Info;
  delete Gauge;
}

}
}
}
