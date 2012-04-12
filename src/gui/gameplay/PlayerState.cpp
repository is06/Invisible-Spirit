/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/ref/core.h"
#include "../../../include/gui/gameplay/PlayerState.h"
#include "../../../include/gui/Text.h"
#include "../../../include/gui/gameplay/MainStateInfo.h"

namespace is06
{
namespace hud
{

CPlayerState::CPlayerState()
{
  PlayerName = new CText("Ayron", 0, 0);
  LevelLabel = new CText("niv.", 0, -24);
  LevelInfo = new CText("1", 100, -24);

  HpInfo = new CMainStateInfo();
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

void CPlayerState::setOpacity(irr::u8 value)
{
  PlayerName->setOpacity(value);
  LevelLabel->setOpacity(value);
  LevelInfo->setOpacity(value);
  HpInfo->setOpacity(value);
}

CPlayerState::~CPlayerState()
{
  delete PlayerName;
  delete LevelLabel;
  delete LevelInfo;
  delete HpInfo;
}

}
}
