/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/core.h"
#include "../../include/engine/CGame.h"
#include "../../include/hud/CBarCounter.h"
#include "../../include/hud/CEnergyInterface.h"

namespace is06
{
namespace nHud
{

CEnergyInterface::CEnergyInterface() : CHud()
{
  HpBar = new CBarCounter(100, 0, 100, (nEngine::CGame::ScreenPos.Right - 170), (nEngine::CGame::ScreenPos.Bottom + 30), 150, 4, EBS_LIFE);
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
