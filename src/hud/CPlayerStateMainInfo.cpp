/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/core.h"
#include "../../include/hud/CPlayerStateMainInfo.h"
#include "../../include/hud/CText.h"
#include "../../include/hud/CBarCounter.h"

namespace is06
{
namespace nHud
{

CPlayerStateMainInfo::CPlayerStateMainInfo() : CHud()
{
  Label = new CText();
  Info = new CText();
  Gauge = new CBarCounter(60, 0, 100, 150, 150, 150, 10, EBS_LIFE);
}

void CPlayerStateMainInfo::render()
{
  CHud::render();
  Label->render();
  Info->render();
  Gauge->render();
}

void CPlayerStateMainInfo::show()
{
  Label->show();
  Info->show();
  Gauge->show();
}

void CPlayerStateMainInfo::hide()
{
  Label->hide();
  Info->hide();
  Gauge->hide();
}

void CPlayerStateMainInfo::setOpacity(u8 value)
{
  Label->setOpacity(value);
  Info->setOpacity(value);
  Gauge->setOpacity(value);
}

CPlayerStateMainInfo::~CPlayerStateMainInfo()
{
  delete Label;
  delete Info;
  delete Gauge;
}

}
}
