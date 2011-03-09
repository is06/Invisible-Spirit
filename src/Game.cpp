/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../include/core.h"

using namespace irr;

IrrlichtDevice* Game::device;
video::IVideoDriver* Game::videoDriver;
video::IGPUProgrammingServices* Game::gpuManager;
scene::ISceneManager* Game::sceneManager;
NewtonWorld* Game::newtonWorld;
Scene* Game::currentScene;
EventManager* Game::eventManager;
Settings* Game::settings;

ScreenPosition Game::screenPos;
Shaders Game::shaders;
bool Game::exit;
u8 Game::framerate;

/**
 * Pseudo-constructeur de Game, cette fonction initialise les objets Irrlicht, Newton et du jeu
 */
void Game::init() {
  // Gestionnaire d'événements et paramètres du fichier ini
  eventManager = new EventManager();
  settings = new Settings();

  // Limites de résolution d'écran 320x200 => 1920x1080
  u32 screenWidth = settings->getParamInt("display", "width");
  u32 screenHeight = settings->getParamInt("display", "height");
  if(screenWidth < 320) screenWidth = 320;
  if(screenWidth > 1920) screenWidth = 1920;
  if(screenHeight < 200) screenHeight = 200;
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
  device->setWindowCaption(L"Invisible Spirit 0.1 r12 (02/03/2011)");

  // Activation du joystick
  core::array<SJoystickInfo> joystickInfo;
  device->activateJoysticks(joystickInfo);

  videoDriver = device->getVideoDriver();
  gpuManager = videoDriver->getGPUProgrammingServices();
  sceneManager = device->getSceneManager();
  initScreenPositions(screenWidth, screenHeight);
  initShaders();

  // Initialisation du moteur physique
  newtonWorld = NewtonCreate();

  framerate = 60;
  exit = false;

  // Scène de démarrage
  currentScene = new MAP_CANYON();
}

/**
 * Fonction de la boucle principale du jeu
 */
void Game::run() {
  f32 fps = 0;
  f32 before, after, renderTime, timeToSleep;

  while(device->run()) {
    if(exit) {
      break;
    }

    before = device->getTimer()->getRealTime();
    fps = videoDriver->getFPS();

    videoDriver->beginScene();
    currentScene->events();
    sceneManager->drawAll();
    currentScene->postRender();

    after = device->getTimer()->getRealTime();
    renderTime = after - before;

    timeToSleep = ((1000.0f / framerate) - renderTime) + after;

    while(device->getTimer()->getRealTime() < timeToSleep) {
      //device->yield();
    }

    videoDriver->endScene();
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
NewtonWorld* Game::getNewtonWorld() {
  return newtonWorld;
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
void Game::debugExit() {
  exit = true;
  //system("pause");
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

f32 Game::getFramerate() {
  return framerate;
}

/**
 * Pseudo-destructeur de Game
 */
void Game::finish() {
  delete currentScene;
  NewtonDestroyAllBodies(newtonWorld);
  NewtonDestroy(newtonWorld);
  device->drop();
}
