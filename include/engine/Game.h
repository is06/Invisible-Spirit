/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_GAME_H__
#define __IS06_GAME_H__

#include "ScreenPosition.h"
#include "LocaleIdentifier.h"
#include "../shader/Shaders.h"
#include "../scene/SceneIdentifier.h"
#include "../debug/ErrorCode.h"
#include "../debug/GameDebugOption.h"

//! Main namespace for Invisible Spirit Game
namespace is06
{
//! Namespace for debugging information and parameters
namespace nDebug
{
}
//! Hud namespace with all simili 2D elements to display
namespace nHud
{
}
//! This namespace contains all levels and maps of the game
namespace nMap
{
}
//! The namespace which provides 3D Model classes
namespace n3D
{
}
//! Namespace for scene types
namespace nScene
{
}
//! This namespace is for shader graphical effects
namespace nShader
{
}
//! Namespace for sound and music interfaces
namespace nSound
{
}
//! Namespace for engine classes
namespace nEngine
{
//! Singleton class CGame manage everything, it contains the main loop and all main entities like the current scene
/** \section usecase Use case
 * \code
 * int main()
 * {
 *   try {
 *     is06::nEngine::CGame::init();
 *     is06::nEngine::CGame::run();
 *     is06::nEngine::CGame::finish();
 *   } catch(const exception& e) {
 *     cerr << "Exception: " << e.what() << endl;
 *     is06::nEngine::CGame::errorLog(e);
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
    static void warning(is06::nDebug::EErrorCode code);
    static void fatalError(is06::nDebug::EErrorCode code);
    static void errorLog(const exception& e);

    static IrrlichtDevice* getDevice();
    static video::IVideoDriver* getVideoDriver();
    static scene::ISceneManager* getSceneManager();
    static gui::IGUIEnvironment* getDebugGUI();
    static NewtonWorld* getNewtonWorld();
    static nEngine::CEventManager* getEventManager();
    static nEngine::CTranslation* getGlobalTranslations();
    static nEngine::CSave* getCurrentSave();
    static nScene::CScene* getCurrentScene();
    static nSound::CSoundManager* getSoundManager();

    static f32 getFramerate();
    static f32 getSpeedFactor();
    static f32 getCurrentTime();
    static nEngine::ELocaleIdentifier getCurrentLocale();
    static nSound::CMusicReference* getMusicReference();

    static void changeScreenDisplay(u32 width=848, u32 height=480, u8 colorDepth=32);

    static nEngine::CSettings* Settings;
    static nEngine::SScreenPosition ScreenPos;
    static nShader::CShaders Shaders;
    static nDebug::SGameDebugOption DebugOption;

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
    static nEngine::CEventManager* EventManager;
    static nScene::CScene* CurrentScene;
    static nEngine::CTranslation* GlobalTranslations;
    static nEngine::CSave* CurrentSave;
    static nSound::CSoundManager* SoundManager;
    static nSound::CMusicReference* MusicReference;

    static nEngine::ELocaleIdentifier CurrentLocale;
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
