/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/ref/core.h"
#include "../../../include/gui/gameplay/MainStateInfo.h"
#include "../../../include/gui/Text.h"
#include "../../../include/gui/counter/BarCounter.h"

namespace is06
{
namespace hud
{

CMainStateInfo::CMainStateInfo() : CHud()
{
  Label = new CText();
  Info = new CText();
  Gauge = new CBarCounter(60, 0, 100, 150, 150, 150, 10, BAR_STYLE_LIFE);
}

void CMainStateInfo::render()
{
  CHud::render();
  Label->render();
  Info->render();
  Gauge->render();
}

void CMainStateInfo::show()
{
  Label->show();
  Info->show();
  Gauge->show();
}

void CMainStateInfo::hide()
{
  Label->hide();
  Info->hide();
  Gauge->hide();
}

void CMainStateInfo::setOpacity(irr::u8 value)
{
  Label->setOpacity(value);
  Info->setOpacity(value);
  Gauge->setOpacity(value);
}

CMainStateInfo::~CMainStateInfo()
{
  delete Label;
  delete Info;
  delete Gauge;
}

}
}
