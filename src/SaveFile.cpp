/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../include/ref/core.h"
#include "../include/SaveFile.h"
#include "../include/Game.h"

using namespace irr;
using namespace std;

/**
 * Default constructor
 * Does nothing
 */
SaveFile::SaveFile()
{

}

/**
 * Creates the stream for reading
 */
void SaveFile::prepareForRead(u8 slot)
{
  string filePath("save_");
  filePath += slot + ".dat";
  rs.open(filePath.c_str(), ios::in);

  if (!rs) {
    Game::fatalError(ERRCODE_20);
  }
}

/**
 * Creates the stream for writing
 */
void SaveFile::prepareForWrite(u8 slot)
{
  string filePath("save_");
  filePath += slot + ".dat";
  ws.open(filePath.c_str(), ios::out | ios::trunc);

  if (!ws) {
    Game::fatalError(ERRCODE_21);
  }
}

/**
 * Adds an integer variable in the save file
 */
void SaveFile::addVariable(u32 index, s32 value)
{
  ws << index << "\ti\t" << value << "\n";
}

/**
 * Adds a boolean variable in the save file
 */
void SaveFile::addVariable(u32 index, bool value)
{
  u8 intValue = value ? 1 : 0;
  ws << index << "\tb\t" << intValue << "\n";
}

/**
 * Adds a string variable in the save file
 */
void SaveFile::addVariable(u32 index, const wstring& value)
{
  ws << index << "\ts\t" << value.c_str() << "\n";
}

/**
 * Reads the next variable in save file
 * @return SaveFileElement structure
 */
SaveFileElement SaveFile::getNextElement()
{
  wchar_t currentChar;
  bool inIndexDeclaration = true;
  bool inTypeDeclaration = false;
  bool inValueDeclaration = false;
  string index = "";
  char type;
  wstring value = L"";

  SaveFileElement result;

  if (rs) {
    while (rs.get(currentChar)) {
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
        istringstream iss(index.c_str());
        iss >> result.index;
        result.type = type;
        result.value = value;
        break;
      }
      if (inIndexDeclaration) {
        index += currentChar;
      }
      if (inTypeDeclaration) {
        type = (c8)currentChar;
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
SaveFile::~SaveFile()
{
  rs.close();
  ws.close();
}
