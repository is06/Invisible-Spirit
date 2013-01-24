/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/Engine/core.h"
#include "../../include/Hud/CMenuOption.h"
#include "../../include/Hud/CWindow.h"
#include "../../include/Hud/CText.h"

namespace is06
{
namespace NHud
{

CMenuOption::CMenuOption(EMenuIcon icon, const string& title, f32 x, f32 y, EMenuStyle style) : CHud()
{
  Icon = icon;

  EWindowStyle boxStyle = EWS_STD;
  EFontStyle fontStyle = EFS_STANDARD_48;

  switch (style) {
    case EMS_STD:
      boxStyle = EWS_STD;
      fontStyle = EFS_STANDARD_48;
      break;
    case EMS_TITLE:
      boxStyle = EWS_NONE;
      fontStyle = EFS_STANDARD_48;
      break;
    default:
      boxStyle = EWS_NONE;
      fontStyle = EFS_STANDARD_48;
      break;
  }

  Box = new CWindow(x + 75, y, 150, 28, 3, boxStyle);
  Label = new CText(title, x + 6, y, fontStyle);

  Hover = false;
  Enabled = true;
  Visible = true;
  Selectable = true;
}

void CMenuOption::render()
{
  CHud::render();
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

void CMenuOption::setOpacity(u8 value)
{
  Label->setOpacity(value);
}

CMenuOption::~CMenuOption()
{
  delete Label;
  delete Box;
}

}
}
