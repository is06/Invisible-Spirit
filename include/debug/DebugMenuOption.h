/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_DEBUG_MENU_OPTION_H__
#define __IS06_DEBUG_MENU_OPTION_H__

using namespace irr;

class DebugMenuOption {
  public:
    DebugMenuOption(const core::stringw& text, s32 coordX, s32 coordY, DebugMenuOptionType type = DEBUG_MENU_OPTION_SUB);
    ~DebugMenuOption();

    void events();
    void setSelected(bool value);
    void setSelectable(bool value);
    void setMin(f32 value);
    void setMax(f32 value);

    void attachColor(DebugColor component, const video::SColorf& color);

    DebugMenuOptionType getType();

  private:
    core::stringc currentText;
    bool selected;
    bool selectable;
    DebugMenuOptionType currentType;
    gui::IGUIStaticText* guiElement;

    f32 min;
    f32 max;

    DebugColor colorComponent;
    video::SColorf colorMemory;
};

#endif
