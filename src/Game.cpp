/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../include/ref/core.h"
#include "../include/Game.h"
#include "../include/EventManager.h"
#include "../include/Settings.h"
#include "../include/sound/SoundManager.h"
#include "../include/Save.h"
#include "../include/sound/MusicReference.h"
#include "../include/scene/Scene.h"
#include "../include/scene/SceneMenu.h"
#include "../include/scene/SceneGameplay.h"
#include "../include/ref/maps.h"
#include "../include/Translation.h"

#include "../include/map/MAP_2D_TEST.h"
#include "../include/map/MAP_ALPHA_ZONE.h"
#include "../include/map/MAP_CANYON.h"

using namespace irr;
using namespace std;

IrrlichtDevice* Game::device;
video::IVideoDriver* Game::videoDriver;
video::IGPUProgrammingServices* Game::gpuManager;
scene::ISceneManager* Game::sceneManager;
gui::IGUIEnvironment* Game::debugGUI;
NewtonWorld* Game::newtonWorld;
Scene* Game::currentScene;
EventManager* Game::eventManager;
Settings* Game::settings;
Translation* Game::globalTranslations;
Save* Game::currentSave;
SoundManager* Game::soundManager;
MusicReference* Game::musicLibrary;

ScreenPosition Game::screenPos;
Shaders Game::shaders;
GameDebugOption Game::debugOption;
s32 Game::nextScene;
LocaleIdentifier Game::currentLocale;
bool Game::sceneChanged;
bool Game::exit;
bool Game::independantSpeed;
bool Game::processorPriority;
u8 Game::framerate;
f32 Game::speedFactor;

/**
 * All initializations
 */
void Game::init()
{
  // Event Manager and INI settings
  eventManager = new EventManager();
  settings = new Settings();

  // Screen size limit 640x480 => 1920x1080
  u32 screenWidth = settings->getParamInt("display", "width");
  u32 screenHeight = settings->getParamInt("display", "height");
  if(screenWidth < 640) screenWidth = 640;
  if(screenWidth > 1920) screenWidth = 1920;
  if(screenHeight < 480) screenHeight = 480;
  if(screenHeight > 1080) screenHeight = 1080;

  initDebugOptions();

  // Irrlicht Device creation
  device = createDevice(
    video::EDT_OPENGL,
    core::dimension2du(screenWidth, screenHeight),
    settings->getParamInt("display", "depth"),
    (settings->getParamInt("display", "fullscreen") == 1),
    true,
    (settings->getParamInt("display", "vsync") == 1),
    eventManager
  );
  device->setWindowCaption(L"Invisible Spirit 0.1");

  // Gestion de la vitesse de rendu
  independantSpeed = (settings->getParamInt("processor", "independant_speed") == 1);
  processorPriority = (settings->getParamInt("processor", "priority") == 1);

  // Activation du joystick
  core::array<SJoystickInfo> joystickInfo;
  device->activateJoysticks(joystickInfo);

  videoDriver = device->getVideoDriver();
  gpuManager = videoDriver->getGPUProgrammingServices();
  sceneManager = device->getSceneManager();
  debugGUI = device->getGUIEnvironment();
  initScreenPositions(screenWidth, screenHeight);
  initShaders();
  initLocale();

  soundManager = new SoundManager();

  musicLibrary = new MusicReference();

  currentSave = new Save();
  newtonWorld = NewtonCreate();

  framerate = 60;
  exit = false;

  sceneChanged = true;
  nextScene = SCENE_MENU;
}

/**
 * Game main loop
 */
