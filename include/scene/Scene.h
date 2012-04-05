/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_SCENE_H__
#define __IS06_SCENE_H__

#include "../engine/ShadowProcessor.h"
#include "../enums/styles/FadeColor.h"

using namespace irr;
using namespace std;

class Scene
{
  public:
    Scene();
    virtual ~Scene();

    virtual void events() = 0;
    virtual void postRender() = 0;
    virtual void hudRender() = 0;

    void darkenNonGlowingEntities();
    void revealNonGlowingEntities();
    void addToEntityList(ModelEntity* entity);

    void setSaveSlot(Save* saveSlot);
    void fadeIn(f32 speed = 1.5f, FadeColor color = FADE_COLOR_BLACK);
    void fadeOut(f32 speed = 3.0f, FadeColor color = FADE_COLOR_BLACK);

    Camera* getActiveCamera();

    ShadowProcessor* getShadowProcessor();

    static bool inMapEditingMode;

  protected:
    gui::IGUIInOutFader* inFader;
    gui::IGUIInOutFader* outFader;

    Picture* dummy;

    Camera* cam;
    //PlayerControl* control;
    //MapEditor* mapEditor;
    Keyboard* keyboard;
    Gamepad* gamepad;
    Save* gameSave;
    DialogInterface* dialog;
    MusicReference* music;
    Translation* globalTranslations;
    Translation* sceneTranslations;

    ShadowProcessor* shadows;

    f32 timeElapsed;
    f32 startTime;
    f32 speedFactor;

    gui::IGUIStaticText* debugInfo;

    map<ModelEntity*, bool> entityList;
    map<ModelEntity*, bool>::iterator entityListIt;

  private:
    void generateDebugInfo();
};

#endif
