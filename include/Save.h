/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_SAVE_H__
#define __IS06_SAVE_H__

#include "enums/engine/SceneIdentifier.h"

using namespace irr;
using namespace std;

class Save
{
  public:
    Save();
    ~Save();

    void load();
    void write();
    void createNewFile();

    s32& getInteger(u32 index);
    bool& getBoolean(u32 index);
    core::stringw& getString(u32 index);

  private:
    // General information
    u8 slot;

    // Various data
    map<u32, s32> integerList;
    map<u32, bool> booleanList;
    map<u32, core::stringw> stringList;

    // Default values
    void setGeneralDefaultValues();
};

#endif
