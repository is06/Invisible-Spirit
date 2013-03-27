/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/Engine/core.h"
#include "../../include/Hud/CPlayerState.h"
#include "../../include/Hud/CText.h"
#include "../../include/Hud/PlayerState/CMainInfo.h"

namespace is06 { namespace NHud { namespace NPlayerState {

CPlayerState::CPlayerState()
{
  PlayerName = new CText("Ayron", 0, 0);
  LevelLabel = new CText("niv.", 0, -24);
  LevelInfo = new CText("1", 100, -24);

  HpInfo = new NPlayerState::CMainInfo();
}

void CPlayerState::render()
{
  PlayerName->render();
  LevelLabel->render();
  LevelInfo->render();
  HpInfo->render();
}

void CPlayerState::show()
{
  PlayerName->show();
  LevelLabel->show();
  LevelInfo->show();
  HpInfo->show();
}

void CPlayerState::hide()
{
  PlayerName->hide();
  LevelLabel->hide();
  LevelInfo->hide();
  HpInfo->hide();
}

void CPlayerState::setOpacity(f32 value)
{
  Opacity = value;
  PlayerName->setOpacity(PlayerName->getOpacity() * Opacity);
  LevelLabel->setOpacity(LevelLabel->getOpacity() * Opacity);
  LevelInfo->setOpacity(LevelInfo->getOpacity() * Opacity);
  HpInfo->setOpacity(HpInfo->getOpacity() * Opacity);
}

void CPlayerState::addOpacity(f32 value)
{
  Opacity += value;
  PlayerName->setOpacity(PlayerName->getOpacity() * Opacity);
  LevelLabel->setOpacity(LevelLabel->getOpacity() * Opacity);
  LevelInfo->setOpacity(LevelInfo->getOpacity() * Opacity);
  HpInfo->setOpacity(HpInfo->getOpacity() * Opacity);
}

void CPlayerState::subOpacity(f32 value)
{
  Opacity -= value;
  PlayerName->setOpacity(PlayerName->getOpacity() * Opacity);
  LevelLabel->setOpacity(LevelLabel->getOpacity() * Opacity);
  LevelInfo->setOpacity(LevelInfo->getOpacity() * Opacity);
  HpInfo->setOpacity(HpInfo->getOpacity() * Opacity);
}

f32 CPlayerState::getOpacity()
{
  return Opacity;
}

CPlayerState::~CPlayerState()
{
  delete PlayerName;
  delete LevelLabel;
  delete LevelInfo;
  delete HpInfo;
}

}}}
