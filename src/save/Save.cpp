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

namespace is06
{
namespace engine
{

/**
 * Default constructor
 */
CSave::CSave()
{

}

/**
 * @todo
 */
void CSave::loadPrimitiveInfo(irr::u8 slot)
{
  CSaveFile* saveFile = new CSaveFile();
  saveFile->prepareForRead(slot);

  SSaveFileElement element;

  for (irr::u32 i = 0; i < 65535; i++) {
    element = saveFile->getNextElement();
    if (element.Type == 'i') {
      //istd::stringstream iss(element.value.c_str());
      //iss >> integerList[i];
    } else if (element.Type == 'b') {
      //s32 intValue = -1;
      //istd::stringstream iss(element.value.c_str());
      //iss >> intValue;
      //booleanList[i] = (intValue == 1);
    } else if (element.Type == 's') {
      //std::stringList[i] = element.value;
    }
  }
}

/**
 *
 */
void CSave::load(irr::u8 slot)
{
  CSaveFile* saveFile = new CSaveFile();
  saveFile->prepareForRead(slot);

  SSaveFileElement element;

  for (irr::u32 i = 0; i < 65535; i++) {
    element = saveFile->getNextElement();
    if (element.Type == 'i') {
      std::istringstream iss(element.Value.c_str());
      iss >> IntegerList[i];
    } else if (element.Type == 'b') {
      irr::s32 intValue = -1;
      std::istringstream iss(element.Value.c_str());
      iss >> intValue;
      BooleanList[i] = (intValue == 1);
    } else if (element.Type == 's') {
      StringList[i] = element.Value;
    }
  }

  delete saveFile;
}

/**
 *
 */
void CSave::write(irr::u8 slot)
{
  CSaveFile* saveFile = new CSaveFile();
  saveFile->prepareForWrite(slot);

  for (irr::u32 i = 0; i < 65535; i++) {
    if (IntegerList.find(i) != IntegerList.end()) {
      saveFile->addVariable(i, IntegerList[i]);
    } else if (BooleanList.find(i) != BooleanList.end()) {
      saveFile->addVariable(i, BooleanList[i]);
    } else if (StringList.find(i) != StringList.end()) {
      saveFile->addVariable(i, StringList[i]);
    }
  }

  delete saveFile;
}

/**
 * This function creates a brand new file for the player, every memorized pieces
 * of data are initialized here, like the start map or character HP...
 * It changes the current map of the game so the player can start to play.
 */
void CSave::createNewFile()
{
  setGeneralDefaultValues();
  CGame::changeScene(IntegerList[11]);
}

/**
 *
 */
irr::s32& CSave::getInteger(irr::u32 index)
{
  return IntegerList[index];
}

/**
 *
 */
bool& CSave::getBoolean(irr::u32 index)
{
  return BooleanList[index];
}

/**
 *
 */
std::string& CSave::getString(irr::u32 index)
{
  return StringList[index];
}

void CSave::setInteger(irr::u32 index, irr::s32 value)
{
  IntegerList[index] = value;
}

void CSave::incInteger(irr::u32 index, irr::s32 value)
{
  IntegerList[index] += value;
}

void CSave::decInteger(irr::u32 index, irr::s32 value)
{
  IntegerList[index] -= value;
}

void CSave::setBoolean(irr::u32 index, bool value)
{
  BooleanList[index] = value;
}

void CSave::setString(irr::u32 index, const std::string& value)
{
  StringList[index] = value;
}

/**
 *
 */
void CSave::setGeneralDefaultValues()
{
  // Primitive Info
  IntegerList[1] = -1; // Slot number (-1 = No slot number)

  // Map info
  IntegerList[11] = SCENE_MAP_ALPHA_ZONE; // Current map id
  StringList[12] = "Alpha Zone (Debug)"; // Current map name

  // Time info
  IntegerList[21] = 0; // Total game time, in seconds
  IntegerList[22] = 1337; // World time, from 0 to 1439, 720 = 12pm

  // Player info
  IntegerList[101] = 180; // HP
  IntegerList[102] = 180; // Max HP
}

/**
 *
 */
CSave::~CSave()
{

}

}
}
