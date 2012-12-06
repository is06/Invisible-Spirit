/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/core.h"
#include "../../include/3d/CTPCamera.h"
#include "../../include/scene/CSceneSelectMap.h"

namespace is06
{
namespace nScene
{

CSceneSelectMap::CSceneSelectMap() : CScene()
{
  BackBufferColor = video::SColor(0, 0, 0, 0);
  Camera = new n3D::CTPCamera();
  Camera->setControl(false);
}

void CSceneSelectMap::events()
{
  CScene::events();

}

void CSceneSelectMap::postRender()
{
  CScene::postRender();

}

void CSceneSelectMap::hudRender()
{
  CScene::hudRender();

}

CSceneSelectMap::~CSceneSelectMap()
{

}

}
}
