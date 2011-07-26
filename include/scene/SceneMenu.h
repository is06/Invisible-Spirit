/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_SCENE_MENU_H__
#define __IS06_SCENE_MENU_H__

#include "Scene.h"

using namespace irr;
using namespace std;

class SceneMenu : public Scene {
  public:
    SceneMenu();
    ~SceneMenu();

    void events();
    void postRender();

  private:
    Picture* dummy;
    Picture* title;
    Menu* mainMenu;
    StaticModel* lightRays;
};

#endif
