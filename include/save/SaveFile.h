/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_SAVE_FILE_H__
#define __IS06_SAVE_FILE_H__

#include "SaveFileElement.h"

using namespace irr;
using namespace std;

class SaveFile
{
  public:
    SaveFile();
    ~SaveFile();

    void prepareForRead(u8 slot);
    void prepareForWrite(u8 slot);

    void addVariable(u32 index, s32 value);
    void addVariable(u32 index, bool value);
    void addVariable(u32 index, const wstring& value);

    SaveFileElement getNextElement();

  private:
    wifstream rs;
    wofstream ws;
};

#endif
