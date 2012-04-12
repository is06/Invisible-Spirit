/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_SAVE_FILE_H__
#define __IS06_SAVE_FILE_H__

#include "SaveFileElement.h"

namespace is06
{
namespace engine
{

class CSaveFile
{
  public:
    CSaveFile();
    ~CSaveFile();

    void prepareForRead(irr::u8 slot);
    void prepareForWrite(irr::u8 slot);

    void addVariable(irr::u32 index, irr::s32 value);
    void addVariable(irr::u32 index, bool value);
    void addVariable(irr::u32 index, const std::string& value);

    SSaveFileElement getNextElement();

  private:
    std::ifstream Rs;
    std::ofstream Ws;
};

}
}

#endif
