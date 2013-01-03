/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/core.h"
#include "../../include/engine/CGame.h"
#include "../../include/hud/CHudEnsembleCommands.h"
#include "../../include/hud/CTextButton.h"
#include "../../include/hud/CIconButton.h"
#include "../../include/hud/CIconTextButton.h"

namespace is06
{
namespace nHud
{

CHudEnsembleCommands::CHudEnsembleCommands() : CHud()
{
  Menu = new CTextButton(nEngine::CGame::ScreenPos.Hud.Left + 70, nEngine::CGame::ScreenPos.Hud.Bottom + 110);
  Defense = new CIconButton(nEngine::CGame::ScreenPos.Hud.Left + 30, nEngine::CGame::ScreenPos.Hud.Bottom + 70);
  Jump = new CIconButton(nEngine::CGame::ScreenPos.Hud.Left + 110, nEngine::CGame::ScreenPos.Hud.Bottom + 70);
  Command = new CIconTextButton(nEngine::CGame::ScreenPos.Hud.Left + 70, nEngine::CGame::ScreenPos.Hud.Bottom + 30);
}

void CHudEnsembleCommands::render()
{
  CHud::render();
  Menu->render();
  Defense->render();
  Jump->render();
  Command->render();
}

void CHudEnsembleCommands::hide()
{
  Menu->hide();
  Defense->hide();
  Jump->hide();
  Command->hide();
}

void CHudEnsembleCommands::show()
{
  Menu->show();
  Defense->show();
  Jump->show();
  Command->show();
}

void CHudEnsembleCommands::setOpacity(u8 value)
{
  Menu->setOpacity(value);
  Defense->setOpacity(value);
  Jump->setOpacity(value);
  Command->setOpacity(value);
}

CHudEnsembleCommands::~CHudEnsembleCommands()
{
  delete Menu;
  delete Defense;
  delete Jump;
  delete Command;
}

}
}
