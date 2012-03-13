/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/enums/styles/FontStyle.h"
#include "../../include/enums/styles/BarStyle.h"
#include "../../include/gui/Text.h"
#include "../../include/gui/BarCounter.h"
#include "../../include/gui/Picture.h"
#include "../../include/gui/TargetLifeMeter.h"

using namespace irr;
using namespace std;

TargetLifeMeter::TargetLifeMeter(s32 init, s32 min, s32 max)
{
  label = new Text("Cible", 0, 0, FONT_STANDARD_48, 0);
  counter = new BarCounter(init, min, max, 0, 0, 150, 10, BAR_STYLE_LIFE);
  barBack = new Picture();
}

void TargetLifeMeter::render(const core::vector3df& targetPosition)
{
  label->render();
  counter->render();
  barBack->render();
}

void TargetLifeMeter::updateValue(const s32& value)
{
  counter->setValue(value);
}

TargetLifeMeter::~TargetLifeMeter()
{
  delete barBack;
  delete label;
  delete counter;
}
