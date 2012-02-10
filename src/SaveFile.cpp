/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../include/ref/core.h"
#include "../include/SaveFile.h"

using namespace irr;
using namespace std;

SaveFile::SaveFile()
{

}

void SaveFile::prepareForRead(u8 slot)
{
  core::stringc filePath = "save_";
  filePath.append(slot);
  filePath.append(".dat");
  rs.open(filePath.c_str(), ios::in);
}

void SaveFile::prepareForWrite(u8 slot)
{
  core::stringc filePath = "save_";
  filePath.append(slot);
  filePath.append(".dat");
  ws.open(filePath.c_str(), ios::out | ios::trunc);
}

void SaveFile::addVariable(u32 index, s32 value)
{
  ws << index << "\ti\t" << value << "\n";
}

void SaveFile::addVariable(u32 index, bool value)
{
  u8 intValue = value ? 1 : 0;
  ws << index << "\tb\t" << intValue << "\n";
}

void SaveFile::addVariable(u32 index, const core::stringw& value)
{
  ws << index << "\ts\t" << value.c_str() << "\n";
}

SaveFileElement SaveFile::getNextElement()
{
  wchar_t currentChar;
  bool inIndexDeclaration = true;
  bool inTypeDeclaration = false;
  bool inValueDeclaration = false;
  core::stringc index = "";
  c8 type;
  core::stringw value = L"";

  SaveFileElement result;

  while (rs.get(currentChar)) {
    if (currentChar == '\t') {
      if (inIndexDeclaration) {
        inIndexDeclaration = false;
        inTypeDeclaration = true;
      }
      if (inTypeDeclaration) {
        inTypeDeclaration = false;
        inValueDeclaration = true;
      }
      continue;
    }
    if (currentChar == '\n' || currentChar == '\r') {
      istringstream iss(index.c_str());
      iss >> result.index;
      result.type = type;
      result.value = value;

      cout << "read type: " << result.type << endl;
      break;
    }
    if (inIndexDeclaration) {
      index.append(currentChar);
    }
    if (inTypeDeclaration) {
      wcout << L"Current Char=" << currentChar << endl;
      type = static_cast<c8>(currentChar);
    }
    if (inValueDeclaration) {
      value.append(currentChar);
    }
  }

  return result;
}

SaveFile::~SaveFile()
{
  rs.close();
  ws.close();
}
