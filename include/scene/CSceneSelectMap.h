/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_SCENE_SELECT_MAP_H__
#define __IS06_SCENE_SELECT_MAP_H__

#include "CScene.h"

namespace is06
{
namespace nScene
{

class CSceneSelectMap : public CScene
{
  public:
    CSceneSelectMap();
    ~CSceneSelectMap();

    void events();
    void postRender();
    void hudRender();
};

}
}

#endif
