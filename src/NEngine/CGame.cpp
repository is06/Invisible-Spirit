/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/core.h"
#include "../../../include/maps.h"
#include "../../../include/NEngine/NCore/CGame.h"
#include "../../../include/NEngine/NResource/CTranslation.h"
#include "../../../include/NEngine/NException/CEngineException.h"
#include "../../../include/NEngine/NException/CDisplayException.h"
#include "../../../include/NEngine/NException/CMapException.h"
#include "../../../include/NEngine/NEvent/CEventManager.h"
#include "../../../include/NEngine/NResource/CSettings.h"
#include "../../../include/NEngine/NSave/CSave.h"
#include "../../../include/NSound/CSoundManager.h"
#include "../../../include/NSound/CMusicReference.h"
#include "../../../include/NScene/CScene.h"
#include "../../../include/NScene/CSceneMenu.h"
#include "../../../include/NScene/CSceneSelectMap.h"
#include "../../../include/NScene/CSceneGameplay.h"

#include "../../../include/NMap/NDebug/MAP_DEBUG.h"
#include "../../../include/NMap/NDebug/MAP_ALPHA_ZONE.h"
#include "../../../include/NMap/NDungeon/MAP_DUNGEON_1.h"
#include "../../../include/NMap/NDungeon/MAP_DUNGEON_2.h"
#include "../../../include/NMap/NDungeon/MAP_DUNGEON_3.h"
#include "../../../include/NMap/NDungeon/MAP_DUNGEON_4.h"
#include "../../../include/NMap/NDungeon/MAP_DUNGEON_5.h"
#include "../../../include/NMap/NDungeon/MAP_DUNGEON_6.h"
#include "../../../include/NMap/NDungeon/MAP_DUNGEON_7.h"
#include "../../../include/NMap/NDungeon/MAP_DUNGEON_8.h"
#include "../../../include/NMap/NDungeon/MAP_DUNGEON_9.h"

using namespace irr;

