/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/core.h"
#include "../../../include/N3D/NCharacter/CPlayableCharacter.h"
#include "../../../include/N3D/NPart/CMapPart.h"
#include "../../../include/NMap/NDebug/MAP_DEBUG.h"

using namespace irr;

namespace is06 { namespace NMap { namespace NDebug {

MAP_DEBUG::MAP_DEBUG() : NScene::CSceneGameplay()
{

}

void MAP_DEBUG::events()
{
  NScene::CSceneGameplay::events();
}

void MAP_DEBUG::postRender()
{
  NScene::CSceneGameplay::postRender();
}

void MAP_DEBUG::hudRender()
{
  NScene::CSceneGameplay::hudRender();
}

MAP_DEBUG::~MAP_DEBUG()
{

}

}}}
