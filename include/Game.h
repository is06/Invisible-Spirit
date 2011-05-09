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

    static void quit();
    static void changeScene(SceneIdentifier id);

    static IrrlichtDevice* getDevice();
    static video::IVideoDriver* getVideoDriver();
    static scene::ISceneManager* getSceneManager();
    static gui::IGUIEnvironment* getDebugGUI();
    static NewtonWorld* getNewtonWorld();
    static EventManager* getEventManager();
    static Translation* getGlobalTranslations();
    static Save* getCurrentSave();

    static f32 getFramerate();
    static f32 getSpeedFactor();
    static LocaleIdentifier getCurrentLocale();

    static Settings* settings;
    static ScreenPosition screenPos;
    static Shaders shaders;

  private:
    Game();
    static void initScreenPositions(u32 w, u32 h);
    static void initShaders();
    static void initLocale();
    static void loadNextScene();

    // Objets Irrlicht
    static IrrlichtDevice* device;
    static video::IVideoDriver* videoDriver;
    static video::IGPUProgrammingServices* gpuManager;
    static scene::ISceneManager* sceneManager;
    static gui::IGUIEnvironment* debugGUI;

    // Objets Newton
    static NewtonWorld* newtonWorld;

    // Objets IS06
    static EventManager* eventManager;
    static Scene* currentScene;
    static SceneIdentifier nextScene;
    static LocaleIdentifier currentLocale;
    static Translation* globalTranslations;
    static Save* currentSave;
    static SoundManager* soundManager;

    static bool sceneChanged;
    static bool exit;
    static bool independantSpeed;
    static bool processorPriority;
    static u8 framerate;
    static f32 speedFactor;
};

#endif
