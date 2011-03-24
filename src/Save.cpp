/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../include/ref/core.h"

using namespace irr;
using namespace std;

Save::Save() {

}

void Save::load() {

}

void Save::write() {

}

/**
 * This function creates a brand new file for the player, every memorized pieces
 * of data are initialized here, like the start map or character HP and MP...
 * It changes the current map of the game so the player can start to play.
 */
void Save::createNewFile() {
  // Save info
  slot = 0;

  // Map Info
  currentMap = SCENE_MAP_ALPHA_ZONE;

  // PlayerInfo
  playerData.level = 1;
  playerData.currentHP = 100;
  playerData.maxHP = 100;
  playerData.currentMP = 0;
  playerData.maxMP = 0;
  playerData.strength = 10;
  playerData.defense = 8;

  powerData.fightPowerData.strike.nameTranslationIdentifier = "power_fight_strike_name";
  powerData.fightPowerData.strike.level = 1;
  powerData.fightPowerData.strike.exp = 0;

  powerData.fightPowerData.reversedStrike.nameTranslationIdentifier = "power_fight_reversed_strike_name";
  powerData.fightPowerData.reversedStrike.level = 1;
  powerData.fightPowerData.reversedStrike.exp = 0;

  powerData.fightPowerData.finalStrike.nameTranslationIdentifier = "power_fight_final_strike_name";
  powerData.fightPowerData.finalStrike.level = 1;
  powerData.fightPowerData.finalStrike.exp = 0;

  powerData.fightPowerData.block.nameTranslationIdentifier = "power_fight_block_name";
  powerData.fightPowerData.block.level = 1;
  powerData.fightPowerData.block.exp = 0;

  powerData.fightPowerData.verticalStrike.level = 0;
  powerData.fightPowerData.upperStrike.level = 0;
  powerData.fightPowerData.jumpStrike.level = 0;
  powerData.fightPowerData.circularStrike.level = 0;
  powerData.fightPowerData.omniStrike.level = 0;

  powerData.magicPowerData.barrier.level = 0;
  powerData.magicPowerData.confuse.level = 0;
  powerData.magicPowerData.countdown.level = 0;
  powerData.magicPowerData.craziness.level = 0;
  powerData.magicPowerData.cure.level = 0;
  powerData.magicPowerData.dark.level = 0;
  powerData.magicPowerData.earth.level = 0;
  powerData.magicPowerData.earth2.level = 0;
  powerData.magicPowerData.earth3.level = 0;
  powerData.magicPowerData.fire.level = 0;
  powerData.magicPowerData.fire2.level = 0;
  powerData.magicPowerData.fire3.level = 0;
  powerData.magicPowerData.freeze.level = 0;
  powerData.magicPowerData.ice.level = 0;
  powerData.magicPowerData.ice2.level = 0;
  powerData.magicPowerData.ice3.level = 0;
  powerData.magicPowerData.light.level = 0;
  powerData.magicPowerData.poison.level = 0;
  powerData.magicPowerData.reflect.level = 0;
  powerData.magicPowerData.respawn.level = 0;
  powerData.magicPowerData.restore.level = 0;
  powerData.magicPowerData.shield.level = 0;
  powerData.magicPowerData.sleep.level = 0;
  powerData.magicPowerData.slow.level = 0;
  powerData.magicPowerData.thunder.level = 0;
  powerData.magicPowerData.thunder2.level = 0;
  powerData.magicPowerData.thunder3.level = 0;
  powerData.magicPowerData.water.level = 0;
  powerData.magicPowerData.water2.level = 0;
  powerData.magicPowerData.water3.level = 0;

  powerData.statePowerData.BonusHP.level = 0;
  powerData.statePowerData.BonusMP.level = 0;
  powerData.statePowerData.BonusSpeed.level = 0;
  powerData.statePowerData.BonusStrength.level = 0;

  // Start map
  Game::changeScene(currentMap);
}

Save::~Save() {

}
