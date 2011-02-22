/**************************************************************************************
Le code source d'Invisible Spirit par Thomas Noury est mis à disposition selon les
termes de la licence Creative Commons Paternité - Pas d'Utilisation Commerciale -
Partage des Conditions Initiales à l'Identique 3.0 Unported.
Basé(e) sur une oeuvre à www.is06.com.  Les autorisations au-delà du champ de
cette licence peuvent être obtenues à http://www.is06.com.
***************************************************************************************/

#ifndef __IS06_GAME_H__
#define __IS06_GAME_H__

using namespace irr;

class Game {
  public:
    static void init();
    static void run();
    static void finish();

    static IrrlichtDevice* getDevice();
    static video::IVideoDriver* getVideoDriver();
    static scene::ISceneManager* getSceneManager();
    static NewtonWorld* getNewtonWorld();
    static EventManager* getEventManager();
    static void debugExit();

    static const u16 MAX_POINT_COLLIDE = 64;
    static f32 contacts[MAX_POINT_COLLIDE*3];
    static f32 normals[MAX_POINT_COLLIDE*3];
    static f32 penetration[MAX_POINT_COLLIDE*3];

  private:
    Game();

    // Objets Irrlicht
    static IrrlichtDevice* device;
    static video::IVideoDriver* videoDriver;
    static scene::ISceneManager* sceneManager;

    // Objets Newton
    static NewtonWorld* newtonWorld;

    // Objets IS06
    static EventManager* eventManager;
    static Scene* currentScene;

    static bool exit;
    static u8 framerate;
};

#endif
