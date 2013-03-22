/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_ICON_TEXT_BUTTON_H__
#define __IS06_ICON_TEXT_BUTTON_H__

#include "../CButton.h"

namespace is06
{
namespace NHud
{
namespace NButton
{

class CIconText : public CButton
{
  public:
    CIconText(f32 x, f32 y);
    ~CIconText();

    void render();

    void changeCommand(NEngine::NControl::ECommandIdentifier newCommand);

  protected:
    CPicture* Icon;
    CText* Label;
};

}
}
}

#endif
