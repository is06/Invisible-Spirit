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

using namespace irr;
using namespace std;

class Game
{
  public:
    static void init();
    static void run();
    static void finish();

    static void quit();
    static void changeScene(s32 id);
    static void warning(ErrorCode code);
    static void fatalError(ErrorCode code);
    static void errorLog(const exception& e);

    static IrrlichtDevice* getDevice();
    static video::IVideoDriver* getVideoDriver();
    static scene::ISceneManager* getSceneManager();
    static gui::IGUIEnvironment* getDebugGUI();
    static NewtonWorld* getNewtonWorld();
    static EventManager* getEventManager();
    static Translation* getGlobalTranslations();
    static Save* getCurrentSave();
    static Scene* getCurrentScene();
    static SoundManager* getSoundManager();

    static f32 getFramerate();
    static f32 getSpeedFactor();
    static f32 getCurrentTime();
    static LocaleIdentifier getCurrentLocale();
    static MusicReference* getMusicReference();

    static void changeScreenDisplay(u32 width=848, u32 height=480, u8 colorDepth=32);

    static Settings* settings;
    static ScreenPosition screenPos;
    static Shaders shaders;
    static GameDebugOption debugOption;

  private:
    Game();

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

    // Game actions
    static void loadNextScene();

    // Irrlicht objects
    static IrrlichtDevice* device;
    static video::IVideoDriver* videoDriver;
    static video::IGPUProgrammingServices* gpuManager;
    static scene::ISceneManager* sceneManager;
    static gui::IGUIEnvironment* debugGUI;

    // Newton objects
    static NewtonWorld* newtonWorld;

    // is06 objects
    static EventManager* eventManager;
    static Scene* currentScene;
    static Translation* globalTranslations;
    static Save* currentSave;
    static SoundManager* soundManager;
    static MusicReference* musicLibrary;

    static LocaleIdentifier currentLocale;
    static s32 nextScene;
    static bool sceneChanged;
    static bool screenSizeChanged;
    static bool exit;
    static bool independantSpeed;
    static bool processorPriority;
    static u8 framerate;
    static f32 speedFactor;
};

#endif
