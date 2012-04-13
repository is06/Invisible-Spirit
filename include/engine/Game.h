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

#include "../screen/SceneIdentifier.h"
#include "LocaleIdentifier.h"
#include "ErrorCode.h"
#include "../debug/GameDebugOption.h"

//! Main namespace for Invisible Spirit Game
namespace is06
{
//! Namespace for debugging information and parameters
namespace debug
{
}
//! Hud namespace with all simili 2D elements to display
namespace hud
{
}
//! This namespace contains all levels and maps of the game
namespace level
{
}
//! The model namespace provides 3D Model classes
namespace model
{
}
//! Namespace for screens and scene types
namespace screen
{
}
//! This namespace is for shader graphical effects
namespace shader
{
}
//! Namespace for sound and music interfaces
namespace sound
{
}
//! Namespace for engine classes
namespace engine
{
//! Singleton class CGame manage everything, it contains the main loop and all main entities like the current scene
/** \section usecase Use case
 * \code
 * int main()
 * {
 *   try {
 *     is06::engine::CGame::init();
 *     is06::engine::CGame::run();
 *     is06::engine::CGame::finish();
 *   } catch(const exception& e) {
 *     cerr << "Exception: " << e.what() << endl;
 *     is06::engine::CGame::errorLog(e);
 *   }
 *   return 0;
 * }
 * \endcode
*/
class CGame
{
  public:
    static void init();
    static void run();
    static void finish();

    static void quit();
    static void changeScene(s32 id);
    static void warning(is06::debug::EErrorCode code);
    static void fatalError(is06::debug::EErrorCode code);
    static void errorLog(const exception& e);

    static IrrlichtDevice* getDevice();
    static video::IVideoDriver* getVideoDriver();
    static scene::ISceneManager* getSceneManager();
    static gui::IGUIEnvironment* getDebugGUI();
    static NewtonWorld* getNewtonWorld();
    static engine::CEventManager* getEventManager();
    static engine::CTranslation* getGlobalTranslations();
    static engine::CSave* getCurrentSave();
    static screen::CScene* getCurrentScene();
    static sound::CSoundManager* getSoundManager();

    static f32 getFramerate();
    static f32 getSpeedFactor();
    static f32 getCurrentTime();
    static engine::ELocaleIdentifier getCurrentLocale();
    static sound::CMusicReference* getMusicReference();

    static void changeScreenDisplay(u32 width=848, u32 height=480, u8 colorDepth=32);

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
    static IrrlichtDevice* Device;
    static video::IVideoDriver* VideoDriver;
    static video::IGPUProgrammingServices* GpuManager;
    static scene::ISceneManager* SceneManager;
    static gui::IGUIEnvironment* DebugGUI;

    // Newton objects
    static NewtonWorld* GameNewtonWorld;

    // is06 objects
    static engine::CEventManager* EventManager;
    static screen::CScene* CurrentScene;
    static engine::CTranslation* GlobalTranslations;
    static engine::CSave* CurrentSave;
    static sound::CSoundManager* SoundManager;
    static sound::CMusicReference* MusicReference;

    static engine::ELocaleIdentifier CurrentLocale;
    static s32 NextScene;
    static bool SceneChanged;
    static bool ScreenSizeChanged;
    static bool Exit;
    static bool IndependantSpeed;
    static bool ProcessorPriority;
    static u8 Framerate;
    static f32 SpeedFactor;
};

}
}

#endif
