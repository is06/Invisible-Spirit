/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/core.h"
#include "../../include/hud/EFontStyle.h"
#include "../../include/hud/EBarStyle.h"
#include "../../include/hud/CText.h"
#include "../../include/hud/CBarCounter.h"
#include "../../include/hud/CPicture.h"
#include "../../include/hud/CTargetLifeMeter.h"

namespace is06
{
namespace nHud
{

CTargetLifeMeter::CTargetLifeMeter(s32 init, s32 min, s32 max)
{
  Label = new CText("Cible", 0, 0, EFS_STANDARD_48, 0);
  Gauge = new CBarCounter(init, min, max, 0, 0, 150, 10, EBS_LIFE);
  BarBack = new CPicture();
}

void CTargetLifeMeter::render(const core::vector3df& targetPosition)
{
  Label->render();
  Gauge->render();
  BarBack->render();
}

void CTargetLifeMeter::updateValue(const s32& value)
{
  Gauge->setValue(value);
}

CTargetLifeMeter::~CTargetLifeMeter()
{
  delete BarBack;
  delete Label;
  delete Gauge;
}

}
}