void Game::run()
{
  // For independant speed
  u32 lastCycleTime, loopTime = 0;
  // For constant speed
  u32 before, after, renderTime, timeToSleep = 0;

  s32 lastFPS = -1;

  while (device->run()) {
    if (exit) {
      break;
    }

    if (sceneChanged) {
      loadNextScene();
    }

    s32 fps = videoDriver->getFPS();

    if (lastFPS != fps) {
      wstring str = L"fps: ";
      str += fps;
      device->setWindowCaption(str.c_str());
      lastFPS = fps;
    }

    if (independantSpeed) {
      // ----------------------------------------------------
      // Speed Independant Loop

      // Speed factor computation
      lastCycleTime = device->getTimer()->getRealTime() - loopTime;
      loopTime = device->getTimer()->getRealTime();
      speedFactor = lastCycleTime / 1000.0f;
      if(speedFactor > 1.0f) speedFactor = 1.0f; // Limit min 1fps
      if(speedFactor < 0.0f) speedFactor = 0.0f; // Limit max fps (infinite) negative = reversed movements

      videoDriver->beginScene(true, true, video::SColor(255,0,0,0));
      currentScene->events();
      sceneManager->drawAll();
      if (!debugOption.display.hidePostRender) {
        currentScene->postRender();
      }
      debugGUI->drawAll();

      soundManager->setEarsData(currentScene->getActiveCamera(), speedFactor);
      soundManager->update();

      videoDriver->endScene();
      if (!processorPriority) {
        device->yield();
      }

    } else {
      // ----------------------------------------------------
      // Constant Speed Loop
      before = device->getTimer()->getRealTime();

      speedFactor = 1.0f / framerate;

      videoDriver->beginScene(true, true, video::SColor(255,255,255,255));
      currentScene->events();
      sceneManager->drawAll();
      if (!debugOption.display.hidePostRender) {
        currentScene->postRender();
      }
      debugGUI->drawAll();
      soundManager->setEarsData(currentScene->getActiveCamera(), speedFactor);
      soundManager->update();
      videoDriver->endScene();

      after = device->getTimer()->getRealTime();
      renderTime = after - before;

      timeToSleep = (u32)(((1000.0f / framerate) - renderTime) + after);

      while (device->getTimer()->getRealTime() < timeToSleep) {
        if (!processorPriority) {
          device->yield();
        }
      }
    }
  }
}

/**
 * Access to the Irrlicht device
 * @return IrrlichtDevice*
 */
IrrlichtDevice* Game::getDevice()
{
  return device;
}

/**
 * Access to the Irrlicht video driver
 * @return IVideoDriver*
 */
video::IVideoDriver* Game::getVideoDriver()
{
  return videoDriver;
}

/**
 * Access to the Irrlicht scene manager
 * @return ISceneManager*
 */
scene::ISceneManager* Game::getSceneManager()
{
  return sceneManager;
}

/**
 * Access to the Debug GUI interface
 * @return IGUIEnvironment*
 */
gui::IGUIEnvironment* Game::getDebugGUI()
{
  return debugGUI;
}

/**
 * Access to the Newton world entity
 * @return NewtonWorld*
 */
NewtonWorld* Game::getNewtonWorld()
{
  return newtonWorld;
}

/**
 * Access to the current scene
 * @return Scene*
 */
Scene* Game::getCurrentScene()
{
  return currentScene;
}

/**
 * Access to the Event manager
 * @return EventManager*
 */
EventManager* Game::getEventManager()
{
  return eventManager;
}

/**
 * Set instruction in order to quit the game
 */
void Game::quit()
{
  exit = true;
}

/**
 * Initializes screen position values
 * @param u32 w screen width
 * @param u32 h screen height
 */
void Game::initScreenPositions(u32 w, u32 h)
{
  f32 ratio = (f32)w / (f32)h;
  h = 480;
  w = h * ratio;

  screenPos.hCenter = 0.0f;
  screenPos.vCenter = 0.0f;
  screenPos.top = (h / 2.0f);
  screenPos.bottom = (h / 2.0f) * -1;
  screenPos.left = (w / 2.0f) * -1;
  screenPos.right = (w / 2.0f);
}

/**
 * Initializes shader custom material values
 */
void Game::initShaders()
{
  shaders.opacity = 0;

  if (gpuManager) {

    // Shader Opacity
    /*
    OpacityShaderCallback* cb = new OpacityShaderCallback();
    shaders.opacity = gpuManager->addHighLevelShaderMaterialFromFiles(
      "resource/shader/opacity.vert", "vertexMain", video::EVST_VS_1_1,
      "resource/shader/opacity.frag", "pixelMain", video::EPST_PS_1_1,
      cb, video::EMT_TRANSPARENT_ALPHA_CHANNEL
    );
    cb->drop();
    */
    // Shader Glow
    shaders.glow = gpuManager->addHighLevelShaderMaterialFromFiles(
      "resource/shader/glow.vert", "vertexMain", video::EVST_VS_1_1,
      "resource/shader/glow.frag", "pixelMain", video::EPST_PS_1_1,
      0, video::EMT_TRANSPARENT_ADD_COLOR
    );
  }
}

/**
 * Creates a global translation object according to the locale set in settings
 */
