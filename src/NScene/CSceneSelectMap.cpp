/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/core.h"
#include "../../include/N3D/NCamera/CThirdPerson.h"
#include "../../include/NScene/CSceneSelectMap.h"

namespace is06 { namespace NScene {

CSceneSelectMap::CSceneSelectMap() : CScene()
{
  BackBufferColor = video::SColor(0, 0, 0, 0);
  Camera = new N3D::NCamera::CThirdPerson();
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

}}
