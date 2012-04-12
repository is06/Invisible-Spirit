/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_SCENE_H__
#define __IS06_SCENE_H__

#include "../engine/ShadowProcessor.h"
#include "../enums/styles/FadeColor.h"

using namespace std;

namespace is06
{
namespace scene
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
    void addToEntityList(model::CModelEntity* entity);

    void setSaveSlot(engine::CSave* save);
    void fadeIn(irr::f32 speed = 1.5f, engine::EFadeColor color = engine::FADE_COLOR_BLACK);
    void fadeOut(irr::f32 speed = 3.0f, engine::EFadeColor color = engine::FADE_COLOR_BLACK);

    const irr::video::SColor& getBackBufferColor() const;

    model::CCamera* getActiveCamera();

    engine::CShadowProcessor* getShadowProcessor();

    static bool InMapEditingMode;

  protected:
    irr::gui::IGUIInOutFader* InFader;
    irr::gui::IGUIInOutFader* OutFader;

    hud::CPicture* Dummy;

    model::CCamera* Camera;
    //PlayerControl* control;
    //MapEditor* mapEditor;
    engine::CKeyboard* Keyboard;
    engine::CGamepad* Gamepad;
    engine::CSave* GameSave;
    engine::CDialogInterface* Dialog;
    sound::CMusicReference* Music;
    engine::CTranslation* GlobalTranslations;
    engine::CTranslation* SceneTranslations;

    engine::CShadowProcessor* Shadows;

    irr::video::SColor BackBufferColor;
    irr::f32 TimeElapsed;
    irr::f32 StartTime;
    irr::f32 SpeedFactor;
    irr::gui::IGUIStaticText* DebugInfo;

    map<model::CModelEntity*, bool> EntityList;
    map<model::CModelEntity*, bool>::iterator EntityListIt;

  private:
    void generateDebugInfo();
};

}
}

#endif
