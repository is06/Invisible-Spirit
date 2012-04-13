/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/core.h"
#include "../../include/engine/Game.h"
#include "../../include/hud/BarCounter.h"
#include "../../include/hud/EnergyInterface.h"

namespace is06
{
namespace hud
{

CEnergyInterface::CEnergyInterface() : CHud()
{
  HpBar = new CBarCounter(100, 0, 100, (engine::CGame::ScreenPos.Right - 170), (engine::CGame::ScreenPos.Bottom + 30), 150, 4, BAR_STYLE_LIFE);
}

void CEnergyInterface::render()
{
  CHud::render();
  HpBar->render();
}

void CEnergyInterface::hide()
{
  HpBar->hide();
}

void CEnergyInterface::show()
{
  HpBar->show();
}

void CEnergyInterface::setOpacity(u8 value)
{
  HpBar->setOpacity(value);
}

CEnergyInterface::~CEnergyInterface()
{
  delete HpBar;
}

}
}
