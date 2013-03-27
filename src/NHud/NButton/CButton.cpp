/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/core.h"
#include "../../../include/NHud/NButton/CButton.h"
#include "../../../include/NHud/NPrimitive/CPicture.h"

namespace is06 { namespace NHud { namespace NButton {

CButton::CButton(f32 x, f32 y) : NCore::CHudEntity()
{
  ButtonCircle = new NPrimitive::CPicture(x, y, 40, 40, "resource/hud/button/buttonCircle.png");
}

void CButton::render()
{
  NCore::CHudEntity::render();
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

}}}
