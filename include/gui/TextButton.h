/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_TEXT_BUTTON_H__
#define __IS06_TEXT_BUTTON_H__

class TextButton : public Button {
  public:
    TextButton(f32 x, f32 y);
    ~TextButton();

    void render();

  protected:
    Text* text;
};

#endif
