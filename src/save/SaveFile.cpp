/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/save/SaveFile.h"
#include "../../include/Game.h"

namespace is06
{
namespace engine
{

/**
 * Default constructor
 * Does nothing
 */
CSaveFile::CSaveFile()
{

}

/**
 * Creates the stream for reading
 */
void CSaveFile::prepareForRead(irr::u8 slot)
{
  std::string filePath("save_");
  filePath += slot + ".dat";
  Rs.open(filePath.c_str(), std::ios::in);

  if (!Rs) {
    CGame::fatalError(debug::ERRCODE_20);
  }
}

/**
 * Creates the stream for writing
 */
void CSaveFile::prepareForWrite(irr::u8 slot)
{
  std::string filePath("save_");
  filePath += slot + ".dat";
  Ws.open(filePath.c_str(), std::ios::out | std::ios::trunc);

  if (!Ws) {
    CGame::fatalError(debug::ERRCODE_21);
  }
}

/**
 * Adds an integer variable in the save file
 */
void CSaveFile::addVariable(irr::u32 index, irr::s32 value)
{
  Ws << index << "\ti\t" << value << "\n";
}

/**
 * Adds a boolean variable in the save file
 */
void CSaveFile::addVariable(irr::u32 index, bool value)
{
  irr::u8 intValue = value ? 1 : 0;
  Ws << index << "\tb\t" << intValue << "\n";
}

/**
 * Adds a std::string variable in the save file
 */
void CSaveFile::addVariable(irr::u32 index, const std::string& value)
{
  Ws << index << "\ts\t" << value.c_str() << "\n";
}

/**
 * Reads the next variable in save file
 * @return SaveFileElement structure
 */
SSaveFileElement CSaveFile::getNextElement()
{
  char currentChar = 0;
  bool inIndexDeclaration = true;
  bool inTypeDeclaration = false;
  bool inValueDeclaration = false;
  std::string index("");
  char type = 0;
  std::string value("");

  SSaveFileElement result;

  if (Rs) {
    while (Rs.get(currentChar)) {
      if (currentChar == '\t') {
        if (inIndexDeclaration) {
          inIndexDeclaration = false;
          inTypeDeclaration = true;
          continue;
        }
        if (inTypeDeclaration) {
          inTypeDeclaration = false;
          inValueDeclaration = true;
          continue;
        }
      }
      if (currentChar == '\n' || currentChar == '\r') {
        std::istringstream iss(index.c_str());
        iss >> result.Index;
        result.Type = type;
        result.Value = value;
        break;
      }
      if (inIndexDeclaration) {
        index += currentChar;
      }
      if (inTypeDeclaration) {
        type = (char)currentChar;
      }
      if (inValueDeclaration) {
        value += currentChar;
      }
    }
  }

  return result;
}

/**
 * Closes file
 */
CSaveFile::~CSaveFile()
{
  Rs.close();
  Ws.close();
}

}
}
