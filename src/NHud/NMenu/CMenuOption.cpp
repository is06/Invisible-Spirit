/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/core.h"
#include "../../../include/NHud/NMenu/CMenuOption.h"
#include "../../../include/NHud/NWindow/CWindow.h"
#include "../../../include/NHud/NText/CText.h"

namespace is06 { namespace NHud { namespace NMenu {

CMenuOption::CMenuOption(EMenuIcon icon, const string& title, f32 x, f32 y, EMenuStyle style) : NCore::CHudEntity()
{
  Icon = icon;

  NWindow::EWindowStyle boxStyle = NWindow::EWS_STD;
  NText::EFontStyle fontStyle = NText::EFS_STANDARD_48;

  switch (style) {
    case EMS_STD:
      boxStyle = NWindow::EWS_STD;
      fontStyle = NText::EFS_STANDARD_48;
      break;
    case EMS_TITLE:
      boxStyle = NWindow::EWS_NONE;
      fontStyle = NText::EFS_STANDARD_48;
      break;
    default:
      boxStyle = NWindow::EWS_NONE;
      fontStyle = NText::EFS_STANDARD_48;
      break;
  }

  Box = new NWindow::CWindow(x + 75, y, 150, 28, 3, boxStyle);
  Label = new NText::CText(title, x + 6, y, fontStyle);

  Hover = false;
  Enabled = true;
  Visible = true;
  Selectable = true;
}

void CMenuOption::render()
{
  NCore::CHudEntity::render();
  Box->render();
  Label->render();
}

void CMenuOption::setHover(bool value)
{
  Hover = value;
}

void CMenuOption::setEnabled(bool value)
{
  Enabled = value;
  if (Enabled) {
    setOpacity(255);
  } else {
    setOpacity(128);
  }
}

void CMenuOption::setSelectable(bool value)
{
  Selectable = value;
}

void CMenuOption::show()
{
  Visible = true;
  Label->show();
}

void CMenuOption::hide()
{
  Visible = false;
  Label->hide();
}

void CMenuOption::setOpacity(f32 value)
{
  Opacity = value;
  Label->setOpacity(Label->getOpacity() * Opacity);
}

void CMenuOption::addOpacity(f32 value)
{
  Opacity += value;
  Label->setOpacity(Label->getOpacity() * Opacity);
}

void CMenuOption::subOpacity(f32 value)
{
  Opacity -= value;
  Label->setOpacity(Label->getOpacity() * Opacity);
}

f32 CMenuOption::getOpacity()
{
  return Opacity;
}

CMenuOption::~CMenuOption()
{
  delete Label;
  delete Box;
}

}}}
