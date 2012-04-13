/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/core.h"
#include "../../include/engine/maps.h"
#include "../../include/engine/Game.h"
#include "../../include/engine/Translation.h"
#include "../../include/engine/EngineException.h"
#include "../../include/engine/EventManager.h"
#include "../../include/engine/Settings.h"
#include "../../include/engine/Save.h"
#include "../../include/sound/SoundManager.h"
#include "../../include/sound/MusicReference.h"
#include "../../include/screen/Scene.h"
#include "../../include/screen/SceneMenu.h"
#include "../../include/screen/SceneGameplay.h"
#include "../../include/level/MAP_ALPHA_ZONE.h"

namespace is06
{
namespace engine
{

IrrlichtDevice* CGame::Device;
video::IVideoDriver* CGame::VideoDriver;
video::IGPUProgrammingServices* CGame::GpuManager;
scene::ISceneManager* CGame::SceneManager;
gui::IGUIEnvironment* CGame::DebugGUI;
NewtonWorld* CGame::GameNewtonWorld;
screen::CScene* CGame::CurrentScene;
engine::CEventManager* CGame::EventManager;
engine::CTranslation* CGame::GlobalTranslations;
engine::CSave* CGame::CurrentSave;
sound::CSoundManager* CGame::SoundManager;
sound::CMusicReference* CGame::MusicReference;
s32 CGame::NextScene;
engine::ELocaleIdentifier CGame::CurrentLocale;
bool CGame::SceneChanged;
bool CGame::ScreenSizeChanged;
bool CGame::Exit;
bool CGame::IndependantSpeed;
bool CGame::ProcessorPriority;
u8 CGame::Framerate;
f32 CGame::SpeedFactor;

//! Settings interface
/**
 * \section usecase Use case
 * \code
 * engine::CGame::Settings->getParamString("display", "renderer");
 * \endcode
 */
engine::CSettings* CGame::Settings;

//! Screen position information
engine::SScreenPosition CGame::ScreenPos;

//! Shaders interface
shader::CShaders CGame::Shaders;

//! Debug options information
debug::SGameDebugOption CGame::DebugOption;

//! All initializations
void CGame::init()
{
  Settings = new CSettings();
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
  // For constant speed
  u32 before, after, renderTime, timeToSleep = 0;

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
      core::stringw str = L"Invisible Spirit 0.1 release 9 - fps: ";
      str += fps;
      Device->setWindowCaption(str.c_str());
      lastFPS = fps;
    }

    if (IndependantSpeed) {
      // ----------------------------------------------------
      // Speed Independant Loop

      // Speed factor computation
      lastCycleTime = Device->getTimer()->getRealTime() - loopTime;
      loopTime = Device->getTimer()->getRealTime();
      SpeedFactor = lastCycleTime / 1000.0f;
      if (SpeedFactor > 1.0f) SpeedFactor = 1.0f; // Limit min 1fps
      if (SpeedFactor < 0.0f) SpeedFactor = 0.0f; // Limit max fps (infinite) negative = reversed movements

      VideoDriver->beginScene(true, true, CurrentScene->getBackBufferColor());

      // Main events
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

    } else {
      // ----------------------------------------------------
      // Constant Speed Loop
      before = Device->getTimer()->getRealTime();

      SpeedFactor = 1.0f / Framerate;

      VideoDriver->beginScene(true, true, CurrentScene->getBackBufferColor());

      // Main events
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

      after = Device->getTimer()->getRealTime();
      renderTime = after - before;

      timeToSleep = (u32)(((1000.0f / Framerate) - renderTime) + after);

      while (Device->getTimer()->getRealTime() < timeToSleep) {
        if (!ProcessorPriority) {
          Device->yield();
        }
      }
    }
  }
}

//! Access to the Irrlicht device
/** \return IrrlichtDevice*
*/
IrrlichtDevice* CGame::getDevice()
{
  return Device;
}

//! Access to the Irrlicht video driver
/** \return IVideoDriver*
*/
video::IVideoDriver* CGame::getVideoDriver()
{
  return VideoDriver;
}

//! Access to the Irrlicht scene manager
/** \return ISceneManager*
*/
scene::ISceneManager* CGame::getSceneManager()
{
  return SceneManager;
}

//! Access to the Debug GUI interface
/** \return IGUIEnvironment*
*/
gui::IGUIEnvironment* CGame::getDebugGUI()
{
  return DebugGUI;
}

