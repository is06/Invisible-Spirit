/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_SCENE_GAMEPLAY_H__
#define __IS06_SCENE_GAMEPLAY_H__

#include "../../include/scene/Scene.h"

namespace is06
{
namespace scene
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
    model::CPlayableCharacter* Ayron;
    model::CLevelMesh* Level;
    hud::CGameplayInterface* GameplayInterface;
    hud::CEnergyInterface* EnergyInterface;
    hud::CGameplayMenu* GameplayMenu;
    hud::CWorldTimeCounter* WorldTime;
    engine::CTimer* EverySecondTimer;

  private:
    void manageCameraControl();
    void manageCharacterJumps();
    void manageCharacterMovements();
    void manageCharacterCollisions();
    void manageMenuControl();
    void everySecond();
    bool QuitIsFading;
};

}
}

#endif
