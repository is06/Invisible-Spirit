/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_SAVE_SLOT_H__
#define __IS06_SAVE_SLOT_H__

namespace is06
{
namespace NEngine
{
namespace NSave
{

//! Visual representation of a single save slot in the save slot selection menu
class CSlot
{
  public:
    CSlot(CSave* save);
    ~CSlot();

  private:
    string PlaceNameIdentifier;
    u32 TotalGameTime;
};

}
}
}

#endif
