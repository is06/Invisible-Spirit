/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/Engine/core.h"
#include "../../include/Hud/CHudEnsemble.h"
#include "../../include/Hud/Ensemble/CCommands.h"

namespace is06 { namespace NHud { namespace NPart

CHudEnsemble::CHudEnsemble() : CHud()
{
  Buttons = new NEnsemble::CCommands();
}

void CHudEnsemble::render()
{
  CHud::render();
  Buttons->render();
}

void CHudEnsemble::hide()
{
  Buttons->hide();
}

void CHudEnsemble::show()
{
  Buttons->show();
}

void CHudEnsemble::setOpacity(f32 value)
{
  Opacity = value;
  Buttons->setOpacity(Buttons->getOpacity() * Opacity);
}

void CHudEnsemble::addOpacity(f32 value)
{
  Opacity += value;
  Buttons->setOpacity(Buttons->getOpacity() * Opacity);
}

void CHudEnsemble::subOpacity(f32 value)
{
  Opacity -= value;
  Buttons->setOpacity(Buttons->getOpacity() * Opacity);
}

f32 CHudEnsemble::getOpacity()
{
  return Opacity;
}

CHudEnsemble::~CHudEnsemble()
{
  delete Buttons;
}

}}}
