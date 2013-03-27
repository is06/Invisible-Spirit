/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/core.h"
#include "../../../include/NHud/NButton/CIconTextButton.h"

namespace is06 { namespace NHud { namespace NButton {

CIconTextButton::CIconTextButton(f32 x, f32 y) : CButton(x, y)
{
  //text = new Text(textMsg);
  //icon = new Picture(40, 40, x - 2, y + 2, "resource/hud/default.bmp");
}

void CIconTextButton::render()
{
  CButton::render();
  //text->render();
  //icon->render();
}

void CIconTextButton::changeCommand(NEngine::NControl::ECommandIdentifier newCommand)
{
  switch (newCommand) {
    default:
      //icon->change("resource/hud/fireCommand.bmp");
      break;
  }
}

CIconTextButton::~CIconTextButton()
{
  //delete text;
  //delete icon;
}

}}}
