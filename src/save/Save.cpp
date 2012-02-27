/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/save/Save.h"
#include "../../include/save/SaveFile.h"
#include "../../include/Game.h"

using namespace irr;
using namespace std;

/**
 * Default constructor
 */
Save::Save()
{

}

/**
 * @todo
 */
void Save::loadPrimitiveInfo(u8 slot)
{
  SaveFile* saveFile = new SaveFile();
  saveFile->prepareForRead(slot);

  SaveFileElement element;

  for (u32 i = 0; i < 65535; i++) {
    element = saveFile->getNextElement();
    if (element.type == 'i') {
      //istringstream iss(element.value.c_str());
      //iss >> integerList[i];
    } else if (element.type == 'b') {
      //s32 intValue = -1;
      //istringstream iss(element.value.c_str());
      //iss >> intValue;
      //booleanList[i] = (intValue == 1);
    } else if (element.type == 's') {
      //stringList[i] = element.value;
    }
  }
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
      istringstream iss(element.value.c_str());
      iss >> integerList[i];
    } else if (element.type == 'b') {
      s32 intValue = -1;
      istringstream iss(element.value.c_str());
      iss >> intValue;
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
  Game::changeScene(integerList[11]);
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
string& Save::getString(u32 index)
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

void Save::setString(u32 index, const string& value)
{
  stringList[index] = value;
}

/**
 *
 */
void Save::setGeneralDefaultValues()
{
  // Primitive Info
  integerList[1] = -1; // Slot number (-1 = No slot number)

  // Map info
  integerList[11] = SCENE_MAP_ALPHA_ZONE; // Current map id
  stringList[12] = "Alpha Zone (Debug)"; // Current map name

  // Time info
  integerList[21] = 0; // Total game time, in seconds
  integerList[22] = 1337; // World time, from 0 to 1439, 720 = 12pm

  // Player info
  integerList[101] = 180; // HP
  integerList[102] = 180; // Max HP
}

/**
 *
 */
Save::~Save()
{

}
