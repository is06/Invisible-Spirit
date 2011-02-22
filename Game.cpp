/**************************************************************************************
Le code source d'Invisible Spirit par Thomas Noury est mis à disposition selon les
termes de la licence Creative Commons Paternité - Pas d'Utilisation Commerciale -
Partage des Conditions Initiales à l'Identique 3.0 Unported.
Basé(e) sur une oeuvre à www.is06.com.  Les autorisations au-delà du champ de
cette licence peuvent être obtenues à http://www.is06.com.
***************************************************************************************/

#include "core.h"

using namespace irr;

IrrlichtDevice* Game::device;
video::IVideoDriver* Game::videoDriver;
scene::ISceneManager* Game::sceneManager;
NewtonWorld* Game::newtonWorld;
Scene* Game::currentScene;
EventManager* Game::eventManager;

bool Game::exit;
u8 Game::framerate;
f32 Game::contacts[MAX_POINT_COLLIDE*3];
f32 Game::normals[MAX_POINT_COLLIDE*3];
f32 Game::penetration[MAX_POINT_COLLIDE*3];

/**
 * Pseudo-constructeur de Game, cette fonction initialise les objets Irrlicht, Bullet et du jeu
 */
void Game::init() {
  eventManager = new EventManager();

  core::array<SJoystickInfo> joystickInfo;

  device = createDevice(video::EDT_OPENGL, core::dimension2du(640, 480), 32, false, false, false, eventManager);
  device->setWindowCaption(L"Invisible Spirit (Newton version) 0.1-110120-1");
  device->activateJoysticks(joystickInfo);

  videoDriver = device->getVideoDriver();
  sceneManager = device->getSceneManager();

  newtonWorld = NewtonCreate();
  NewtonSetPlatformArchitecture(newtonWorld, 0);
  f32 minSize[3] = {-500.0f, -500.0f, -500.0f};
  f32 maxSize[3] = {500.0f, 500.0f, 500.0f};
  NewtonSetWorldSize(newtonWorld, minSize, maxSize);
  NewtonSetSolverModel(newtonWorld, 1);

  framerate = 60;
  exit = false;

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

/**
 * Pseudo-destructeur de Game
 */
void Game::finish() {
  delete currentScene;
  NewtonDestroyAllBodies(newtonWorld);
  NewtonDestroy(newtonWorld);
  device->drop();
}
