/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_SCENE_H__
#define __IS06_SCENE_H__

#include "../Scene/ELoadingStatus.h"
#include "../Shader/CShadowProcessor.h"
#include "../Engine/CPlayerControl.h"
#include "../Hud/EFadeColor.h"
#include "../Hud/CCinemascopeMode.h"
#include "../3D/CSky.h"
#include "../Debug/CConsole.h"

namespace is06
{
namespace NScene
{

class CScene
{
  public:
    CScene();
    virtual ~CScene();

    virtual void                            events() = 0;
    virtual void                            postRender() = 0;
    virtual void                            hudRender() = 0;
    virtual void                            start();

    // Loading methods
    virtual void                            startLoadingScreen();
    virtual void                            stopLoadingScreen();
    virtual void                            loadingSequence();
    NScene::ELoadingStatus                  getLoadingStatus();
    void                                    setLoadingStatus(NScene::ELoadingStatus status);

    void                                    setSaveSlot(NEngine::CSave* save);
    void                                    fadeIn(f32 speed = 1.5f, NHud::EFadeColor color = NHud::EFC_BLACK);
    void                                    fadeOut(f32 speed = 3.0f, NHud::EFadeColor color = NHud::EFC_BLACK);

    const video::SColor&                    getBackBufferColor() const;
    N3D::CCamera*                           getActiveCamera();
    NShader::CShadowProcessor*              getShadowProcessor();

  protected:
    // Faders
    gui::IGUIInOutFader*                    InFader;
    gui::IGUIInOutFader*                    OutFader;

    // 2D elements
    NHud::CPicture* Dummy;
    NHud::CCinemascopeMode*                 Cinemascope;

    // 3D entities
    N3D::CCamera*                           Camera;
    N3D::CSky*                              Sky;

    // Interfaces
    NEngine::CPlayerControl*                Control;
    NEngine::CSave*                         GameSave;
    NEngine::NGameplay::CDialogInterface*   Dialog;
    NSound::CMusicReference*                Music;
    NEngine::NResource::CTranslation*       GlobalTranslations;
    NEngine::NResource::CTranslation*       SceneTranslations;
    NShader::CShadowProcessor*              ShadowProcessor;

    // Primitive data
    video::SColor                           BackBufferColor;
    f32                                     SceneTime;
    f32                                     StartTime;
    f32                                     SpeedFactor;
    NScene::ELoadingStatus                  LoadingStatus;

    // Debug Tools
    NDebug::CConsole*                       DebugConsole;

  private:
    // Methods
    void                                    generateDebugInfo();
    gui::IGUIStaticText*                    DebugInfo;
};

}
}

#endif
