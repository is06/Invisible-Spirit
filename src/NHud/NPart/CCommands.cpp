/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/core.h"
#include "../../../include/NEngine/NCore/CGame.h"
#include "../../../include/NHud/NPart/CCommands.h"
#include "../../../include/NHud/NText/CText.h"
#include "../../../include/NHud/NButton/CTextButton.h"
#include "../../../include/NHud/NButton/CIconButton.h"
#include "../../../include/NHud/NButton/CIconTextButton.h"

namespace is06 { namespace NHud { namespace NPart {

CCommands::CCommands() : NCore::CHudEntity()
{
  Menu = new NButton::CTextButton(NEngine::NCore::CGame::ScreenPos.Hud.Left + 70, NEngine::NCore::CGame::ScreenPos.Hud.Bottom + 110);
  Defense = new NButton::CIconButton(NEngine::NCore::CGame::ScreenPos.Hud.Left + 30, NEngine::NCore::CGame::ScreenPos.Hud.Bottom + 70);
  Jump = new NButton::CIconButton(NEngine::NCore::CGame::ScreenPos.Hud.Left + 110, NEngine::NCore::CGame::ScreenPos.Hud.Bottom + 70);
  Command = new NButton::CIconTextButton(NEngine::NCore::CGame::ScreenPos.Hud.Left + 70, NEngine::NCore::CGame::ScreenPos.Hud.Bottom + 30);
}

void CCommands::render()
{
  NCore::CHudEntity::render();
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

void CCommands::setOpacity(f32 value)
{
  Opacity = value;
  Menu->setOpacity(Menu->getOpacity() * Opacity);
  Defense->setOpacity(Defense->getOpacity() * Opacity);
  Jump->setOpacity(Jump->getOpacity() * Opacity);
  Command->setOpacity(Command->getOpacity() * Opacity);
}

void CCommands::addOpacity(f32 value)
{
  Opacity += value;
  Menu->setOpacity(Menu->getOpacity() * Opacity);
  Defense->setOpacity(Defense->getOpacity() * Opacity);
  Jump->setOpacity(Jump->getOpacity() * Opacity);
  Command->setOpacity(Command->getOpacity() * Opacity);
}

void CCommands::subOpacity(f32 value)
{
  Opacity -= value;
  Menu->setOpacity(Menu->getOpacity() * Opacity);
  Defense->setOpacity(Defense->getOpacity() * Opacity);
  Jump->setOpacity(Jump->getOpacity() * Opacity);
  Command->setOpacity(Command->getOpacity() * Opacity);
}

f32 CCommands::getOpacity()
{
  return Opacity;
}

CCommands::~CCommands()
{
  delete Menu;
  delete Defense;
  delete Jump;
  delete Command;
}

}}}
