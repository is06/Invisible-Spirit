/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/ref/core.h"
#include "../../../include/gui/gameplay/CapacityInfo.h"
#include "../../../include/gui/Picture.h"
#include "../../../include/gui/Text.h"

namespace is06
{
namespace hud
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
