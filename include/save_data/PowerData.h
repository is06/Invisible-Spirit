/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_POWER_DATA_H__
#define __IS06_POWER_DATA_H__

using namespace irr;
using namespace std;

struct PowerData {
  map<core::stringc, PowerElementData> fightPowers;
  map<core::stringc, PowerElementData> blackMagicPowers;
  map<core::stringc, PowerElementData> whiteMagicPowers;
  map<core::stringc, PowerElementData> statePowers;
};

#endif
