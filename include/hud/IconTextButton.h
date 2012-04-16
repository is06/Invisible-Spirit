/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_ICON_TEXT_BUTTON_H__
#define __IS06_ICON_TEXT_BUTTON_H__

#include "Button.h"

namespace is06
{
namespace nHud
{

class CIconTextButton : public CButton
{
  public:
    CIconTextButton(f32 x, f32 y);
    ~CIconTextButton();

    void render();

    void changeCommand(nEngine::ECommandIdentifier newCommand);

  protected:
    CPicture* Icon;
    CText* Label;
};

}
}

#endif
