/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/Engine/core.h"
#include "../../../include/Engine/Save/CFile.h"
#include "../../../include/Engine/CGame.h"
#include "../../../include/Engine/Exception/CFileException.h"

namespace is06
{
namespace NEngine
{
namespace NSave
{

//! Default constructor, does nothing
CFile::CFile()
{

}

//! Creates the stream for reading
void CFile::prepareForRead(u8 slot)
{
  string filePath("save_");
  filePath += slot + ".dat";
  Rs.open(filePath.c_str(), ios::in);

  if (!Rs) {
    throw new NException::CFileException("[E20] Unable to open save file");
  }
}

//! Creates the stream for writing
void CFile::prepareForWrite(u8 slot)
{
  string filePath("save_");
  filePath += slot + ".dat";
  Ws.open(filePath.c_str(), ios::out | ios::trunc);

  if (!Ws) {
    throw new NException::CFileException("[E21] Unable to write save file");
  }
}

//! Adds an integer variable in the save file
void CFile::addVariable(u32 index, s32 value)
{
  Ws << index << "\ti\t" << value << "\n";
}

//! Adds a boolean variable in the save file
void CFile::addVariable(u32 index, bool value)
{
  u8 intValue = value ? 1 : 0;
  Ws << index << "\tb\t" << intValue << "\n";
}

//! Adds a string variable in the save file
void CFile::addVariable(u32 index, const string& value)
{
  Ws << index << "\ts\t" << value.c_str() << "\n";
}

//! Reads the next variable in save file
/**
 * \return SaveFileElement structure
 */
SFileElement CFile::getNextElement()
{
  char currentChar = 0;
  bool inIndexDeclaration = true;
  bool inTypeDeclaration = false;
  bool inValueDeclaration = false;
  string index("");
  char type = 0;
  string value("");

  SFileElement result;

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
        istringstream iss(index.c_str());
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

//! Closes file
CFile::~CFile()
{
  Rs.close();
  Ws.close();
}

}
}
}
