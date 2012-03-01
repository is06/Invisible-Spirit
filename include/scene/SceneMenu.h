/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_SCENE_MENU_H__
#define __IS06_SCENE_MENU_H__

#include "Scene.h"
#include "../save/SaveSlot.h"

using namespace irr;
using namespace std;

class SceneMenu : public Scene
{
  public:
    SceneMenu();
    ~SceneMenu();

    void events();
    void postRender();

  private:
    void createSaveListMenu();
    void destroySaveListMenu();
    void createOptionMenu();
    void destroyOptionMenu();

    void manageMainMenu();
    void manageSaveListMenu();
    void manageOptionMenu();

    void initModeList();
    void retrieveSaveSlotList();
    void clearSaveSlotList();

    Picture* dummy;
    Picture* title;
    Menu* mainMenu;
    StaticModel* lightRays;
    map<u16, core::vector3di> modeList;
    map<u8, SaveSlot*> saveSlotList;

    bool newGameIsFading;
    bool quitIsFading;

    bool inTitleFadeIn;
    bool inMainMenu;
    bool inSaveListMenu;
    bool inOptionMenu;
    bool inNewGameFadeOut;
};

#endif
