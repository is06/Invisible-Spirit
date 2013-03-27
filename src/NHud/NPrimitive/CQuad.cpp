/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/NEngine/NCore/CGame.h"
#include "../../../include/NEngine/NEvent/CEventManager.h"
#include "../../../include/NHud/NPrimitive/CQuad.h"

using namespace irr;

namespace is06 { namespace NHud { namespace NPrimitive {

CQuad::CQuad(f32 x, f32 y, f32 w, f32 h, video::SColor color) : CFlatElement(x, y, w, h, false)
{
  Material.DiffuseColor = color;
}

void CQuad::render()
{
  CFlatElement::render();
}

CQuad::~CQuad()
{

}

}}}
