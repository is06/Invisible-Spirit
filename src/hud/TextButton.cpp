/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/core.h"
#include "../../include/hud/TextButton.h"

namespace is06
{
namespace nHud
{

CTextButton::CTextButton(f32 x, f32 y) : CButton(x, y)
{

}

void CTextButton::render()
{
  CButton::render();
}

CTextButton::~CTextButton()
{

}

}
}
