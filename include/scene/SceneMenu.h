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

namespace is06
{
namespace scene
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

    hud::CPicture* Dummy;
    hud::CPicture* Title;
    hud::CPicture* CreativeCommons;
    hud::CMenu* MainMenu;
    std::map<irr::u16, irr::core::vector3di> ModeList;
    std::map<irr::u8, engine::CSaveSlot*> SaveSlotList;

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
