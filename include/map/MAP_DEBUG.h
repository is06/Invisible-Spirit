/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_MAP_DEBUG__
#define __IS06_MAP_DEBUG__

#include "../scene/CSceneGameplay.h"

namespace is06
{
namespace nMap
{

class MAP_DEBUG : public nScene::CSceneGameplay
{
  public:
    MAP_DEBUG();
    ~MAP_DEBUG();

    void events();
    void postRender();
    void hudRender();

  private:

};

}
}

#endif

