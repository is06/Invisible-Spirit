/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/core.h"
#include "../../include/hud/CHudEnsemble.h"
#include "../../include/hud/CHudEnsembleCommands.h"

namespace is06
{
namespace nHud
{

CHudEnsemble::CHudEnsemble() : CHud()
{
  Buttons = new CHudEnsembleCommands();
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

void CHudEnsemble::setOpacity(u8 value)
{
  Buttons->setOpacity(value);
}

CHudEnsemble::~CHudEnsemble()
{
  delete Buttons;
}

}
}
