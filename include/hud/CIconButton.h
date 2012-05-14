/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_ICON_BUTTON_H__
#define __IS06_ICON_BUTTON_H__

#include "CButton.h"

namespace is06
{
namespace nHud
{

class CIconButton : public CButton
{
  public:
    CIconButton(f32 x, f32 y);
    ~CIconButton();

    void render();

  protected:
    CPicture* Icon;
};

}
}

#endif
