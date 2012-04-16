/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_SAVE_H__
#define __IS06_SAVE_H__

#include "../scene/SceneIdentifier.h"
#include "../engine/DifficultyLevel.h"

namespace is06
{
namespace nEngine
{

//! Class for storing variables and using them in scenes or maps
class CSave
{
  public:
    CSave();
    ~CSave();

    void loadPrimitiveInfo(u8 slot);
    void load(u8 slot);
    void write(u8 slot);
    void createNewFile(nEngine::EDifficultyLevel difficultyLevel);

    s32& getInteger(u32 index);
    bool& getBoolean(u32 index);
    string& getString(u32 index);

    void setInteger(u32 index, s32 value);
    void incInteger(u32 index, s32 value);
    void decInteger(u32 index, s32 value);
    void setBoolean(u32 index, bool value);
    void setString(u32 index, const string& value);

  private:
    // Data maps
    map<u32, s32> IntegerList;
    map<u32, bool> BooleanList;
    map<u32, string> StringList;

    // Default values
    void setGeneralDefaultValues(nEngine::EDifficultyLevel difficultyLevel);
};

}
}

#endif
