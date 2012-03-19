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

using namespace std;
using namespace irr;

CapacityInfo::CapacityInfo() : Hud()
{
  icon = new Picture();
  value = new Text();
}

void CapacityInfo::render()
{
  Hud::render();
  icon->render();
  value->render();
}

CapacityInfo::~CapacityInfo()
{
  delete icon;
  delete value;
}
