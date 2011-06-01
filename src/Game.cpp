/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../include/ref/core.h"

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

ScreenPosition Game::screenPos;
Shaders Game::shaders;
SceneIdentifier Game::nextScene;
LocaleIdentifier Game::currentLocale;
bool Game::sceneChanged;
bool Game::exit;
bool Game::independantSpeed;
bool Game::processorPriority;
u8 Game::framerate;
f32 Game::speedFactor;

/**
 * Pseudo-constructeur de Game, cette fonction initialise les objets Irrlicht, Newton et du jeu
 */
void Game::init() {
  // Gestionnaire d'événements et paramètres du fichier ini
  eventManager = new EventManager();
  settings = new Settings();

  // Limites de résolution d'écran 640x480 => 1920x1080
  u32 screenWidth = settings->getParamInt("display", "width");
  u32 screenHeight = settings->getParamInt("display", "height");
  if(screenWidth < 640) screenWidth = 640;
  if(screenWidth > 1920) screenWidth = 1920;
  if(screenHeight < 480) screenHeight = 480;
  if(screenHeight > 1080) screenHeight = 1080;

  // Création du device
  device = createDevice(
    video::EDT_OPENGL,
    core::dimension2du(screenWidth, screenHeight),
    settings->getParamInt("display", "depth"),
    (settings->getParamInt("display", "fullscreen") == 1),
    true,
    (settings->getParamInt("display", "vsync") == 1),
    eventManager);
  device->setWindowCaption(L"Invisible Spirit 0.1 r15 (09/04/2011)");

  video::IVideoModeList* vml = device->getVideoModeList();

  s32 videoModeCount = vml->getVideoModeCount();
  s32 colorDepth;
  core::dimension2du vres;

  cout << "Supported video modes:" << endl;

  for(s32 i = 0; i < videoModeCount; i++) {
    vres = vml->getVideoModeResolution(i);
    colorDepth = vml->getVideoModeDepth(i);
    cout << "- " << vres.Width << "x" << vres.Height << "x" << colorDepth << endl;
  }

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

  currentSave = new Save();
  newtonWorld = NewtonCreate();

  framerate = 60;
  exit = false;

  sceneChanged = true;
  nextScene = SCENE_MAP_ALPHA_ZONE;
}

/**
 * Game main loop
 */
void Game::run() {
  // For independant speed
  u32 lastCycleTime, loopTime = 0;
  // For constant speed
  u32 before, after, renderTime, timeToSleep = 0;

  s32 lastFPS = -1;

  while(device->run()) {
    if(exit) {
      break;
    }

    if(sceneChanged) {
      loadNextScene();
    }

    s32 fps = videoDriver->getFPS();

    if(lastFPS != fps) {
      core::stringw str = L"fps: ";
      str += fps;
      device->setWindowCaption(str.c_str());
      lastFPS = fps;
    }

    if(independantSpeed) {
      // ----------------------------------------------------
      // Speed Independant Loop

      // Speed factor computation
      lastCycleTime = device->getTimer()->getRealTime() - loopTime;
      loopTime = device->getTimer()->getRealTime();

      speedFactor = lastCycleTime / 1000.0f;
      if(speedFactor > 1.0f) speedFactor = 1.0f; // Limit min 1fps
      if(speedFactor < 0.0f) speedFactor = 0.0f; // Limit max fps (infinite) negative = reversed time

      videoDriver->beginScene(true, true, video::SColor(255,0,0,0));
      currentScene->events();
      sceneManager->drawAll();
      currentScene->postRender();
      //debugGUI->drawAll();

      soundManager->setEarsData(currentScene->getActiveCamera(), speedFactor);
      soundManager->update();
      videoDriver->endScene();

      if(!processorPriority) {
        device->yield();
      }

    } else {
      // ----------------------------------------------------
      // Constant Speed Loop
      before = device->getTimer()->getRealTime();

      speedFactor = 1.0f / framerate;

      videoDriver->beginScene(true, true, video::SColor(255,0,0,0));
      currentScene->events();
      sceneManager->drawAll();
      currentScene->postRender();
      //debugGUI->drawAll();
      soundManager->setEarsData(currentScene->getActiveCamera(), speedFactor);
      soundManager->update();
      videoDriver->endScene();

      after = device->getTimer()->getRealTime();
      renderTime = after - before;

      timeToSleep = (u32)(((1000.0f / framerate) - renderTime) + after);

      while(device->getTimer()->getRealTime() < timeToSleep) {
        if(!processorPriority) {
          device->yield();
        }
      }
    }
  }
}

/**
 * Permet d'accéder au device Irrlicht n'importe où dans le programme
 * @return IrrlichtDevice* un pointeur vers l'objet du device en cours
 */
IrrlichtDevice* Game::getDevice() {
  return device;
}

/**
 * Permet d'accéder au driver vidéo Irrlicht
 * @return IVideoDriver* un pointeur vers l'objet videoDriver en cours
 */
video::IVideoDriver* Game::getVideoDriver() {
  return videoDriver;
}

/**
 * Permet d'accéder au gestionnaire de scènes Irrlicht
 * @return ISceneManager* un pointeur vers l'objet sceneManager en cours
 */
scene::ISceneManager* Game::getSceneManager() {
  return sceneManager;
}

/**
 * TODO
 */
gui::IGUIEnvironment* Game::getDebugGUI() {
  return debugGUI;
}

/**
 * TODO
 */
NewtonWorld* Game::getNewtonWorld() {
  return newtonWorld;
}

Scene* Game::getCurrentScene() {
  return currentScene;
}

/**
 * Permet d'accéder au gestionnaire d'événements
 * @return EventManager* un pointeur vers l'objet eventManager en cours
 */
EventManager* Game::getEventManager() {
  return eventManager;
}

/**
 * Permet de quitter le programme
 */
void Game::quit() {
  exit = true;
}

/**
 *
 */
void Game::initScreenPositions(u32 w, u32 h) {
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
 *
 */
void Game::initShaders() {
  shaders.opacity = 0;

  if(gpuManager) {

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

void Game::initLocale() {
  core::stringc textLocale = settings->getParamString("regional", "locale");
  currentLocale = LOCALE_FRE_FR;
  if(textLocale == "eng-GB") {
    currentLocale = LOCALE_ENG_GB;
  }

  globalTranslations = new Translation("global.txt");
}

f32 Game::getFramerate() {
  return framerate;
}

f32 Game::getSpeedFactor() {
  return speedFactor;
}

void Game::changeScene(SceneIdentifier id) {
  nextScene = id;
  sceneChanged = true;
}

void Game::loadNextScene() {
  delete currentScene;
  switch(nextScene) {
    case SCENE_MENU: currentScene = new SceneMenu(); break;

    case SCENE_MAP_ALPHA_ZONE: currentScene = new MAP_ALPHA_ZONE(); break;
    case SCENE_MAP_CANYON: currentScene = new MAP_CANYON(); break;
  }
  sceneChanged = false;
}

LocaleIdentifier Game::getCurrentLocale() {
  return currentLocale;
}

Translation* Game::getGlobalTranslations() {
  return globalTranslations;
}

Save* Game::getCurrentSave() {
  return currentSave;
}

SoundManager* Game::getSoundManager() {
  return soundManager;
}

/**
 * Pseudo-destructeur de Game
 */
void Game::finish() {
  delete currentScene;
  delete eventManager;
  delete settings;
  delete globalTranslations;
  delete currentSave;
  NewtonDestroyAllBodies(newtonWorld);
  NewtonDestroy(newtonWorld);
  device->drop();
}
