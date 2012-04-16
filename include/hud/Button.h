/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_BUTTON_H__
#define __IS06_BUTTON_H__

#include "../engine/CommandIdentifier.h"
#include "Hud.h"

namespace is06
{
namespace nHud
{

//! Graphical representation of a button in the HUD gameplay interface
class CButton : public CHud
{
  public:
    CButton(f32 x, f32 y);
    virtual ~CButton();

    virtual void render() = 0;

    void changeCommand(nEngine::ECommandIdentifier newCommand);
    void hide();
    void show();
    void setOpacity(u8 value);

  protected:
    CPicture* ButtonCircle;
};

}
}

#endif
