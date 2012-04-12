/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_BUTTON_H__
#define __IS06_BUTTON_H__

#include "../../enums/gameplay/CommandIdentifier.h"
#include "../Hud.h"

namespace is06
{
namespace hud
{

class CButton : public CHud
{
  public:
    CButton(irr::f32 x, irr::f32 y);
    virtual ~CButton();

    virtual void render() = 0;

    void changeCommand(engine::ECommandIdentifier newCommand);
    void hide();
    void show();
    void setOpacity(irr::u8 value);

  protected:
    CPicture* ButtonCircle;
};

}
}

#endif
