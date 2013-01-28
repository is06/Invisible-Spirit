/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/Engine/core.h"
#include "../../include/Hud/CButton.h"
#include "../../include/Hud/CPicture.h"

namespace is06
{
namespace NHud
{

CButton::CButton(f32 x, f32 y) : CHud()
{
  ButtonCircle = new CPicture(x, y, 40, 40, "resource/Hud/button/buttonCircle.png");
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

void CButton::setOpacity(f32 value)
{
  Opacity = value;
  ButtonCircle->setOpacity(ButtonCircle->getOpacity() * Opacity);
}

void CButton::addOpacity(f32 value)
{
  Opacity += value;
  ButtonCircle->setOpacity(ButtonCircle->getOpacity() * Opacity);
}

void CButton::subOpacity(f32 value)
{
  Opacity -= value;
  ButtonCircle->setOpacity(ButtonCircle->getOpacity() * Opacity);
}

f32 CButton::getOpacity()
{
  return Opacity;
}

CButton::~CButton()
{
  delete ButtonCircle;
}

}
}
