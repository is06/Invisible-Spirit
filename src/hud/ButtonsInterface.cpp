/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/core.h"
#include "../../include/engine/Game.h"
#include "../../include/hud/ButtonsInterface.h"
#include "../../include/hud/TextButton.h"
#include "../../include/hud/IconButton.h"
#include "../../include/hud/IconTextButton.h"

namespace is06
{
namespace hud
{

CButtonsInterface::CButtonsInterface() : CHud()
{
  Menu = new CTextButton(engine::CGame::ScreenPos.Left + 70, engine::CGame::ScreenPos.Bottom + 110);
  Defense = new CIconButton(engine::CGame::ScreenPos.Left + 30, engine::CGame::ScreenPos.Bottom + 70);
  Jump = new CIconButton(engine::CGame::ScreenPos.Left + 110, engine::CGame::ScreenPos.Bottom + 70);
  Command = new CIconTextButton(engine::CGame::ScreenPos.Left + 70, engine::CGame::ScreenPos.Bottom + 30);
}

void CButtonsInterface::render()
{
  CHud::render();
  Menu->render();
  Defense->render();
  Jump->render();
  Command->render();
}

void CButtonsInterface::hide()
{
  Menu->hide();
  Defense->hide();
  Jump->hide();
  Command->hide();
}

void CButtonsInterface::show()
{
  Menu->show();
  Defense->show();
  Jump->show();
  Command->show();
}

void CButtonsInterface::setOpacity(u8 value)
{
  Menu->setOpacity(value);
  Defense->setOpacity(value);
  Jump->setOpacity(value);
  Command->setOpacity(value);
}

CButtonsInterface::~CButtonsInterface()
{
  delete Menu;
  delete Defense;
  delete Jump;
  delete Command;
}

}
}
