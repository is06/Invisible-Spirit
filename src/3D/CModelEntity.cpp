/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/Engine/core.h"
#include "../../include/Engine/CGame.h"
#include "../../include/Engine/Resource/CResourceManager.h"
#include "../../include/3D/CModelEntity.h"

namespace is06
{
namespace N3D
{

//! Initializations
CModelEntity::CModelEntity() : NEngine::CEntity()
{
  MainMesh = NULL;
  MainBody = NULL;
  AttachedSpeaker = NULL;
}

//! Rendering and event method
void CModelEntity::update()
{

}

void CModelEntity::shaderRender()
{

}

//! Loads a mesh in this entity
/**
 * \param string& meshFilePath
 */
void CModelEntity::loadMesh(const string& meshFilePath)
{
  MainMesh = NEngine::NResource::CResourceManager::loadMesh(meshFilePath);
}

//! Returns the irrlicht mesh object of the entity
scene::IMesh* CModelEntity::getMesh()
{
  return MainMesh;
}

//! Returns newton main body of this entity
NewtonBody* CModelEntity::getMainBody()
{
  if (MainBody) {
    return MainBody;
  } else {
    return NULL;
  }
}

void CModelEntity::attachSpeaker(NSound::CSpeaker* speaker)
{
  AttachedSpeaker = speaker;
}

//! Destroys all objects
CModelEntity::~CModelEntity()
{
  AttachedSpeaker = NULL;
}

}
}
