/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../../include/core.h"
#include "../../../include/NEngine/NCore/CGame.h"
#include "../../../include/NEngine/NResource/CResourceManager.h"

namespace is06 { namespace NEngine { namespace NResource {

CResourceManager::CResourceManager()
{

}

scene::IMesh* CResourceManager::loadMesh(const string& path)
{
  return NEngine::NCore::CGame::getSceneManager()->getMesh(path.c_str());
}

video::ITexture* CResourceManager::loadTexture(const string& path)
{
  return NEngine::NCore::CGame::getVideoDriver()->getTexture(path.c_str());
}

CResourceManager::~CResourceManager()
{

}

}}}
