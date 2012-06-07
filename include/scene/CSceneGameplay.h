/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_SCENE_GAMEPLAY_H__
#define __IS06_SCENE_GAMEPLAY_H__

#include "CScene.h"
#include "../hud/CMiniMap.h"
#include "../hud/CGameplayMenu.h"

namespace is06
{
namespace nScene
{

class CSceneGameplay : public CScene
{
  public:
    CSceneGameplay();
    virtual ~CSceneGameplay();
    virtual void events();
    virtual void postRender();
    virtual void hudRender();

  protected:
    void loadMapSection(const string& mapName, const string& sectionName, const core::vector3df& position);
    void unloadUnusedMapSection();

    n3D::CPlayableCharacter* Hero;
    n3D::CLevelMesh* Level[2];
    nHud::CGameplayInterface* GameplayInterface;
    nHud::CEnergyInterface* EnergyInterface;
    nHud::CMiniMap* MiniMap;
    nHud::CWorldTimeCounter* WorldTime;
    nHud::nMenu::CGameplayMenu* GameplayMenu;
    nEngine::CTimer* EverySecondTimer;

  private:
    void manageCameraControl();
    void manageCharacterJumps();
    void manageCharacterMovements();
    void manageCharacterCollisions();
    void manageMenuControl();
    void everySecond();
    void switchLevelMeshes();

    bool QuitIsFading;
};

}
}

#endif