namespace is06 { namespace NEngine { namespace NCore {

IrrlichtDevice* CGame::Device;
video::IVideoDriver* CGame::VideoDriver;
video::IGPUProgrammingServices* CGame::GpuManager;
scene::ISceneManager* CGame::SceneManager;
gui::IGUIEnvironment* CGame::DebugGUI;
NewtonWorld* CGame::GameNewtonWorld;
NScene::CScene* CGame::CurrentScene;
NEngine::CEventManager* CGame::EventManager;
NEngine::NResource::CTranslation* CGame::GlobalTranslations;
NEngine::CSave* CGame::CurrentSave;
NSound::CSoundManager* CGame::SoundManager;
NSound::CMusicReference* CGame::MusicReference;
s32 CGame::NextScene;
NEngine::ELocaleIdentifier CGame::CurrentLocale;
bool CGame::SceneChanged;
bool CGame::ScreenSizeChanged;
bool CGame::Exit;
bool CGame::IndependantSpeed;
bool CGame::ProcessorPriority;
u8 CGame::Framerate;
f32 CGame::SpeedFactor;

//! Settings interface
/**
 * \section settings_usecase Settings use case
 * \code
 * string rendererName = NEngine::CGame::Settings->getParamString("display", "renderer");
 * \endcode
 */
NEngine::NResource::CSettings* CGame::Settings;

//! Screen position information
/**
 * \section screenpos_usecase ScreenPos use case
 * \code
 * f32 topEdge = NEngine::CGame::ScreenPos.Top;
 * \endcode
 */
NEngine::SScreenPosition CGame::ScreenPos;

//! Shaders interface
/**
 * \section shaders_usecase Shaders use case
 * \code
 * Material.MaterialType = (video::E_MATERIAL_TYPE)NEngine::CGame::Shaders.HorizontalBlur;
 * \endcode
 */
NShader::CShaders CGame::Shaders;

//! Debug options information
NDebug::SOption CGame::DebugOption;

//! All initializations
void CGame::init()
{
  Settings = new NResource::CSettings();
  initScreenPositions();
  initIrrlichtInterfaces();
  initDebugOptions();
  initRenderSystem();
  initControls();
  initShaders();
  initLocale();
  initScenes();
  initPhysics();
  initSoundLayer();
  initSaveSystem();
}

//! Game main loop
void CGame::run()
{
  // For independant speed
  u32 lastCycleTime, loopTime = 0;
  s32 lastFPS = -1;

  while (Device->run()) {
    if (Exit || ScreenSizeChanged) {
      break;
    }

    if (SceneChanged) {
      loadNextScene();
    }

    s32 fps = VideoDriver->getFPS();

    if (lastFPS != fps) {
      core::stringw str = L"Invisible Spirit 0.1 release 10 - fps: ";
      str += fps;
      Device->setWindowCaption(str.c_str());
      lastFPS = fps;
    }

    // Speed factor computation
    lastCycleTime = Device->getTimer()->getRealTime() - loopTime;
    loopTime = Device->getTimer()->getRealTime();
    SpeedFactor = lastCycleTime / 1000.0f;
    if (SpeedFactor > 1.0f) SpeedFactor = 1.0f; // Limit min 1fps
    if (SpeedFactor < 0.0f) SpeedFactor = 0.0f; // Limit max fps (infinite) negative = reversed movements

    VideoDriver->beginScene(true, true, CurrentScene->getBackBufferColor());

    // Main events
    manageLoadingScreen();
    CurrentScene->events();
    SceneManager->drawAll();

    // Post Render events
    if (!DebugOption.Display.HidePostRender) {
      CurrentScene->postRender();
    }
    CurrentScene->hudRender();
    DebugGUI->drawAll();

    SoundManager->setEarsData(CurrentScene->getActiveCamera());
    SoundManager->update();

    VideoDriver->endScene();
    if (!ProcessorPriority) {
      Device->yield();
    }
  }
}

//! Access to the Irrlicht device
/**
 * \return IrrlichtDevice*
 */
IrrlichtDevice* CGame::getDevice()
{
  return Device;
}

//! Access to the Irrlicht video driver
/**
 * \return IVideoDriver*
 */
video::IVideoDriver* CGame::getVideoDriver()
{
  return VideoDriver;
}

//! Access to the Irrlicht scene manager
/**
 * \return ISceneManager*
 */
scene::ISceneManager* CGame::getSceneManager()
{
  return SceneManager;
}

//! Access to the Debug GUI interface
/**
 * \return IGUIEnvironment*
 */
gui::IGUIEnvironment* CGame::getDebugGUI()
{
  return DebugGUI;
}

//! Access to the Newton world entity
/**
 * \return NewtonWorld*
 */
NewtonWorld* CGame::getNewtonWorld()
{
  return GameNewtonWorld;
}

//! Access to the current scene
/**
 * \return CScene*
 */
NScene::CScene* CGame::getCurrentScene()
{
  return CurrentScene;
}

//! Access to the Event manager
/**
 * \return CEventManager*
 */
CEventManager* CGame::getEventManager()
{
  return EventManager;
}

//! Set instruction in order to quit the game
void CGame::quit()
{
  Exit = true;
}

//! Irrlicht interfaces initialization
void CGame::initIrrlichtInterfaces()
{
  Device = NULL;
  VideoDriver = NULL;

  // Custom Event Manager
  EventManager = new CEventManager();

  // Getting from ini file
  u32 screenWidth = Settings->getParamInt("display", "width");
  u32 screenHeight = Settings->getParamInt("display", "height");
  u8 screenDepth = Settings->getParamInt("display", "depth");

  video::E_DRIVER_TYPE renderer = video::EDT_SOFTWARE;
  if (Settings->getParamString("display", "renderer") == "direct3d") {
    renderer = video::EDT_DIRECT3D9;
  } else if (Settings->getParamString("display", "renderer") == "opengl") {
    renderer = video::EDT_OPENGL;
  }

  // Irrlicht Device creation
  SIrrlichtCreationParameters deviceParameters;
  deviceParameters.AntiAlias = Settings->getParamInt("display", "anti_aliasing");
  deviceParameters.Bits = screenDepth;
  deviceParameters.DriverType = renderer;
  deviceParameters.EventReceiver = EventManager;
  deviceParameters.Fullscreen = (Settings->getParamInt("display", "fullscreen") == 1);
  deviceParameters.Stencilbuffer = false;
  deviceParameters.Vsync = (Settings->getParamInt("display", "vsync") == 1);
  deviceParameters.WindowSize = core::dimension2du(screenWidth, screenHeight);
  Device = createDeviceEx(deviceParameters);

  if (!Device) {
    throw NException::CEngineException("Irrlicht device not created");
  }

  // Other interfaces
  VideoDriver = Device->getVideoDriver();
  VideoDriver->getDriverType();

  if (!VideoDriver) {
    throw NException::CEngineException("Video driver not created");
  }

  GpuManager = VideoDriver->getGPUProgrammingServices();
  SceneManager = Device->getSceneManager();
  DebugGUI = Device->getGUIEnvironment();

  // Check Driver Graphical Capabilities
  checkGraphicalCapabilities();
}

//! Sets some rendering behavior information like framerate or if the game must leave some CPU to the other programs
void CGame::initRenderSystem()
{
  // Render speed
  Framerate = 60;
  ProcessorPriority = (Settings->getParamInt("processor", "priority") == 1);
}

//! Initializes screen position values
void CGame::initScreenPositions()
{
  ScreenSizeChanged = false;

  // Getting from ini file
  u32 screenWidth = Settings->getParamInt("display", "width");
  u32 screenHeight = Settings->getParamInt("display", "height");
  u8 screenDepth = Settings->getParamInt("display", "depth");

  // Display Screen position info
  ScreenPos.Display.Width = screenWidth;
  ScreenPos.Display.Height = screenHeight;
  ScreenPos.Display.HCenter = screenWidth / 2;
  ScreenPos.Display.VCenter = screenHeight / 2;
  ScreenPos.Display.Top = 0;
  ScreenPos.Display.Bottom = screenHeight;
  ScreenPos.Display.Left = 0;
  ScreenPos.Display.Right = screenWidth;
  ScreenPos.Display.ColorDepth = screenDepth;

  // Screen size limit 640x480 => 1920x1080
  //@TODO: uncomment this block later
  /*
  if(screenWidth < 640) screenWidth = 640;
  if(screenWidth > 1920) screenWidth = 1920;
  if(screenHeight < 480) screenHeight = 480;
  if(screenHeight > 1080) screenHeight = 1080;
  */

  // Ratio computation
  f32 ratio = (f32)screenWidth / (f32)screenHeight;
  screenHeight = 720;
  screenWidth = screenHeight * ratio;

  // Hud Screen position info
  ScreenPos.Hud.Width = screenWidth;
  ScreenPos.Hud.Height = screenHeight;
  ScreenPos.Hud.HCenter = 0.0f;
  ScreenPos.Hud.VCenter = 0.0f;
  ScreenPos.Hud.Top = (screenHeight / 2.0f);
  ScreenPos.Hud.Bottom = (screenHeight / 2.0f) * -1;
  ScreenPos.Hud.Left = (screenWidth / 2.0f) * -1;
  ScreenPos.Hud.Right = (screenWidth / 2.0f);
}

//! Initializes shader custom material values
void CGame::initShaders()
{
  Shaders = NShader::CShaders();
  Shaders.createMaterials(GpuManager);
}

//! Creates a global translation object according to the locale set in settings
void CGame::initLocale()
{
  //string textLocale = settings->getParamstring("regional", "locale");
  CurrentLocale = ELI_FRE_FR;
  /*
  if (textLocale == "eng-GB") {
    currentLocale = ELI_ENG_GB;
  }
  */

  GlobalTranslations = new NEngine::NResource::CTranslation("global.ist");
}

//!
void CGame::initDebugOptions()
{
  DebugOption.Display.HidePostRender = false;
  DebugOption.Display.ShowIrrlichtDebugData = false;
  DebugOption.Display.ShowWireFrame = false;
}

//!
void CGame::initSoundLayer()
{
  SoundManager = new NSound::CSoundManager();
  MusicReference = new NSound::CMusicReference();
}

//!
void CGame::initScenes()
{
  Exit = false;
  SceneChanged = true;
  NextScene = NScene::ESI_MAP_ALPHA_ZONE;
}

//!
void CGame::initControls()
{
  // Joystick activation
  //core::array<SJoystickInfo> joystickInfo;
  //Device->activateJoysticks(joystickInfo);
}

//! Creates the Newton world object
void CGame::initPhysics()
{
  GameNewtonWorld = NewtonCreate();
}

//! Creates an empty save memory slot
void CGame::initSaveSystem()
{
  CurrentSave = new CSave();
}

//! Check for mandatory graphical capabilities
void CGame::checkGraphicalCapabilities()
{
  if (VideoDriver->getDriverType() == video::EDT_DIRECT3D9) {
    // DirectX 9 requirements
    // HLSL
    if (!VideoDriver->queryFeature(video::EVDF_HLSL)) {
      throw NException::CDisplayException("[E56] HLSL not supported");
    }
    // Vertex Shader 2.0
    if (!VideoDriver->queryFeature(video::EVDF_VERTEX_SHADER_2_0)) {
      throw NException::CDisplayException("[E50] Vertex shaders 2.0 not supported");
    }
    // Pixel Shader 2.0
    if (!VideoDriver->queryFeature(video::EVDF_PIXEL_SHADER_2_0)) {
      throw NException::CDisplayException("[E51] Pixel shaders 2.0 not supported");
    }
  } else if (VideoDriver->getDriverType() == video::EDT_OPENGL) {
    // OpenGL requirements
    // GLSL
    if (!VideoDriver->queryFeature(video::EVDF_ARB_GLSL)) {
      throw NException::CDisplayException("[E55] GLSL not supported");
    }
  }

  // Render to target textures
  if (!VideoDriver->queryFeature(video::EVDF_RENDER_TO_TARGET)) {
    throw NException::CDisplayException("[E52] Render to target textures not supported");
  }
}

//! Changes the game screen window
void CGame::changeScreenDisplay(u32 width, u32 height, u8 colorDepth)
{
  ScreenSizeChanged = true;
  delete CurrentScene;
  Device->drop();
  ScreenPos.Display.Width = width;
  ScreenPos.Display.Height = height;
  ScreenPos.Display.ColorDepth = colorDepth;
  initIrrlichtInterfaces();
  initScenes();
}

//! Returns constant framerate target value
/**
 * \return f32
 */
f32 CGame::getFramerate()
{
  return Framerate;
}

//! Returns the speed factor, used to perform computation on movements and time
/**
 * \return f32
 */
f32 CGame::getSpeedFactor()
{
  return SpeedFactor;
}

//! Returns current real time in milliseconds
f32 CGame::getCurrentTime()
{
  return Device->getTimer()->getRealTime();
}

//! Changes the current scene by passing its id
/**
 * \param s32 the scene id
 */
void CGame::changeScene(s32 id)
{
  NextScene = id;
  SceneChanged = true;
}

//! Loads the scene which is specified in nextScene attribute on the next cycle
void CGame::loadNextScene()
{
  delete CurrentScene;

  switch (NextScene) {
    // Menus
    case NScene::ESI_MENU: CurrentScene = new NScene::CSceneMenu(); break;
    case NScene::ESI_SELECT_MAP: CurrentScene = new NScene::CSceneSelectMap(); break;

    // Debug
    case NScene::ESI_MAP_ALPHA_ZONE: CurrentScene = new NMap::NDebug::MAP_ALPHA_ZONE(); break;
    case NScene::ESI_MAP_DEBUG: CurrentScene = new NMap::NDebug::MAP_DEBUG(); break;

    // Countries

    // Dungeons
    case NScene::ESI_MAP_DUNGEON_1: CurrentScene = new NMap::NDungeon::MAP_DUNGEON_1(); break;
    case NScene::ESI_MAP_DUNGEON_2: CurrentScene = new NMap::NDungeon::MAP_DUNGEON_2(); break;
    case NScene::ESI_MAP_DUNGEON_3: CurrentScene = new NMap::NDungeon::MAP_DUNGEON_3(); break;
    case NScene::ESI_MAP_DUNGEON_4: CurrentScene = new NMap::NDungeon::MAP_DUNGEON_4(); break;
    case NScene::ESI_MAP_DUNGEON_5: CurrentScene = new NMap::NDungeon::MAP_DUNGEON_5(); break;
    case NScene::ESI_MAP_DUNGEON_6: CurrentScene = new NMap::NDungeon::MAP_DUNGEON_6(); break;
    case NScene::ESI_MAP_DUNGEON_7: CurrentScene = new NMap::NDungeon::MAP_DUNGEON_7(); break;
    case NScene::ESI_MAP_DUNGEON_8: CurrentScene = new NMap::NDungeon::MAP_DUNGEON_8(); break;
    case NScene::ESI_MAP_DUNGEON_9: CurrentScene = new NMap::NDungeon::MAP_DUNGEON_9(); break;

    default:
      throw NException::CMapException("[E10] Unknown map id");
      break;
  }

  CurrentScene->setSaveSlot(CurrentSave);

  // Displays scene loading screen
  CurrentScene->startLoadingScreen();

  SceneChanged = false;
}

void CGame::manageLoadingScreen()
{
  if (CurrentScene->getLoadingStatus() == NScene::ELS_LOADS) {
    // When the loading sequence finishes, start the loading outro
    CurrentScene->loadingSequence();
    CurrentScene->setLoadingStatus(NScene::ELS_OUTRO);
  } else if (CurrentScene->getLoadingStatus() == NScene::ELS_READY) {
    CurrentScene->start();
    CurrentScene->setLoadingStatus(NScene::ELS_PLAYING);
  }
}

//! Writes an error message in error.log file
/**
 * \param EngineException& to write
 */
void CGame::writeErrorToLogFile(const exception& e)
{
  ofstream errorLogFile("error.log", ios::out | ios::app);
  if (errorLogFile) {
    errorLogFile << e.what() << endl;
    errorLogFile.close();
  }
}

//! Get the current locale defined in configuration file
/**
 * \return ELocaleIdentifier
 */
ELocaleIdentifier CGame::getCurrentLocale()
{
  return CurrentLocale;
}

//! Returns a pointer to the global translation interface
/**
 * \return CTranslation*
 */
NResource::CTranslation* CGame::getGlobalTranslations()
{
  return GlobalTranslations;
}

//! Returns a pointer to the current save slot
/**
 * \return CSave*
 */
CSave* CGame::getCurrentSave()
{
  return CurrentSave;
}

//! Returns a pointer to the Invisible Spirit Sound Manager
/**
 * \return CSoundManager*
 */
NSound::CSoundManager* CGame::getSoundManager()
{
  return SoundManager;
}

//! Returns the music interface
NSound::CMusicReference* CGame::getMusicReference()
{
  return MusicReference;
}

//! Flush and delete everything, finishes the game
void CGame::finish()
{
  delete CurrentScene;
  delete Settings;
  delete SoundManager;
  delete MusicReference;
  delete GlobalTranslations;
  delete CurrentSave;

  NewtonDestroyAllBodies(GameNewtonWorld);
  NewtonDestroy(GameNewtonWorld);
  Device->drop();

  delete EventManager;
}

}}}
