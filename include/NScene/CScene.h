/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_SCENE_SCENE_H__
#define __IS06_SCENE_SCENE_H__

#include "../N3D/NCamera/CCamera.h"
#include "../NScene/ELoadingStatus.h"
#include "../NShader/CShadowProcessor.h"
#include "../NEngine/NControl/CPlayerControl.h"
#include "../NHud/NPrimitive/EFadeColor.h"
#include "../NHud/NPart/CCinemascopeMode.h"
#include "../N3D/NPart/CSky.h"
#include "../NDebug/CConsole.h"
#include "ESceneIdentifier.h"

namespace is06 { namespace NScene {

class CScene
{
public:
  CScene();
  virtual ~CScene();

  virtual void events() = 0;
  virtual void postRender() = 0;
  virtual void hudRender() = 0;
  virtual void start();

  // Loading methods
  virtual void startLoadingScreen();
  virtual void stopLoadingScreen();
  virtual void loadingSequence();
  NScene::ELoadingStatus getLoadingStatus();
  void setLoadingStatus(NScene::ELoadingStatus status);

  // Save
  void setSaveSlot(NEngine::NSave::CSave* save);

  // Fades
  void fadeIn(f32 speed = 1.5f, NHud::NPrimitive::EFadeColor color = NHud::NPrimitive::EFC_BLACK);
  void fadeOut(f32 speed = 3.0f, NHud::NPrimitive::EFadeColor color = NHud::NPrimitive::EFC_BLACK);

  const video::SColor& getBackBufferColor() const;
  N3D::NCamera::CCamera* getActiveCamera();
  NShader::CShadowProcessor* getShadowProcessor();

  static CScene* getSceneFromIdentifier(const ESceneIdentifier& id);

protected:
  // Faders
  gui::IGUIInOutFader* InFader;
  gui::IGUIInOutFader* OutFader;

  // 2D elements
  NHud::NPrimitive::CPicture* Dummy;
  NHud::NPart::CCinemascopeMode* Cinemascope;

  // 3D entities
  N3D::NCamera::CCamera* Camera;
  N3D::NPart::CSky* Sky;

  // Interfaces
  NEngine::NControl::CPlayerControl* Control;
  NEngine::NSave::CSave* GameSave;
  NEngine::NGameplay::CDialogInterface* Dialog;
  NSound::CMusicReference* Music;
  NEngine::NResource::CTranslation* GlobalTranslations;
  NEngine::NResource::CTranslation* SceneTranslations;
  NShader::CShadowProcessor* ShadowProcessor;

  // Primitive data
  video::SColor BackBufferColor;
  f32 SceneTime;
  f32 StartTime;
  f32 SpeedFactor;
  NScene::ELoadingStatus LoadingStatus;

  // Debug Tools
  NDebug::CConsole* DebugConsole;

private:
  // Methods
  void generateDebugInfo();
  gui::IGUIStaticText* DebugInfo;
};

}}

#endif
