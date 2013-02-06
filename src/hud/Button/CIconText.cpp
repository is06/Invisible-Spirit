/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/Engine/core.h"
#include "../../../include/Hud/Button/CIconText.h"

namespace is06
{
namespace NHud
{
namespace NButton
{

CIconText::CIconText(f32 x, f32 y) : CButton(x, y)
{
  //text = new Text(textMsg);
  //icon = new Picture(40, 40, x - 2, y + 2, "resource/hud/default.bmp");
}

void CIconText::render()
{
  CButton::render();
  //text->render();
  //icon->render();
}

void CIconText::changeCommand(NEngine::NControl::ECommandIdentifier newCommand)
{
  switch (newCommand) {
    default:
      //icon->change("resource/hud/fireCommand.bmp");
      break;
  }
}

CIconText::~CIconText()
{
  //delete text;
  //delete icon;
}

}
}
}
