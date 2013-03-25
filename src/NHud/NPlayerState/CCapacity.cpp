/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/Engine/core.h"
#include "../../../include/Hud/PlayerState/CCapacity.h"
#include "../../../include/Hud/CPicture.h"
#include "../../../include/Hud/CText.h"

namespace is06 { namespace NHud { namespace NPlayerState {

CCapacity::CCapacity() : CHud()
{
  Icon = new CPicture();
  Value = new CText();
}

void CCapacity::render()
{
  CHud::render();
  Icon->render();
  Value->render();
}

CCapacity::~CCapacity()
{
  delete Icon;
  delete Value;
}

}}}
