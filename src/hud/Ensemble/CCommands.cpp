/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/Engine/core.h"
#include "../../../include/Engine/CGame.h"
#include "../../../include/Hud/Ensemble/CCommands.h"
#include "../../../include/Hud/Button/CText.h"
#include "../../../include/Hud/Button/CIcon.h"
#include "../../../include/Hud/Button/CIconText.h"

namespace is06
{
namespace NHud
{
namespace NEnsemble
{

CCommands::CCommands() : CHud()
{
  Menu = new NButton::CText(NEngine::CGame::ScreenPos.Hud.Left + 70, NEngine::CGame::ScreenPos.Hud.Bottom + 110);
  Defense = new NButton::CIcon(NEngine::CGame::ScreenPos.Hud.Left + 30, NEngine::CGame::ScreenPos.Hud.Bottom + 70);
  Jump = new NButton::CIcon(NEngine::CGame::ScreenPos.Hud.Left + 110, NEngine::CGame::ScreenPos.Hud.Bottom + 70);
  Command = new NButton::CIconText(NEngine::CGame::ScreenPos.Hud.Left + 70, NEngine::CGame::ScreenPos.Hud.Bottom + 30);
}

void CCommands::render()
{
  CHud::render();
  Menu->render();
  Defense->render();
  Jump->render();
  Command->render();
}

void CCommands::hide()
{
  Menu->hide();
  Defense->hide();
  Jump->hide();
  Command->hide();
}

void CCommands::show()
{
  Menu->show();
  Defense->show();
  Jump->show();
  Command->show();
}

void CCommands::setOpacity(u8 value)
{
  Menu->setOpacity(value);
  Defense->setOpacity(value);
  Jump->setOpacity(value);
  Command->setOpacity(value);
}

CCommands::~CCommands()
{
  delete Menu;
  delete Defense;
  delete Jump;
  delete Command;
}

}
}
}
