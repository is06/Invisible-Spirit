/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../include/ref/core.h"
#include "../include/Game.h"
#include "../include/EngineException.h"
#include "../include/EventManager.h"
#include "../include/Settings.h"
#include "../include/sound/SoundManager.h"
#include "../include/save/Save.h"
#include "../include/sound/MusicReference.h"
#include "../include/scene/Scene.h"
#include "../include/scene/SceneMenu.h"
#include "../include/scene/SceneGameplay.h"
#include "../include/shader/DiffuseShaderCallback.h"
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
MusicReference* Game::musicReference;

ScreenPosition Game::screenPos;
Shaders Game::shaders;
GameDebugOption Game::debugOption;
s32 Game::nextScene;
LocaleIdentifier Game::currentLocale;
bool Game::sceneChanged;
bool Game::screenSizeChanged;
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
  settings = new Settings();

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
    if (exit || screenSizeChanged) {
      break;
    }

    if (sceneChanged) {
      loadNextScene();
    }

    s32 fps = videoDriver->getFPS();

    if (lastFPS != fps) {
      core::stringw str = L"Invisible Spirit 0.1 release 9 - fps: ";
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

      videoDriver->beginScene(true, true, video::SColor(255, 255, 255, 255));

      // Main events
      currentScene->events();
      sceneManager->drawAll();

      // Post Render events
      if (!debugOption.display.hidePostRender) {
        currentScene->postRender();
      }
      debugGUI->drawAll();

      soundManager->setEarsData(currentScene->getActiveCamera());
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

      videoDriver->beginScene(true, true, video::SColor(255, 255, 255, 255));

      // Main events
      currentScene->events();
      sceneManager->drawAll();

      // Post Render events
      if (!debugOption.display.hidePostRender) {
        currentScene->postRender();
      }
      debugGUI->drawAll();

      soundManager->setEarsData(currentScene->getActiveCamera());
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
 * Irrlicht interfaces initialization
 */
void Game::initIrrlichtInterfaces()
{
  // Custom Event Manager
  eventManager = new EventManager();

  // Getting from ini file
  u32 screenWidth = settings->getParamInt("display", "width");
  u32 screenHeight = settings->getParamInt("display", "height");
  u8 screenDepth = settings->getParamInt("display", "depth");

  // Irrlicht Device creation
  device = createDevice(
    video::EDT_OPENGL,
    core::dimension2du(screenWidth, screenHeight),
    screenDepth,
    (settings->getParamInt("display", "fullscreen") == 1),
    true,
    (settings->getParamInt("display", "vsync") == 1),
    eventManager
  );
  device->setWindowCaption(L"Invisible Spirit 0.1 release 9");

  // Other interfaces
  videoDriver = device->getVideoDriver();
  gpuManager = videoDriver->getGPUProgrammingServices();
  sceneManager = device->getSceneManager();
  debugGUI = device->getGUIEnvironment();

  // Check Driver Graphical Capabilities
  checkGraphicalCapabilities();
}

/**
 *
 */
void Game::initRenderSystem()
{
  // Render speed
  framerate = 60;
  independantSpeed = (settings->getParamInt("processor", "independant_speed") == 1);
  processorPriority = (settings->getParamInt("processor", "priority") == 1);
}

/**
 * Initializes screen position values
 */
void Game::initScreenPositions()
{
  screenSizeChanged = false;

  // Getting from ini file
  u32 screenWidth = settings->getParamInt("display", "width");
  u32 screenHeight = settings->getParamInt("display", "height");
  u8 screenDepth = settings->getParamInt("display", "depth");

  screenPos.width = screenWidth;
  screenPos.height = screenHeight;
  screenPos.depth = screenDepth;

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

  cout << screenWidth << "x" << screenHeight << endl;

  // Screen position info
  screenPos.hCenter = 0.0f;
  screenPos.vCenter = 0.0f;
  screenPos.top = (screenHeight / 2.0f);
  screenPos.bottom = (screenHeight / 2.0f) * -1;
  screenPos.left = (screenWidth / 2.0f) * -1;
  screenPos.right = (screenWidth / 2.0f);
}

/**
 * Initializes shader custom material values
 */
void Game::initShaders()
{
  shaders.diffuse = 0;
  shaders.glow = 0;

  if (gpuManager) {
    // Shader Diffuse (2D Elements)
    DiffuseShaderCallback* cb = new DiffuseShaderCallback();
    shaders.diffuse = gpuManager->addHighLevelShaderMaterialFromFiles(
      "resource/shader/diffuse.vert", "vertexMain", video::EVST_VS_1_1,
      "resource/shader/diffuse.frag", "pixelMain", video::EPST_PS_1_1,
      cb, video::EMT_TRANSPARENT_ALPHA_CHANNEL
    );
    cb->drop();

    // Shader Glow
    shaders.glow = gpuManager->addHighLevelShaderMaterialFromFiles(
      "resource/shader/glow.vert", "vertexMain", video::EVST_VS_1_1,
      "resource/shader/glow.frag", "pixelMain", video::EPST_PS_1_1,
      0, video::EMT_SOLID
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

  globalTranslations = new Translation("global.ist");
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
 *
 */
void Game::initSoundLayer()
{
  soundManager = new SoundManager();
  musicReference = new MusicReference();
}

/**
 *
 */
void Game::initScenes()
{
  exit = false;
  sceneChanged = true;
  nextScene = SCENE_MENU;
}

/**
 *
 */
void Game::initControls()
{
  // Joystick activation
  core::array<SJoystickInfo> joystickInfo;
  device->activateJoysticks(joystickInfo);
}

/**
 *
 */
void Game::initPhysics()
{
  newtonWorld = NewtonCreate();
}

/**
 *
 */
void Game::initSaveSystem()
{
  currentSave = new Save();
}

/**
 * Check for mandatory graphical capabilities
 */
void Game::checkGraphicalCapabilities()
{
  if (!videoDriver->queryFeature(video::EVDF_VERTEX_SHADER_1_1)) {
    fatalError(ERRCODE_50);
  }
  if (!videoDriver->queryFeature(video::EVDF_PIXEL_SHADER_1_1)) {
    fatalError(ERRCODE_51);
  }
  if (!videoDriver->queryFeature(video::EVDF_RENDER_TO_TARGET)) {
    fatalError(ERRCODE_52);
  }
  /*
  if (!videoDriver->queryFeature(video::EVDF_TEXTURE_NSQUARE)) {
    fatalError(ERRCODE_53);
  }
  if (!videoDriver->queryFeature(video::EVDF_TEXTURE_NPOT)) {
    fatalError(ERRCODE_54);
  }
  if (!videoDriver->queryFeature(video::EVDF_ARB_GLSL)) {
    fatalError(ERRCODE_55);
  }
  */
}

/**
 *
 */
void Game::changeScreenDisplay(u32 width, u32 height, u8 colorDepth)
{
  screenSizeChanged = true;
  delete currentScene;
  device->drop();
  screenPos.width = width;
  screenPos.height = height;
  screenPos.depth = colorDepth;
  initIrrlichtInterfaces();
  initScenes();
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
    case ERRCODE_21: throw EngineException(code, "Unable to write save file", 2); break;
    default: throw EngineException(code, "Unknown warning", 2); break;
  }
}

/**
 * Launches an error to error.log file by its code number
 * @param ErrorCode code the code number
 */
void Game::fatalError(ErrorCode code)
{
  switch (code) {
    case ERRCODE_10: throw EngineException(code, "Unknown map id", 3); break;
    case ERRCODE_20: throw EngineException(code, "Unable to open save file", 3); break;
    case ERRCODE_30: throw EngineException(code, "Mesh file not found", 3); break;
    case ERRCODE_45: throw EngineException(code, "Level Mesh need an Irrlicht mesh, use loadMesh method in scene constructor", 3); break;
    case ERRCODE_46: throw EngineException(code, "Level Mesh need an Irrlicht node, use createNode method in scene constructor", 3); break;
    case ERRCODE_47: throw EngineException(code, "Level Mesh need a Newton body, use loadMeshCollision method in scene constructor", 3); break;
    case ERRCODE_50: throw EngineException(code, "Vertex Shaders 2.0 not supported", 3); break;
    case ERRCODE_51: throw EngineException(code, "Pixels Shaders 2.0 not supported", 3); break;
    case ERRCODE_52: throw EngineException(code, "Render to target not supported", 3); break;
    case ERRCODE_53: throw EngineException(code, "Non-square textures not supported", 3); break;
    case ERRCODE_54: throw EngineException(code, "Non-power of two texture size not supported", 3); break;
    case ERRCODE_55: throw EngineException(code, "GLSL not supported", 3); break;
    default: throw EngineException(code, "Internal error", 3); break;
  }

}

/**
 * Writes an error message in error.log file
 * @param EngineException& to write
 */
void Game::errorLog(const exception& e)
{
  ofstream errorLogFile("error.log", ios::out | ios::app);
  if (errorLogFile) {
    errorLogFile << e.what() << endl;
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
  return musicReference;
}

/**
 * Flush and delete everything, finishes the game
 */
void Game::finish()
{
  delete currentScene;
  delete settings;
  delete soundManager;
  delete musicReference;
  delete globalTranslations;
  delete currentSave;

  NewtonDestroyAllBodies(newtonWorld);
  NewtonDestroy(newtonWorld);
  device->drop();

  delete eventManager;
}
