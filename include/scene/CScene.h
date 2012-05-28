/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_SCENE_H__
#define __IS06_SCENE_H__

#include "../engine/CShadowProcessor.h"
#include "../engine/CPlayerControl.h"
#include "../engine/EFadeColor.h"
#include "../hud/CCinemascopeMode.h"

namespace is06
{
namespace nScene
{

class CScene
{
  public:
    CScene();
    virtual ~CScene();

    virtual void events() = 0;
    virtual void postRender() = 0;
    virtual void hudRender() = 0;

    void darkenNonGlowingEntities();
    void revealNonGlowingEntities();
    void addToEntityList(n3D::CModelEntity* entity);

    void setSaveSlot(nEngine::CSave* save);
    void fadeIn(f32 speed = 1.5f, nEngine::EFadeColor color = nEngine::EFC_BLACK);
    void fadeOut(f32 speed = 3.0f, nEngine::EFadeColor color = nEngine::EFC_BLACK);

    const video::SColor& getBackBufferColor() const;

    n3D::CCamera* getActiveCamera();

    nEngine::CShadowProcessor* getShadowProcessor();

    static bool InMapEditingMode;

  protected:
    // Faders
    gui::IGUIInOutFader* InFader;
    gui::IGUIInOutFader* OutFader;

    // 2D elements
    nHud::CPicture* Dummy;
    nHud::CCinemascopeMode* Cinemascope;

    // 3D entities
    n3D::CCamera* Camera;

    // Interfaces
    nEngine::CPlayerControl* Control;
    nEngine::CSave* GameSave;
    nEngine::CDialogInterface* Dialog;
    nSound::CMusicReference* Music;
    nEngine::CTranslation* GlobalTranslations;
    nEngine::CTranslation* SceneTranslations;
    nEngine::CShadowProcessor* Shadows;

    // Primitive data
    video::SColor BackBufferColor;
    f32 TimeElapsed;
    f32 StartTime;
    f32 SpeedFactor;
    gui::IGUIStaticText* DebugInfo;

    // A map for post processing effects
    map<n3D::CModelEntity*, bool> EntityList;
    map<n3D::CModelEntity*, bool>::iterator EntityListIt;

    // Methods
    void setSkyBox(const string& textureName);

  private:
    // 3D Entities
    scene::ISceneNode* SkyBox;

    // Methods
    void generateDebugInfo();
};

}
}

#endif
