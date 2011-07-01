/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../include/ref/core.h"
#include "../include/Save.h"
#include "../include/Game.h"

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
  playerData.currentLevel = 1;

  playerData.currentHP = 100;
  playerData.maxHP = 100;
  playerData.currentMP = 0;
  playerData.maxMP = 0;

  playerData.strength = 10;
  playerData.defense = 8;
  playerData.magic = 0;
  playerData.resistance = 0;
  playerData.speed = 11;
  playerData.precision = 9;

  initFightPowers();
  initMagicPowers();
  initStatePowers();

  // Start map
  Game::changeScene(currentMap);
}

/**
 *
 */
void Save::initFightPowers() {
  PowerElementData& power = powerData.fightPowers["strike"];
  power.nameTranslationIdentifier = "gameplay_power_fight_strike";
  power.level = 1;
  power.exp = 0;
  power.nextLevel = 2000;

  power = powerData.fightPowers["reversed_strike"];
  power.nameTranslationIdentifier = "gameplay_power_fight_reversed_strike";
  power.level = 1;
  power.exp = 0;
  power.nextLevel = 2000;

  power = powerData.fightPowers["final_strike"];
  power.nameTranslationIdentifier = "gameplay_power_fight_final_strike";
  power.level = 1;
  power.exp = 0;
  power.nextLevel = 2000;

  power = powerData.fightPowers["block"];
  power.nameTranslationIdentifier = "gameplay_power_fight_block";
  power.level = 1;
  power.exp = 0;

  powerData.fightPowers["vertical_strike"].level = 0;
  powerData.fightPowers["upper_strike"].level = 0;
  powerData.fightPowers["jump_strike"].level = 0;
  powerData.fightPowers["circular_strike"].level = 0;
  powerData.fightPowers["omni_strike"].level = 0;
}

/**
 *
 */
void Save::initMagicPowers() {
/*
  powerData.magicPowers["barrier"].level = 0;
  powerData.magicPowers["confuse"].level = 0;
  powerData.magicPowers["countdown"].level = 0;
  powerData.magicPowers["craziness"].level = 0;
  powerData.magicPowers["cure"].level = 0;
  powerData.magicPowers["dark"].level = 0;
  powerData.magicPowers["earth"].level = 0;
  powerData.magicPowers["earth2"].level = 0;
  powerData.magicPowers["earth3"].level = 0;
  powerData.magicPowers["fire"].level = 0;
  powerData.magicPowers["fire2"].level = 0;
  powerData.magicPowers["fire3"].level = 0;
  powerData.magicPowers["freeze"].level = 0;
  powerData.magicPowers["ice"].level = 0;
  powerData.magicPowers["ice2"].level = 0;
  powerData.magicPowers["ice3"].level = 0;
  powerData.magicPowers["light"].level = 0;
  powerData.magicPowers["poison"].level = 0;
  powerData.magicPowers["reflect"].level = 0;
  powerData.magicPowers["respawn"].level = 0;
  powerData.magicPowers["restore"].level = 0;
  powerData.magicPowers["shield"].level = 0;
  powerData.magicPowers["sleep"].level = 0;
  powerData.magicPowers["slow"].level = 0;
  powerData.magicPowers["thunder"].level = 0;
  powerData.magicPowers["thunder2"].level = 0;
  powerData.magicPowers["thunder3"].level = 0;
  powerData.magicPowers["water"].level = 0;
  powerData.magicPowers["water2"].level = 0;
  powerData.magicPowers["water3"].level = 0;
*/
}

/**
 *
 */
void Save::initStatePowers() {
  powerData.statePowers["bonus_hp"].level = 0;
  powerData.statePowers["bonus_mp"].level = 0;
  powerData.statePowers["bonus_strength"].level = 0;
  powerData.statePowers["bonus_defense"].level = 0;
  powerData.statePowers["bonus_magic"].level = 0;
  powerData.statePowers["bonus_resistance"].level = 0;
  powerData.statePowers["bonus_precision"].level = 0;
  powerData.statePowers["bonus_speed"].level = 0;
}

/**
 *
 */
void Save::powerGet(PowerType type, const core::stringc& id) {
  core::stringc name = "power_";
  PowerElementData& power = powerData.fightPowers[id];
  switch(type) {
    case POWERTYPE_FIGHT:
      name.append("fight_");
      name.append(id);
      power = powerData.fightPowers[id];
    break;
    case POWERTYPE_BLACK_MAGIC:
      name.append("magic_");
      name.append(id);
      power = powerData.whiteMagicPowers[id];
    break;
    case POWERTYPE_WHITE_MAGIC:
      name.append("magic_");
      name.append(id);
      power = powerData.blackMagicPowers[id];
    break;
    case POWERTYPE_STATE:
      name.append("state_");
      name.append(id);
      power = powerData.statePowers[id];
      power.type = ELMTYPE_STATE_STATS;
    break;
  }
  name.append("_name");
  power.level = 1;
  power.exp = 0;
  power.nameTranslationIdentifier = name;
}

/**
 *
 */
void Save::playerExpUp(u32 value) {
  playerData.currentExp += value;
}

/**
 *
 */
void Save::playerLevelUp(u32 value) {
  playerData.currentLevel += value;
}

/**
 *
 */
Save::~Save() {

}
