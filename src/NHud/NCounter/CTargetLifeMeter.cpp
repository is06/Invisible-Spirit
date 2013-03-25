/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/Engine/core.h"
#include "../../../include/Hud/EFontStyle.h"
#include "../../../include/Hud/CText.h"
#include "../../../include/Hud/CPicture.h"
#include "../../../include/Hud/Counter/CBar.h"
#include "../../../include/Hud/Counter/EBarStyle.h"
#include "../../../include/Hud/Counter/CTargetLife.h"

namespace is06 { namespace NHud { namespace NCounter {

//! \todo comment this function
CTargetLife::CTargetLife(s32 init, s32 min, s32 max)
{
  Label = new NHud::CText("Cible", 0, 0, EFS_STANDARD_48, 0);
  Gauge = new CBar(init, min, max, 0, 0, 150, 10, EBS_LIFE);
  BarBack = new CPicture();
}

//! \todo manage targetPosition parameter
void CTargetLife::render(const core::vector3df& targetPosition)
{
  Label->render();
  Gauge->render();
  BarBack->render();
}

//! \todo comment this function
void CTargetLife::updateValue(const s32& value)
{
  Gauge->setValue(value);
}

//! \todo comment this function
CTargetLife::~CTargetLife()
{
  delete BarBack;
  delete Label;
  delete Gauge;
}

}}}
