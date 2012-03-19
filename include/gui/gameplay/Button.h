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

class Button : public Hud
{
  public:
    Button(f32 x, f32 y);
    virtual ~Button();

    virtual void render() = 0;

    void changeCommand(CommandIdentifier newCommand);
    void hide();
    void show();
    void setOpacity(u8 value);

  protected:
    Picture* buttonCircle;
};

#endif
