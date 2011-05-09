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
    DebugMenu();
    ~DebugMenu();

    void events();
    void nextOption();
    void prevOption();
    void enter();

    void addOption(const core::stringc& text);

  private:
    bool visible;
    map<s32, DebugMenuOption*> options;
    map<s32, DebugMenuOption*>::iterator optionsIt;
    s32 currentOption;
    s32 nextOptionID;
    s32 nextOptionY;
};


#endif
