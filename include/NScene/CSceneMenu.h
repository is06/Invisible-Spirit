/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_SCENE_SCENE_MENU_H__
#define __IS06_SCENE_SCENE_MENU_H__

#include "CScene.h"
#include "../NEngine/NSave/CSaveSlot.h"

namespace is06 { namespace NScene {

//! The game main menu scene (also title screen)
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

  NHud::NPrimitive::CPicture* Title;
  NHud::NPrimitive::CPicture* CreativeCommons;
  NHud::NMenu::CMenu* MainMenu;
  map<u16, core::vector3di> ModeList;
  map<u8, NEngine::NSave::CSaveSlot*> SaveSlotList;

  bool NewGameIsFading;
  bool QuitIsFading;

  bool InTitleFadeIn;
  bool InMainMenu;
  bool InSaveListMenu;
  bool InOptionMenu;
  bool InNewGameFadeOut;
};

}}

#endif
