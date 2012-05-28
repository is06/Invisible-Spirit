/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/engine/core.h"
#include "../../include/engine/CGame.h"
#include "../../include/3d/CModelEntity.h"

namespace is06
{
namespace n3D
{

//! Initializations
CModelEntity::CModelEntity() : nEngine::CEntity()
{
  MainMesh = NULL;
  MainBody = NULL;
  AttachedSpeaker = NULL;
}

//! Rendering and event method
void CModelEntity::update()
{
  //Entity::update();
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
  MainMesh = nEngine::CGame::getSceneManager()->getMesh(meshFilePath.c_str());
}

//! Returns the irrlicht mesh object of the entity
scene::IMesh* CModelEntity::getMesh()
{
  return MainMesh;
}

//! Returns newton main body of this entity
NewtonBody* CModelEntity::getMainBody()
{
  return MainBody;
}

void CModelEntity::attachSpeaker(nSound::CSpeaker* speaker)
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
