/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/save/Save.h"
#include "../../include/save/SaveSlot.h"

SaveSlot::SaveSlot(Save* save)
{
  name = save->getString(1);
  placeNameIdentifier = save->getString(12);
  totalGameTime = save->getInteger(21);
}

SaveSlot::~SaveSlot()
{

}
