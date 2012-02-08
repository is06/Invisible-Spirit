/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_SCENE_H__
#define __IS06_SCENE_H__

using namespace irr;
using namespace std;

class Scene
{
  public:
    Scene();
    virtual ~Scene();

    virtual void events() = 0;
    virtual void postRender() = 0;

    Camera* getActiveCamera();

    static bool inMapEditingMode;

  protected:
    Camera* cam;
    //PlayerControl* control;
    //MapEditor* mapEditor;
    Keyboard* keyboard;
    Gamepad* gamepad;
    MusicReference* music;
    Translation* globalTranslations;
    Translation* sceneTranslations;

    f32 timeElapsed;
    f32 speedFactor;

  private:
};

#endif
