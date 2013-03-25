/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#ifndef __IS06_MAP_DUNGEON_2__
#define __IS06_MAP_DUNGEON_2__

#include "../../Scene/CSceneDungeon.h"

namespace is06 { namespace NMap { namespace NDungeon {

class MAP_DUNGEON_2 : public NScene::CSceneDungeon
{
public:
  MAP_DUNGEON_2();
  ~MAP_DUNGEON_2();

  void events();
};

}}}

#endif
