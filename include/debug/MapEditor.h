/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_MAP_EDITOR_H__
#define __IS06_MAP_EDITOR_H__

class MapEditor {
  public:
    MapEditor();
    ~MapEditor();

    void events();
    void toggle();
    bool isRunning();

  private:
    DebugMenu* mainMenu;
    DebugMenu* subMenu;
    DebugMenu* propMenu;

    s32 currentMenuID;
    bool active;
};

#endif
