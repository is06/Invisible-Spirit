/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/Engine/core.h"
#include "../../../include/Hud/Button/CIcon.h"

namespace is06 { namespace NHud { namespace NButton {

CIcon::CIcon(f32 x, f32 y) : CButton(x, y)
{

}

void CIcon::render()
{
  CButton::render();
}

CIcon::~CIcon()
{

}

}}}
