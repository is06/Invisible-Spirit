/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/core.h"
#include "../../../include/NHud/NPlayerState/CCapacity.h"
#include "../../../include/NHud/NPrimitive/CPicture.h"
#include "../../../include/NHud/NText/CText.h"

namespace is06 { namespace NHud { namespace NPlayerState {

CCapacity::CCapacity() : NCore::CHudEntity()
{
    Icon = new NPrimitive::CPicture();
    Value = new NText::CText();
}

void CCapacity::render()
{
    NCore::CHudEntity::render();
    Icon->render();
    Value->render();
}

CCapacity::~CCapacity()
{
    delete Icon;
    delete Value;
}

}}}
