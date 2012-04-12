/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/ref/core.h"
#include "../../../include/gui/gameplay/Button.h"
#include "../../../include/gui/Picture.h"

namespace is06
{
namespace hud
{

CButton::CButton(irr::f32 x, irr::f32 y) : CHud()
{
  ButtonCircle = new CPicture(x, y, 40, 40, "resource/hud/button/buttonCircle.png");
}

void CButton::render()
{
  CHud::render();
  ButtonCircle->render();
}

void CButton::hide()
{
  ButtonCircle->hide();
}

void CButton::show()
{
  ButtonCircle->show();
}

void CButton::setOpacity(irr::u8 value)
{
  ButtonCircle->setOpacity(value);
}

CButton::~CButton()
{
  delete ButtonCircle;
}

}
}
