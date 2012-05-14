/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/core.h"
#include "../../include/hud/CCapacityInfo.h"
#include "../../include/hud/CPicture.h"
#include "../../include/hud/CText.h"

namespace is06
{
namespace nHud
{

CCapacityInfo::CCapacityInfo() : CHud()
{
  Icon = new CPicture();
  Value = new CText();
}

void CCapacityInfo::render()
{
  CHud::render();
  Icon->render();
  Value->render();
}

CCapacityInfo::~CCapacityInfo()
{
  delete Icon;
  delete Value;
}

}
}
