/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_MAP_METADIM__
#define __IS06_MAP_METADIM__

#include "../../Scene/CSceneGameplay.h"

namespace is06
{
namespace NMap
{
namespace NGeneric
{

class MAP_METADIM : public NScene::CSceneGameplay
{
  public:
    MAP_METADIM();
    ~MAP_METADIM();

    void events();
    void postRender();
    void hudRender();

  private:
    u8 EventState;
};

}
}
}

#endif
