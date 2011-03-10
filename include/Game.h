/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

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

    static Settings* settings;

    static ScreenPosition screenPos;
    static Shaders shaders;

    static f32 getFramerate();

    static void changeScene(SceneIdentifier id);

  private:
    Game();
    static void initScreenPositions(u32 w, u32 h);
    static void initShaders();
    static void loadNextScene();

    // Objets Irrlicht
    static IrrlichtDevice* device;
    static video::IVideoDriver* videoDriver;
    static video::IGPUProgrammingServices* gpuManager;
    static scene::ISceneManager* sceneManager;

    // Objets Newton
    static NewtonWorld* newtonWorld;

    // Objets IS06
    static EventManager* eventManager;
    static Scene* currentScene;
    static SceneIdentifier nextScene;

    static bool sceneChanged;
    static bool exit;
    static u8 framerate;
};

#endif
