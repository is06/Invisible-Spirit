/******************************************************************************
Le code source d'Invisible Spirit par Thomas Noury est mis à disposition selon
les termes de la licence Creative Commons Paternité - Pas d'Utilisation
Commerciale - Partage des Conditions Initiales à l'Identique (BY-NC-SA) 3.0
Unported. Basé(e) sur une oeuvre à www.is06.com.  Les autorisations au-delà du
champ de cette licence peuvent être obtenues à http://www.is06.com.
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
f32 Game::contacts[MAX_POINT_COLLIDE*3];
f32 Game::normals[MAX_POINT_COLLIDE*3];
f32 Game::penetration[MAX_POINT_COLLIDE*3];

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
  device->setWindowCaption(L"Invisible Spirit 0.1 r9 (23/02/2011)");

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
  NewtonSetPlatformArchitecture(newtonWorld, 0);
  f32 minSize[3] = {-500.0f, -500.0f, -500.0f};
  f32 maxSize[3] = {500.0f, 500.0f, 500.0f};
  NewtonSetWorldSize(newtonWorld, minSize, maxSize);
  NewtonSetSolverModel(newtonWorld, 1);

  framerate = 60;
  exit = false;

  // Scène de démarrage
  currentScene = new SceneGameplay_MAP_CANYON();
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
    NewtonUpdate(newtonWorld, (1.0f / (f32)fps));

    videoDriver->beginScene();
    currentScene->events();
    sceneManager->drawAll();
    currentScene->postRender();


    after = device->getTimer()->getRealTime();
    renderTime = after - before;

    timeToSleep = ((1000.0f / framerate) - renderTime) + after;

    while(device->getTimer()->getRealTime() < timeToSleep) {
      device->yield();
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
    // Shader Bloom

  }
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
