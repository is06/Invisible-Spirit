/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/core.h"
#include "../../include/hud/CGameplayInterface.h"
#include "../../include/hud/CButtonsInterface.h"

namespace is06
{
namespace nHud
{

CGameplayInterface::CGameplayInterface() : CHud()
{
  Buttons = new CButtonsInterface();
}

void CGameplayInterface::render()
{
  CHud::render();
  Buttons->render();
}

void CGameplayInterface::hide()
{
  Buttons->hide();
}

void CGameplayInterface::show()
{
  Buttons->show();
}

void CGameplayInterface::setOpacity(u8 value)
{
  Buttons->setOpacity(value);
}

CGameplayInterface::~CGameplayInterface()
{
  delete Buttons;
}

}
}
