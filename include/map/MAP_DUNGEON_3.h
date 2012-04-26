/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_MAP_DUNGEON_3__
#define __IS06_MAP_DUNGEON_3__

#include "../scene/SceneDungeon.h"

namespace is06
{
namespace nMap
{

class MAP_DUNGEON_3 : public nScene::CSceneDungeon
{
  public:
    MAP_DUNGEON_3();
    ~MAP_DUNGEON_3();

    void events();
};

}
}

#endif