void Game::initLocale()
{
  //string textLocale = settings->getParamString("regional", "locale");
  currentLocale = LOCALE_FRE_FR;
  /*
  if (textLocale == "eng-GB") {
    currentLocale = LOCALE_ENG_GB;
  }
  */

  globalTranslations = new Translation("global.txt");
}

/**
 *
 */
void Game::initDebugOptions()
{
  debugOption.display.hidePostRender = false;
  debugOption.display.showIrrlichtDebugData = false;
  debugOption.display.showWireFrame = false;
}

/**
 * Returns constant framerate target value
 * @return f32
 */
f32 Game::getFramerate()
{
  return framerate;
}

/**
 * Returns the speed factor, used to perform computation on movements
 * and time
 * @return f32
 */
f32 Game::getSpeedFactor()
{
  return speedFactor;
}

/**
 *
 */
f32 Game::getCurrentTime()
{
  return device->getTimer()->getRealTime();
}

/**
 * Changes the current scene by passing its id
 * @param s32 id the scene id
 */
void Game::changeScene(s32 id)
{
  nextScene = id;
  sceneChanged = true;
}

/**
 * Loads the scene which is specified in nextScene attribute on the next cycle
 */
void Game::loadNextScene()
{
  delete currentScene;
  switch (nextScene) {
    case SCENE_MENU: currentScene = new SceneMenu(); break;

    case SCENE_MAP_2D_TEST:currentScene = new MAP_2D_TEST(); break;
    case SCENE_MAP_ALPHA_ZONE: currentScene = new MAP_ALPHA_ZONE(); break;
    case SCENE_MAP_CANYON: currentScene = new MAP_CANYON(); break;

    default: fatalError(ERRCODE_10); break;
  }

  currentScene->setSaveSlot(currentSave);
  sceneChanged = false;
}

/**
 *
 */
void Game::warning(ErrorCode code)
{
  switch (code) {
    case ERRCODE_21: errorLog("--> WARNING : 21 : Unable to write save file"); break;
    default: errorLog("Unknown warning"); break;
  }
}

/**
 * Launches an error to error.log file by its code number
 * @param ErrorCode code the code number
 */
void Game::fatalError(ErrorCode code)
{
  switch (code) {
    case ERRCODE_10: errorLog("/!\\ FATAL ERROR : 10 : Unknown map id"); break;
    case ERRCODE_20: errorLog("/!\\ FATAL ERROR : 20 : Unable to open save file"); break;
    case ERRCODE_30: errorLog("/!\\ FATAL ERROR : 30 : Mesh file not found"); break;
    case ERRCODE_45: errorLog("/!\\ FATAL ERROR : 45 : Level Mesh need an Irrlicht mesh, use loadMesh method in scene constructor"); break;
    case ERRCODE_46: errorLog("/!\\ FATAL ERROR : 46 : Level Mesh need an Irrlicht node, use createNode method in scene constructor"); break;
    case ERRCODE_47: errorLog("/!\\ FATAL ERROR : 47 : Level Mesh need a Newton body, use loadMeshCollision method in scene constructor"); break;
    default: errorLog("/!\\ FATAL ERROR : Unknown error"); break;
  }
}

/**
 * Writes an error message in error.log file
 * @param string& errorText the message to write
 */
void Game::errorLog(const string& errorText)
{
  ofstream errorLogFile("error.log", ios::out | ios::app);
  if (errorLogFile) {
    errorLogFile << errorText.c_str() << endl;
    errorLogFile.close();
  }
}

/**
 * Get the current locale defined in configuration file
 * @return LocaleIdentifier
 */
LocaleIdentifier Game::getCurrentLocale()
{
  return currentLocale;
}

/**
 * Returns a pointer to the global translation interface
 * @return Translation*
 */
Translation* Game::getGlobalTranslations()
{
  return globalTranslations;
}

/**
 * Returns a pointer to the current save slot
 * @return Save*
 */
Save* Game::getCurrentSave()
{
  return currentSave;
}

/**
 * Returns a pointer to the Invisible Spirit Sound Manager
 * @return SoundManager*
 */
SoundManager* Game::getSoundManager()
{
  return soundManager;
}

/**
 *
 */
MusicReference* Game::getMusicReference()
{
  return musicLibrary;
}

/**
 * Flush and delete everything, finishes the game
 */
void Game::finish()
{
  delete currentScene;
  delete settings;
  delete musicLibrary;
  delete globalTranslations;
  delete currentSave;
  NewtonDestroyAllBodies(newtonWorld);
  NewtonDestroy(newtonWorld);
  device->drop();
  delete eventManager;
}
