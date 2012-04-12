/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_GAME_H__
#define __IS06_GAME_H__

#include "ScreenPosition.h"
#include "Shaders.h"

#include "enums/engine/SceneIdentifier.h"
#include "enums/engine/LocaleIdentifier.h"
#include "enums/debug/ErrorCode.h"
#include "debug/GameDebugOption.h"

namespace is06
{
namespace engine
{

class CGame
{
  public:
    static void init();
    static void run();
    static void finish();

    static void quit();
    static void changeScene(irr::s32 id);
    static void warning(is06::debug::EErrorCode code);
    static void fatalError(is06::debug::EErrorCode code);
    static void errorLog(const std::exception& e);

    static irr::IrrlichtDevice* getDevice();
    static irr::video::IVideoDriver* getVideoDriver();
    static irr::scene::ISceneManager* getSceneManager();
    static irr::gui::IGUIEnvironment* getDebugGUI();
    static NewtonWorld* getNewtonWorld();
    static engine::CEventManager* getEventManager();
    static engine::CTranslation* getGlobalTranslations();
    static engine::CSave* getCurrentSave();
    static scene::CScene* getCurrentScene();
    static sound::CSoundManager* getSoundManager();

    static irr::f32 getFramerate();
    static irr::f32 getSpeedFactor();
    static irr::f32 getCurrentTime();
    static engine::ELocaleIdentifier getCurrentLocale();
    static sound::CMusicReference* getMusicReference();

    static void changeScreenDisplay(irr::u32 width=848, irr::u32 height=480, irr::u8 colorDepth=32);

    static engine::CSettings* Settings;
    static engine::SScreenPosition ScreenPos;
    static shader::CShaders Shaders;
    static debug::SGameDebugOption DebugOption;

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

    // Irrlicht objects
    static irr::IrrlichtDevice* Device;
    static irr::video::IVideoDriver* VideoDriver;
    static irr::video::IGPUProgrammingServices* GpuManager;
    static irr::scene::ISceneManager* SceneManager;
    static irr::gui::IGUIEnvironment* DebugGUI;

    // Newton objects
    static NewtonWorld* GameNewtonWorld;

    // is06 objects
    static engine::CEventManager* EventManager;
    static scene::CScene* CurrentScene;
    static engine::CTranslation* GlobalTranslations;
    static engine::CSave* CurrentSave;
    static sound::CSoundManager* SoundManager;
    static sound::CMusicReference* MusicReference;

    static engine::ELocaleIdentifier CurrentLocale;
    static irr::s32 NextScene;
    static bool SceneChanged;
    static bool ScreenSizeChanged;
    static bool Exit;
    static bool IndependantSpeed;
    static bool ProcessorPriority;
    static irr::u8 Framerate;
    static irr::f32 SpeedFactor;
};

}
}

#endif
