/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/core.h"
#include "../../include/3d/CPlayableCharacter.h"
#include "../../include/3d/CLevelMesh.h"
#include "../../include/map/MAP_DEBUG.h"

using namespace irr;

namespace is06
{
namespace nMap
{

MAP_DEBUG::MAP_DEBUG() : nScene::CSceneGameplay()
{

}

void MAP_DEBUG::events()
{
  nScene::CSceneGameplay::events();
}

void MAP_DEBUG::postRender()
{
  nScene::CSceneGameplay::postRender();
}

void MAP_DEBUG::hudRender()
{
  nScene::CSceneGameplay::hudRender();
}

MAP_DEBUG::~MAP_DEBUG()
{

}

}
}

