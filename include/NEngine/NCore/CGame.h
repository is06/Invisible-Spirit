/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_ENGINE_GAME_H__
#define __IS06_ENGINE_GAME_H__

#include "SScreenPosition.h"
#include "Resource/ELocaleIdentifier.h"
#include "../Shader/CShaders.h"
#include "../Scene/ESceneIdentifier.h"
#include "../Debug/EErrorCode.h"
#include "../Debug/SOption.h"

namespace is06 { namespace NEngine { namespace NCore {

//! Singleton class CGame manage everything, it contains the main loop and all main entities like the current scene
class CGame
{
public:
  static void init();
  static void run();
  static void finish();

  static void quit();
  static void changeScene(s32 id);
  static void writeErrorToLogFile(const exception& e);

  static IrrlichtDevice* getDevice();
  static video::IVideoDriver* getVideoDriver();
  static scene::ISceneManager* getSceneManager();
  static gui::IGUIEnvironment* getDebugGUI();
  static NewtonWorld* getNewtonWorld();
  static NEngine::CEventManager* getEventManager();
  static NEngine::NResource::CTranslation* getGlobalTranslations();
  static NEngine::CSave* getCurrentSave();
  static NScene::CScene* getCurrentScene();
  static NSound::CSoundManager* getSoundManager();

  static f32 getFramerate();
  static f32 getSpeedFactor();
  static f32 getCurrentTime();
  static NEngine::ELocaleIdentifier getCurrentLocale();
  static NSound::CMusicReference* getMusicReference();

  static void changeScreenDisplay(u32 width=848, u32 height=480, u8 colorDepth=32);

  static NEngine::NResource::CSettings* Settings;
  static NEngine::SScreenPosition ScreenPos;
  static NShader::CShaders Shaders;
  static NDebug::SOption DebugOption;

private:
  CGame();

  // Game initializations
  static void initIrrlichtInterfaces();
  static void initRenderSystem();
  static void initScreenPositions();
  static void initShaders();
  static void initLocale();
  static void initScenes();
  static void initControls();
  static void initSoundLayer();
  static void initPhysics();
  static void initSaveSystem();
  static void initDebugOptions();
  static void checkGraphicalCapabilities();

  // Game actions
  static void loadNextScene();
  static void manageLoadingScreen();

  // Irrlicht objects
  static IrrlichtDevice* Device;
  static video::IVideoDriver* VideoDriver;
  static video::IGPUProgrammingServices* GpuManager;
  static scene::ISceneManager* SceneManager;
  static gui::IGUIEnvironment* DebugGUI;

  // Newton objects
  static NewtonWorld* GameNewtonWorld;

  // is06 objects
  static NEngine::CEventManager* EventManager;
  static NScene::CScene* CurrentScene;
  static NEngine::NResource::CTranslation* GlobalTranslations;
  static NEngine::CSave* CurrentSave;
  static NSound::CSoundManager* SoundManager;
  static NSound::CMusicReference* MusicReference;

  static NEngine::ELocaleIdentifier CurrentLocale;
  static s32 NextScene;
  static bool SceneChanged;
  static bool ScreenSizeChanged;
  static bool Exit;
  static bool IndependantSpeed;
  static bool ProcessorPriority;
  static u8 Framerate;
  static f32 SpeedFactor;
};

}}}

#endif
