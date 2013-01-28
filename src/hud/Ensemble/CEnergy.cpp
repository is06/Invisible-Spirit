/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/Engine/core.h"
#include "../../../include/Engine/CGame.h"
#include "../../../include/Hud/Counter/CBar.h"
#include "../../../include/Hud/Ensemble/CEnergy.h"

namespace is06
{
namespace NHud
{
namespace NEnsemble
{

CEnergy::CEnergy() : CHud()
{
  HpBar = new NCounter::CBar(100, 0, 100, (NEngine::CGame::ScreenPos.Hud.Right - 170), (NEngine::CGame::ScreenPos.Hud.Bottom + 30), 150, 4, EBS_LIFE);
}

void CEnergy::render()
{
  CHud::render();
  HpBar->render();
}

void CEnergy::hide()
{
  HpBar->hide();
}

void CEnergy::show()
{
  HpBar->show();
}

void CEnergy::setOpacity(f32 value)
{
  Opacity = value;
  HpBar->setOpacity(HpBar->getOpacity() * Opacity);
}

void CEnergy::addOpacity(f32 value)
{
  Opacity += value;
  HpBar->setOpacity(HpBar->getOpacity() * Opacity);
}

void CEnergy::subOpacity(f32 value)
{
  Opacity -= value;
  HpBar->setOpacity(HpBar->getOpacity() * Opacity);
}

f32 CEnergy::getOpacity()
{
  return Opacity;
}

CEnergy::~CEnergy()
{
  delete HpBar;
}

}
}
}
