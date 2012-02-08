/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../include/ref/core.h"
#include "../include/enums/engine/SaveIntegerIdentifier.h"
#include "../include/Save.h"
#include "../include/Game.h"

using namespace irr;
using namespace std;

Save::Save()
{

}

/**
 *
 */
void Save::load()
{

}

/**
 *
 */
void Save::write()
{

}

/**
 * This function creates a brand new file for the player, every memorized pieces
 * of data are initialized here, like the start map or character HP and MP...
 * It changes the current map of the game so the player can start to play.
 */
void Save::createNewFile()
{
  setGeneralDefaultValues();

  Game::changeScene(integerList[SII_CURRENT_MAP]);
}

/**
 *
 */
s32& Save::getInteger(u32 index)
{
  return integerList[index];
}

/**
 *
 */
bool& Save::getBoolean(u32 index)
{
  return booleanList[index];
}

/**
 *
 */
core::stringw& Save::getString(u32 index)
{
  return stringList[index];
}

/**
 *
 */
void Save::setGeneralDefaultValues()
{
  // Save info
  slot = 0;

  // Map Info
  integerList[SII_CURRENT_MAP] = SCENE_MAP_ALPHA_ZONE;
}

/**
 *
 */
Save::~Save()
{

}
