/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_MAGIC_POWER_DATA_H__
#define __IS06_MAGIC_POWER_DATA_H__

using namespace irr;
using namespace std;

struct MagicPowerData {
  // High level = high magical power
  PowerElementData fire;      // Blaze
  PowerElementData fire2;     // Blaze x2 (2 blazes at once)
  PowerElementData fire3;     // Blaze x3 (3 blazes at once)
  // High level = high magical power
  PowerElementData ice;       // Shard
  PowerElementData ice2;      // Shard x2
  PowerElementData ice3;      // Shard x3
  // High level = high magical power
  PowerElementData water;     // Bubble
  PowerElementData water2;    // Bubble x2
  PowerElementData water3;    // Bubble x3
  // High level = high magical power
  PowerElementData thunder;   // Lightning
  PowerElementData thunder2;  // Lightning x2
  PowerElementData thunder3;  // Lightning x3
  // High level = high magical power
  PowerElementData earth;     // Rock
  PowerElementData earth2;    // Rock x2
  PowerElementData earth3;    // Rock x3
  // High level = high magical power
  PowerElementData dark;      // Dark
  PowerElementData light;     // Light
  // Level 1 = +33% / Level 2 = +66% / Level 3 = +100%
  PowerElementData cure;      // Cure
  // Level 1 = +1HP / Level 2 = +50% / Level 3 = +100%
  PowerElementData respawn;   // Respawn
  // Level 1 = +1%/sec / Level 2 = +2%/sec / Level 3 = +5%/sec
  PowerElementData restore;   // Restore
  // Level 1 = damage-10% / Level 2 = damage-20% / Level 3 = damage-40%
  PowerElementData shield;    // Shield
  // Level 1 = damage-10% / Level 2 = damage-20% / Level 3 = damage-40%
  PowerElementData barrier;   // Barrier
  // Level 1 = reflect 20% / Level 2 = reflect 50% / Level 3 = reflect 100%
  PowerElementData reflect;   // Reflect

  PowerElementData poison;
  PowerElementData sleep;
  PowerElementData slow;
  PowerElementData freeze;
  PowerElementData craziness;
  PowerElementData confuse;
  PowerElementData countdown;
};

#endif

