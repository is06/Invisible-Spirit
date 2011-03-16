/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_ICON_TEXT_BUTTON_H__
#define __IS06_ICON_TEXT_BUTTON_H__

class IconTextButton : public Button {
  public:
    IconTextButton(f32 x, f32 y);
    ~IconTextButton();

    void render();

    void changeCommand(CommandIdentifier newCommand);

  protected:
    Picture* icon;
    Text* text;
};

#endif
