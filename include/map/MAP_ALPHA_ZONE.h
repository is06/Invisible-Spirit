/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_MAP_ALPHA_ZONE__
#define __IS06_MAP_ALPHA_ZONE__

#include "../../include/scene/SceneGameplay.h"

class MAP_ALPHA_ZONE : public SceneGameplay
{
  public:
    MAP_ALPHA_ZONE();
    ~MAP_ALPHA_ZONE();

    void events();
    void postRender();

  private:
    Speaker* spk;
    OmniLight* lt;
};

#endif
