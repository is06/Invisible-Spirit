/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../include/ref/core.h"
#include "../include/Save.h"
#include "../include/SaveFile.h"
#include "../include/Game.h"

using namespace irr;
using namespace std;

/**
 * Default constructor
 */
Save::Save()
{

}

/**
 *
 */
void Save::load(u8 slot)
{
  SaveFile* saveFile = new SaveFile();
  saveFile->prepareForRead(slot);

  SaveFileElement element;

  for (u32 i = 0; i < 65535; i++) {
    element = saveFile->getNextElement();
    if (element.type == 'i') {
      wistringstream wss(element.value.c_str());
      wss >> integerList[i];
    } else if (element.type == 'b') {
      s32 intValue = -1;
      wistringstream wss(element.value.c_str());
      wss >> intValue;
      booleanList[i] = (intValue == 1);
    } else if (element.type == 's') {
      stringList[i] = element.value;
    }
  }

  delete saveFile;
}

/**
 *
 */
void Save::write(u8 slot)
{
  SaveFile* saveFile = new SaveFile();
  saveFile->prepareForWrite(slot);

  for (u32 i = 0; i < 65535; i++) {
    if (integerList.find(i) != integerList.end()) {
      saveFile->addVariable(i, integerList[i]);
    } else if (booleanList.find(i) != booleanList.end()) {
      saveFile->addVariable(i, booleanList[i]);
    } else if (stringList.find(i) != stringList.end()) {
      saveFile->addVariable(i, stringList[i]);
    }
  }

  delete saveFile;
}

/**
 * This function creates a brand new file for the player, every memorized pieces
 * of data are initialized here, like the start map or character HP...
 * It changes the current map of the game so the player can start to play.
 */
void Save::createNewFile()
{
  setGeneralDefaultValues();
  Game::changeScene(integerList[1]);
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
wstring& Save::getString(u32 index)
{
  return stringList[index];
}

void Save::setInteger(u32 index, s32 value)
{
  integerList[index] = value;
}

void Save::incInteger(u32 index, s32 value)
{
  integerList[index] += value;
}

void Save::decInteger(u32 index, s32 value)
{
  integerList[index] -= value;
}

void Save::setBoolean(u32 index, bool value)
{
  booleanList[index] = value;
}

void Save::setString(u32 index, const wstring& value)
{
  stringList[index] = value;
}

/**
 *
 */
void Save::setGeneralDefaultValues()
{
  // Map info
  integerList[1] = SCENE_MAP_ALPHA_ZONE; // Current map id

  // Time info
  integerList[11] = 0; // Total game time, in seconds
  integerList[12] = 1337; // World time, from 0 to 1439, 720 = 12pm
}

/**
 *
 */
Save::~Save()
{

}
