/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_MAP_2D_TEST__
#define __IS06_MAP_2D_TEST__

#include "../../include/scene/SceneGameplay.h"
#include "../../include/gui/BarCounter.h"

class MAP_2D_TEST : public SceneGameplay {
  public:
    MAP_2D_TEST();
    ~MAP_2D_TEST();

    void events();
    void postRender();

  private:
    BarCounter* bar;
};

#endif

