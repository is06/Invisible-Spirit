/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_ENGINE_CORE_GAME_H__
#define __IS06_ENGINE_CORE_GAME_H__

#include "../NDisplay/SScreenPosition.h"
#include "../NResource/ELocaleIdentifier.h"
#include "../../NShader/CShaders.h"
#include "../../NScene/ESceneIdentifier.h"
#include "../../NDebug/EErrorCode.h"
#include "../../NDebug/SOption.h"

namespace is06 { namespace NEngine { namespace NCore {

//! Singleton class CGame manage everything, it contains the main loop and all main entities like the current scene
class CGame
{
public:
  // Main program actions
  static void init();
  static void run();
  static void finish();

  // Pointers getters
  static IrrlichtDevice* getDevice();
  static video::IVideoDriver* getVideoDriver();
  static scene::ISceneManager* getSceneManager();
  static gui::IGUIEnvironment* getDebugGUI();
  static NewtonWorld* getNewtonWorld();
  static NEvent::CEventManager* getEventManager();
  static NResource::CTranslation* getGlobalTranslations();
  static NSave::CSave* getCurrentSave();
  static NScene::CScene* getCurrentScene();
  static NSound::CSoundManager* getSoundManager();
  static NResource::CResourceManager* getResourceManager();
  static NResource::CSettings* getSettings();
  static NSound::CMusicReference* getMusicReference();

  // Data getters
  static f32 getFramerate();
  static f32 getSpeedFactor();
  static f32 getCurrentTime();
  static NResource::ELocaleIdentifier getCurrentLocale();

  // Game actions
  static void quit();
  static void changeScene(const NScene::ESceneIdentifier& id);
  static void writeErrorToLogFile(const exception& e);
  static void changeScreenDisplay(u32 width=848, u32 height=480, u8 colorDepth=32);

  // Game data structure properties
  static NDisplay::SScreenPosition ScreenPos;
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
  static NEvent::CEventManager* EventManager;
  static NScene::CScene* CurrentScene;
  static NResource::CTranslation* GlobalTranslations;
  static NSave::CSave* CurrentSave;
  static NSound::CSoundManager* SoundManager;
  static NSound::CMusicReference* MusicReference;
  static NResource::CResourceManager* ResourceManager;
  static NResource::CSettings* Settings;

  // Primitive data
  static NResource::ELocaleIdentifier CurrentLocale;
  static NScene::ESceneIdentifier NextScene;
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
