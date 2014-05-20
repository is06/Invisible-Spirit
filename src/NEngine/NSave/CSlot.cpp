/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/core.h"
#include "../../../include/NEngine/NSave/CSave.h"
#include "../../../include/NEngine/NSave/CSaveSlot.h"

namespace is06 { namespace NEngine { namespace NSave {

//! Constructor
CSaveSlot::CSaveSlot(CSave* save)
{
    PlaceNameIdentifier = save->getString(12);
    TotalGameTime = save->getInteger(21);
}

//! Destructor
CSaveSlot::~CSaveSlot()
{

}

}}}
