/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/core.h"
#include "../../include/engine/CGame.h"
#include "../../include/hud/CBarCounter.h"
#include "../../include/hud/CHudEnsembleEnergy.h"

namespace is06
{
namespace nHud
{

CHudEnsembleEnergy::CHudEnsembleEnergy() : CHud()
{
  HpBar = new CBarCounter(100, 0, 100, (nEngine::CGame::ScreenPos.Hud.Right - 170), (nEngine::CGame::ScreenPos.Hud.Bottom + 30), 150, 4, EBS_LIFE);
}

void CHudEnsembleEnergy::render()
{
  CHud::render();
  HpBar->render();
}

void CHudEnsembleEnergy::hide()
{
  HpBar->hide();
}

void CHudEnsembleEnergy::show()
{
  HpBar->show();
}

void CHudEnsembleEnergy::setOpacity(u8 value)
{
  HpBar->setOpacity(value);
}

CHudEnsembleEnergy::~CHudEnsembleEnergy()
{
  delete HpBar;
}

}
}
