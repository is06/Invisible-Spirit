/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"

using namespace std;
using namespace irr;

Counter::Counter(s32 init, s32 min, s32 max) {
  minValue = min;
  maxValue = max;
  currentValue = init;
}

void Counter::addValue(s32 val) {
  currentValue += val;
}

void Counter::subValue(s32 val) {
  currentValue -= val;
}

void Counter::setValue(s32 val) {
  currentValue = val;
}

Counter::~Counter() {

}
