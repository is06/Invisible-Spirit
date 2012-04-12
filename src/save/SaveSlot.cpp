/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/save/Save.h"
#include "../../include/save/SaveSlot.h"

namespace is06
{
namespace engine
{

CSaveSlot::CSaveSlot(CSave* save)
{
  PlaceNameIdentifier = save->getString(12);
  TotalGameTime = save->getInteger(21);
}

CSaveSlot::~CSaveSlot()
{

}

}
}
