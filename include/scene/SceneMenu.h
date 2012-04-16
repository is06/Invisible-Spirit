/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_SCENE_MENU_H__
#define __IS06_SCENE_MENU_H__

#include "Scene.h"
#include "../engine/SaveSlot.h"

namespace is06
{
namespace nScene
{

class CSceneMenu : public CScene
{
  public:
    CSceneMenu();
    ~CSceneMenu();

    void events();
    void postRender();
    void hudRender();

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

    nHud::CPicture* Dummy;
    nHud::CPicture* Title;
    nHud::CPicture* CreativeCommons;
    nHud::CMenu* MainMenu;
    map<u16, core::vector3di> ModeList;
    map<u8, nEngine::CSaveSlot*> SaveSlotList;

    bool NewGameIsFading;
    bool QuitIsFading;

    bool InTitleFadeIn;
    bool InMainMenu;
    bool InSaveListMenu;
    bool InOptionMenu;
    bool InNewGameFadeOut;
};

}
}

#endif