//! Access to the Newton world entity
/** \return NewtonWorld*
*/
NewtonWorld* CGame::getNewtonWorld()
{
  return GameNewtonWorld;
}

//! Access to the current scene
/** \return CScene*
*/
screen::CScene* CGame::getCurrentScene()
{
  return CurrentScene;
}

//! Access to the Event manager
/** \return CEventManager*
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
  // Custom Event Manager
  EventManager = new CEventManager();

  // Getting from ini file
  u32 screenWidth = Settings->getParamInt("display", "width");
  u32 screenHeight = Settings->getParamInt("display", "height");
  u8 screenDepth = Settings->getParamInt("display", "depth");

  video::E_DRIVER_TYPE renderer = video::EDT_SOFTWARE;
  string rendererParam = Settings->getParamString("display", "renderer");
  if (rendererParam == "direct3d") {
    renderer = video::EDT_DIRECT3D9;
  } else if (rendererParam == "opengl") {
    renderer = video::EDT_OPENGL;
  }

  // Irrlicht Device creation
  Device = createDevice(
    renderer,
    core::dimension2du(screenWidth, screenHeight),
    screenDepth,
    (Settings->getParamInt("display", "fullscreen") == 1),
    true,
    (Settings->getParamInt("display", "vsync") == 1),
    EventManager
  );
  Device->setWindowCaption(L"Invisible Spirit 0.1 release 9");

  // Other interfaces
  VideoDriver = Device->getVideoDriver();
  GpuManager = VideoDriver->getGPUProgrammingServices();
  SceneManager = Device->getSceneManager();
  DebugGUI = Device->getGUIEnvironment();

  // Check Driver Graphical Capabilities
  checkGraphicalCapabilities();
}

//!
void CGame::initRenderSystem()
{
  // Render speed
  Framerate = 60;
  IndependantSpeed = (Settings->getParamInt("processor", "independant_speed") == 1);
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

  ScreenPos.DisplayWidth = screenWidth;
  ScreenPos.DisplayHeight = screenHeight;
  ScreenPos.DisplayDepth = screenDepth;

  // Screen size limit 640x480 => 1920x1080
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

  // Screen position info
  ScreenPos.Width = screenWidth;
  ScreenPos.Height = screenHeight;
  ScreenPos.HCenter = 0.0f;
  ScreenPos.VCenter = 0.0f;
  ScreenPos.Top = (screenHeight / 2.0f);
  ScreenPos.Bottom = (screenHeight / 2.0f) * -1;
  ScreenPos.Left = (screenWidth / 2.0f) * -1;
  ScreenPos.Right = (screenWidth / 2.0f);

}

//! Initializes shader custom material values
void CGame::initShaders()
{
  Shaders = shader::CShaders();
  Shaders.createMaterials(GpuManager);
}

//! Creates a global translation object according to the locale set in settings
void CGame::initLocale()
{
  //string textLocale = settings->getParamstring("regional", "locale");
  CurrentLocale = LOCALE_FRE_FR;
  /*
  if (textLocale == "eng-GB") {
    currentLocale = LOCALE_ENG_GB;
  }
  */

  GlobalTranslations = new engine::CTranslation("global.ist");
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
  SoundManager = new sound::CSoundManager();
  MusicReference = new sound::CMusicReference();
}

//!
void CGame::initScenes()
{
  Exit = false;
  SceneChanged = true;
  NextScene = screen::SCENE_MENU;
}

//!
void CGame::initControls()
{
  // Joystick activation
  core::array<SJoystickInfo> joystickInfo;
  Device->activateJoysticks(joystickInfo);
}

//!
void CGame::initPhysics()
{
  GameNewtonWorld = NewtonCreate();
}

//!
void CGame::initSaveSystem()
{
  CurrentSave = new CSave();
}

//! Check for mandatory graphical capabilities
void CGame::checkGraphicalCapabilities()
{
  if (!VideoDriver->queryFeature(video::EVDF_VERTEX_SHADER_1_1)) {
    fatalError(debug::ERRCODE_50);
  }
  if (!VideoDriver->queryFeature(video::EVDF_PIXEL_SHADER_1_1)) {
    fatalError(debug::ERRCODE_51);
  }
  if (!VideoDriver->queryFeature(video::EVDF_RENDER_TO_TARGET)) {
    fatalError(debug::ERRCODE_52);
  }
}

