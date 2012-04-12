/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_MAP_CANYON__
#define __IS06_MAP_CANYON__

#include "../scene/SceneGameplay.h"

namespace is06
{
namespace map
{

class MAP_CANYON : public scene::CSceneGameplay
{
  public:
    MAP_CANYON();
    ~MAP_CANYON();

    void events();
    void postRender();
    void hudRender();
};

}
}

#endif
