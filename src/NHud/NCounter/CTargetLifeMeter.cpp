/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/core.h"
#include "../../../include/NHud/NText/EFontStyle.h"
#include "../../../include/NHud/NText/CText.h"
#include "../../../include/NHud/NPrimitive/CPicture.h"
#include "../../../include/NHud/NCounter/CBarMeter.h"
#include "../../../include/NHud/NCounter/EBarStyle.h"
#include "../../../include/NHud/NCounter/CTargetLifeMeter.h"

namespace is06 { namespace NHud { namespace NCounter {

//! \todo comment this function
CTargetLifeMeter::CTargetLifeMeter(s32 init, s32 min, s32 max)
{
    Label = new NText::CText("Cible", 0, 0, NText::EFS_STANDARD_48, 0);
    Gauge = new CBarMeter(init, min, max, 0, 0, 150, 10, NCounter::EBS_LIFE);
    BarBack = new NPrimitive::CPicture();
}

//! \todo manage targetPosition parameter
void CTargetLifeMeter::render(const core::vector3df& targetPosition)
{
    Label->render();
    Gauge->render();
    BarBack->render();
}

//! \todo comment this function
void CTargetLifeMeter::updateValue(const s32& value)
{
    Gauge->setValue(value);
}

//! \todo comment this function
CTargetLifeMeter::~CTargetLifeMeter()
{
    delete BarBack;
    delete Label;
    delete Gauge;
}

}}}
