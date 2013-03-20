/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_TEXT_BUTTON_H__
#define __IS06_TEXT_BUTTON_H__

#include "../CButton.h"

namespace is06
{
namespace NHud
{
namespace NButton
{

class CText : public CButton
{
  public:
    CText(f32 x, f32 y);
    ~CText();

    void render();

  protected:
    NHud::CText* Label;
};

}
}
}

#endif
