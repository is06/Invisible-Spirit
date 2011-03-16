/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_FIGHT_POWER_DATA_H__
#define __IS06_FIGHT_POWER_DATA_H__

using namespace irr;
using namespace std;

struct FightPowerData {
  // Horizontal combo
  PowerElementData strike;
  PowerElementData reversedStrike;
  PowerElementData finalStrike;

  // Vertical combo
  PowerElementData verticalStrike;
  PowerElementData upperStrike;
  PowerElementData jumpStrike;

  // Other strikes
  PowerElementData circularStrike;

  // Power special strikes
  PowerElementData omniStrike;

  PowerElementData block;
};

#endif
