/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/core.h"
#include "../../include/hud/CIconButton.h"

namespace is06
{
namespace nHud
{

CIconButton::CIconButton(f32 x, f32 y) : CButton(x, y)
{

}

void CIconButton::render()
{
  CButton::render();
}

CIconButton::~CIconButton()
{

}

}
}
