/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_SAVE_H__
#define __IS06_SAVE_H__

#include "../enums/engine/SceneIdentifier.h"

namespace is06
{
namespace engine
{

class CSave
{
  public:
    CSave();
    ~CSave();

    void loadPrimitiveInfo(irr::u8 slot);
    void load(irr::u8 slot);
    void write(irr::u8 slot);
    void createNewFile();

    irr::s32& getInteger(irr::u32 index);
    bool& getBoolean(irr::u32 index);
    std::string& getString(irr::u32 index);

    void setInteger(irr::u32 index, irr::s32 value);
    void incInteger(irr::u32 index, irr::s32 value);
    void decInteger(irr::u32 index, irr::s32 value);
    void setBoolean(irr::u32 index, bool value);
    void setString(irr::u32 index, const std::string& value);

  private:
    // Data maps
    std::map<irr::u32, irr::s32> IntegerList;
    std::map<irr::u32, bool> BooleanList;
    std::map<irr::u32, std::string> StringList;

    // Default values
    void setGeneralDefaultValues();
};

}
}

#endif