//! Changes the game screen window
void CGame::changeScreenDisplay(u32 width, u32 height, u8 colorDepth)
{
  ScreenSizeChanged = true;
  delete CurrentScene;
  Device->drop();
  ScreenPos.DisplayWidth = width;
  ScreenPos.DisplayHeight = height;
  ScreenPos.DisplayDepth = colorDepth;
  initIrrlichtInterfaces();
  initScenes();
}

//! Returns constant framerate target value
/** \return f32
*/
f32 CGame::getFramerate()
{
  return Framerate;
}

//! Returns the speed factor, used to perform computation on movements and time
/** \return f32
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
/** \param s32 the scene id
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
    case screen::SCENE_MENU: CurrentScene = new screen::CSceneMenu(); break;
    case screen::SCENE_MAP_ALPHA_ZONE: CurrentScene = new level::MAP_ALPHA_ZONE(); break;

    default: fatalError(debug::ERRCODE_10); break;
  }

  CurrentScene->setSaveSlot(CurrentSave);
  SceneChanged = false;
}

//! Writes a warning in the console
void CGame::warning(debug::EErrorCode code)
{
  switch (code) {
    case debug::ERRCODE_21: throw engine::CEngineException(code, "Unable to write save file", 2); break;
    default: throw engine::CEngineException(code, "Unknown warning", 2); break;
  }
}

//! Launches an error to error.log file by its code number
/** \param EErrorCode the code number
*/
void CGame::fatalError(debug::EErrorCode code)
{
  switch (code) {
    case debug::ERRCODE_10: throw engine::CEngineException(code, "Unknown map id", 3); break;
    case debug::ERRCODE_20: throw engine::CEngineException(code, "Unable to open save file", 3); break;
    case debug::ERRCODE_30: throw engine::CEngineException(code, "Mesh file not found", 3); break;
    case debug::ERRCODE_45: throw engine::CEngineException(code, "Level Mesh need an Irrlicht mesh, use loadMesh method in scene constructor", 3); break;
    case debug::ERRCODE_46: throw engine::CEngineException(code, "Level Mesh need an Irrlicht node, use createNode method in scene constructor", 3); break;
    case debug::ERRCODE_47: throw engine::CEngineException(code, "Level Mesh need a Newton body, use loadMeshCollision method in scene constructor", 3); break;
    case debug::ERRCODE_50: throw engine::CEngineException(code, "Vertex Shaders 2.0 not supported", 3); break;
    case debug::ERRCODE_51: throw engine::CEngineException(code, "Pixels Shaders 2.0 not supported", 3); break;
    case debug::ERRCODE_52: throw engine::CEngineException(code, "Render to target not supported", 3); break;
    case debug::ERRCODE_53: throw engine::CEngineException(code, "Non-square textures not supported", 3); break;
    case debug::ERRCODE_54: throw engine::CEngineException(code, "Non-power of two texture size not supported", 3); break;
    case debug::ERRCODE_55: throw engine::CEngineException(code, "GLSL not supported", 3); break;
    case debug::ERRCODE_60: throw engine::CEngineException(code, "No local translation object for dialog interface", 3); break;
    default: throw engine::CEngineException(code, "Internal error", 3); break;
  }

}

//! Writes an error message in error.log file
/** \param EngineException& to write
*/
void CGame::errorLog(const exception& e)
{
  ofstream errorLogFile("error.log", ios::out | ios::app);
  if (errorLogFile) {
    errorLogFile << e.what() << endl;
    errorLogFile.close();
  }
}

//! Get the current locale defined in configuration file
/** \return ELocaleIdentifier
*/
ELocaleIdentifier CGame::getCurrentLocale()
{
  return CurrentLocale;
}

//! Returns a pointer to the global translation interface
/** \return CTranslation*
*/
CTranslation* CGame::getGlobalTranslations()
{
  return GlobalTranslations;
}

//! Returns a pointer to the current save slot
/** \return CSave*
*/
CSave* CGame::getCurrentSave()
{
  return CurrentSave;
}

//! Returns a pointer to the Invisible Spirit Sound Manager
/** \return CSoundManager*
*/
sound::CSoundManager* CGame::getSoundManager()
{
  return SoundManager;
}

//! Returns the music interface
sound::CMusicReference* CGame::getMusicReference()
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

}
}
