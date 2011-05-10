/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_DEBUG_MENU_H__
#define __IS06_DEBUG_MENU_H__

using namespace std;
using namespace irr;

class DebugMenu {
  public:
    DebugMenu(s32 menuX, DebugMenu* parent = NULL);
    ~DebugMenu();

    void events();
    void nextOption();
    void prevOption();
    void enter();
    void returnParent();
    void setBrowseable(bool value);
    void setVisible(bool value);
    void addOption(const core::stringc& text, DebugMenuOptionType type = DEBUG_MENU_OPTION_SUB, f32 minValue = 0.0f, f32 maxValue = 1.0f);
    void removeAllOptions();
    s32 getCurrentOption();

    DebugMenu* getSubMenu(s32 optionID);
    DebugMenuOption* getOption(s32 optionID);

  private:
    bool visible;
    bool browseable;
    map<s32, DebugMenuOption*> options;
    map<s32, DebugMenuOption*>::iterator optionsIt;
    map<s32, DebugMenu*> subMenus;
    map<s32, DebugMenu*>::iterator subMenusIt;
    s32 currentOption;
    s32 parentOptionID;
    s32 nextOptionID;
    s32 coordX;
    s32 nextOptionY;
    DebugMenu* parentMenu;
};


#endif
